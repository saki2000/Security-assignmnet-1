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

// template to check for overflow                       //#SS3
template<typename T>
T intAddition( T i16t_a,  T i16t_b) 
{
   
    if (((i16t_b > 0) && (i16t_a > (numeric_limits<T>::max() - i16t_b))) ||
        ((i16t_b < 0) && (i16t_a < (numeric_limits<T>::min() - i16t_b))))
    {
        cerr << "System error ";
        return 0;
    }
    else 
    {
        return i16t_a + i16t_b;
    }
}


// template to check for overflow
template<typename T>
T intSubstaction(T i16t_a, T i16t_b)                        //#SS3
{
    if ((i16t_b > 0 && i16t_a < numeric_limits<T>::min() + i16t_b) ||
        (i16t_b < 0 && i16t_a > numeric_limits<T>::max() + i16t_b))
    {
        cerr << "System error";
        return 0;
    }
    else
    {
        return  i16t_a - i16t_b;
    }
}
