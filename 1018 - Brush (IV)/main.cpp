/*
     If opportunity doesn't knock, build a door.

            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            |S|.|S|.|R|.|A|.|S|.|A|.|M|.|K|
            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    Success is how high you bounce when you hit bottom.
*/


#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

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
/*------------------------------------------------*/

int vis[17][17];

pii slope(pii a, pii b)
{
    int y=b.ss-a.ss;
    int x=b.ff-a.ff;
    return pii(x,y);
}

int ask(pii a, pii b)
{
    if(((a.ff*b.ss)-(a.ss*b.ff))==0) return 1;
    return 0;
}

int dp[1<<17];
int n;


int func(int mask)
{
    if(__builtin_popcount(mask)==n) return 0;
    //if(n-__builtin_popcount(mask)<3) return 1;
    if(dp[mask]!=-1) return dp[mask];
    dp[mask]=1<<30;
    for(int i=0; i<n; i++)
    {
        if(check(mask,i)==0)
        {
            for(int j=i; j<n; j++)
            {
                if(check(mask,j)==0)
                    dp[mask]=min(dp[mask],func(mask|vis[i][j])+1);
            }
            break;
        }
    }
    return dp[mask];
}


int main()
{

    ///freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        sf(n);
        vector<pii>v;
        int a,b;
        loop(i,n)
        {
            sff(a,b);
            v.pb(pii(a,b));
        }

        for(int i=0; i<n; i++)
            for(int j=i; j<n; j++)
            {
                if(i==j)
                {
                    vis[i][j]=Set(vis[i][j],i);
                }
                else
                {
                    for(int k=0; k<n; k++)
                    {
                        pii slp1=slope(v[i],v[j]);
                        pii slp2=slope(v[i],v[k]);
                        if(ask(slp1,slp2))
                        {
                            vis[i][j]=Set(vis[i][j],k);
                        }

                    }
                }
            }

//        for(int i=0;i<n;i++,cout<<endl)
//            for(int j=0;j<n;j++)
//                cout<<vis[i][j]<<" ";

        ms(dp,-1);
        PRINT_CASE;
        printf("%d\n",func(0));
        ms(vis,0);

    }

    return 0;
}
