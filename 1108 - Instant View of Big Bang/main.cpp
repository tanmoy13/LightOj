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
#define MAX             1005
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
    data(int x, int y, int z)
    {
        u=x,v=y,w=z;
    }
};

int n,m,total_edge;
vector<data> graph;
vector<int>ans,reverse_graph[MAX];
map<int,bool>mp;
int d[MAX];
bool visited[MAX];

void dfs(int u)
{
    mp[u]=1;
    ans.pb(u);
    loop(i,SZ(reverse_graph[u]))
    {
        int v=reverse_graph[u][i];
        if(!mp[v])
            dfs(v);
    }
}

bool bellmanford()
{
    for(int i=1;i<n;i++)
    {
        loop(i,m)
        {
            int u=graph[i].u;
            int v=graph[i].v;
            if(d[u]+graph[i].w<d[v])
            {
                d[v]=d[u]+graph[i].w;
            }
        }
    }

    bool negative_cycle=0;

    loop(i,m)
        {
            int u=graph[i].u;
            int v=graph[i].v;
            if(d[u]+graph[i].w<d[v])
            {
                negative_cycle=1;
                d[v]=d[u]+graph[i].w;
                if(!mp[u])
                    dfs(u);
            }
        }
        return negative_cycle;
}

void allclear()
{
    graph.clear();
    ans.clear();
    mp.clear();

    loop(i,n+2)
        {d[i]=inf;reverse_graph[i].clear();}
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        int u,v,w;
        sff(n,m);
        allclear();
        loop(i,m)
        {
            sfff(u,v,w);
            graph.pb(data(v,u,w));//reversing graph
            reverse_graph[v].pb(u);
        }

        PRINT_CASE;
        if(bellmanford())
        {
            sort(all(ans));
            pf("%d",ans[0]);
            REP(i,1,SZ(ans))
            pf(" %d",ans[i]);
            pf("\n");
        }
        else
            pf("impossible\n");
    }
    return 0;
}
