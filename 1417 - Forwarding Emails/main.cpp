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
//#define MAX             50005
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
//int n,dfsnum,dis[MAX];
//vector<int> graph[MAX],rev_graph[MAX];
//bool mp[MAX],mp1[MAX],mp2[MAX];
//
//void allclear()
//{
//    loop(i,n+2)
//    {
//        graph[i].clear();
//        rev_graph[i].clear();
//        dis[i]=0;
//        mp[i]=mp1[i]=mp2[i]=0;
//    }
//    dfsnum=0;
//}
//
//void dfs1(int u)
//{
//    mp[u]=1;
//    dfsnum++;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(!mp[v])
//            dfs1(v);
//    }
//    dis[u]=++dfsnum;
//}
//
//void dfs2(int u)
//{
//    mp1[u]=1;
//    loop(i,SZ(rev_graph[u]))
//    {
//        int v=rev_graph[u][i];
//        if(!mp1[v])
//            dfs2(v);
//    }
//}
//
//void dfs3(int u)
//{
//    mp2[u]=1;
//    dfsnum++;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(!mp2[v])
//            dfs3(v);
//    }
//}
//
//void dfs4(int u)
//{
//    mp2[u]=0;
//    loop(i,SZ(graph[u]))
//    {
//        int v=graph[u][i];
//        if(mp2[v])
//            dfs4(v);
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
//        sf(n);
//        allclear();
//        int a,b;
//        loop(i,n)
//        {
//            sff(a,b);
//            graph[a].pb(b);
//            rev_graph[b].pb(a);
//        }
//        REP(i,1,n+1)
//        {
//            if(!mp[i])
//                dfs1(i);
//        }
//
//        vector<pii>top_sort;
//        REP(i,1,n+1)
//        {
//            top_sort.pb(MP(dis[i],i));
//        }
//
//
//        sort(top_sort.rbegin(),top_sort.rend());
//        vector<int>scc;
//
//        loop(i,SZ(top_sort))
//        {
//            int u=top_sort[i].ss;
//            if(!mp1[u])
//            {
//                scc.pb(u);
//                dfs2(u);
//            }
//        }
//
//        top_sort.clear();
//        loop(i,SZ(scc))
//        {
//            int u=scc[i];
//            if(!mp2[u])
//            {
//                dfsnum=0;
//                dfs3(u);
//                top_sort.pb(MP(dfsnum,u));
//                dfs4(u);
//            }
//        }
//
//        sort(top_sort.rbegin(),top_sort.rend());
//        PRINT_CASE;
//        if(SZ(top_sort)==1)
//            pf("%d\n",top_sort[0].ss);
//        else
//        {
//            loop(i,SZ(top_sort)-1)
//            {
//                if(top_sort[i].ff!=top_sort[i+1].ff)
//                {
//                    pf("%d\n",top_sort[i].ss);
//                    break;
//                }
//            }
//        }
//    }
//    return 0;
//}


#include<bits/stdc++.h>
using namespace std;

#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define sqr(x)      (x)*(x)
#define all(x)      x.begin(),x.end()
#define un(x)       x.erase(unique(all(x)), x.end())
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define D(x)        cout<<#x " = "<<(x)<<endl
#define pf          printf
#define VI          vector <int>
#define pii         pair <int, int>
#define pll         pair <LL, LL>
#define pb          push_back
#define mp          make_pair
#define pi          acos(-1.00)
#define DBG         pf("Hi\n")
#define sz          size()
#define ins         insert
#define fi          first
#define se          second
#define xx          first
#define yy          second
#define inf         (1<<29)
#define MOD         100007
#define eps         1e-9
#define MAX         50000

typedef long long int LL;
typedef double db;

//int dx[] = {+0,+1,+0,-1};
//int dy[] = {+1,+0,-1,+0};
//int dx[] = {-1,-1,-1,+0,+0,+1,+1,+1};
//int dy[] = {-1,+0,+1,-1,+1,-1,+0,+1};
//bool check(int n, int pos) {return (bool) (n & (1<<pos));}
//int on(int n, int pos) {return n | (1<<pos); }
//int off(int n, int pos) {return n & ~(1<<pos); }

int vis[MAX+10];
VI v[MAX+10];

int cycle(int node,int src,int total)
{
//    D(src);
    if(node==src)
    {
//        D(total);
        return total;
    }
    return vis[node]=cycle(v[node][0],src,total+1);

}

int dfs(int node)
{
//     D(node);
    if(vis[node]==-1)
        return -1;

    if(vis[node])
        return vis[node];
    vis[node]=-1;
    int i,ret=0;
    ret=dfs(v[node][0]);
    if(ret==-1)
    {
        cycle(v[node][0],node,1)-1;
        return vis[node];
    }
    if(vis[node]!=-1)
        return vis[node];
    return vis[node]=ret+1;
}

int main()
{
    //freopen("c:\\Users\\User\\Desktop\\in.txt", "r", stdin);
    //freopen("c:\\Users\\User\\Desktop\\out.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    int i,j,k,cs,n,t,nw;
    sf(t);
    FRE(cs,1,t)
    {
        mem(vis,0);
        FRE(i,0,MAX)
        v[i].clear();
        sf(n);
        FRE(i,1,n)
        {
            sff(k,j);
            v[k].pb(j);
        }
        int mx=-213,ans;
        FRE(i,1,n)
        {
            if(!vis[i])
            {
                nw=dfs(i);
//                D(nw);
                if(nw>mx)
                {
                    mx=nw;
                    ans=i;
                }
            }
        }
//        D(mx);
        pf("Case %d: %d\n",cs,ans);
    }
    return 0;
}

