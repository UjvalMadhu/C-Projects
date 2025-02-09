//////////////////////////////////////////////////////////////////////
/////                                                           //////
/////          Project:  Casting Operations                     //////
/////                                                           //////
//////////////////////////////////////////////////////////////////////
//                                                                  //
// Author: Ujval Madhu                                              //
// Filename: casting_test.cpp                                       //
// Description: Program for testing the counter class with the      //
// casting functionality                                            //
// Change Log: 8th Feb 2024                                        //
// Copyright: Ujval Madhu, All rights reserved                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "casting_counter.h"
#include <iostream>
#include <cassert>

using namespace std;


int main(){

    cout << "Initializing Counter class object counter1 Unparameterized " << endl;
    Counter counter1;
    assert(counter1.get_count() == 0);

    cout << "Setting counter1 value to 8" << endl;
    counter1.set(8) ;
    assert ( counter1.get_count() == 8 ) ;

    cout << "Incrementing counter1 value" << endl;
    counter1.increment ( ) ;
    assert ( counter1.get_count() == 9) ;

    // 1. Static Casting (Upcasting)
    Derived_Counter* dc_ptr = new Derived_Counter();
    dc_ptr->set(100);
    dc_ptr->increment();
    Counter* bc_ptr = static_cast<Counter*>(dc_ptr);
    cout<< "Base Class From Derived Class (Upcasting):" << bc_ptr->get_count() << endl;

   //2. Static Casting (Downcasting)
    Derived_Counter* dc_ptr2 = static_cast<Derived_Counter*>(bc_ptr);
    cout<< "Derived Class From Base Class (Downcasting):" << dc_ptr2->get_count() << endl;
    dc_ptr2->new_func();
    assert ( dc_ptr2->get_count() == 102 ) ;

   // 3. Dynamic Cast (Downcasting)
    Derived_Counter* dc_ptr3 = dynamic_cast<Derived_Counter*>(bc_ptr);
    dc_ptr3->increment();
    cout<< "Derived Class3 From Base Class (Downcasting):" << dc_ptr3->get_count() << endl;
    assert ( dc_ptr2->get_count() == 104 ) ;
    Square* sq_ptr4 = dynamic_cast<Square*>(bc_ptr);
    cout<< "Checking if Dynamic Cast returns nullptr for incorrect casting" << endl;
    assert (sq_ptr4 == nullptr) ;

    // 4. const_cast
    const int const_var   = 10;
    int* nonConst_ptr_var = const_cast<int*>(&const_var);
    *nonConst_ptr_var+=1;
    cout<< "Modified const variable value using const casting: "<< *nonConst_ptr_var << endl;
    assert (*nonConst_ptr_var == 11) ;
  
    // 5. Reinterpret Cast
    cout  << "Size of Counter* : "        << sizeof(Counter*)
          << "\nSize of int : "           << sizeof(int)
          << "\nSize of long int : "      << sizeof(long int)
          << "\nSize of long long int : " << sizeof(long long int)
          << "\nSize of short int : "     << sizeof(short int)
          << "\nSize of char : "          << sizeof(char) << endl;

    cout<< "Base Class before reinterpret Casting to and from long int:" << bc_ptr->get_count() << endl;
    long int li_var = reinterpret_cast<long int>(&bc_ptr);
    Counter* bc_ptr2 = reinterpret_cast<Counter*>(&li_var);
    cout<< "Base Class after reinterpret Casting to and from long int:" << bc_ptr2->get_count() << endl;

    // Reinterpret Casting to lower precision than the Counter* size will result in error
    // cout<< "Base Class before reinterpret Casting to and from short int:" << bc_ptr->get_count() << endl;
    // short int si_var = reinterpret_cast<short int>(&bc_ptr);
    // Counter* bc_ptr3 = reinterpret_cast<Counter*>(&si_var);
    // cout<< "Base Class after reinterpret Casting to and from short int:" << bc_ptr3->get_count() << endl;

    cout << "Casting Counter* to int and back and then trying to use the pointer" << endl;
    cout<< reinterpret_cast<Counter*>(reinterpret_cast<unsigned long int>(&bc_ptr)) -> get_count( ) << endl;

    cout << "TEST PASSED" << endl;

  return 0;
}