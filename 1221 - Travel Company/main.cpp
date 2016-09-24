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
#define MAX             105
#define CIN             ios_base::sync_with_stdio(0)
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

vector<int>from,to,cost;
int d[MAX];

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n,r,p;
        sfff(n,r,p);
        int a,b,income,expence;
        loop(i,r)
        {
            sc("%d %d %d %d",&a,&b,&income,&expence);
            from.pb(a);
            to.pb(b);
            cost.pb(p*expence-income);
        }

        bool test=0;
        for(int j=1;j<=n;j++)
        {
            for(int i=0;i<r;i++)
            {
                int temp=d[from[i]]+cost[i];
                if(temp<d[to[i]])
                {
                    if(j==n) test=1;
                    d[to[i]]=temp;
                }
            }
        }

        PRINT_CASE;
        if(test)
            pf("YES\n");
        else
            pf("NO\n");

        ms(d,0);
        from.clear();
        to.clear();
        cost.clear();
    }
    return 0;
}

//
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
//#define MAX             105
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
//int graph[MAX][MAX];
//
//void allclear(int n)
//{
//    for(int i=0; i<n+2; i++)
//    {
//        for(int j=0; j<=n+2; j++)
//        {
//            graph[i][j]=inf;
//        }
//        graph[i][i]=0;
//    }
//}
//
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int t;
//    sf(t);
//    TEST_CASE(t)
//    {
//        int n,r,p;
//        sfff(n,r,p);
//        allclear(n);
//        int a,b,income,expence;
//        loop(i,r)
//        {
//            sc("%d %d %d %d",&a,&b,&income,&expence);
//            graph[a][b]=p*expence-income;
//        }
//
//        REP(k,0,n) REP(i,0,n) REP(j,0,n) graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
//        bool negative_cycle=0;
//        REP(i,0,n)
//        if(graph[i][i]<0)
//            negative_cycle=1;
//        PRINT_CASE;
//        if(negative_cycle)
//            pf("YES\n");
//        else
//            pf("NO\n");
//    }
//    return 0;
//}
