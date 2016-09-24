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
#define PRINT_CASE      printf("Case %d:\n",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long

using namespace std;

struct data
{
    int u,v,w;
    bool operator< (const data& p)const
    {
        return w<p.w;
    }
    data(int x,int y, int z)
    {
        u=x,v=y,w=z;
    }
};

vector<data>edge;
int n,m,cnt=0;
int par[210];

int find_par(int n)
{
    return par[n]=(par[n]==n)?n:find_par(par[n]);
}

int mst()
{
    int cnt=0,sum=0;
    sort(all(edge));
    vector<data>temp;
    for(int i=0; i<SZ(edge); i++)
    {
        int u=find_par(edge[i].u);
        int v=find_par(edge[i].v);
        if(u!=v)
        {
            cnt++;
            par[u]=v;
            sum+=edge[i].w;
            temp.pb(edge[i]);
            if(cnt==n-1)
            break;
        }
    }
    edge.clear();
    edge=temp;
    if(cnt==n-1) return sum;
    return -1;
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
        PRINT_CASE;
        while(m--)
        {
            int x,y,z;
            sfff(x,y,z);
            edge.pb(data(x,y,z));
            loop(i,n+5)
            par[i]=i;
            pf("%d\n",mst());
        }
        edge.clear();
    }
    return 0;
}
