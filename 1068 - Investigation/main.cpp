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
//int Set(int N,int pos){return N=N | (1<<pos);}
//int reset(int N,int pos){return N= N & ~(1<<pos);}
//bool check(int N,int pos){return (bool)(N & (1<<pos));}
/*------------------------------------------------*/

int digit[15],dig_len,casino;

ll dp[12][100][100][2];
int state[12][100][100][2];

int a,b,k;


ll DP(int i, int num_mod,int sum_mod,int small)
{
    if(i>=dig_len)
    {
        if(num_mod==0 && sum_mod==0) return 1;
        return 0;
    }
    ll &ret=dp[i][num_mod][sum_mod][small];
    int &stt=state[i][num_mod][sum_mod][small];


    if(stt==casino) return ret;
    stt=casino;
    ret=0;

    for(int j=0; j<digit[i]; j++)
    {
        ret+=DP(i+1,((num_mod*10)+j)%k,(sum_mod+j)%k,1);
    }

    ret+=DP(i+1,((num_mod*10)+digit[i])%k,(sum_mod+digit[i])%k,small);

    if(small)
        for(int j=digit[i]+1; j<10; j++)
            ret+=DP(i+1,((num_mod*10)+j)%k,(sum_mod+j)%k,small);
    return ret;
}

ll calculator(int n)
{
    casino++;
//    ms(dp,-1);
    dig_len=0;
    while(n)
    {
        digit[dig_len++]=n%10;
        n/=10;
    }
    reverse(digit,digit+dig_len);

    return DP(0,0,0,0);
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    casino=0;
    int t;
    sf(t);
    TEST_CASE(t)
    {

        sfff(a,b,k);
        PRINT_CASE;
        if(k>=99)
        {
            pf("%d\n",0);
            continue;
        }

        pf("%lld\n",calculator(b)-calculator(a-1));
    }
    return 0;
}
