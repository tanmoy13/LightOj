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

struct data
{
    int u,v,w;
    bool operator < (const data& p) const
    {
        return w<p.w;
    }
    data(int x,int y,int z)
    {
        u=x;
        v=y;
        w=z;
    }
};

int par[MAX],test[MAX];
vector<data>edge;
int n;

int find_par(int n)
{
    return par[n]= (par[n]==n)?n:find_par(par[n]);
}

int find_par_test(int n)
{
    return test[n]= (test[n]==n)?n:find_par_test(test[n]);
}

int kruskal()
{
    sort(all(edge));
    int cost=0,cnt=0;
    loop(i,SZ(edge))
    {
        int u=find_par(edge[i].u);
        int v=find_par(edge[i].v);
        if(u!=v)
        {
            par[u]=v;
            cost+=edge[i].w;
            cnt++;
            if(cnt==n-1)
                return cost;
        }
    }
}

void allclear()
{
    loop(i,n+2)
    {
        test[i]=i;
        par[i]=i;
    }
    edge.clear();
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t,c;
    sf(t);
    TEST_CASE(t)
    {
        sf(n);
        allclear();
        int total_cost=0;
        loop(i,n) loop(j,n)
        {
            c=0;
            sf(c);
            if(c)
            {
                total_cost+=c;
                edge.pb(data(i,j,c));
                int a=find_par_test(i);
                int b=find_par_test(j);
                if(a!=b)
                {
                    test[a]=b;
                }
            }
        }
        int cnt=0;
        loop(i,n)
        if(test[i]==i) cnt++;
        PRINT_CASE;
        if(cnt>1)
        {
            cout<<-1<<endl;
            continue;
        }
        else
        {
            int temp=kruskal();
            cout<<total_cost-temp<<endl;
        }
    }
    return 0;
}
