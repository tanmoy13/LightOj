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
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int

using namespace std;

struct edge
{
    string u,v;
    int w;
    bool operator<(const edge& p) const
    {
        return w<p.w;
    }
};

vector<edge>v;
int pr[MAX],cnt=0;
map <string,int>mp;

int find(int r)
{
    return pr[r]=(pr[r]==r)?r:find(pr[r]);
}


int kruskal(int n)
{
    sort(all(v));
    edge p;
    int s=0;
    cnt=0;
    int l=v.size();
    for(int i=1; i<=n; i++)
        pr[i]=i;
    for(int i=0; i<l; i++)
    {
        p=v[i];
        int x=find(mp[p.u]);
        int y=find(mp[p.v]);
        if(x!=y)
        {
            pr[x]=y;
            cnt++;
            s+=p.w;
            if(cnt==n-1)
                break;
        }
    }
    return s;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int n,m,z=1,t;
    cin>>t;
    for(int e=1;e<=t;e++)
    {
        z=1;
    cin>>m;
    getchar();
    edge p;
    while(m--)
    {
        cin>>p.u>>p.v>>p.w;
        v.push_back(p);
        if(mp[p.u]==0)
        {
            mp[p.u]=z++;
        }
        if(mp[p.v]==0)
        {
            mp[p.v]=z++;
        }
    }
    int ans=kruskal(--z);
    if(cnt!=z-1)
        cout<<"Case "<<e<<": "<<"Impossible"<<endl;
    else
        cout<<"Case "<<e<<": "<<ans<<endl;
        v.clear();
        mp.clear();
    }
    return 0;
}
