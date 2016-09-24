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
#define MAX 100
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define loop(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 1000000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int
#define mod 100000007



#define rep(i,n) for(int i=0; i<(int)n; i++)
#define repv(i,n) for(int i=n-1; i>=0; i--)
#define repl(i,n) for(int i=1; i<=(int)n; i++)
#define replv(i,n) for(int i=n; i>=1; i--)

#define sdi(x) scanf("%d",&x)
#define sdii(x,y) scanf("%d%d",&x,&y)
#define SDs(x) scanf("%s",x)

using namespace std;
//int n,k;
//int dp[52][1010];
//int coin[200],num_coin[200];
//
//int coin_change(int indx, int cur)
//{
//    if(indx==n)
//    {
//        if(cur==k) return 1;
//        return 0;
//    }
//    if(cur>k) return 0;
//    if(cur==k)return 1;
//    int &rfr=dp[indx][cur];
//    if(rfr!=-1) return rfr;
//    int ans=0;
//    for(int i=0; i<=num_coin[indx]; i++)
//    {
//        ans=(ans+coin_change(indx+1,cur+coin[indx]*(i)))%mod;
//    }
//    rfr=ans;
//    return rfr;
//}
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int t;
//    cin>>t;
//    for(int z=1; z<=t; z++)
//    {
//        ms(dp,-1);
//        cin>>n>>k;
//        for(int i=0; i<n; i++)
//            cin>>coin[i];
//        for(int i=0; i<n; i++)
//            cin>>num_coin[i];
//        cout<<"Case "<<z<<": "<<coin_change(0,0)<<endl;
//    }
//    return 0;
//}


int c[200],a[200];
int n,k;
int dp[1003][51];
int MOD=100000007;
int call(int amount,int idx)
{
        if(idx>n)
        {
                if(amount==k) return 1;
                return 0;
        }

        if(amount>k) return 0;
        if(amount==k) return 1;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int ret=0;

        for(int take=1;take<=c[idx];take++)
        {
            if(amount+a[idx]*take<=k)
                ret+=call(amount+a[idx]*take,idx+1)%MOD;
                else break;
        }
        ret+=call(amount,idx+1)%MOD;
        return dp[amount][idx]=ret%MOD;

}
int main()
{
        //READ("in");
        int t,kas=0;
        cin>>t;
        while(t--)
        {
                ms(dp,-1);
                cin>>n>>k;
                repl(i,n)sdi(a[i]);
                repl(i,n)sdi(c[i]);
                int ret=call(0,1)%MOD;
                printf("Case %d: %d\n",++kas,ret);
        }
}
