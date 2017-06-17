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
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define loop1(i,n)       for(int i=1;i<=n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define LINE_PRINT_CASE  printf("Case %d:\n",z)
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

#define mx 100005

int ara[mx],lis[mx],dp[mx],position[mx];

int main()
{

//    freopen("in.txt","r",stdin);
//	  freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n,q;
        sff(n,q);
        for(int i=0;i<n;i++) sf(ara[i]);
        fill(dp,dp+mx,(1<<30));
        ms(position,-1);
        dp[0]=-dp[0];
        for(int i=n-1;i>=0;i--)
        {
            int pos=lower_bound(dp,dp+n+1,-ara[i])-dp;
            lis[i]=pos;
            dp[pos]=-ara[i];
        }

        int lis_value=*max_element(lis,lis+n);

        LINE_PRINT_CASE;
        while(q--)
        {
            int a;
            sf(a);
            if(a>lis_value)
            {
                pf("Impossible\n");
                continue;
            }
            vector<int>v;
            int last=-(1<<30),i=0;
            while(i<n && a)
            {
                int x=lis[i];
                if(x>=a && last<ara[i])
                {
                    v.pb(ara[i]);
                    a--;
                    last=ara[i];
                }
                i++;
            }

//            reverse(all(v));
            for(i=0;i<SZ(v);i++)
            {
                pf("%d",v[i]);
                if(i!=SZ(v)-1)
                    pf(" ");
            }
            pf("\n");
        }
    }

    return 0;
}
