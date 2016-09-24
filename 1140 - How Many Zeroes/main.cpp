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


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

ll dp[20][20];

ll func(ll len, ll digit)
{
    if(!len) return digit;
    ll &ret=dp[len][digit];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=0;i<10;i++)
    {
        if(i==0) ret+=func(len-1,digit+1);
        else ret+=func(len-1,digit);
    }
    return ret;
}


ll calculator(ll n)
{
    stringstream ss;
    ss<<n;
    string str;
    ss>>str;
    ll len=SZ(str);
    ll ans=0,i,j;

    for(i=1;i<len;i++)
        for(j=1;j<10;j++)
            ans+=func(i-1,0);

    for(j=1;j<str[0]-'0';j++)
        ans+=func(len-1,0);

    ll temp_sum=0;

    for(i=1;i<len;i++)
    {
        for(j=0;j<str[i]-'0';j++)
            if(j==0) ans+=func(len-i-1,temp_sum+1);
            else ans+=func(len-i-1,temp_sum);
        if(str[i]=='0') temp_sum++;
    }
    return ans;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        ll m,n;
        cin>>m>>n;
        ms(dp,-1);
        ll temp=0;
        if(m==0)temp=1;
        PRINT_CASE;
        pf("%lld\n",calculator(n+1)-calculator(m)+temp);
    }
    return 0;
}
