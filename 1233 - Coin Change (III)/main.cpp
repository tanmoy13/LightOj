/*
         +-+ +-+ +-+
         |R| |.| |S|
         +-+ +-+ +-+
 */

#include <bits/stdc++.h>

#define pii             pair <int,int>
#define sc              scanf
#define pf              printf
#define Pi              2*acos(0.0)
#define ms(a,b)         memset(a, b, sizeof(a))
#define pb(a)           push_back(a)
#define MP              make_pair
#define db              double
#define ll              long long
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define D(x)            cout<<#x " = "<<(x)<<endl
#define VI              vector <int>
#define DBG             pf("Hi\n")
#define MOD             100007
#define MAX             10000
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long


using namespace std;

/*----------------------- Graph Moves---------------------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*--------------------------------------------------------------*/


/*------------------------Bitmask-------------------------------*/
int Set(int N,int pos)
{
    return N=N | (1<<pos);
}
int reset(int N,int pos)
{
    return N= N & ~(1<<pos);
}
bool check(int N,int pos)
{
    return (bool)(N & (1<<pos));
}
/*--------------------------------------------------------------*/

bool dp[100005];
int num_coin[100005];
int n,m;
int coin[110],num[110];
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        sff(n,m);
        loop(i,n)
        {
            sf(coin[i]);
        }
        loop(i,n)
        {
            sf(num[i]);
        }
        loop(i,m+2)
        {
            dp[i]=0;
            num_coin[i]=inf;
        }
        dp[0]=1;
        num_coin[0]=0;
        int cnt=0;
        for(int i=0; i<n; i++)
        {
            int val=coin[i];
            int hi=0;
            int temp=val;
            for(int k=val; k<=m; k++)
            {
                if(dp[k]==0 && dp[k-val]==1 && num_coin[k-val]+1<=num[i])
                {
                    dp[k]=1;
                    if(dp[k])
                        cnt++;
                    num_coin[k]=num_coin[k-val]+1;
                }
            }
            loop(j,m+2) num_coin[j]=0;
            num_coin[0]=0;
        }
        PRINT_CASE;
        pf("%d\n",cnt);
    }
    return 0;
}
