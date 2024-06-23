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

    void append_n(int);
    void delete_n(int);
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

template <class T>  /*尾插 n个*/
void Uni_array<T>::append_n(int extra_n)
{
    unsigned int new_capacity = this->m_Capacity + extra_n;
    T* new_ptr;
    new_ptr = new T[new_capacity]();        /*申请堆区空间 后赋初值为0*/
    for(int i;i<this->m_Capacity;i++){
        new_ptr[i] = this->m_ptr[i];        /*逐个复制之前数组的元素*/
    }

    this->m_Capacity = new_capacity;
    delete[] this->m_ptr;                   /*如果不删除 一定会造成内存泄漏*/
    this->m_ptr = new_ptr;

}

template <class T>
void Uni_array<T>::delete_n(int delete_n)       /*尾删n个*/     /*我突然有个问题。类模板里面能不能有函数模板做成员函数。*/ /*搜了一下 可以*/
{                                                      
    if(!delete_n)
        return;
    int new_capacity = this->m_Capacity - delete_n;
    

    this->m_Capacity = new_capacity;
}


#if 0       /*就放这里 提醒自己吧*/
template <class T>
void Uni_array<T>::delete_n(int delete_n)       /*尾删n个*/     /*我突然有个问题。类模板里面能不能有函数模板做成员函数。*/ /*搜了一下 可以*/
{                                                       /*源赖是new[] 和delete[]必须成对使用。 new[]出来的内存只能整体删除 而不能只删除其中部分*/
    if(!delete_n)
        return;
    int delete_nn = delete_n;
    int new_capacity = m_Capacity - delete_nn;
    T* ptr = this->m_ptr;
    // delete[] ptr;
    int debug=0;
    do{
        delete (ptr+m_Capacity-delete_nn);
        debug++;
        delete_nn--;
    }while(delete_nn!=0);

    this->m_Capacity = new_capacity;
}
#endif