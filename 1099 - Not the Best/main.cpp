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
#define MAX             5005
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
    int u,w;
     bool operator < (const data &p) const
     {
         return w>p.w;
     }
     data(){};
     data(int x,int z){u=x,w=z;}
};

int n,m;
vector<int> graph[MAX],cost[MAX];
int dis1[MAX],dis2[MAX],weight2[MAX],min_cost,par[MAX],a,b,c;
bool visited[MAX];
void dijkastra1(int src, int dst)
{
    loop(i,dst+2)
        dis1[i]=dis2[i]=inf;
    ms(visited,0);
    REP(i,1,n+1)
    {
        dis2[i]=inf;
        loop(j,SZ(graph[i]))
        dis2[i]=min(dis2[i],cost[i][j]*2);
    }

    priority_queue<data>Q;
    Q.push(data(src,0));
    int cnt=0;
    dis1[src]=0;
    data u;
    int v;
    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();

        if(visited[u.u]);


        loop(i,SZ(graph[u.u]))
        {
            v=graph[u.u][i];
            int temp=dis[u.u]+cost[u.u][i];
            if(dis[v]>temp)
            {
                if(cost[u.u][i]<c && SZ(graph[u.u])>1)
                {
                    a=u.u;b=v;
                    c=cost[u.u][i];
                }
                par[v]=u.u;
                dis[v]=temp;
                Q.push(data(v,dis[v]));
            }
        }
    }
}

void allclear()
{
    loop(i,n+2)
   {
     graph[i].clear();
     cost[i].clear();
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
        c=inf;
        int u,v,w;
        loop(i,m)
        {
            sfff(u,v,w);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(w);
            cost[v].pb(w);
        }
        dijkastra1(1,n);
        int cost=dijkastra2(1,n);
        PRINT_CASE;
        if(cost==min_cost)
            cost=min_cost*3;
        pf("%d\n",cost);
        allclear();
    }
    return 0;
}
