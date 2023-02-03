#pragma once
#include <iostream>


using namespace std;

class bad_range : public exception
{
public:
    virtual const char* what() const noexcept override
    {
        return "ERROR: Выход за границы контейнера! ";
    }
};