#include <iostream>
#include "IntegerArray.h"
#include <exception>



int main()
{
    setlocale(LC_ALL, "");

    try
    {
        IntegerArray array(-1);



        for (int i{ 0 }; i < 10; ++i)
            array[i] = i + 1;


        // Resize the array to 8 elements
        array.resize(8);

        // Insert the number 20 before element with index 5
        array.insertBefore(20, 5);

        // Remove the element with index 3
        array.remove(3);

        // Add 30 and 40 to the end and beginning
        array.insertAtEnd(30);
        array.insertAtBeginning(40);

        // A few more tests to ensure copy constructing / assigning arrays
        // doesn't break things
        {
            IntegerArray b{ array };
            b = array;
            b = b;
            array = array;
        }

        // Print out all the numbers
        for (int i{ 0 }; i < array.getLength(); ++i)
            std::cout << array[i] << ' ';

        std::cout << '\n';
    }
    catch (exception& e)
    {
        cout << "Exception: " << e.what() << endl;
    }
      
    return 0;
}

