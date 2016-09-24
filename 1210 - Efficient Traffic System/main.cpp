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
#define MAX             20010
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

int n,m;
vector<int>graph[MAX],reverse_graph[MAX];
int finish[MAX],start,scc,belong[MAX],indegree[MAX],outdegree[MAX];
bool visited[MAX];

bool test(pii a, pii b)
{
    return a.ff>b.ff;
}

void dfs1(int n)
{
    visited[n]=1;
    start++;
    loop(i,SZ(graph[n]))
    {
        int v=graph[n][i];
        if(!visited[v])
            dfs1(v);
    }
    finish[n]=++start;
}

void dfs2(int n)
{
    visited[n]=1;
    belong[n]=scc;
    loop(i,SZ(reverse_graph[n]))
    {
        int v=reverse_graph[n][i];
        if(visited[v]==0)
        {
            dfs2(v);
        }
    }
}

void dfs3(int u)
{
    visited[u]=1;
    loop(i,SZ(graph[u]))
    {
        int v=graph[u][i];
        if(belong[u]!=belong[v])
        {
            indegree[belong[v]]++;
            outdegree[belong[u]]++;
        }
        if(!visited[v])
            dfs3(v);
    }
}

void allclear()
{
    loop(i,n+2)
    {
        graph[i].clear();
        reverse_graph[i].clear();
        visited[i]=0;
        belong[i]=-1;
        indegree[i]=0;
        finish[i]=0;
        outdegree[i]=0;
    }
    start=0;
    scc=0;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        sff(n,m);
        allclear();
        while(m--)
        {
            int u,v;
            sff(u,v);
            graph[u].pb(v);
            reverse_graph[v].pb(u);
        }

        vector<pii>v;
        for(int i=1; i<=n; i++)
            if(!visited[i])
                dfs1(i);
        for(int i=1; i<=n; i++)
        {
            v.pb(MP(finish[i],i));
        }
        sort(all(v),test);
        loop(i,n+2)
        visited[i]=0;

        loop(i,SZ(v))
        {
            int u=v[i].ss;
            if(!visited[u])
            {
                scc++;
                dfs2(u);
            }
        }

        loop(i,n+2)
        visited[i]=0;
        for(int i=1; i<=n; i++)
        {
            if(!visited[i])
                dfs3(i);
        }

        int in=0,out=0;
        for(int i=1; i<=scc && scc>1; i++)
        {
            if(!indegree[i])
                in++;
            if(!outdegree[i])
                out++;
        }
        PRINT_CASE;
        pf("%d\n",max(in,out));
    }
    return 0;
}
