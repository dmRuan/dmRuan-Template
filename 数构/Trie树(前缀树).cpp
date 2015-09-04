struct Node { //不封装成类，由于部分系统在类内不可开过大的数组
    int cnt;//统计前缀个数
    int nx[MAXA];//下一个字母的id
    void init() {//初始化
        cnt = 0;
        memset(nx, 0, sizeof(nx));
    }
}tri[MAXN];

void  inserts(char *s) {
    int c;
    int nu = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        c = s[i] - 'a';
        if( tri[nu].nx[c] == 0 ) {//后面没有该节点
            tri[nn].init();//初始化节点
            tri[nu].nx[c] = nn;//增加字母
            nn++;
        }
        nu = tri[nu].nx[c];
        tri[nu].cnt++;
    }
}
int inquire(char *s) {
    int c;
    int nu = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        c = s[i] - 'a';
        if( tri[nu].nx[c] == 0 ) {
            return 0;
        }
        nu = tri[nu].nx[c];
    }
    return tri[nu].cnt;
}

/*hiho 1014 Trie树
 *输入：给出一堆单词，给出要查询的前缀
 *输出：求以查询为前缀的单词个数
 */
/*
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 1e6 + 5;
const int MAXL = 10 + 5;
const int MAXA = 26 + 5;

int n, m, nn;
char inq[MAXN][MAXL];
struct Node {
    int cnt;
    int nx[MAXA];
    void init() {
        cnt = 0;
        memset(nx, 0, sizeof(nx));
    }
}tri[MAXN];

void  inserts(char *s) {
    int c;
    int nu = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        c = s[i] - 'a';
        if( tri[nu].nx[c] == 0 ) {
            tri[nn].init();
            tri[nu].nx[c] = nn;
            nn++;
        }
        nu = tri[nu].nx[c];
        tri[nu].cnt++;
    }
}
int inquire(char *s) {
    int c;
    int nu = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++) {
        c = s[i] - 'a';
        if( tri[nu].nx[c] == 0 ) {
            return 0;
        }
        nu = tri[nu].nx[c];
    }
    return tri[nu].cnt;
}


int main()
{
freopen("in.txt", "r", stdin);
    while( ~scanf("%d", &n) ) {
        //initialization
        char str[MAXL];
        tri[0].init();
        nn = 1;
        for(int i = 0; i < n; i++) {
            scanf("%s", str);
            inserts(str);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++) {
            scanf("%s", inq[i]);
        }

        //solve & output
        for(int i = 0; i < m; i++) {
            printf("%d\n", inquire(inq[i]));
        }
    }

    return 0;
}
*/
/*test*/
/*
5
babaab
babbbaaaa
abba
aaaaabaa
babaababb
7
a
b
babb
baabaaa
bab
bb
bbabbaab

ans:
2
3
1
0
3
0
0


3
xyz
xyzw
axyzw
3
xy
x
a

ans:
2
2
1
*/
