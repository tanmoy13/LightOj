///*
//         +-+ +-+ +-+
//         |R| |.| |S|
//         +-+ +-+ +-+
// */
//
//#include <bits/stdc++.h>
//
//#define pii             pair <int,int>
//#define sc              scanf
//#define pf              printf
//#define Pi              2*acos(0.0)
//#define ms(a,b)         memset(a, b, sizeof(a))
//#define pb(a)           push_back(a)
//#define MP              make_pair
//#define db              double
//#define ll              long long
//#define EPS             10E-10
//#define ff              first
//#define ss              second
//#define sqr(x)          (x)*(x)
//#define D(x)            cout<<#x " = "<<(x)<<endl
//#define VI              vector <int>
//#define DBG             pf("Hi\n")
//#define MOD             100007
//#define MAX             10005
//#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)           (int)a.size()
//#define sf(a)           scanf("%d",&a)
//#define sff(a,b)        scanf("%d%d",&a,&b)
//#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
//#define loop(i,n)       for(int i=0;i<n;i++)
//#define REP(i,a,b)      for(int i=a;i<b;i++)
//#define TEST_CASE(t)    for(int z=1;z<=t;z++)
//#define PRINT_CASE      printf("Case %d: ",z)
//#define all(a)          a.begin(),a.end()
//#define intlim          2147483648
//#define inf             1000000
//#define ull             unsigned long long
//
//using namespace std;
//
//int n,m;
//vector<int>graph[MAX],reverse_graph[MAX],scc;
//vector<pii>v;
//int indegree[MAX],topsort[MAX],finish;
//bool visited[MAX];
//
//void allclear()
//{
//    loop(i,n+2)
//    {
//        graph[i].clear();
//        reverse_graph[i].clear();
//        indegree[i]=0;
//        visited[i]=0;
//        topsort[i];
//    }
//    scc.clear();
//    v.clear();
//    finish=0;
//}
//
//void dfs1(int u)
//{
//    finish++;
//    visited[u]=1;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(!visited[v])
//            dfs1(v);
//    }
//    topsort[u]=++finish;
//}
//
//void dfs2(int u)
//{
//    visited[u]=1;
//    loop(i,SZ(reverse_graph[u]))
//    {
//        int v=reverse_graph[u][i];
//        if(!visited[v])
//            dfs2(v);
//    }
//}
//
//void dfs3(int u)
//{
//    visited[u]=1;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(!visited[v])
//            dfs3(v);
//    }
//}
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int t,a,b;
//    sf(t);
//    TEST_CASE(t)
//    {
//        sff(n,m);
//        loop(i,m)
//        {
//            sff(a,b);
//            graph[a].pb(b);
//            reverse_graph[b].pb(a);
//            indegree[b]++;
//        }
//
//        int ans=0;
//        REP(i,1,n+1)
//        {
//            if(!visited[i])
//                dfs1(i);
//        }
//
//        REP(i,1,n+1)
//        {
//            v.pb(MP(topsort[i],i));
//        }
//        sort(all(v));
//        loop(i,n+2)
//        visited[i]=0;
//
//        for(int i=SZ(v)-1; i>=0; i--)
//        {
//            int u=v[i].ss;
//            if(!visited[u])
//            {
//                scc.pb(u);
//                dfs2(u);
//            }
//        }
//
//        loop(i,n+2)
//        visited[i]=0;
//
//        loop(i,SZ(scc))
//        {
//            if(!visited[scc[i]])
//            {
//                ans++;
//                dfs3(scc[i]);
//            }
//        }
//        PRINT_CASE;
//        pf("%d\n",ans);
//        allclear();
//    }
//    return 0;
//}


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
#define MAX             10005
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
vector<int>graph[MAX],topsort;
bool visited[MAX],test;

void allclear()
{
    loop(i,n+2)
    {
        graph[i].clear();
        visited[i]=0;
    }
    topsort.clear();
}

void dfs(int u)
{
    visited[u]=1;
    loop(i,SZ(graph[u]))
    {
        int v=graph[u][i];
        if(!visited[v])
            dfs(v);
    }
    if(test)
        topsort.pb(u);
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t,a,b;
    sf(t);
    TEST_CASE(t)
    {
        sff(n,m);
        loop(i,m)
        {
            sff(a,b);
            graph[a].pb(b);
        }
        test=1;
        int ans=0;
        REP(i,1,n+1)
        {
            if(!visited[i])
                dfs(i);
        }

        test=0;
        loop(i,n+2) visited[i]=0;
        for(int i=SZ(topsort)-1; i>=0; i--)
        {
            int u=topsort[i];
            if(!visited[u])
            {
                dfs(u);
                ans++;
            }
        }
        PRINT_CASE;
        pf("%d\n",ans);
        allclear();
    }
    return 0;
}


