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
#define CASE_PRINT      cout<<"Case "<<z<<": ";
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




int base,k,len,O_O;
string str;


ll dp[1<<16][21];
int state[1<<16][21];



int bigmod(int n, int pow,int mod)
{
    if(pow==0) return 1;
    else if(pow==1) return n;

    if(pow & 1)
    {
        return ((n%mod)*(bigmod(n,pow-1,mod))%mod)%mod;
    }
    else
    {
        ll temp=bigmod(n,pow/2,mod);
        return ((temp%mod)*(temp%mod))%mod;
    }
}

int digit(int i)
{
    if(str[i]>='0' && str[i]<='9') return str[i]-'0';
    else
        return 10+str[i]-'A';
}


ll call(int mask, int mod)
{
    int on_bit=__builtin_popcount(mask);
    if(on_bit==len)
    {
        if(mod==0) return 1;
        return 0;
    }

    ll &ret=dp[mask][mod];
    int &vis=state[mask][mod];
    if(vis==O_O) return ret;
    vis=O_O;

    ll temp=0;

    for(int i=0;i<len;i++)
    {
        if(!check(mask,i))
        {
//            D(bigmod(base,on_bit));
//            D(digit(i));
            temp+=call(Set(mask,i),(mod+digit(i)*bigmod(base,on_bit,k))%k);
        }
    }
    return ret=temp;
//    return temp;

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
        O_O=z;
        cin>>base>>k;
        cin>>str;
        len=SZ(str);
        CASE_PRINT;
        cout<<call(0,0)<<endl;
    }
    return 0;
}
