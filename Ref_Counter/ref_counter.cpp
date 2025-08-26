////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project:  References Enhancement on Counter      //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: ref_counter.cpp                                      //
// Description: counter class with reference variable             //
// and ref- qualified function capabilities                       //
// Change Log: 2nd Jan 2024                                       //
// Copyright: Ujval Madhu, All rights reserved                    //
//                                                                //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include "ref_counter.h"

using namespace std;

// Class default constructor
Counter::Counter() : value(0), ref_value(value) {}

// Class parameterized constructor
Counter::Counter(int value_) : value(value_), ref_value(value) {}

// Copy Constructor
Counter::Counter(const Counter& other): value(other.get_count()), ref_value(value) {}

// Copy Assignment
Counter& Counter::operator=(const Counter& other){
    if(this != &other){
        value = other.value;
    }
    return *this;
}

// Move Constructor
Counter::Counter(Counter&& other): value(other.value), ref_value(value) {
    other.value = 0;
}

// Move Assignment Operator
Counter& Counter::operator =( Counter&& other) noexcept {
    if(this != &other){
        value = other.value;
        other.value = 0;
    } 
    return *this;
}

// Destructor
Counter::~Counter(){};

// Set counter value
void Counter::set_count(int value_){
    this->value = value_;
}

// Counter value access
int Counter::get_count() const {
    return value;
}

// Counter Increment
void Counter::increment(){
    ref_value+=1;
}

// Reference qualified function
// Combines the count value of two counters in both lvalue and rvalue argument format
// lvalue version
void Counter::combine_counters(const Counter& other) &{
    this-> value += other.value;
}

// rvalue version
void Counter::combine_counters(Counter&& other) && {
    this-> value += other.value;
}

