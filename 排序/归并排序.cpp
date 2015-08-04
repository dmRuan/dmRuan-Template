/*
 *1.注意ans[]必须初始化为输入的序列
 */
void mergex(int l, int m, int r)
{
    int cnt = 0;
    int t[r-l+1];
    for(int i = l, j = m+1; i <= m || j <= r; cnt++) {
        /*由小到大*/if(j > r || (i <= m && a[i] <= a[j]))   t[cnt] = a[i++];
        /*由大到小*///if(j > r || (i <= m && a[i] >= a[j]))   t[cnt] = a[i++];
        else                                    t[cnt] = a[j++];
    }
    for(int i = l; i <= r; i++) a[i] = t[i-l];
}

void merge_sort(int l, int r)
{
    if(l < r) {
        int m = (l+r)/2;
        merge_sort(l, m);
        merge_sort(m+1, r);
        mergex(l, m, r);
    }
}



/*
//poj-2299-归并排序求逆序数
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 500000 + 5;

int n;
__int64 a[MAXN], t[MAXN];
__int64 ans;

void merger(int l, int m, int r)
{
    int cnt = l;
    for(int i = l, j = m+1; i <= m || j <= r; cnt++) {
        if(j > r || (i <= m && a[i] <= a[j]))   t[cnt] = a[i++];
        else                                    { t[cnt] = a[j++]; ans += m-i+1; }/*
    }
    for(int i = l; i <= r; i++) a[i] = t[i];
}

void division(int l, int r)
{
    if(l < r) {
        int m = l + (r-l)/2;
        division(l, m);
        division(m+1, r);
        merger(l, m, r);
    }
}

int main()
{
    while(~scanf("%d", &n) && n) {
        ans = 0;
        for(int i = 0; i < n; i++)  cin>> a[i];
        division(0, n-1);
        cout<< ans<< endl;
    }
    return 0;
}


/*

5
9 1 0 5 4
3
1 2 3
0

*/



