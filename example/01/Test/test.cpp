#include "test.h"
#include <time.h>
#include <iostream>

using namespace std;

//生成棋盘,10s
void test_case1()
{


    time_t begin, end;
    time(&begin);

    time(&end);


    cout << end - begin << endl;
}