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


const int fx[]={+1,-1,+0,+0};
const int fy[]={+0,+0,+1,-1};

char graph[502][502];
int dp[502][502];
bool visited[502][502];
bool dpvisited[502][502];
int n,m,cnt;

bool test(int x, int y)
{
    if(visited[x][y] || x<0 || x>=n || y<0 || y>=m || graph[x][y]=='#') return 1;
    return 0;
}

bool dptest(int x, int y)
{
    if(dpvisited[x][y] || x<0 || x>=n || y<0 || y>=m || graph[x][y]=='#') return 1;
    return 0;
}

void dfs1(int x, int y)
{
    if(test(x,y)) return;
    visited[x][y]=1;
    if(graph[x][y]=='C')
        cnt++;
    loop(i,4)
    dfs1(x+fx[i],y+fy[i]);
}

void dfs2(int x, int y)
{
        if(dptest(x,y)) return;
        dpvisited[x][y]=1;
        dp[x][y]=cnt;
        loop(i,4)
        dfs2(x+fx[i],y+fy[i]);
}

void allclear()
{
    loop(i,n) loop(j,m)
    {
        visited[i][j]=dpvisited[i][j]=0;
        dp[i][j]=-1;
    }
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t,p,q,k;
    sf(t);
    TEST_CASE(t)
    {
        sfff(n,m,k);
        getchar();
        allclear();
        loop(i,n)
        gets(graph[i]);
        PRINT_CASE;
        while(k--)
        {
            sff(p,q);
            p--;q--;
            if(graph[p][q]=='#')
            {
                pf("0\n");
                continue;
            }
            else if(visited[p][q])
            {
                pf("%d\n",dp[p][q]);
            }
            else
            {
                cnt=0;
                dfs1(p,q);
                dfs2(p,q);
                pf("%d\n",dp[p][q]);
            }
        }
    }
    return 0;
}
