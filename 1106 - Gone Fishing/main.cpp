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
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<=b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d:\n",z)
#define CASE_PRINT      cout<<"Case "<<z<<": ";
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
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

int f[30],d[30],t[30];

int n,h;

int dp[30][195];
int ttime,fish;
vector<int>v;


int call(int idx, int time)
{
    if(time==ttime || time-t[idx-1]==ttime) return 0;
    if(time<0 || time>ttime) return -10000000;
    if(idx==n && time!=ttime) return -10000000;
    if(idx>n) return 0;
    int &ret=dp[idx][time];

    if(ret!=-1) return ret;

    int p=0,r=0,q=0,s=0;

    for(int i=1; i<=ttime-time; i++)
    {
        r+=f[idx]-(d[idx]*(i-1));
        p=max(p,r);
        q=max(q,p+call(idx+1,time+i+t[idx]));
    }
    s=call(idx+1,time+t[idx]);
    return ret=max(q,s);
}

void print_path(int idx, int time, int remain)
{
    if(remain==0) return;
    if(time==ttime || time-t[idx-1]==ttime) return ;
    if(idx>n) return;

    int p=0,r=0,q=0,s=0;

    int maxx=-1;

    if(remain-call(idx+1,time+t[idx])==0)
    {
        maxx=0;
    }

    q=0;
    for(int i=1; i<=ttime-time; i++)
    {
        r+=f[idx]-(d[idx]*(i-1));
        p=max(p,r);
        s=(p+call(idx+1,time+i+t[idx]));
        if(remain-s==0)
        {
            if(i>maxx)
            {
                maxx=i;
                q=p;
            }
        }
    }
    v.pb(maxx);
    print_path(idx+1,time+maxx+t[idx],remain-q);
}



int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int tt;
//    sf(tt);
//    TEST_CASE(tt)
    bool test=0;
    while(sf(n)==1)
    {
        if(n==0) break;
        if(test) pf("\n");
        test=1;
        sf(h);
        loop(i,n) sf(f[i]);
        loop(i,n) sf(d[i]);
        loop(i,n-1) sf(t[i]);

        ms(dp,-1);
        ttime=h*60/5;
//        PRINT_CASE;

        fish=call(0,0);
        print_path(0,0,fish);
//        if(fish==0)
//        {
//            v.pb(ttime);
//        }
        REP(i,SZ(v),n) v.pb(0);
        printf("%d",v[0]*5);
        if(SZ(v)>1) pf(",");
        REP(i,1,n-1)
        {
            printf(" %d",v[i]*5);
            if(i!=n-1)pf(",");
        }
        pf("\n");
        pf("Number of fish expected: %d\n",fish);
        v.clear();
    }

    return 0;
}
