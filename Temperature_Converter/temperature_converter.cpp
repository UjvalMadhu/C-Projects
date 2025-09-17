////////////////////////////////////////////////////////////////////
/////                                                         //////
/////        Project: Temperature Converter                   //////
/////                                                         //////
////////////////////////////////////////////////////////////////////
//                                                                //
// Author: Ujval Madhu                                            //
// Filename: temerpature_converter.cpp                            //
// Description: Class definition file                             //
//                                                                //
// Change Log: 2nd Sept 2025                                      //
// Copyright: Ujval Madhu, All rights reserved                    //
//                                                                //
////////////////////////////////////////////////////////////////////

#include "temperature_converter.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

// Temperature Struct implementation
TemperatureConverter::Temperature::Temperature(double c): celsius(c) {
    updateFromC();
}

void TemperatureConverter::Temperature::updateFromC() {
    fahrenheit  = TemperatureConverter::c2F(celsius);
    kelvin      = TemperatureConverter::c2K(celsius); 
}

void TemperatureConverter::Temperature::updateFromF() {
    celsius     = TemperatureConverter::f2C(fahrenheit);
    kelvin      = TemperatureConverter::f2K(fahrenheit);
}

void TemperatureConverter::Temperature::updateFromK() {
    celsius     = TemperatureConverter::k2C(kelvin);
    fahrenheit  = TemperatureConverter::k2F(kelvin);
}

void TemperatureConverter::Temperature::display() const{
    std::cout << "====================================\n";
    std::cout << "||       Temperature Results      ||\n";
    std::cout << "====================================\n";
    std::cout << "|| Celsius: "<< std::setw(10) << std::fixed <<std::setprecision(2)
              << celsius << "°C         ||\n";
    std::cout << "|| Fahrenheit: "<< std::setw(10) << std::fixed <<std::setprecision(2)
              << fahrenheit << "°F   ||\n";
    std::cout << "|| Kelvin: "<< std::setw(10) << std::fixed <<std::setprecision(2)
              << kelvin << "°K          ||\n"; 
    std::cout << "||================================||\n";
}

