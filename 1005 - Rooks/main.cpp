///*
//MMP""MM""YMM   db      `7MN.   `7MF'`7MMM.     ,MMF' .g8""8q.`YMM'   `MM'
//P'   MM   `7  ;MM:       MMN.    M    MMMb    dPMM .dP'    `YM.VMA   ,V
//     MM      ,V^MM.      M YMb   M    M YM   ,M MM dM'      `MM VMA ,V
//     MM     ,M  `MM      M  `MN. M    M  Mb  M' MM MM        MM  VMMP
//     MM     AbmmmqMA     M   `MM.M    M  YM.P'  MM MM.      ,MP   MM
//     MM    A'     VML    M     YMM    M  `YM'   MM `Mb.    ,dP'   MM
//   .JMML..AMA.   .AMMA..JML.    YM  .JML. `'  .JMML. `"bmmd"'   .JMML.
//*/
//
//
//#include <iostream>
//#include <cstdio>
//#include <cmath>
//#include <cstring>
//#include <algorithm>
//#include <cstdlib>
//#include <vector>
//#include <sstream>
//#include <set>
//#include <queue>
//#include <stack>
//#include <list>
//#include <string>
//#include <map>
//
//#define pii pair <int,int>
//#define sc scanf
//#define pf printf
//#define Pi 2*acos(0.0)
//#define ms(a,b) memset(a, b, sizeof(a))
//#define pb(a) push_back(a)
//#define MP make_pair
//#define oo 1<<29
//#define dd double
//#define ll long long
//#define EPS 10E-10
//#define ff first
//#define ss second
//#define MAX 100
//#define SZ(a) (int)a.size()
//#define getint(a) scanf("%d",&a)
//#define loop(i,n) for(int i=0;i<n;i++)
//#define all(a) a.begin(),a.end()
//#define intlim 2147483648
//#define inf 1000000
//#define rtintlim 46340
//#define llim 9223372036854775808
//#define rtllim 3037000499
//#define ull unsigned long long
//#define I int
//
//using namespace std;
//
//ll dp[100][100];
//ull dp1[100][100];
//
//ll nCr(int n, int r)
//{
//    if(r>n) return 0;
//    if(r==1) return n;
//    if(n==r) return 1;
//    ll &rfr=dp[n][r];
//    if(rfr!=-1)
//        return rfr;
//    return rfr=nCr(n-1,r)+nCr(n-1,r-1);
//}
//
//
////ll nPr(int n, int r)
////{
////    if(r>n) return 0;
////    if(r==1) return n;
////    ll &rfr=dp1[n][r];
////    if(rfr!=-1)
////        return rfr;
////    return rfr=(n-r+1)*nPr(n,r-1);
////}
//
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int n,r;
//    ms(dp,-1);
//    //ms(dp1,-1);
//    for(int i=0;i<=50;i++)
//        dp1[i][0]=1;
//
//    for(int i=1;i<=50;i++)
//    {
//        for(int j=1,k=i;j<=i;j++,k--)
//            dp1[i][j]=k*dp1[i][j-1];
//    }
//    //cout<<dp1[5][2]<<endl;
//    int t,cases=0;
//    cin>>t;
//    while(t--)
//    {
//        cin>>n>>r;
//        cout<<"Case "<<++cases<<": "<<nCr(n,r)*dp1[n][r]<<endl;
//    }
//    return 0;
//}
//
//
///*
//nPr=n*(n-1)*(n-2)*...*(n-r+1);
//*/



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
#define MAX             32
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sfl(a)          scanf("%lld",&a)
#define sff(a,b)        scanf("%d %d",&a,&b)
#define sffl(a,b)       scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long

using namespace std;


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

ll dp[MAX][MAX][MAX*MAX];
int n,m;
bool visited
ll func(int i, int j, int n)
{
    if(i>=n || j>=m) return 0;
    if(n==m) return 1;

    ll &ret=dp[i][j][n];
    if(ret!=-1) return ret;
    ll ans=0;
    ans+=func(i+1,j,n+1);

}
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        ms(dp,-1);
        sff(n,m);
        cout<<func(0,0,0)<<endl;
    }
    return 0;
}
