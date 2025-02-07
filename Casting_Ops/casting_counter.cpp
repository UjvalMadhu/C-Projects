////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project: Casting Enhancement on Counter          //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: casting_counter.cpp                                  //
// Description: Definitions for counter class with                //
// Casting capabilities                                           //
// Change Log: 6th Feb 2024                                       //
// Copyright: Ujval Madhu, All rights reserved                    //
//                                                                //
////////////////////////////////////////////////////////////////////

#include "casting_counter.h"

using namespace std;

unsigned Counter::object_count = 0; 

// Class default constructor
Counter::Counter() : value(0), ref_value(value), mode(BIN) {++object_count;}

// Class parameterized constructor
Counter::Counter(int value_, mode_t mode_) : value(value_), ref_value(value), mode(mode_)  {++object_count;}

// Copy Constructor
Counter::Counter(const Counter& other): value(other.value), ref_value(value) , mode(other.mode){++object_count;}

// Copy Assignment
Counter& Counter::operator=(const Counter& other){
    if(this != &other){
        value = other.value;
        mode  = other.mode;
    }
    return *this;
}

// Copy Assignment
Counter& Counter::operator=(int val){
        value = val;
    return *this;
}

// Move Constructor
Counter::Counter(Counter&& other): value(other.value), ref_value(value), mode(other.mode) {
    other.value = 0;
    other.mode  = BIN;
}

// Move Assignment Operator
Counter& Counter::operator =( Counter&& other) noexcept {
    if(this != &other){
        value = other.value;
        mode  = other.mode;
        other.value = 0;
        other.mode  = BIN;
    } 
    return *this;
}

// Counter Increment
void Counter::increment(){

    switch(mode) {

        case BIN:   ref_value+=1; break;                                          // Binary Counter
        case BCD:                                                                 // BCD Counter
                {   unsigned temp = ref_value, result = 0, carry = 1;
                    for(unsigned i = 0; i < sizeof(ref_value); i++){
                        unsigned l4b = (temp + carry) & 0xF;
                        if((carry = (l4b == 0xA))) l4b = 0x0;
                        result +=  (l4b<<i*4);
                        temp >>= 4;
                    } ref_value = result; 
                }break;
        case GRY:                                                                // Gray Code Counter
                {    unsigned bin = ref_value;
                    for(unsigned mask = bin >> 1; mask; mask >>= 1){
                        bin ^= mask;
                    }
                    bin += 1;
                    ref_value = bin ^ (bin >> 1); 
                }break;
    }

    
}

Counter::~Counter(){--object_count;}

int Counter::get_count(void) const {return value;};

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

// Get Mode
Counter::mode_t Counter::get_mode(void) const { return mode;}

// Get Object Count
unsigned Counter::get_object_count(void) {return object_count;}

// Set counter value
// This is an overloaded function with 3 possible declarations

// 1. With Counter Value
void Counter::set(int value_){
    this->value = value_;
}

// 2. With mode
void Counter::set(Counter::mode_t mode_){
    this->mode = mode_;
}

// 3. With both Counter Value and mode
void Counter::set(int value_, Counter::mode_t mode_){
    this->value = value_;
    this->mode  = mode_;
}



