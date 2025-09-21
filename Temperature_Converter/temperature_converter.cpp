////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project: Temperature Converter                   //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: temerpature_converter.cpp                            //
// Description: Class definition file                             //
//                                                                //
// Change Log: 2nd Sept 2025                                      //
// Copyright: Ujval Madhu, All rights reserved                    //
//                                                                //
////////////////////////////////////////////////////////////////////

#include "temperature_converter.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

// Temperature Struct implementation
TemperatureConverter::Temperature::Temperature(double c): celsius(c) {
    updateFromC();
}

void TemperatureConverter::Temperature::updateFromC() {
    fahrenheit  = TemperatureConverter::c2F(celsius);
    kelvin      = TemperatureConverter::c2K(celsius); 
}

void TemperatureConverter::Temperature::updateFromF() {
    celsius     = TemperatureConverter::f2C(fahrenheit);
    kelvin      = TemperatureConverter::f2K(fahrenheit);
}

void TemperatureConverter::Temperature::updateFromK() {
    celsius     = TemperatureConverter::k2C(kelvin);
    fahrenheit  = TemperatureConverter::k2F(kelvin);
}

void TemperatureConverter::Temperature::display() const{
    std::cout << "====================================\n";
    std::cout << "||       Temperature Results      ||\n";
    std::cout << "====================================\n";
    std::cout << "|| Celsius:    "<< std::setw(10) << std::fixed <<std::setprecision(2)
              << celsius << "°C       ||\n";
    std::cout << "|| Fahrenheit: "<< std::setw(10) << std::fixed <<std::setprecision(2)
              << fahrenheit << "°F       ||\n";
    std::cout << "|| Kelvin:     "<< std::setw(10) << std::fixed <<std::setprecision(2)
              << kelvin << "°K       ||\n"; 
    std::cout << "||================================||\n";
}

TemperatureConverter::TemperatureConverter() : temp(20.0) {}

// Public Function Implementations, can be used by user and derived classes

double TemperatureConverter::c2F(double celsius){
    return  (celsius * 9.0 / 5.0) + 32.0;
}

double TemperatureConverter::c2K(double celsius){
    return celsius + 273.15;
}

double TemperatureConverter::f2C(double fahrenheit){
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double TemperatureConverter::f2K(double fahrenheit){
    return c2K(f2C(fahrenheit));
}

double TemperatureConverter::k2C(double kelvin){
    return kelvin - 273.15;
}

double TemperatureConverter::k2F(double kelvin){
    return c2F(k2C(kelvin));
}

void TemperatureConverter::setC(double celsius) {
    temp.celsius = celsius;
    temp.updateFromC();
}

void TemperatureConverter::setF(double fahrenheit) {
    temp.fahrenheit = fahrenheit;
    temp.updateFromF();
}

void TemperatureConverter::setK(double kelvin) {
    temp.kelvin = kelvin;
    temp.updateFromK();
}

void TemperatureConverter::displayTemperatures() const {
    temp.display();
}

void TemperatureConverter::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void TemperatureConverter::waitForEnter() {
    std::cout << "\nPress Enter to continue...";
    std::cin.ignore();
    std::cin.get();
}

void TemperatureConverter::showMenu() const {
    std::cout << "==========================================\n";
    std::cout << "||       TEMPERATURE CONVERTER          ||\n";
    std::cout << "==========================================\n";
    std::cout << "|| 1. Enter Celsius temperature         ||\n";
    std::cout << "|| 2. Enter Fahrenheit temperature      ||\n";
    std::cout << "|| 3. Enter Kelvin temperature          ||\n";
    std::cout << "|| 4. Show current temperatures         ||\n";
    std::cout << "|| 5. Preset: Water freezing point      ||\n";
    std::cout << "|| 6. Preset: Water boiling point       ||\n";
    std::cout << "|| 7. Preset: Room temperature          ||\n";
    std::cout << "|| 8. Show reference information        ||\n";
    std::cout << "|| 0. Exit                              ||\n";
    std::cout << "==========================================\n";
    std::cout << "Enter your choice: ";
}

void TemperatureConverter::run() {
    int choice;
    double inputTemp;

    std::cout << "Welcome to Temperature Converter\n\n";

    while(true) {
        showMenu();

        if (!(std::cin>> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input! Please Enter a number. \n";
            waitForEnter();
            clearScreen();
            continue;
        }

        switch (choice) {
            case 1:
                std::cout << "\n Enter Temperature in Celsius: ";
                if (std::cin>> inputTemp){
                    setC(inputTemp);
                    std::cout << "\n";
                    displayTemperatures();
                } else {
                    std::cout << "Invalid Temperature Value!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                waitForEnter();
                break;
            
            case 2:
                std::cout << "\n Enter Temperature in Fahrenheit: ";
                if (std::cin>> inputTemp){
                    setF(inputTemp);
                    std::cout << "\n";
                    displayTemperatures();
                } else {
                    std::cout << "Invalid Temperature Value!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                waitForEnter();
                break;
            
            case 3:
                std::cout << "\n Enter Temperature in Kelvin: ";
                if (std::cin>> inputTemp){
                    setK(inputTemp);
                    std::cout << "\n";
                    displayTemperatures();
                } else {
                    std::cout << "Invalid Temperature Value!\n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
                waitForEnter();
                break;
            
            case 4:
                std::cout << "\n";
                displayTemperatures();
                waitForEnter();
                break;

             case 5:
                setC(0.0);
                std::cout << "\nSet to water freezing point:\n";
                displayTemperatures();
                waitForEnter();
                break;
                
            case 6:
                setC(100.0);
                std::cout << "\nSet to water boiling point:\n";
                displayTemperatures();
                waitForEnter();
                break;
                
            case 7:
                setC(20.0);
                std::cout << "\nSet to room temperature:\n";
                displayTemperatures();
                waitForEnter();
                break;

            case 8:
                std::cout << "==============================================\n";
                std::cout << "||           REFERENCE TEMPERATURES          ||\n";
                std::cout << "==============================================\n";
                std::cout << "|| Absolute Zero: 0K / -273.15 C / -459.67 F ||\n";
                std::cout << "|| Water Freezes:  273.15 K / 0 C / 32 F     ||\n";
                std::cout << "|| Water Boils:  373.15 K  / 100 C / 212 F   ||\n";
                std::cout << "||                                           ||\n";
                std::cout << "|| Conversion Formulas:                      ||\n";
                std::cout << "|| F = (C x 9/5) + 32                        ||\n";
                std::cout << "|| C = (F - 32) x 5/9                        ||\n";
                std::cout << "|| K = C + 273.15                            ||\n";
                std::cout << "===============================================\n";
                waitForEnter();
                break;
            
            case 0:
                std::cout << "\nThank you for using Temperature Converter!\n";
                return;
            
            default:
                std::cout << "Inalid Entry! Please Select 0-8\n";
                waitForEnter();
                break;
        }

        clearScreen();
    }
        
}
