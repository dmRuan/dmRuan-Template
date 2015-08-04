#include<iostream>
#include<vector>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 1000;
int n, m;

/*��ʼ��*/
vector<int> g[N];//�ڽӱ�洢��
vector<int> que[N];//�洢��ѯ
int root;//����
int indeg[N];//�������������
void inputtree()//���Ĵ洢
{
    cin>>n;
    //��ʼ��
    for(int i = 0; i < n; i++)
    {
        g[i].clear();
        indeg[i] = 0;
    }
    //��������ߴ洢��
    for(int i = 0; i < n-1; i++)
    {
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        indeg[y]++;
    }
    //���
    for(int i = 0; i < n; i++)
        if(!indeg[i])   {root = i; break;}
}
void inputque()//����ѯ��
{
    //��ʼ��
    for(int i = 0; i < n; i++)
        que[i].clear();
    cin>>m;
    //��������
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin>>u>>v;
        que[u].push_back(v);
        que[v].push_back(u);
    }
}

/*���鼯*/
int fa[N];
void initset()//��ʼ������
{
    for(int i = 0; i < n; i++)
        fa[i] = i;
}
int findx(int x)
{
    if(fa[x] == x)  return x;
    return fa[x] = findx(fa[x]);
}
void unionx(int nx, int ny)//�ϲ�����
{
    int x = findx(nx);
    int y = findx(ny);
    if(x != y)  fa[y] = x;
}

/*Tarjan*/
bool vis[N];//�ý���Ƿ���ʹ�
int ancestor[N];//�ѷ��ʽڵ㼯�ϵ�����
void Tarjan(int x)
{
    for(int i = 0; i < g[x].size(); i++)
    {
        Tarjan(g[x][i]);//�������
        unionx(x, g[x][i]);//��������ڵ�ϲ�
        ancestor[findx(x)] = x;//�ϲ��󼯺ϵ�����
    }
    vis[x] = 1;
    for(int i = 0; i < que[x].size(); i++)
        if(vis[que[x][i]])
            printf("%d��%d��LCAΪ:%d\n", x, que[x][i],
                   ancestor[findx(que[x][i])]);
}

int main()
{
    //����
    inputtree();
    inputque();
    //��ʼ��
    initset();
    for(int i = 0; i < n; i++)  ancestor[i] = i;
    memset(vis, 0, sizeof(vis));
    //���
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
