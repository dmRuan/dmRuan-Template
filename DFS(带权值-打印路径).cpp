/*
 *输入：n(行数), m(列数), p(体力)
 *输出：存在路径的话打印路径；不存在路径的话输出“Can not escape!”
 *样例输入：
4 4 10
1 0 0 1
1 1 0 1
0 1 1 1
0 0 1 1
 *样例输出：
[0,0],[1,0],[1,1],[2,1],[2,2],[2,3],[1,3],[0,3]
 */
#include <bits/stdc++.h>

using namespace std;

#define N 15

int n, m, p, stp;
int path[N][N];
int c[N][N];
bool vis[N][N];
int mov[4][3] = {{-1,0,3}, {1,0,0}, {0,-1,1}, {0,1,1}};

void output() {
    for(int i = 0; i < stp-1; i++) {
        printf("[%d,%d],", path[i][0], path[i][1]);
    }
    printf("[%d,%d]\n", 0, m-1);
}

bool isOK(int x, int y) {
    return x >= 0 && x < n
            && y >= 0 && y < m
            && c[x][y] == 1
            && vis[x][y] == 0;
}

bool dfs(int x, int y, int p) {
    if( p >= 0 && x == 0 && y == m-1 ) {//reach the destination
        return 1;

    } else if( p < 0 )  return 0;//weight is not enough

    for(int i = 0; i < 4; i++) {
        int xx = x + mov[i][0];
        int yy = y + mov[i][1];
        int pp = p - mov[i][2];//consume weight

        if( isOK(xx, yy) ) {
            vis[xx][yy] = 1;
            path[stp][0] = xx;//save the path
            path[stp++][1] = yy;
            if( dfs(xx, yy, pp) )
                return 1;
            vis[xx][yy] = 0;
            stp--;
        }
    }

    return 0;
}

int main()
{
#ifdef dmRuan
    freopen("in.txt", "r", stdin);
#endif // dmRuan
    while( ~scanf("%d%d%d", &n, &m, &p) ) {
        memset(vis, 0, sizeof(vis));

        //input
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cin >> c[i][j];
            }
        }

        //solve and output
        vis[0][0] = 1;
        path[0][0] = path[0][1] = 0;
        stp = 1;
        if( dfs(0, 0, p) ) {
            output();

        } else  cout << "Can not escape!" << endl;

    }

    return 0;
}
