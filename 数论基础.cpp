

/*���Լ��*/
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b,a%b);
}


/*��С������*/
int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}



/*ŷ������*/
int euler(int x)
{
    int ans = x;
    for(int i = 2; i*i <= x; i++)
    {
        if(x%i == 0)    ans -= ans/i;
        while(x%i == 0) x /= i;
    }
    if(x > 1)   ans -= ans/x;
    return ans;
}
//С��չ��������������������֮��=euler(n)*n/2;
/*ŷ���������*/
int euler[N];
void makeEuler()
{
    euler[1] = 1;
    for(int i = 0; i < N; i++)
        euler[i] = i;
    for(int i = 2; i < N; i++)
        if(euler[i] == i)
            for(int j = i; j < N; j+=i)
                euler[j] = euler[j]/i*(i-1);
}




/*������ȡģ*/
int powerMod(int a, int b)
{
    int ans = 1;
    a = a % MOD;
    while(b > 0)
    {
        if(b%2) ans = (ans*a)%MOD;
        b /= 2;
        a = (a*a)%MOD;
    }
    return ans;
}
