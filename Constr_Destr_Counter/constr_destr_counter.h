////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project:  Constructors & Destructor              //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: constr_destr_counter.h                               //
// Description: Header File for the counter class                 //
// Change Log: 31st Dec 2024                                      //
// Copyright: (c) Ujval Madhu, All rights reserved                //
//                                                                //
////////////////////////////////////////////////////////////////////

#ifndef COUNTER_H
#define COUNTER_H

class Counter{
    public:
        // Class default constructor
        Counter();

        // Class parameterized constructor
        Counter(int value_);

        // Copy Constructor
        Counter(const Counter& other);

        // Copy Assignment
        Counter& operator=(const Counter& other);

        // Move Constructor
        Counter(Counter&& other);

        // Move Assignment Operator
        Counter& operator =( Counter&& other) noexcept;

        // Destructor
        ~Counter();

        void set_count(int value_);

        int get_count(void) const;

        void increment(void);

    private:
        int value;
};

#endif