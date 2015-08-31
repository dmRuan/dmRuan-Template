/*极角排序
 *1.找出最下左点rp（点输入过程中找）
 *2.sort重写的cmp（注意不排第rp，以rp为基础点ba）
 */

//找最下左点
if( isg(P[rp].y, P[i].y)
  || (ise(P[rp].y, P[i].y) && isg(P[rp].x, P[i].x)) )
rp = i;

//重写的cmp，ba是排序的比较点
bool cmp(Point a, Point b) {
    double pa = sgn(cross(a, b, P[ba]));
    if( pa == 0 )   return isg(dist(b, P[0]), dist(a, P[0]));//调节同一极角的点,距离近的优先
    else            return pa > 0;//逆时针排序
}



/*poj 1696-Space Ant
 *题意：求给定点的螺旋（逆时针）序列
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
        ba = 0;//基准点
        swap(P[0], P[rp]);
        for(int i = 1; i < n; i++) {//求逆螺旋序列
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
