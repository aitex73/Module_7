#pragma once
using namespace std;


class IntegerArray
{
private:
    int m_length{};
    int* m_data{};

public:
    IntegerArray() = default;

    IntegerArray(int length);
      

    IntegerArray(const IntegerArray& a);


    ~IntegerArray();
 
    void erase();

    int& operator[](int index);
    
    void reallocate(int newLength);

    void resize(int newLength);
    

    IntegerArray& operator=(const IntegerArray& a);
   

    void insertBefore(int value, int index);
 

    void remove(int index);
   
    
    void insertAtBeginning(int value);
    void insertAtEnd(int value);

    int getLength() const;
};

