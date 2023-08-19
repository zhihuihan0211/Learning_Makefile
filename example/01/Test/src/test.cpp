#include "../include/test.h"
#include <time.h>
#include <iostream>

using namespace std;
//
//
void test_case1()
{


    time_t begin, end;
    time(&begin);

    time(&end);


    cout << end - begin << endl;
}