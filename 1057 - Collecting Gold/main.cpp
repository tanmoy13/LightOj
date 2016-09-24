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
const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

vector<pii>points;

int dis[16][22][22];
bool vis[16][22][22];
int r,c,n;

pii start;

void bfs(int idx, pii src)
{
    vis[idx][src.ff][src.ss]=1;
    dis[idx][src.ff][src.ss]=0;
    queue<pii>Q;
    Q.push(src);
    while(!Q.empty())
    {
        pii u=Q.front();
        Q.pop();
        for(int i=0;i<8;i++)
        {
            int aa=u.ff+fx[i];
            int bb=u.ss+fy[i];
            if(!vis[idx][aa][bb] && aa>=0 && aa<r && bb>=0 && bb<c)
            {
                dis[idx][aa][bb]=dis[idx][u.ff][u.ss]+1;
                vis[idx][aa][bb]=1;
                Q.push(pii(aa,bb));
            }
        }
    }
}

int dp[1<<16][16];

int func(int mask, int last)
{
    if(__builtin_popcount(mask)==SZ(points))
    {
        return dis[last][start.ff][start.ss];
    }
    int &ret=dp[mask][last];
    if(ret!=-1) return ret;

    int p=1<<29;

    for(int i=0;i<SZ(points);i++)
    {
        if(check(mask,i)==0)
        {
            p=min(p,dis[last][points[i].ff][points[i].ss]+func(Set(mask,i),i+1));
        }
    }
    return ret=p;
}

int main()
{

    CIN;
//    freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    TEST_CASE(t)
    {
        cin>>r>>c;
        string str;
        loop(i,r)
        {
            cin>>str;
            loop(j,c)
            {
                if(str[j]=='x') start=pii(i,j);
                if(str[j]=='g')
                    points.pb(pii(i,j));
            }
        }
        ms(vis,0);
        bfs(0,start);
        loop(i,SZ(points))
        {
            bfs(i+1,points[i]);
        }
        ms(dp,-1);
        CASE_PRINT;
        cout<<func(0,0)<<endl;
        points.clear();
    }

    return 0;
}





