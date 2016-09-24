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

string str;
int n;

bool ispal[1005][1005];

//BABAB

bool generate_pal()
{
    loop(i,n)
    {
      ispal[i][i]=1;
    }

    for(int i=0;i<n-1;i++)
        ispal[i][i+1]=(str[i]==str[i+1]);

    for(int len=3;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
             ispal[i][i+len-1]= ((str[i]==str[i+len-1]) && ispal[i+1][i+len-2]);

    }
}

int dp[1005];

int call(int i)
{
    if(i>=n) return 0;
    if(dp[i]!=-1) return dp[i];

    int x=INT_MAX;
    for(int j=i;j<n;j++)
        if(ispal[i][j])
        x=min(x,call(j+1)+1);
    return dp[i]=x;
}

int main()
{
    CIN;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    TEST_CASE(t)
    {
        cin>>str;
        n=SZ(str);
        ms(dp,-1);
        generate_pal();
//        int xx;
//        cin>>xx;
//        while(xx--)
//        {
//            int a,b;
//            cin>>a>>b;
//
//            if(ispal[a][b]) cout<<"YES"<<endl;
//            else cout<<"NO"<<endl;
//        }

        cout<<"Case "<<z<<": ";
        cout<<call(0)<<endl;
    }


    return 0;
}
