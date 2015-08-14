/*��������
 *1.�ҳ��������rp��������������ң�
 *2.sort��д��cmp��ע�ⲻ�ŵ�rp����rpΪ������ba��
 */

//���������
if( sgn(P[rp].y - P[i].y) > 0
  || (sgn(P[rp].y - P[i].y == 0)) && sgn(P[rp].x- P[i].x > 0) )
rp = i;

//��д��cmp��ba������ıȽϵ�
bool cmp(Point a, Point b)
{
    double pa = sgn(cross(a, b, P[ba]));
    if( pa == 0 )
        return dis(a,P[ba]) < dis(b,P[ba]);//����ͬһ���ǵĵ�
    else return pa > 0;//��ʱ������
}



/*poj 1696-Space Ant
 *���⣺����������������ʱ�룩����
 */
/*
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

const int MAXN = 50 + 5;
const double eps = 1e-8;
const int INF = 1<<22;

int n;
int rp, ba;
bool vis[MAXN];
struct Point {
    int idx;
    double x, y;
    Point() {}
    void input() {
        scanf("%d %lf %lf", &idx, &x, &y);
    }
    Point (double _x, double _y) {
        x = _x; y = _y;
    }
    Point(int _idx, double _x, double _y) {
        idx = _idx; x = _x; y = _y;
    }
    Point operator -(const Point &b) const {
        return Point(x-b.x, y-b.y);
    }
    double operator *(const Point &b) const {
        return x*b.x + y*b.y;
    }
    double operator ^(const Point &b) const {
        return x*b.y - y*b.x;
    }
}P[MAXN];

int sgn(double x)
{
    return (x>eps) - (x<-eps);
}
double dis(Point a, Point b)
{
    return sqrt((a-b) * (a-b));
}
double cross(Point a, Point b, Point o)
{
    return (a-o) ^ (b-o);
}
bool cmp(Point a, Point b)
{
    double pa = sgn(cross(a, b, P[ba]));
    if( pa == 0 )
        return dis(a,P[ba]) < dis(b,P[ba]);
    else return pa > 0;
}

int main()
{
#ifdef dmRuan
    freopen("in.txt", "r", stdin);
#endif // dmRuan
    int T;
    scanf("%d", &T);
    while( T-- ) {
        //initialization
        rp = 0;
        memset(vis, 0, sizeof(vis));
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            P[i].input();
            if( sgn(P[rp].y - P[i].y) > 0
               || (sgn(P[rp].y - P[i].y == 0)) && sgn(P[rp].x- P[i].x > 0) )
                rp = i;
        }

        //solve
        ba = 0;//��׼��
        swap(P[0], P[rp]);
        for(int i = 1; i < n; i++) {//������������
            sort(P+i, P+n, cmp);
            ba++;
        }

        //output
        printf("%d", n);
        for(int i = 0; i < n; i++)  printf(" %d", P[i].idx);
        printf("\n");
    }

    return 0;
}

*/
