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

TemperatureConverter::TemperatureConverter() : temp(20.0) {}

// Public Function Implementations, can be used by user and derived classes

double TemperatureConverter::c2F(double celsius){
    return  (celsius * 9.0 / 5.0) + 32.0;
}

double TemperatureConverter::c2K(double celsius){
    return celsius + 273.15;
}

double TemperatureConverter::f2C(double fahrenheit){
    return (fahrenheit - 32) * 5.0 / 9.0;
}

double TemperatureConverter::f2K(double fahrenheit){
    return c2K(f2C(fahrenheit));
}

double TemperatureConverter::k2C(double kelvin){
    return kelvin - 273.15;
}

double TemperatureConverter::k2F(double kelvin){
    return c2F(k2C(kelvin));
}

void TemperatureConverter::setC(double celsius) {
    temp.celsius = celsius;
    temp.updateFromCelsius();
}

void TemperatureConverter::setF(double fahrenheit) {
    temp.fahrenheit = fahrenheit;
    temp.updateFromFahrenheit();
}

void TemperatureConverter::setK(double kelvin) {
    temp.kelvin = kelvin;
    temp.updateFromKelvin();
}

void TemperatureConverter::displayTemperatures() const {
    temp.display();
}