////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project:  References Enhancement on Counter      //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: ref_counter.h                                        //
// Description: Header file for counter class with                //
// reference variable and ref-qualified function capabilities     //
// Change Log: 2nd Jan 2024                                       //
// Copyright: Ujval Madhu, All rights reserved                    //
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

        void combine_counters(const Counter& other) &;

        void combine_counters(Counter&& other) &&;

    protected:
        int value;
        int& ref_value;
};

#endif