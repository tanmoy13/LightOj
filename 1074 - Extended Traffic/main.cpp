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
#define MAX             202
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d:\n",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long

using namespace std;

int n,m;
int weight[MAX], d[MAX];
vector<int>u,v,cost,graph[MAX];
void allclear()
{
    loop(i,n+1)
    {
        weight[i]=0;
        d[i]=inf;
    }
    d[1]=0;
    u.clear();
    v.clear();
    cost.clear();
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        sf(n);
        allclear();
        for(int i=1;i<=n;i++) sf(weight[i]);
        sf(m);
        int x,y;
        loop(i,m)
        {
            sff(x,y);
            u.pb(x);
            v.pb(y);
            int xx=weight[y]-weight[x];
            cost.pb(xx*sqr(xx));
        }

        for(int i=1;i<=n;i++)
        {
            bool update=0;
            loop(i,m)
            {
                int x=u[i];
                int y=v[i];
                if(d[x]+cost[i]<d[y])
                {
                    update=1;
                    d[y]=d[x]+cost[i];
                }
            }
            if(update==0)
                break;
        }
        PRINT_CASE;
        int p,q;
        sf(q);
        loop(i,q)
        {
            sf(p);
            if(d[p]<3 ||d[p]>100000)
                pf("?\n");
            else
                pf("%d\n",d[p]);
        }
    }
    return 0;
}
