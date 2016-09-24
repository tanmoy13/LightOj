#include <iostream>
#include <cstdio>

using namespace std;

int cnt_bit(long long n)
{
    int cnt=0;
    for(int i=1; i<=n; i*=2)
    {
        if((n & (i))!=0)
            cnt++;
    }
    return cnt;
}


long long func(long long n)
{
    long long temp;
    for(int i=1; i<=n; i*=2)
    {
        if((n & (i))!=0)
        {
            temp=n+i;
            break;
        }
    }
    int bit_need = cnt_bit(n)-cnt_bit(temp);
    for(int i=0; i<bit_need; i++)
        temp+=(1<<i);
    return temp;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int z=1; z<=t; z++)
    {
        long long n;
        scanf("%lld",&n);
        n=func(n);
        printf("Case %d: %lld\n",z,n);
    }
    return 0;
}
