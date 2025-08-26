/////////////////////////////////////////////////////////////////////////////////
////                       Project:  IO Operations                         //////
/////////////////////////////////////////////////////////////////////////////////
// Author: Ujval Madhu
// Description: This program demonstrates some fundamental IO operations in C++ 
// 1) The program inputs name and date of birth from a user,
// 2) Calculates Age of User from DOB,
// 3) Write to a file,
// 4) Read data from the file and display the contents.
// Change Log: 28th Dec 2024

#include <iostream>
#include <fstream>
#include <ctime>
#include <limits>

using namespace std;

struct UserDetails{
    char name[90];
    int  day, month, year;

    int calculate_age() const{
        time_t now          = time(0);
        tm* lc_time         = localtime(&now);
        int current_year    = 1900 + lc_time->tm_year;
        int current_month   = 1+ lc_time->tm_mon;
        int current_day     = lc_time->tm_mday;

        int age             = current_year - year;
        if(month > current_month || (current_month == month && day > current_day)){
            age--;
        }
        return age;
    }
};

int main(){
    UserDetails user;
    UserDetails user_read;
    ofstream out_file;
    ifstream in_file;
    const char filename[100] = "user_data.txt";

    #if defined pass1

        out_file.open(filename, ios::out);
        if(!out_file.is_open()){
            cerr << "Error Opening the file for writing" <<endl;
            return 1;
        }

        cout << "Welcome" << endl;
        cout << "Enter User Details:" << endl;
        cout << "Name: ";
        cin.getline(user.name, 90);

        while(true){
            cout << "Enter your day of birth(1-31): ";
            cin >> user.day;
            if(cin.fail() || user.day < 1 || user.day > 31){
                cout << "\nInvalid Day. Please enter a day between 1 and 31: ";
                cin.clear();   // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignores any existing value
                continue;
            }
            break;
        }
        
        while(true){
            cout << "Enter your month of birth(1-12): ";
            cin >> user.month;
            if(cin.fail() || user.month < 1 || user.month > 12){
                cout << "\nInvalid Day. Please enter a month between 1 and 12: ";
                cin.clear();   // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }

        while(true){
            cout << "Enter your year of birth: ";
            cin >> user.year;
            if(cin.fail() || user.year < 0){
                cout << "\nInvalid Day. Please enter a valid year: ";
                cin.clear();   // Clear error flags
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        // int age = user.calculate_age();

        // out_file << "Name: " << user.name << endl;
        // out_file << "Date of Birth: " << user.day << "/"<< user.month << "/" << user.year << endl;
        // out_file << "Age: " << age << endl;

        out_file.write((char*)&user, sizeof(user));
        out_file.close();

        cout<< "File Created" <<endl;
    
    #elif defined pass2
        in_file.open(filename, ios::in);
        if(!in_file.is_open()){
            cerr << "Error Opening the file for writing" <<endl;
            return 1;
        }
        in_file.read((char*)&user_read, sizeof(user_read));
        cout << "You are " << user_read.name << " and you are " << user_read.calculate_age() << " years old. " << endl;


    #else

        cerr << "You must include -Dpass1 or -Dpass2";

    #endif

    return 0;
}
