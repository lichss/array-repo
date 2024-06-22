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
    void step(int);
};




#include "uni_array.cpp"

