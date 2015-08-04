/*��������*/
/*
 *�������ҵ����ݼ�
 *���ֶ��г���Ϊk-1
 */
void solve()
{
    int s = 0, t = 0;//��β�±�
    for(int i = 0; i < n; i++) {
        while(s < t && arr[i] >= arr[que[t-1]]) t--;//ά�����е�����
        que[t++] = i;
        if(i - k + 1 >= 0) {//ά�����г���Ϊk
            //ans[i - k + 1] = arr[que[s]];
            if(que[s] == i - k + 1)
                s++;
        }
    }
}













/*
//poj2823-Sliding Window
#include <iostream>
#include <cstdio>
using namespace std;
const int MAXN = 1000000 + 5;

int n, k, m;
int arr[MAXN], ans[MAXN];
int que[MAXN];

void solve()
{
    int s = 0, t = 0;
    for(int i = 0; i < n; i++) {
        while(s < t && arr[i] >= arr[que[t-1]]) t--;
        que[t++] = i;
        if(i - k + 1 >= 0) {
            ans[i - k + 1] = arr[que[s]];
            if(que[s] == i - k + 1)
                s++;
        }
    }
}

void solve1()
{
    int s = 0, t = 0;
    for(int i = 0; i < n; i++) {
        while(s < t && arr[i] <= arr[que[t-1]]) t--;
        que[t++] = i;
        if(i - k + 1 >= 0) {
            ans[i - k + 1] = arr[que[s]];
            if(que[s] == i - k + 1)
                s++;
        }
    }
}

int main()
{
    while(~scanf("%d %d", &n, &k)) {
        m = n-k+1;
        for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

        solve1();
        for(int i = 0; i < m; i++) printf("%d ", ans[i]);
        printf("\n");

        solve();
        for(int i = 0; i < m; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}


/*

5 3
1 3 5 4 2

8 3
1 3 -1 -3 5 3 6 7

*/
