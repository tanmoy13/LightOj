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
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
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

vector<int>graph[110];
int flow[110][110],par[110];
bool visited[110];

int path_flow(int sink,int minflow)
{
    if(par[sink]==-1)
    {
       return minflow;
    }
    else
    {
        int mini=path_flow(par[sink],min(minflow,flow[par[sink]][sink]));
        flow[par[sink]][sink]-=mini;
        flow[sink][par[sink]]+=mini;
        return mini;
    }

}

int max_flow(int src, int sink)
{


    int ans=0;

    while(1)
    {
        ms(visited,0);
        ms(par,-1);
        queue<int>Q;
        Q.push(src);
        visited[src]=1;
        bool test=0;
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            if(u==sink)
            {
                test=1;
                break;
            }

            loop(i,SZ(graph[u]))
            {
                int v=graph[u][i];
                if(!visited[v] && flow[u][v]>0)
                {
                    par[v]=u;
                    Q.push(v);
                    visited[v]=1;
                }
            }

        }

        int ans1=path_flow(sink,1000000000);
        if(ans1==0 || test==0)
            break;
        ans+=ans1;
    }

    return ans;

}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n;
        sf(n);
        int src,sink,edge;
        ms(flow,0);
        loop(i,102)
        {
            graph[i].clear();
        }

        sfff(src,sink,edge);
        while(edge--)
        {
            int a,b,c;
            sfff(a,b,c);
            graph[a].pb(b);
            graph[b].pb(a);
            flow[a][b]+=c;
            flow[b][a]+=c;
        }
        PRINT_CASE;
        int ans=max_flow(src,sink);
        pf("%d\n",ans);
    }
    return 0;
}
