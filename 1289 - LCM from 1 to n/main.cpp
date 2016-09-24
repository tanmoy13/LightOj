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
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

#define maxx 100000008

ll vis[maxx/64+5];
int prime[6000000];
unsigned int cummul[6000000];
int cnt_p=0;

void sieve()
{
    ll i,j,k;
    for(i=3; i<maxx; i+=2)
        if(!(vis[i/64]&(1LL<<(i%64))))
            for(j=i*i; j<maxx; j+=2*i)
                vis[j/64]|=(1LL<<(j%64));

    cummul[cnt_p]=2;
    prime[cnt_p]=2;
    for (int i = 3; i<maxx; i+=2)
        if(!(vis[i/64]&(1LL<<(i%64))))
            {
                cnt_p++;
                prime[cnt_p]=i;
                cummul[cnt_p]=cummul[cnt_p-1]*i;
            }
}


int main()
{

    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    sieve();
    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n;
        sf(n);
        int idx=upper_bound(prime,prime+cnt_p+1,n)-prime;
        unsigned int ans=cummul[idx-1];
        int root=sqrt(n);

        for(int i=0;i<=cnt_p && prime[i]<=root;i++)
        {
            int x=n/prime[i];
            unsigned int temp=1;
            while(x>=prime[i])
            {
                temp*=prime[i];
                x/=prime[i];
            }
            ans*=temp;
        }

        PRINT_CASE;
        printf("%u\n",ans);
    }

    return 0;
}


