/////*
////         +-+ +-+ +-+
////         |R| |.| |S|
////         +-+ +-+ +-+
//// */
////
////#include <bits/stdc++.h>
////
////#define pii             pair <int,int>
////#define sc              scanf
////#define pf              printf
////#define Pi              2*acos(0.0)
////#define ms(a,b)         memset(a, b, sizeof(a))
////#define pb(a)           push_back(a)
////#define MP              make_pair
////#define db              double
////#define ll              long long
////#define EPS             10E-10
////#define ff              first
////#define ss              second
////#define sqr(x)          (x)*(x)
////#define D(x)            cout<<#x " = "<<(x)<<endl
////#define VI              vector <int>
////#define DBG             pf("Hi\n")
////#define MOD             100007
////#define MAX             10000
////#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
////#define SZ(a)           (int)a.size()
////#define sf(a)           scanf("%d",&a)
////#define sff(a,b)        scanf("%d%d",&a,&b)
////#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
////#define loop(i,n)       for(int i=0;i<n;i++)
////#define REP(i,a,b)      for(int i=a;i<b;i++)
////#define TEST_CASE(t)    for(int z=1;z<=t;z++)
////#define PRINT_CASE      printf("Case %d: ",z)
////#define all(a)          a.begin(),a.end()
////#define intlim          2147483648
////#define inf             1000000
////#define ull             unsigned long long
////
////using namespace std;
////
////
/////*----------------------Graph Moves----------------*/
//////const int fx[]={+1,-1,+0,+0};
//////const int fy[]={+0,+0,+1,-1};
//////const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//////const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//////const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//////const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/////*------------------------------------------------*/
////
/////*-----------------------Bitmask------------------*/
////int Set(int N,int pos){return N=N | (1<<pos);}
////int reset(int N,int pos){return N= N & ~(1<<pos);}
////bool check(int N,int pos){return (bool)(N & (1<<pos));}
/////*------------------------------------------------*/
////
////char s1[102],s2[102];
////int dp[102][102],len;
////bool visited[102][102];
////vector<string>v;
////string ans;
////map<string,bool>mp;
////
////int func_LCS(int i, int j)
////{
////    if(s1[i]=='\0' || s2[j]=='\0') return 0;
////    int &ret=dp[i][j];
////    if(ret!=-1) return ret;
////    int ans=0;
////    if(s1[i]==s2[j]) ans=1+func_LCS(i+1,j+1);
////    else
////    {
////        ans=max(func_LCS(i+1,j),func_LCS(i,j+1));
////    }
////    return ret=ans;
////}
////
////void find_LCS(int i, int j)
////{
////    D(i);D(j);
////    if(s1[i]=='\0' || s2[j]=='\0')
////    {
////       // D(ans);
////        if(SZ(ans)==len)
////        v.pb(ans);
////        return;
////    }
//////    if(visited[i][j]) return;
//////    visited[i][j]=1;
////
////    if(s1[i]==s2[j])
////    {
////        ans+=s1[i];
////       // if(!mp[ans])
////        find_LCS(i+1,j+1);
////        ans.erase(ans.end()-1);
////    }
////    else
////    {
////        if(dp[i+1][j]>dp[i][j+1]) find_LCS(i+1,j);
////        else if(dp[i+1][j]<dp[i][j+1]) find_LCS(i,j+1);
////        else
////        {
////            find_LCS(i+1,j);
////            find_LCS(i,j+1);
////        }
////    }
////}
////
////int main()
////{
////    ///freopen("in.txt","r",stdin);
////    freopen("out.txt","w",stdout);
////    int t;
////    sf(t);
////    TEST_CASE(t)
////    {
////        getchar();
////        sc("%s %s",s1,s2);
////        ms(dp,-1);
////        ms(visited,0);
////        len=func_LCS(0,0);
////        PRINT_CASE;
////        if(len==0) {pf(":(\n");continue;}
////        v.clear();
////        ans.clear();
////        mp.clear();
////       // D(len);
////        find_LCS(0,0);
////        sort(all(v));
////        //D(SZ(v));
////        cout<<v[0]<<endl;
////    }
////    return 0;
////}
//
//
//


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


/*----------------------Graph Moves----------------*/
//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
//const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
//const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move
/*------------------------------------------------*/

/*-----------------------Bitmask------------------*/
int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

char s1[105],s2[105];
int dp[105][105];
string ans[105][105];
int n,m;

void LCS()
{
    loop(i,n+2)
    {
        dp[i][0]=0;
        ans[i][0]="";
    }
    loop(i,m+2)
    {
        dp[0][i]=0;
        ans[0][i]="";
    }

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(s1[i-1]==s2[j-1])
        {
            dp[i][j]=dp[i-1][j-1]+1;
            ans[i][j]=ans[i-1][j-1]+s1[i-1];
        }
        else if(dp[i-1][j]>dp[i][j-1])
        {
            dp[i][j]=dp[i-1][j];
            ans[i][j]=ans[i-1][j];
        }
        else if(dp[i][j-1]>dp[i-1][j])
        {
            dp[i][j]=dp[i][j-1];
            ans[i][j]=ans[i][j-1];
        }
        else
        {
            dp[i][j]=dp[i-1][j];
            ans[i][j]=min(ans[i-1][j],ans[i][j-1]);
        }
    }
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {
        getchar();
        sc("%s %s",s1,s2);
        n=strlen(s1);
        m=strlen(s2);
        LCS();
        PRINT_CASE;
        if(dp[n][m]==0)
            pf(":(\n");
        else
            cout<<ans[n][m]<<endl;
    }
    return 0;
}
