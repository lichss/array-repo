#include <iostream>
#include <string>

#include "uni_array.h"
#include "test_class.h"

#define pNEWL__ printf("\n")

int main()
{
    {
        Uni_array<double> a1(5);
        Uni_array<double> a3(5);

        a1.show();
        a1[2]+=1;
        printf("\n%f\n",a1[2]);

        pNEWL__;
        Uni_array a2(a1);
        a2.show();
        a2[1] = 2;

        a3 = a1 = a2;
        a3.show();
        printf("一阶段测试通过\n");
        pNEWL__;
        

    }
    {
        using namespace std;
        Uni_array<Test_class> a1(6);
        a1[0].m_int = 1;
        a1[0].m_float= 2.2;
        a1[0].m_char = '9';

        Uni_array<Test_class> a2(6);
        a2 = a1;
        cout << a2[0].m_int;pNEWL__;
        cout << a2[0].m_float;pNEWL__;
        cout << a2[0].m_char;pNEWL__;


    }
    
    
        pNEWL__;
    // {
    //     Uni_array<float> a1(6);
    //     a1.show(6);
    //     a1[3]+=1;
    //     printf("\n%f\n",a1[3]);
    // }

    return 0;
}

