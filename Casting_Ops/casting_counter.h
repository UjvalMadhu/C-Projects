////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project: Casting Enhancement on Counter          //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: casting_counter.h                                    //
// Description: Header file for counter class with                //
// Casting capabilities                                           //
// Change Log: 6th Feb 2024                                       //
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

        // Virtual Destructor, so that it is applicable to derived classes
        virtual ~Counter();

        int get_count(void) const;

        virtual void increment(void); // Virtual

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

// A Derived class for counter

class Derived_Counter : public Counter{
    public:
        void increment(void) override;
        void new_func(void);
};

// A new unrelated class

class Square{
    public:
        Square(int value_);

        ~Square();

        void square_calc();
    
    private:
        int value;

};

#endif