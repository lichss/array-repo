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
    Uni_array(class Uni_array<T> & n);

    ~Uni_array();
    void show(int);
    T& operator[] (int index);
    void operator= (Uni_array&);
private:
    T& visit(int index);


};

template <class T>
Uni_array<T>::Uni_array(int n)
{
    m_Capacity = n;
    m_ptr =  new T[n]();        /*分配堆空间并赋初值为0；*/
}

template <class T>
Uni_array<T>::Uni_array(Uni_array & uarr)    /**/
{
    this->m_Capacity = uarr.m_Capacity;
    m_ptr =  new T[uarr.m_Capacity]();        /*深拷贝 申请另一块堆区内存*/
    for(int i=0;i<uarr.m_Capacity;i++)
    {
        m_ptr[i] = uarr[i];         /*mptr是指针。没有运算符重载。uarr是类引用。发生运算符重载*/
    }
    printf("拷贝完辣！\n");
}

template <class T>
Uni_array<T>::~Uni_array()
{
    if(this->m_ptr != nullptr)
        delete[] this->m_ptr;
    this->m_ptr = nullptr;
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

template <class T>
void Uni_array<T>::operator= (Uni_array& uarr)
{
    this->m_Capacity = uarr.m_Capacity;
    m_ptr =  new T[uarr.m_Capacity]();        /*深拷贝 申请另一块堆区内存*/
    for(int i=0;i<uarr.m_Capacity;i++)
    {
        m_ptr[i] = uarr[i];         /*mptr是指针。没有运算符重载。uarr是类引用。发生运算符重载*/
    }
    printf("拷贝完辣！\n");

    //return *this;
}
