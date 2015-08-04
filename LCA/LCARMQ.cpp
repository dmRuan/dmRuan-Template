//λ�ô�0��ʼ
#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
#include<cstring>
using namespace std;

const int N = 8;
vector<int> g[N];


/*������*/
int root;//����
int indeg[N];//�������
void input()
{
    for(int i = 0; i < N-1; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        indeg[v]++;
    }
    for(int i = 0; i < N; i++)
        if(!indeg[i])   {root = i;break;}
}

/*DFS*/
int f[2*N+1];//ŷ������
int depth[2*N+1];//x���������
int cnt;//��ʼ��Ϊ0
int pos[N];//x��һ�γ��ֵ�λ��,��ʼ��Ϊ-1
void dfs(int x, int d)
{
    pos[x] = cnt;
    depth[cnt] = d;
    f[cnt++] = x;
    for(int i = 0; i < g[x].size(); i++)
    {

        dfs(g[x][i], d+1);
        depth[cnt] = d;//�Է�֧���Ĵ���
        f[cnt++] = x;
    }
}

/*RMQ*/
int dp[N][N];//��Сֵ��Ӧ���±�
void init_RMQ()
{
    for(int i = 0; i < N; i++)
        dp[i][0] = i;//�Լ����Լ�����Сֵ�±�Ϊ�Լ�
}
void RMQ()
{
    init_RMQ();
    for(int j = 1; j < 20; j++)
        for(int i = 0; i < N; i++)
            if(i+(1<<j)-1 < N)
                dp[i][j] = depth[dp[i][j-1]] < depth[dp[i+(1<<(j-1))][j-1]] ? dp[i][j-1] : dp[i+(1<<(j-1))][j-1];
}
int ask(int l, int r)
{
    if(l > r)   swap(l, r);
    int k = log(r-l+1.0)/log(2.0);
    return depth[dp[l][k]] < depth[dp[r-(1<<k)+1][k]] ? dp[l][k] : dp[r-(1<<k)+1][k];
}

/*��ʼ������*/
void init()
{
    memset(pos, -1, sizeof(pos));
    memset(f, -1, sizeof(f));
    root = 0;
    cnt = 0;
    for(int i = 0; i < N; i++)
    {
        g[i].clear();
        indeg[i] = 0;
    }
}

int main()
{
    init();
    input();

    dfs(root, 0);

    RMQ();

    while(1)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        cout<<f[ask(pos[l]+1, pos[r]-1)]<<endl;
    }
//    cout<<'f'<<':'<<endl;
//    for(int i = 0; i < 2*N-1; i++)
//        cout<<f[i]<<' ';
//    cout<<endl;
//
//    cout<<"depth"<<':'<<endl;
//    for(int i = 0; i < 2*N-1; i++)
//        cout<<depth[i]<<' ';
//    cout<<endl;
//
//    cout<<"pos"<<':'<<endl;
//    for(int i = 0; i < N; i++)
//        cout<<pos[i]<<' ';
//    cout<<endl;
//
//    cout<<endl;


    return 0;
}



/*
0 1
0 2
0 3
1 4
1 5
5 6
5 7
*/
