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
// Change Log: 31st Dec 2024                                        //
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

    cout << "Setting counter1 mode to BCD using overloaded function" << endl;
    counter1.set(Counter::BCD);

    cout << "Get Mode check" << endl;
    Counter::mode_t c1_mode = counter1.get_mode();

    cout << "Incrementing counter1 value" << endl;
    counter1.increment ( ) ;
    //cout << counter1.get_count() << endl;
    assert ( counter1.get_count() == 16) ;

    cout << "Initializing counter2 with copy constructor" << endl;
    Counter counter2(counter1);
    assert ( counter2.get_count() == 16 ) ;

    cout << "Initializing using individual parameterization counter2 with value 1 and mode = Gray " << endl;
    counter2.set(0);
    counter2.set(Counter::BCD);
    cout << "Counter 2 BCD Counting" << endl;
    for(int i = 0; i< 25; i++){
      counter2.increment();
      unsigned temp = counter2.get_count();
      cout << temp << endl;
    }
    //cout << counter2.get_count() << endl;
    assert ( counter2.get_count() == 37 ) ;

    cout << "Initializing using parameterized constructor: counter3 with value 1 and mode = Gray" << endl;
    Counter counter3(1, Counter::GRY);
    assert ( counter3.get_count() == 1) ;
    assert ( counter3.get_mode() == Counter::GRY) ;

    cout << "Counting to 10 in Gray Code with counter3" << endl;
    for(int i = 0; i< 10; i++){
      unsigned temp = counter3.get_count();
      cout << temp << endl;
      counter3.increment();
    }
    assert ( counter3.get_count() == 14 ) ;

    cout << "Assigning value 90 to counter2" << endl;
    counter2 = 90;
    assert ( counter2.get_count() == 90 ) ;

    cout << "Moving value counter1 to counter2" << endl;
    counter2 = move(counter1);
    assert ( counter2.get_count() == 16) ;
    assert ( counter1.get_count() == 0 ) ;

    cout << "Combining counter1 with a temp counter of count value 10" << endl;
    counter1.combine_counters(Counter(10, Counter::BIN));
    assert( counter1.get_count() == 10 );

    cout << "Counting the number of objects" << endl;
    assert ( counter2.get_object_count() == 3) ;

    cout << "TEST PASSED" << endl;

  return 0;


}