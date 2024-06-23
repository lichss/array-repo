#include <iostream>
#include <string>

#include "uni_array.h"

int main()
{
    Uni_array<int> a1(5);
    a1.show(5);
    a1[2]+=1;
    printf("\n%d\n",a1.[2]);
    return 0;
}

