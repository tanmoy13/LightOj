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


const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

vector<int>graph[MAX],rev_graph[MAX],scc_graph[MAX];
int visited[MAX];
int node[MAX],scc_num[MAX],node_num,scc;
stack<int>st;
bool test,scc_vis[MAX];

void allclear()
{
    loop(i,node_num+2)
    {
        visited[i]=0;
        graph[i].clear();
        rev_graph[i].clear();
        scc_num[i]=0;
    }
    loop(i,scc+2)
    {
        scc_graph[i].clear();
        scc_vis[i]=0;
    }
    node_num=0;
    scc=0;
}

void dfs1(int u)
{
    visited[u]++;
    loop(i,SZ(graph[u]))
    {
        int v=graph[u][i];
        if(visited[v]==0)
            dfs1(v);
    }
    st.push(u);
}

void dfs2(int u)
{
    visited[u]++;
    scc_num[u]=scc;
    loop(i,SZ(rev_graph[u]))
    {
        int v=rev_graph[u][i];
        if(visited[v]!=2)
            dfs2(v);
    }
}

void dfs3(int u)
{
    scc_vis[u]=1;
    if(SZ(scc_graph[u])>1)
        {test=0;return;}
    loop(i,SZ(scc_graph[u]))
    dfs3(scc_graph[u][i]);
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        ms(node,-1);
        int n,m,u,v;
        node_num=0;
        node[0]=node_num;
        sf(n);
        loop(i,n)
        {
            sf(m);
            loop(j,m)
            {
                sff(u,v);
                if(node[u]==-1) node[u]=++node_num;
                if(node[v]==-1) node[v]=++node_num;
                graph[node[u]].pb(node[v]);
                rev_graph[node[v]].pb(node[u]);
            }
        }

        loop(i,node_num)
        {
            if(visited[i]==0)
                dfs1(i);
        }

        scc=0;
        while(!st.empty())
        {
            u=st.top();
            st.pop();
            if(visited[u]!=2)
            {
                scc++;
                dfs2(u);
            }
        }

        loop(i,node_num)
        {
            loop(j,SZ(graph[i]))
            {
                u=graph[i][j];
                if(scc_num[i]!=scc_num[u])
                    scc_graph[scc_num[i]].pb(scc_num[u]);
            }
        }

        test=1;
        dfs3(scc_num[0]);
        if(test)
        {
            REP(i,1,scc+1)
            {
                if(!scc_vis[i])
                    test=0;
            }
        }
        PRINT_CASE;
        if(test)
            pf("YES\n");
        else
            pf("NO\n");
        allclear();

    }
    return 0;
}

//
//int main()
//{
//    int N,R,D,b,c,i;
//    for(i=1;;i++)
//    {
//        scanf("%d %d",&R,&N);
//        if(R==0 && N==0) break;
//        D=(R-N)/N;
//        b=(R-N)%N;
//        c=(N*26)+N;
//        if(c<R)
//        {
//            printf("Case %d: impossible\n",i);
//        }
//        else if(b==0)
//        {
//            printf("Case %d: %d\n",i,D);
//        }
//        else if(b<=N)
//        {
//            D++;
//            printf("Case %d: %d\n",i,D);
//        }
//    }
//    return 0;
//}
