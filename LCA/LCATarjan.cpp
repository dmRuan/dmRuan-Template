#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1000;
int n, m;

/*初始化*/
vector<int> g[N];//邻接表存储树
vector<int> que[N];//存储查询
int root;//树根
int indeg[N];//入度用于求树根
void inputtree()//树的存储
{
    cin>>n;
    //初始化
    for(int i = 0; i < n; i++)
    {
        g[i].clear();
        indeg[i] = 0;
    }
    //根据有向边存储树
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        indeg[y]++;
    }
    //求根
    for(int i = 0; i < n; i++)
        if(!indeg[i])   {root = i; break;}
}
void inputque()//输入询问
{
    //初始化
    for(int i = 0; i < n; i++)
        que[i].clear();
    cin>>m;
    //保存问题
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        que[u].push_back(v);
        que[v].push_back(u);
    }
}

/*并查集*/
int fa[N];
void initset()//初始化集合
{
    for(int i = 0; i < n; i++)
        fa[i] = i;
}
int findx(int x)
{
    if(fa[x] == x)  return x;
    return fa[x] = findx(fa[x]);
}
void unionx(int nx, int ny)//合并集合
{
    int x = findx(nx);
    int y = findx(ny);
    if(x != y)  fa[y] = x;
}

/*Tarjan*/
bool vis[N];//该结点是否访问过
int ancestor[N];//已访问节点集合的祖先
void Tarjan(int x)
{
    for(int i = 0; i < g[x].size(); i++)
    {
        Tarjan(g[x][i]);//后序遍历
        unionx(x, g[x][i]);//子树与根节点合并
        ancestor[findx(x)] = x;//合并后集合的祖先
    }
    vis[x] = 1;
    for(int i = 0; i < que[x].size(); i++)
        if(vis[que[x][i]])
            printf("%d与%d的LCA为:%d\n", x, que[x][i],
                   ancestor[findx(que[x][i])]);
}

int main()
{
    //输入
    inputtree();
    inputque();
    //初始化
    initset();
    for(int i = 0; i < n; i++)  ancestor[i] = i;
    memset(vis, 0, sizeof(vis));
    //求答案
    Tarjan(root);

    return 0;
}



/*
8
0 1
0 2
0 3
1 4
1 5
5 7
3 6


*/
