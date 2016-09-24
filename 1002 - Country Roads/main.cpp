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
#define MAX 1000
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define loop(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define inf 100000
#define I int

using namespace std;

vector <I> edge[MAX],cost[MAX];

struct data
{
    int city,dist;
    bool operator < (const data& p) const
    {
        return dist > p.dist;
    }
};


I d[MAX];

void dijkstra(I src)
{
    loop(h,MAX)
        d[h]=inf;
    d[src]=0;
    data u,k;
    u.city=src;
    u.dist=0;
    priority_queue <data> Q;
    Q.push(u);
    while(!Q.empty())
    {
        u=Q.top();
        Q.pop();
        I t_cost=d[u.city];
        I l=edge[u.city].size();
        loop(i,l)
        {
            k.city=edge[u.city][i];
            k.dist=max(t_cost,cost[u.city][i]);
            if(d[k.city]>k.dist)
            {
                d[k.city]=k.dist;
                Q.push(k);
            }
        }
    }
}
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    I t,n,m,u,p,w,sr;
    getint(t);
    loop(z,t)
    {
        getint(n);
        getint(m);
        while(m--)
        {
            getint(u);
            getint(p);
            getint(w);
            edge[u].pb(p);
            edge[p].pb(u);
            cost[u].pb(w);
            cost[p].pb(w);
        }
        getint(sr);
        dijkstra(sr);
        pf("Case %d:\n",z+1);
        loop(i,n)
        {
            if(d[i]==inf)
                pf("Impossible\n");
            else
                pf("%d\n",d[i]);
        }
        loop(i,n)
        {
            edge[i].clear();
            cost[i].clear();
        }
    }
    return 0;
}
