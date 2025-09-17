////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project: Temperature Converter                   //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: temerpature_converter.h                              //
// Description: Header file for temperature_converter             //
//                                                                //
// Change Log: 2nd Sept 2025                                      //
// Copyright: Ujval Madhu, All rights reserved                    //
//                                                                //
////////////////////////////////////////////////////////////////////

#ifndef TEMPERATURE_CONVERTER_H
#define TEMPERATURE_CONVERTER_H

#include <string>
#include <iostream>

class TemperatureConverter {
    private:
        struct Temperature {
            double celsius;
            double kelvin;
            double fahrenheit;

            Temperature(double c = 0.0);    // Constructor for Struct
            void updateFromC();
            void updateFromF();
            void updateFromK();
            void display() const;
        }

        Temperature temp;                  // Calling the constructor of the struct, See Struct Implementation

    public:
        TemperatureConverter();                // Class Constructor

        //Static Conversion Commands
        static double c2F(double celsius);
        static double c2K(double celsius);
        static double f2C(double fahrenheit);
        static double f2K(double fahrenheit);
        static double k2C(double kelvin);
        static double k2CF(double kelvin);

        // Interface Functions
        void setC(double celsius);
        void setF(double fahrenheit);
        void setK(double kelvin);
        void displayTemperatures() const;
        void showMenu() const;
        void run();

        // Utility functions
        static void clearScreen();
        static void waitForEnter();
}
#endif