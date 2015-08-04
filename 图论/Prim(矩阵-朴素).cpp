void Prim(int s)
{
    int x = s;
    for(int i = 0; i < n; i++){
        mincost[i] = INF;//mincost[x]为到x的最短距离
        vis[i] = false;
    }
    vis[s] = 1;
    while(1){
        //更新mincost
        for(int i = 0; i < n; i++){
            if(G[s][i] < mincost[i])
                mincost[i] = G[s][i];
        }

        //找下一步
        s = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (s == -1 || mincost[s] > mincost[i]))
                s = i;
        }

        if(s == -1) break;
        ans += mincost[s];
        vis[s] = 1;
    }

}



/*
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int INF = 101;
const int MAXN = 100;

int n, m, w, ans;
int G[MAXN][MAXN];
bool vis[MAXN];
int mincost[MAXN];

void Prim(int s)
{
    int x = s;
    for(int i = 0; i < n; i++){
        mincost[i] = INF;
        vis[i] = false;
    }
    vis[s] = 1;
    while(1){
        //更新mincost
        for(int i = 0; i < n; i++){
            if(G[s][i] < mincost[i])
                mincost[i] = G[s][i];
        }

        //找下一步
        s = -1;
        for(int i = 0; i < n; i++){
            if(!vis[i] && (s == -1 || mincost[s] > mincost[i]))
                s = i;
        }

        if(s == -1) break;
        ans += mincost[s];
        vis[s] = 1;
    }

}

int main()
{
    while(~scanf("%d%d", &n, &m)){
        int u, v;
        ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                G[i][j] = INF;
            }
        }
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            G[u][v] = G[v][u] = w;
        }


        Prim(0);


        printf("%d\n", ans);
    }

    return 0;
}




/*

7 9
0 1 1
1 2 2
1 3 3
1 5 7
2 4 10
3 5 1
3 6 5
4 5 5
5 6 8

*/
*/
