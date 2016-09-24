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
//#define MAX             10000
//#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)           (int)a.size()
//#define sf(a)           scanf("%d",&a)
//#define sfl(a)          scanf("%lld",&a)
//#define sff(a,b)        scanf("%d %d",&a,&b)
//#define sffl(a,b)       scanf("%lld %lld",&a,&b)
//#define sfff(a,b,c)     scanf("%d %d %d",&a,&b,&c)
//#define sfffl(a,b,c)    scanf("%lld %lld %lld",&a,&b,&c)
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
//
///*----------------------Graph Moves----------------*/
////const int fx[]={+1,-1,+0,+0};
////const int fy[]={+0,+0,+1,-1};
////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
////const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
////const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
///*------------------------------------------------*/
//
///*-----------------------Bitmask------------------*/
////int Set(int N,int pos){return N=N | (1<<pos);}
////int reset(int N,int pos){return N= N & ~(1<<pos);}
////bool check(int N,int pos){return (bool)(N & (1<<pos));}
///*------------------------------------------------*/
//
//int n,m;
//int dp[150][150][150];
//
//int grid[150][150];
//
//int call(int i, int j, int x)
//{
//    if(i>=n || j>=m || x>=n || (i+j-x)>=m) return 0;
//    if(i==x && !(i==0 && j==0) && !(i==n-1 && j==m-1)) return -1000000000;
//    int &ret=dp[i][j][x];
//    if(ret!=-1) return ret;
//
//    if(i==0 && j==0 && x==0)
//    {
//        return ret=max(max(call(i+1,j,x+1),call(i+1,j,x)),max(call(i,j+1,x+1),call(i,j+1,x)))+grid[i][j];
//    }
//    else if(i==n-1 && j==m-1 && x==i)
//    {
//        return ret=max(max(call(i+1,j,x+1),call(i+1,j,x)),max(call(i,j+1,x+1),call(i,j+1,x)))+grid[i][j];
//    }
//    else
//        return ret=max(max(call(i+1,j,x+1),call(i+1,j,x)),max(call(i,j+1,x+1),call(i,j+1,x)))+grid[i][j]+grid[x][(i+j)-x];
//}
//
//int main()
//{
//    CIN;
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int t;
//    cin>>t;
//    TEST_CASE(t)
//    {
////        ms(grid,0);
//        cin>>n>>m;
//        loop(i,n) loop(j,m) cin>>grid[i][j];
//
//        ms(dp,-1);
//
//        cout<<"Case "<<z<<": ";
////        PRINT_CASE;
//        cout<<call(0,0,0)<<endl;
//    }
//    return 0;
//}


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

int n,m;
int dp[105][105][105];

int grid[105][105];

int call(int r1, int c1, int r2)
{
    if(r1>=n || c1>=m || r2>=n || (r1+c1-r2)>=m) return 0;
    int c2=(r1+c1-r2);

    int &ret= dp[r1][c1][r2];
    if(ret!=-1) return ret;

    if(r1==r2 && c1==c2)
    {
        if(r1==0 && c1==0 && r2==0)
        {
//            return ret=max(max(call(r1+1,c1,r2),call(r1+1,c1,r2+1)),max(call(r1,c1+1,r2),call(r1,c1+1,r2+1)))+grid[r1][c1];
            return ret=max(call(r1+1,c1,r2),call(r1,c1+1,r2+1))+grid[0][0];
        }
        else if(r1==n-1 && c1==m-1 && r2==n-1)
        {
            return ret=max(call(r1+1,c1,r2),call(r1,c1+1,r2+1))+grid[n-1][m-1];
        }
        else
            return -100000000;
    }
    return ret=max(max(call(r1+1,c1,r2),call(r1+1,c1,r2+1)),max(call(r1,c1+1,r2),call(r1,c1+1,r2+1)))+grid[r1][c1]+grid[r2][c2];
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    CIN;
    int t;
    cin>>t;
    TEST_CASE(t)
    {
//        ms(grid,0);
        cin>>n>>m;
        loop(i,n) loop(j,m) cin>>grid[i][j];

        ms(dp,-1);

        cout<<"Case "<<z<<": ";
//        PRINT_CASE;
        cout<<call(0,0,0)<<endl;
    }
    return 0;
}


