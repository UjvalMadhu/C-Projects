////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project:  Constructors & Destructor              //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: constr_destr_counter.cpp                             //
// Description: counter class with all constructor                //
// and destructor capabilities                                    //
// Change Log: 31st Dec 2024                                      //
// Copyright: Ujval Madhu, All rights reserved                    //
//                                                                //
////////////////////////////////////////////////////////////////////

#include <iostream>
#include "constr_destr_counter.h"

using namespace std;

// Class default constructor
Counter::Counter() : value(0) {}

// Class parameterized constructor
Counter::Counter(int value_) : value(value_) {}

// Copy Constructor
Counter::Counter(const Counter& other){
    value = other.get_count();
}

// Copy Assignment
Counter& Counter::operator=(const Counter& other){
    if(this != &other){
        value = other.value;
    }
    return *this;
}

// Move Constructor
Counter::Counter(Counter&& other) {
    value = other.value;
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

void Counter::set_count(int value_){
    this->value = value_;
}

int Counter::get_count() const {
    return value;
}

void Counter::increment(){
    value+=1;
}