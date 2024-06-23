#include <iostream>
#include <string>

#include "uni_array.h"
#define XNEWL__ printf("\n")

int main()
{
    {
        Uni_array<int> a1(5);
        a1.show(5);
        a1[2]+=1;
        printf("\n%d\n",a1[2]);

        XNEWL__;
        Uni_array a2(a1);
        a2.show(5);
        a2[1] = 2;

        a1 = a2;
        a1.show(5);
    }
        XNEWL__;
    // {
    //     Uni_array<float> a1(6);
    //     a1.show(6);
    //     a1[3]+=1;
    //     printf("\n%f\n",a1[3]);
    // }

    return 0;
}

