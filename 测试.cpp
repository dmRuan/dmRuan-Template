/*���������*/
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

double random()//[0, 1]��ľ��������
{
    return (double)rand()/RAND_MAX;
}
int random(int m)//[0, m-1]��ľ��������
{
    return (int)(random()*(m-1)+0.5);
}

int main()
{
    srand(time(NULL));//�ڳ���ͷ����һ�Σ���Ҫ��ͬһ�������ж�ε���
    return 0;
}
