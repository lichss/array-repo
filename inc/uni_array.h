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
    void show();
    T& operator[] (int index);
    Uni_array& operator= (Uni_array&);
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
    if(this->m_ptr != nullptr){
        printf("delete member ptr:%X\n",this->m_ptr);
        delete[] this->m_ptr;
        this->m_ptr = nullptr;
    }
    else{
        printf("Warning: a nullptr\n");
    }
}
template <class T>
void Uni_array<T>::show()       /*如果想实现比较好的show效果应该要 模板特化 */
{
    for(int i=0;i<this->m_Capacity;i++)
        std::cout << m_ptr[i] << std::endl;
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
Uni_array<T>& Uni_array<T>::operator= (Uni_array& uarr)     /*总感觉有点安全隐患。引用传进来没加const限制。万一不注意改了点可能导致bug*/
{
    this->m_Capacity = uarr.m_Capacity;
    m_ptr =  new T[uarr.m_Capacity]();        /*深拷贝 申请另一块堆区内存*/
    for(int i=0;i<uarr.m_Capacity;i++)
    {
        m_ptr[i] = uarr[i];         /*mptr是指针。没有运算符重载。uarr是类引用。发生运算符重载*/
    }
    printf("拷贝完辣！\n");

    return *this;
}
