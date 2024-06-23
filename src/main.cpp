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

        printf("二阶段测试通过\n");

    }
    
    
    
    {
        using namespace std;

        Uni_array<float> a1(5);
        a1[0]+=1;
        a1[1]+=1;
        a1[2]+=1;
        a1[3]+=1;
        a1[4]+=1;
        a1.append_n(3);
        printf("now capacity become:%d \n",a1.m_Capacity);
        

        a1[5]+=5;
        a1[6]+=6;
        a1[7]+=7;

        pNEWL__;a1.show();

    }

    {
        Uni_array<int> a(5);
        a[0]+=1;
        a[1]+=1;
        a[2]+=1;
        a[3]+=0;
        a[4]+=0;

        a.delete_n(2);
        std::cout << "now capacity:"<<a.m_Capacity;pNEWL__;
    }

    if(0)   /*这段代码的输出结果表示 m_ptr+1会按输入类型<T>的size递增*/
    {
        Uni_array<int> a1(5);
        std::cout<< "size of Uni_array<int>:" << sizeof(Uni_array<int>);pNEWL__;
        std::cout<< "a1.mptr:"<<a1.m_ptr;pNEWL__;
        std::cout<< "a1.mptr+1:"<<a1.m_ptr+1;pNEWL__;
        std::cout<< "a1.mptr+2:"<<a1.m_ptr+2;pNEWL__;
        std::cout<< "a1.mptr+3:"<<a1.m_ptr+3;pNEWL__;

        /*      输出结果
    
        size of Uni_array<int>:16
        a1.mptr:0xc14460
        a1.mptr+1:0xc14464
        a1.mptr+2:0xc14468
        a1.mptr+3:0xc1446c
    
        */

    }

    return 0;
}

