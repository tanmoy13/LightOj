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

bool vis[1000005];
vector<int>v;

void sieve()
{
    for(int i=2;i<1000002;)
    {
        if(vis[i]==0)
        {
            v.pb(i);
            for(int j=i+i;j<1000002;j+=i)
                vis[j]=1;
        }
        for(++i;;i++) if(vis[i]==0) break;
    }
}

int prime[1000000],cnt[1000000],k,l,p;

void gen_div(int n)
{
    k=0;
    int aa=sqrt(n)+1;
    for(int i=0;v[i]<=aa;i++)
    {
        if(n%v[i]==0)
        {
            int cntt=0;
            while(n%v[i]==0)
            {
                n/=v[i];
                cntt++;
            }
            prime[k]=v[i];
            cnt[k]=cntt;
            k++;
        }
    }
    if(n>1)
    {
        prime[k]=n;
        cnt[k]=1;
        k++;
    }
}

vector<int>ans;

void gen_ans(int idx, int num)
{
    if(idx>=k)
    {
        if(num>p) ans.pb(num);
        return;
    }
    int val=1;
    for(int i=0;i<=cnt[idx];i++)
    {
        gen_ans(idx+1,val*num);
        val*=prime[idx];
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
        sff(l,p);
        gen_div(l-p);
        ans.clear();
        gen_ans(0,1);
        sort(all(ans));
        PRINT_CASE;
        if(SZ(ans)==0)
            pf("impossible\n");
        else
        {
            pf("%d",ans[0]);
           REP(i,1,SZ(ans)) pf(" %d",ans[i]);
           pf("\n");
        }

    }

    return 0;
}
