#pragma once
#include <iostream>


using namespace std;

class bad_leight : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Невозможно создать массив, задано отрицательное значение! ";
    }
};