#pragma once
#include<string>
#include <iostream>
#include <limits>

using namespace std;

enum class MenuChoice           // enum for main menu
{
	Quit,
	CurrentWeather,
	NextDayWeather,
	AdminLogIn,
    SIZE                // using this to in case of of adding or deleting options
};

enum class AdminMenuChoice          // enum for admin menu
{
    LogOut,
    Location,
    OverrideSpeed,
    ChangeLights,
    RunTest,
    AddUser,
    SaveData,
    LoadData,
    Emergency,
    SIZE
};

enum class authenticationLevel   // enumerator for authentication
{
    Staff, 
    Admin
};

enum AccessType: int16_t               //// CHEEEEEEEEEEEEK DISSSSSSSSSSSSSS
{
    NA = 0x00,
    FA = 0x10
};

enum class DeviceState            // enum for lift
{
    off, 
    on 
};

static tm time()						// tm for using time
{
    time_t current_time = time(0);
    tm now;
    localtime_s(&now, &current_time);
    return now;
}

 
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

