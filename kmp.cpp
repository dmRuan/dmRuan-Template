int len;
int ans[1000005], num;
char patt[100005], text[1000005];
int nex[1000005];

void getnex()
{
    nex[0] = -1;
    int i = 0, j = -1;
    while(patt[i])
    {
        if(j == -1 || patt[i] == patt[j])
        {
            i++, j++;
            nex[i] = j;
        }
        else    j = nex[j];
    }
}
void kmp()
{
    int i = 0, j = 0;
    while(text[i])
    {
        if(j == -1 || text[i] == patt[j])
        {
            i++, j++;
  //          if(j == len)    ans[num++] = i-len+1;
        }
        else    j = nex[j];
    }
}
