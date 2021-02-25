#pragma once
#include<string>
#include <iostream>
#include <limits>

using namespace std;
 
// template to validate data
template<typename T>
T validation(T& num)
{
    cin >> num;

    while (!(cin.good()))
    {
        //clear stream
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << " - Faulty input! Plese try again: ";
        cin >> num;
    }
    //clear stream
    cin.clear();
    cin.ignore(INT_MAX, '\n');
    return num;
};

// template for checking over and underflow when adding
template<typename T>
T checkAdd(T numOne, T numTwo)
{
    intmax_t sum;                                                    //  largest integral type supported by compailer
    sum = static_cast <intmax_t>( numOne) + static_cast <intmax_t>( numTwo);
    if (sum > numeric_limits<T>::max())                              // check for overflow
    {
        cerr << "Sensor error";
    }
    if (sum < numeric_limits<T>::min())                              // checking for underflow
    {
        cerr << "Sensor error";
    }
    return
        static_cast <T>(sum);                                       // casting back to type T
}

// template for checking over and underflow when substracting
template<typename T>
T checkSubstract(T numOne, T numTwo)
{
    intmax_t sub;                                                    //  largest integral type supported by compailer
    sub = static_cast <intmax_t>(numOne) - static_cast <intmax_t>(numTwo);
    if (sub > numeric_limits<T>::max())                              // check for overflow
    {
        cerr << "System error";
    }
    if (sub < numeric_limits<T>::min())                              // checking for underflow
    {
        cerr << "System error";
    }
    return
        static_cast <T>(sub);                                       // casting back to type T
}

