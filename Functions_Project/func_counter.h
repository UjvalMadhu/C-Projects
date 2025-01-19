////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project: Function Enhancement on Counter         //////
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

        typedef enum {BIN, BCD, GRY} mode_t;                 // Mode Control type for Binary, BCD and Gray Code Counting

        // Class default constructor
        Counter();

        // Class parameterized constructor
        Counter(int value_, mode_t mode_);

        // Copy Constructor
        Counter(const Counter& other);

        Counter& operator=(int val);

        // Copy Assignment
        Counter& operator=(const Counter& other);

        // Move Constructor
        Counter(Counter&& other);

        // Move Assignment Operator
        Counter& operator =( Counter&& other) noexcept;

        // Destructor
        ~Counter();

        int get_count(void) const;

        void increment(void);

        void combine_counters(const Counter& other) &;

        void combine_counters(Counter&& other) &&;

        mode_t get_mode(void) const;                         // Returns the current selected mode of the class object

        static unsigned get_object_count(void);                   // Returns the current active number of objects of the class

        void set(int value_);                                // set is an overloaded function that can accept different combination of parameters

        void set(mode_t mode_);

        void set(int value_, mode_t mode);

        


    protected:
        int value;
        int& ref_value;                  // Reference Value of count
        static unsigned object_count;    // keeps track of the number of objects of the class
        mode_t mode;

};

#endif