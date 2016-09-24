
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
#define MAX             110
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

int n,m,a,b,u,v;
vector<int>edge[MAX];
bool visited[MAX];
int distance1[MAX];
int distance2[MAX];

void BFS(int src,int d[])
{
    queue<int>Q;
    d[src]=0;
    Q.push(src);
    ms(visited,0);
    visited[src]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        REP(i,0,SZ(edge[u]))
        {
            int v=edge[u][i];
            if(visited[v]==0)
            {
                visited[v]=1;
                Q.push(v);
                d[v]=d[u]+1;
            }
        }
    }
}

void clr()
{
    REP(i,0,n)
    {
        edge[i].clear();
    }
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
        REP(i,0,m)
        {
            sff(u,v);
            edge[u].pb(v);
            edge[v].pb(u);
        }
        sff(a,b);
        ms(distance1,0);
        ms(distance2,0);
        BFS(a,distance1);
        BFS(b,distance2);
        int ans=-1;
        REP(i,0,n)
        {
            ans=max(ans,distance1[i]+distance2[i]);
        }
        PRINT_CASE;
        pf("%d\n",ans);
        clr();
    }
    return 0;
}
