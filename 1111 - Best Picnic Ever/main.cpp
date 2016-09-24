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
#define MAX             1010
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

vector<int>v[MAX],people;
int dfs_cnt[MAX];
bool visited[MAX];
int n,k,ans;

void clr()
{
    loop(i,n+1)
    {
        v[i].clear();
        dfs_cnt[i]=0;
    }
}

void dfs(int x)
{
    visited[x]=1;
    dfs_cnt[x]++;
    if(dfs_cnt[x]==k)
        ans++;
    loop(i,SZ(v[x]))
    {
        int u=v[x][i];
        if(!visited[u])
            dfs(u);
    }
}


int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t,m,temp;
    sf(t);
    TEST_CASE(t)
    {
        sfff(k,n,m);

        loop(i,k)
        {
            sf(temp);
            people.pb(temp);
        }

        int a,b;

        loop(i,m)
        {
            sff(a,b);
            v[a].pb(b);
        }

        ans=0;

        loop(j,SZ(people))
        {
            loop(i,n+2)
                visited[i]=0;
            dfs(people[j]);
        }


        PRINT_CASE;
        pf("%d\n",ans);
        clr();
        people.clear();
    }
    return 0;
}
