/*uni_array.h*/

#pragma once
#include <iostream>
#include <string>

template <class T>
class Uni_array
{

public:
    T*  m_ptr;
    unsigned int m_Capacity;
    // unsigned int ; 
    Uni_array(int );
    ~Uni_array();
    void show(int);
    T& operator[] (int index);

private:
    T& visit(int index);


};

template <class T>
Uni_array<T>::Uni_array(int n)
{
    m_Capacity = n;
    m_ptr =  new T[n]();/*分配堆空间并赋初值为0；*/
}

template <class T>
Uni_array<T>::~Uni_array()
{
    delete[] this->m_ptr;
}
template <class T>
void Uni_array<T>::show(int n)
{
    for(int i=0;i<n;i++)
        std::cout << m_ptr[i]<<std::endl;
}


template <class T>
T& Uni_array<T>::visit(int index)
{
    return m_ptr[index];
}

template <class T>
T& Uni_array<T>::operator[] (int index)
{
    return m_ptr[index];
}

#define UNI_ARRAY_CPP__
