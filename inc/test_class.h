#pragma ocne

#include <iostream>
#include <string>

class Test_class
{
public:
    int m_int;
    float m_float;
    char m_char;
    void show();
};

void Test_class::show()
{
    printf("show\n");
}