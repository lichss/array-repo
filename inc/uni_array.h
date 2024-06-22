/*uni_array.h*/

#pragma once
#include <iostream>
#include <string>

template <class T1>
class Uni_array
{

public:
    T1*  m_ptr;
    unsigned int m_Capacity;

    Uni_array(int );
    ~Uni_array();
    void show(int);
};

template <class T1>
Uni_array<T1>::Uni_array(int n)
{
    m_Capacity = n;
    m_ptr =  new T1[n]();
}

template <class T1>
Uni_array<T1>::~Uni_array()
{

}
template <class T1>
void Uni_array<T1>::show(int n)
{
    for(int i=0;i<n;i++)
        std::cout << m_ptr[i]<<std::endl;
}


#include "uni_array.cpp"
#define UNI_ARRAY_CPP__
