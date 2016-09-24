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
    data(int x, int y, int z){u=x,v=y,w=z;}
    bool operator<(const data& p) const
    {
        return w<p.w;
    }
};

vector<data>edge;
int par[MAX],n,m,a,plane=0,ans;
bool visited[MAX];

int find_par(int n)
{
    return par[n]=(par[n]==n)?n:find_par(par[n]);
}

void allclear()
{
    loop(i,n+5)
    {par[i]=i;visited[i]=0;}
    edge.clear();
    plane=0;
    ans=0;
}

int kruskal()
{
    sort(all(edge));
    int cnt=0;
    loop(i,SZ(edge))
    {
        int u=find_par(edge[i].u);
        int v=find_par(edge[i].v);
        if(u!=v)
        {
            par[u]=v;
            if(edge[i].w>=a)
            {
                ans+=a;
                plane++;
            }
            else
            {
                ans+=edge[i].w;
            }
            cnt++;
        }
        if(cnt==n-1) return cnt;
    }
    return cnt;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        sfff(n,m,a);
        int x,y,c;
        allclear();
        loop(i,m)
        {
            sfff(x,y,c);
            edge.pb(data(x,y,c));
        }

        int temp=0;
        temp=kruskal();
//        for(int i=1;i<=n;i++)
//            {
//                if(visited[par[i]]==0)
//                   {
//                     temp++;
//                     visited[par[i]]=1;
//                   }
//            }
        ans+=(n-temp)*a;
        plane+=(n-temp);
        PRINT_CASE;
        pf("%d %d\n",ans,plane);
    }
    return 0;
}
