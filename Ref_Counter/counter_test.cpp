//////////////////////////////////////////////////////////////////////
/////                                                           //////
/////          Project:  Constructors & Destructor              //////
/////                                                           //////
//////////////////////////////////////////////////////////////////////
//                                                                  //
// Author: Ujval Madhu                                              //
// Filename: counter_test.cpp                                       //
// Description: Program for testing the counter class functionality //
// and destructor capabilities                                      //
// Change Log: 31st Dec 2024                                        //
// Copyright: Ujval Madhu, All rights reserved                      //
//                                                                  //
//////////////////////////////////////////////////////////////////////

#include "ref_counter.h"
#include <iostream>
#include <cassert>

using namespace std;


int main(){

    cout << "Initializing Counter class object counter1 Unparameterized " << endl;
    Counter counter1;
    assert(counter1.get_count() == 0);

    cout << "Setting counter1 value to 100" << endl;
    counter1.set_count (100) ;
    assert ( counter1.get_count() == 100 ) ;

    cout << "Incrementing counter1 value" << endl;
    counter1.increment ( ) ;
    assert ( counter1.get_count() == 101) ;

    cout << "Initializing counter2 with copy constructor" << endl;
    Counter counter2(counter1);
    assert ( counter2.get_count() == 101 ) ;

    cout << "Initializing counter3 with value 25" << endl;
    Counter counter3(25);
    assert ( counter3.get_count() == 25 ) ;

    cout << "Assigning counter3 to counter1" << endl;
    counter1 = counter3;
    assert ( counter1.get_count() == 25 ) ;

    cout << "Assigning value 90 to counter2" << endl;
    counter2 = 90;
    assert ( counter2.get_count() == 90 ) ;

    cout << "Moving value counter1 to counter2" << endl;
    counter2 = move(counter1);
    assert ( counter2.get_count() == 25 ) ;
    assert ( counter1.get_count() == 0 ) ;

    cout << "Combining counter 2 and Counter 3 using ref qualified function" << endl;
    counter2.combine_counters(counter3);
    assert( counter2.get_count() == 50 );
    assert( counter3.get_count() == 25 );

    cout << "Combining counter1 with a temp counter of count value 10" << endl;
    counter1.combine_counters(Counter(10));
    assert( counter1.get_count() == 10 );

    cout << "TEST PASSED" << endl;

  return 0;


}