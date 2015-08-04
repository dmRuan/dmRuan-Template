/*注意极角排序的初始化*/
struct P{ int x, y; };
P p[MAXN];
int n;

int dis(P a, P b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int cross(P a, P b, P c)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool cmp(P a, P b)
{
    int x = cross(a, b, p[0]);
    if(x > 0 || (x == 0 && dis(a, p[0]) < dis(b, p[0]))) return 1;
    return 0;
}

vector<P> Graham()
{
    vector<P> stk(n);//存凸包
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 1 && (cross(p[i], stk[k-2], stk[k-1])) <= 0)//
            k--;
        stk[k++] = p[i];
    }
    stk.resize(k);//调整正确的凸包顶点数
    return stk;
}



/*
 *极角排序+Graham Scan：1.可以解决共线和点数为2的情况
 *                      2.极角排序中cross(a, b, c),是以向量(c, a)为开始边，逆时针走到向量(b, c)的角的sin，故正数表示角小于180度，负数表示角大于180度
 *
 */
 /*
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MAXN = 50000 + 5;

struct P{ int x, y; };
P p[MAXN];
int n;

int dis(P a, P b)
{
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int cross(P a, P b, P c)
{
    return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

bool cmp(P a, P b)
{
    int x = cross(a, b, p[0]);
    if(x > 0 || (x == 0 && dis(a, p[0]) < dis(b, p[0]))) return 1;
    return 0;
}

vector<P> Graham()
{
    vector<P> stk(n);//存凸包
    int k = 0;
    for (int i = 0; i < n; i++) {
        while (k > 1 && (cross(p[i], stk[k-2], stk[k-1])) <= 0)//
            k--;
        stk[k++] = p[i];
    }
    stk.resize(k);//调整正确的凸包顶点数
    return stk;
}

int main()
{
    while (~scanf("%d", &n)) {
        int ans = 0, rp = 0;//rp用于临时保存最左下点的下标
        //输入
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &p[i].x, &p[i].y);
            if(p[rp].y > p[i].y
               || (p[rp].y == p[i].y && p[rp].x > p[i].x))//找最左下的点
               rp = i;
        }

        //极角排序
        swap(p[rp], p[0]);//初始化，方便cmp过程
        sort(p + 1, p + n, cmp);

        //Graham Scan构成凸包
        vector<P> stk = Graham();

        //暴力求解
        for (int i = 0; i < stk.size(); i++) {
            for (int j = 0; j < i; j++)
                ans = max(ans, dis(stk[i], stk[j]));
        }

        cout<<ans<<endl;
    }

    return 0;
}

/*
8
0 5
1 8
3 4
5 0
6 2
6 6
8 3
8 7

4
0 0
0 1
1 1
1 0


4
-1 0
0 0
4 0
9 0

5
1 0
0 1
1 3
1 2
1 1

2
1 0
0 1


*/
*/
