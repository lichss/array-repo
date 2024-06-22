/*uni_array.cpp*/
#ifndef UNI_ARRAY_CPP__
#define UNI_ARRAY_CPP__

/*
uni_array<class T1>::
*/
template <class T1>
class Uni_array<T1>;

template <class T1>
Uni_array<T1>::Uni_array(int n)
{
    m_Capacity = n;
    T1 a;
}

template <class T1>
Uni_array<T1>::~Uni_array()
{

}
template <class T1>
void Uni_array<T1>::step(int n)
{

}
#endif