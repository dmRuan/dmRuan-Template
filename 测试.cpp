/*产生随机数*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

double random()//[0, 1]间的均匀随机数
{
    return (double)rand()/RAND_MAX;
}
int random(int m)//[0, m-1]间的均匀随机数
{
    return (int)(random()*(m-1)+0.5);
}

int main()
{
    srand(time(NULL));//在程序开头调用一次，不要在同一个程序中多次调用
    return 0;
}
