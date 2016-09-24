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

int dp[52][52][52];
int state[52][52][52];

string str;

int kk;
bool mixed;
bool test(char ch)
{
    if(ch=='A' || ch=='E' ||ch== 'I'||ch== 'O'||ch== 'U') return 1;
    return 0;

}

int call(int i, int con, int vio)
{
    if(i==SZ(str))
    {
        if(con<5 && vio<3)
        {
            mixed=1;
            return 0;
        }
        if(con>=5 || vio>=3) return 1;
    }

    int &ret=dp[i][con][vio];
    int &st=state[i][con][vio];

    if(st==kk) return ret;
    st=kk;

    int temp=0;

    if(str[i]=='?')
    {

        if(con<5)
        temp=max(temp,call(i+1,0,vio+1));
        else
            temp=max(temp,call(i+1,con,vio+1));

//        temp%=100;

        if(vio<3)
            temp=max(temp,call(i+1,con+1,0));
        else
            temp=max(temp,call(i+1,con+1,vio));

//        temp%=100;

    }

   else if(test(str[i]))
    {
        if(con<5)
        temp=max(temp,call(i+1,0,vio+1));
        else
            temp=max(temp,call(i+1,con,vio+1));
//        temp%=100;
    }
    else
    {
        if(vio<3)
            temp=max(temp,call(i+1,con+1,0));
        else
            temp=max(temp,call(i+1,con+1,vio));
//        temp%=100;
    }


//     cout<<i<<" "<<con<<" "<<vio<<" "<<temp<<endl;
    return ret=temp;

}

int main()
{
//    CIN;
//    freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    cin>>t;
    TEST_CASE(t)
    {
        mixed=0;
        kk++;
        cin>>str;
        int xx=call(0,0,0);
        CASE_PRINT;
        if(xx && mixed)
            cout<<"MIXED"<<endl;
        else if(xx)
            cout<<"BAD"<<endl;
        else
            cout<<"GOOD"<<endl;
    }

    return 0;
}
