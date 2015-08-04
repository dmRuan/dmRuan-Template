#include<cstdio>
#include<cstring>
#include<algorithm>

void Dijkstra(int s, int e)//开始结点s, 终止结点
{
    int u = s;
    D[s] = 0; vis[s] = 1;
    memset(vis, 0, sizeof(vis));
    for(int i = 1; i < n; i++)  D[i] = INF;
    while( u != e ) {
        //更新相邻结点D
        for(int i = 0; i < n; i++){
            if(!vis[i]) D[i] = min(D[i], D[u]+G[u][i]);
        }
        //找下一步
        u = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (u == -1 || D[u] > D[i])) u = i;
        }
        if(u == -1) break;//若无更新，则更新完所有起点所能到达结点的最短距离
        vis[u] = 1;
    }
}



/*

#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 100;
const int MAXN = 100 + 5;

int n, m;
int maze[MAXN][MAXN];
bool vis[MAXN];
int dp[MAXN];

void Dijkstra(int s)
{
    memset(vis, 0, sizeof(vis));
    dp[s] = 0;
    vis[s] = 1;
    for(int i = 1; i < n; i++)
        dp[i] = INF;
    int u = s;
    while(1){
        //更新相邻结点dp
        for(int i = 0; i < n; i++){
            if(!vis[i]) dp[i] = min(dp[i], dp[u]+maze[u][i]);
        }


        //找下一步
        u = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (u == -1 || dp[u] > dp[i])) u = i;
        }

        if(u == -1) break;
        vis[u] = 1;

    }
}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        int x, y, w;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                maze[i][j] = INF;


        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &x, &y, &w);
            maze[x][y] = maze[y][x] = w;
        }



        Dijkstra(0);


        for(int i = 0; i < n; i++)
            printf("%d ", dp[i]);
        printf("\n");
    }

    return 0;
}


/*

7 10
0 1 2
0 2 5
1 2 4
1 3 6
1 4 10
2 3 2
3 5 1
4 5 3
4 6 5
5 6 9

*/


*/
