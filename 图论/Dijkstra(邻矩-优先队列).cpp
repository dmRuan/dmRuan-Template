/*
 *不需要vis数组
 */
struct edge
{
    int v, w;
    edge(int x, int y) {v = x, w = y;}
};
int n, m;
int dp[MAXN];
typedef pair<int, int> P;
vector<edge> G[MAXN];

void Dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > pq;
    for(int i = 0; i < n; i++){
        dp[i] = INF;
    }

    dp[s] = 0;
    pq.push(P(0, s));
    while( !pq.empty() ) {
        //找下一步
        P nex = pq.top(); pq.pop();
        int t = nex.second;
        if(dp[t] < nex.first) continue;//只要==就是要走的代价最小的下一步

        //更新相邻结点的dp
        for(int i = 0; i < G[t].size(); i++) {
            int v = G[t][i].v, w = G[t][i].w;
            if (dp[v] > dp[t] + w) {
                dp[v] = dp[t] + w;
                pq.push(P(dp[v], v));//每次都是把dp放进去优先队列中
            }
        }
    }
}



/*

#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
const int MAXN = 100 + 5;
const int INF = 1 << 20;


struct edge
{
    int v, w;
    edge(int x, int y) {v = x, w = y;}
};
int n, m;
int dp[MAXN];
typedef pair<int, int> P;
vector<edge> G[MAXN];

void Dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > pq;
    for(int i = 0; i < n; i++){
        dp[i] = INF;
    }

    dp[s] = 0;
    pq.push(P(0, s));
    while(!pq.empty()) {
        //找下一步
        P nex = pq.top(); pq.pop();
        int t = nex.second;
        if(dp[t] < nex.first) continue;

        //更新相邻结点的dp
        for(int i = 0; i < G[t].size(); i++) {
            int v = G[t][i].v, w = G[t][i].w;
            if (dp[v] > dp[t] + w) {
                dp[v] = dp[t] + w;
                pq.push(P(dp[v], v));
            }
        }
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m)) {
        int u, v, w;
        for(int i = 0; i < m; i++){
            scanf("%d%d%d", &u, &v, &w);
            G[u].push_back(edge(v, w));
            G[v].push_back(edge(u, w));
        }

        Dijkstra(0);

        for(int i = 0; i < n; i++)
            cout<<dp[i]<<' ';
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
