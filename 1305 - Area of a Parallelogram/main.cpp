/*
MMP""MM""YMM   db      `7MN.   `7MF'`7MMM.     ,MMF' .g8""8q.`YMM'   `MM'
P'   MM   `7  ;MM:       MMN.    M    MMMb    dPMM .dP'    `YM.VMA   ,V
     MM      ,V^MM.      M YMb   M    M YM   ,M MM dM'      `MM VMA ,V
     MM     ,M  `MM      M  `MN. M    M  Mb  M' MM MM        MM  VMMP
     MM     AbmmmqMA     M   `MM.M    M  YM.P'  MM MM.      ,MP   MM
     MM    A'     VML    M     YMM    M  `YM'   MM `Mb.    ,dP'   MM
   .JMML..AMA.   .AMMA..JML.    YM  .JML. `'  .JMML. `"bmmd"'   .JMML.
*/

#include <bits/stdc++.h>

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
#define MAX 10000
#define SZ(a) (int)a.size()
#define getint(a) scanf("%d",&a)
#define loop(i,n) for(int i=0;i<n;i++)
#define TEST_CASE(t) for(int z=1;z<=t;z++)
#define PRINT_CASE printf("Case %d: ",z)
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define inf 1000000
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int

using namespace std;

/* Bits operation */
int Set(int n,int pos)  { return n = n | 1<<pos;}
bool check(int n,int pos) { return n & 1<<pos;}
int Reset(int n, int pos) { return n=n & ~(1<<pos);}

struct point
{
    int x,y;
};
int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    point a,b,c,d;
    int t;
    getint(t);
    TEST_CASE(t)
    {
        cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
        d.x=a.x+c.x-b.x;
        d.y=a.y+c.y-b.y;
        int cc1=-(a.x*(b.y-a.y)-a.y*(b.x-a.x));
        int cc2=-(c.x*(b.y-a.y)-c.y*(b.x-a.x));
        int ccc=abs(cc1-cc2);
        double ddd=(ccc*1.0)/sqrt(((b.y-a.y)*(b.y-a.y))*1.0+(-(b.x-a.x)*-(b.x-a.x))*1.0);
        double qqq=sqrt(1.0*(b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y)*1.0);
        PRINT_CASE;
        cout<<d.x<<" "<<d.y<<" ";
        pf("%0.0f\n",ddd*qqq);
    }
    return 0;
}
