/*
MMP""MM""YMM   db      `7MN.   `7MF'`7MMM.     ,MMF' .g8""8q.`YMM'   `MM'
P'   MM   `7  ;MM:       MMN.    M    MMMb    dPMM .dP'    `YM.VMA   ,V
     MM      ,V^MM.      M YMb   M    M YM   ,M MM dM'      `MM VMA ,V
     MM     ,M  `MM      M  `MN. M    M  Mb  M' MM MM        MM  VMMP
     MM     AbmmmqMA     M   `MM.M    M  YM.P'  MM MM.      ,MP   MM
     MM    A'     VML    M     YMM    M  `YM'   MM `Mb.    ,dP'   MM
   .JMML..AMA.   .AMMA..JML.    YM  .JML. `'  .JMML. `"bmmd"'   .JMML.
*/


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <map>

#define pii pair <int,int>
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define oo 1<<29
#define dd double
#define ll long long
#define EPS 10E-10
#define ff first
#define ss second
#define MAX 120
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define loop(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 100000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int

using namespace std;

struct data
{
    I city,dist;
    bool operator < (const data& p) const
    {
        return dist>p.dist;
    }
};
vector <I> edge[MAX],cost[MAX];
int d[MAX];

int dijkstra(int src,int n)
{
    loop(i,MAX)
        d[i]=inf;
    d[src]=0;
    priority_queue <data> Q;
    data u,v;
    u.city=src;
    u.dist=d[src];
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();
        if(u.city==n)
            return d[u.city];
        for(int i=0;i<edge[u.city].size();i++)
        {
            v.city=edge[u.city][i];
            v.dist=cost[u.city][i]+d[u.city];
            if(d[v.city]>v.dist)
            {
                d[v.city]=v.dist;
                Q.push(v);
            }
        }
    }
    return d[n];
}
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    I n,m,t,u,v,w;
    getint(t);
    loop(z,t)
    {

        getint(n);
        getint(m);
        while(m--)
        {
            getint(u);
            getint(v);
            getint(w);
            edge[u].pb(v);
            cost[u].pb(w);
            edge[v].pb(u);
            cost[v].pb(w);
        }
       I ans=dijkstra(1,n);
        if(ans==inf)
            pf("Case %d: Impossible\n",z+1);
        else
            pf("Case %d: %d\n",z+1,ans);
        loop(i,n+2)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
