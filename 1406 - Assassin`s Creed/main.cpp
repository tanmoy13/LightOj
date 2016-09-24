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
//#define MAX             30
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
//vector<int>graph[MAX],rev_graph[MAX];
//bool vis1[MAX],vis2[MAX],vis3[MAX];
//int dis[MAX];
//int n,m,dfsnum;
//
//void allclear()
//{
//    loop(i,n+5)
//    {
//        vis1[i]=vis2[i]=vis3[i]=0;
//        dis[i]=0;
//        graph[i].clear();
//        rev_graph[i].clear();
//    }
//    dfsnum=0;
//}
//
//void dfs1(int u)
//{
//    vis1[u]=1;
//    dfsnum++;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(!vis1[v])
//            dfs1(v);
//    }
//    dis[u]= ++dfsnum;
//}
//
//void dfs2(int u)
//{
//    vis2[u]=1;
//    loop(i,SZ(rev_graph[u]))
//    {
//        int v=rev_graph[u][i];
//        if(!vis2[v])
//            dfs2(v);
//    }
//}
//
//void dfs3(int u)
//{
//    vis3[u]=1;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(!vis3[v])
//            dfs3(v);
//    }
//}
//
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//
//    int t;
//    sf(t);
//    TEST_CASE(t)
//    {
//        sff(n,m);
//        allclear();
//        int a,b;
//        loop(i,m)
//        {
//            sff(a,b);
//            graph[a].pb(b);
//            rev_graph[b].pb(a);
//        }
//
//        REP(i,1,n+1)
//        if(!vis1[i])
//            dfs1(i);
//
//        vector<pii>v;
//
//        REP(i,1,n+1)
//        {
//            v.pb(MP(dis[i],i));
//        }
//        sort(v.rbegin(),v.rend());
//
//        vector<int>scc;
//
//        loop(i,SZ(v))
//        {
//            int u=v[i].ss;
//            if(!vis2[u])
//            {
//                dfs2(u);
//                scc.pb(u);
//            }
//        }
////        D(SZ(scc));
//        int ans=0;
//        loop(i,SZ(scc))
//        {
//            int u=scc[i];
//            if(!vis3[u])
//            {
//                dfs3(u);
//                ans++;
//            }
//        }
//        PRINT_CASE;
//        pf("%d\n",ans);
//    }
//    return 0;
//}


#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <numeric>
#include <cmath>
#include <cstring>

using namespace std;

int N, E;
vector<int> G[16];
int DP[(1<<16)];
bool vis[16][(1<<16)];
bool flag[(1<<16)];

void DFS(int u, int mask)
{
    int v, len;
    vis[u][mask] = true;
    flag[mask] = true;
    len = G[u].size();
    for(int i=0; i<len; i++)
    {
        v = G[u][i];
        if(!vis[v][mask|(1<<v)]) DFS(v,(mask|(1<<v)));
    }
}


int rec(int mask)
{
    int &ret = DP[mask];
    if(mask==0) return 0;
    if(ret!=-1) return ret;
    ret = 20;
    for(int i=mask; i>0; i=(mask&(i-1)))
    {
        if(flag[i]) ret = min(ret, 1+rec(mask^i));
    }
    return ret;
}

int main()
{
    int test, x, y;
    cin>>test;
    for(int i=1; i<=test; i++)
    {
        cin>>N>>E;
        for(int j=0; j<N; j++) G[j].clear();
        for(int j=0; j<E; j++)
        {
            cin>>x>>y;
            x--, y--;
            G[x].push_back(y);
        }
        memset(vis,false,sizeof(vis));
        memset(flag,false,sizeof(flag));
        for(int j=0; j<N; j++) DFS(j,(1<<j));
        memset(DP,-1,sizeof(DP));
        cout<<"Case "<<i<<": "<<rec((1<<N)-1)<<endl;
    }
    return 0;
}
