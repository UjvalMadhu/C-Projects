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

        Temperature temp;                  // Variable Declaration

    public:
        TemperatureConverter();            // Class Constructor

        //Static Conversion Commands
        static double c2F(double c);
        static double c2K(double c);
        static double f2C(double f);
        static double f2K(double f);
        static double k2C(double k);
        static double k2CF(double k);

        // Interface Functions
        void setC(double c);
        void setF(double f);
        void setK(double k);
        void displayTemperatures() const;
        void showMenu() const;
        void run();

        // Utility functions
        static void clearScreen();
        static void waitForEnter();
}
#endif