#pragma once

#include <iostream>
#include "IntegerArray.h"
#include "bad_leight.h"
#include "bad_range.h"


using namespace std;

  

    IntegerArray::IntegerArray(int length) :
        m_length{ length }
    {
        if (length < 0)
        {
            throw bad_leight();
        };
        if (length > 0)
            m_data = new int[length] {};
    }

    IntegerArray::IntegerArray(const IntegerArray& a)
    {
        reallocate(a.getLength());// Set the size of the new array appropriately

        for (int index{ 0 }; index < m_length; ++index)// Then copy the elements
            m_data[index] = a.m_data[index];
    }

    IntegerArray::~IntegerArray()
    {
        delete[] m_data;
    }

    void IntegerArray:: erase()
    {
        delete[] m_data;
        
        m_data = nullptr;
        m_length = 0;
    }

     int& IntegerArray::operator[](int index)
    {
        if (index < 0 && index > m_length )
        {
            throw bad_range();
        };
       
        return m_data[index];
    }

    void IntegerArray::reallocate(int newLength)
    {
        erase(); // First we delete any existing elements


        if (newLength <= 0) // If our array is going to be empty now, return here
            return;

        m_data = new int[newLength];// Then we have to allocate new elements
        m_length = newLength;
    }

    void IntegerArray::resize(int newLength) // resize resizes the array.  Any existing elements will be kept.  This function operates slowly.
    {
        if (newLength == m_length)// if the array is already the right length, we're don
            return;


        if (newLength <= 0)// If we are resizing to an empty array, do that and return
        {
            erase();
            return;
        }

        int* data{ new int[newLength] };   // First we have to allocate a new array


        if (m_length > 0)
        {
            int elementsToCopy{ (newLength > m_length) ? m_length : newLength };

            for (int index{ 0 }; index < elementsToCopy; ++index)// Now copy the elements one by one
                data[index] = m_data[index];
        }

        delete[] m_data;// Now we can delete the old array because we don't need it any more

        // And use the new array instead!  Note that this simply makes m_data point
        // to the same address as the new array we dynamically allocated.  Because
        // data was dynamically allocated, it won't be destroyed when it goes out of scope.
        m_data = data;
        m_length = newLength;
    }

   IntegerArray& IntegerArray::operator=(const IntegerArray& a)
    {
        if (&a == this)// Self-assignment check
            return *this;

        reallocate(a.getLength());// Set the size of the new array appropriately

        for (int index{ 0 }; index < m_length; ++index) // Then copy the elements
            m_data[index] = a.m_data[index];

        return *this;
    }

    void IntegerArray::insertBefore(int value, int index)
    {
        if (index < 0 && index > m_length)
        {
            throw bad_range();
        };
        

        int* data{ new int[m_length + 1] };// First create a new array one element larger than the old array

        for (int before{ 0 }; before < index; ++before) // Copy all of the elements up to the index
            data[before] = m_data[before];

        data[index] = value;// Insert our new element into the new array

        for (int after{ index }; after < m_length; ++after)// Copy all of the values after the inserted element
            data[after + 1] = m_data[after];

        delete[] m_data;// Finally, delete the old array, and use the new array instead
        m_data = data;
        ++m_length;
    }

    void IntegerArray::remove(int index)
    {
        if (index < 0 && index > m_length)
        {
            throw bad_range();
        };
        
        if (m_length == 1)// If we're removing the last element in the array, we can just erase the array and return early
        {
            erase();
            return;
        }

        int* data{ new int[m_length - 1] };// First create a new array one element smaller than the old array


        for (int before{ 0 }; before < index; ++before)// Copy all of the elements up to the index
            data[before] = m_data[before];

        for (int after{ index + 1 }; after < m_length; ++after)// Copy all of the values after the removed element
            data[after - 1] = m_data[after];

        delete[] m_data;// Finally, delete the old array, and use the new array instead
        m_data = data;
        --m_length;
    }

    void IntegerArray::insertAtBeginning(int value) { insertBefore(value, 0); }// A couple of additional functions just for convenience
    void IntegerArray::insertAtEnd(int value) { insertBefore(value, m_length); }

    int IntegerArray::getLength() const { return m_length; }
