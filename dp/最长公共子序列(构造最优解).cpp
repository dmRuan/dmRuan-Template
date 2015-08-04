/*
 *��������е�i��j�����ַ�����
 *�����ַ����鶼Ҫ-1
 */
#include <iostream>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAXN = 100 + 5;

char s1[100], s2[100];
int p[MAXN][MAXN];//1��б�ߣ�2�����ߣ�3������
int dp[MAXN][MAXN];
stack<char> ans;

int printp();

int main()
{
    while(1) {
        scanf("%s%s", s1, s2);
        int l1 = strlen(s1), l2 = strlen(s2);
        for(int i = 0; i <= l1; i++) {
            dp[i][0] = 0;
        }
        for(int i = 0; i <= l2; i++) {
            dp[0][i] = 0;
        }

        //��̬�滮����
        for(int i = 1; i <= l1; i++) {
            for(int j = 1; j <= l2; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                    p[i][j] = 1;
                }
                else if(dp[i][j-1] >= dp[i-1][j]){
                    dp[i][j] = dp[i][j-1];
                    p[i][j] = 2;
                }
                else if(dp[i][j-1] <= dp[i-1][j]){
                    dp[i][j] = dp[i-1][j];
                    p[i][j] = 3;
                }
            }
        }

        //������󹫹�������
        int i, j;
        i = l1, j = l2;
        while(dp[i][j]) {
            if(p[i][j] == 1) {
                ans.push(s1[i-1]);
                i--, j--;
            }
            else if(p[i][j] == 2) j--;
            else if(p[i][j] == 3) i--;
        }

        //������
        while(!ans.empty()) {
            char x = ans.top(); ans.pop();
            printf("%c ", x);
        }
        printf("\n");
    }


    return 0;
}


/*

abcbdab
bdcaba

*/
