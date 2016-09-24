///*
//     If opportunity doesn't knock, build a door.
//
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//            |S|.|S|.|R|.|A|.|S|.|A|.|M|.|K|
//            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
//
//    Success is how high you bounce when you hit bottom.
//*/
//
//
//#include <bits/stdc++.h>
//
//#define pii              pair <int,int>
//#define pll              pair <long long,long long>
//#define sc               scanf
//#define pf               printf
//#define Pi               2*acos(0.0)
//#define ms(a,b)          memset(a, b, sizeof(a))
//#define pb(a)            push_back(a)
//#define MP               make_pair
//#define db               double
//#define ll               long long
//#define EPS              10E-10
//#define ff               first
//#define ss               second
//#define sqr(x)           (x)*(x)
//#define D(x)             cout<<#x " = "<<(x)<<endl
//#define VI               vector <int>
//#define DBG              pf("Hi\n")
//#define MOD              1000000007
//#define CIN              ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)            (int)a.size()
//#define sf(a)            scanf("%d",&a)
//#define sfl(a)           scanf("%lld",&a)
//#define sff(a,b)         scanf("%d %d",&a,&b)
//#define sffl(a,b)        scanf("%lld %lld",&a,&b)
//#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
//#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
//#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
//#define loop(i,n)        for(int i=0;i<n;i++)
//#define REP(i,a,b)       for(int i=a;i<b;i++)
//#define RREP(i,a,b)      for(int i=a;i>=b;i--)
//#define TEST_CASE(t)     for(int z=1;z<=t;z++)
//#define PRINT_CASE       printf("Case %d: ",z)
//#define CASE_PRINT       cout<<"Case "<<z<<": "
//#define all(a)           a.begin(),a.end()
//#define intlim           2147483648
//#define infinity         (1<<28)
//#define ull              unsigned long long
//#define gcd(a, b)        __gcd(a, b)
//#define lcm(a, b)        ((a)*((b)/gcd(a,b)))
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
//int main()
//{
//
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//
//    int t;
//    sf(t);
//    TEST_CASE(t)
//    {
//        ll n;
//        sfl(n);
//        ll ans=sqrt(n);
//        ans+=sqrt(n/2);
//        PRINT_CASE;
//        printf("%lld\n",n-ans);
//    }
//
//    return 0;
//}


/*
     If opportunity doesn't knock, build a door.

            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
            |S|.|S|.|R|.|A|.|S|.|A|.|M|.|K|
            +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

    Success is how high you bounce when you hit bottom.
*/


#include <bits/stdc++.h>

#define pii              pair <int,int>
#define pll              pair <long long,long long>
#define sc               scanf
#define pf               printf
#define Pi               2*acos(0.0)
#define ms(a,b)          memset(a, b, sizeof(a))
#define pb(a)            push_back(a)
#define MP               make_pair
#define db               double
#define ll               long long
#define EPS              10E-10
#define ff               first
#define ss               second
#define sqr(x)           (x)*(x)
#define D(x)             cout<<#x " = "<<(x)<<endl
#define VI               vector <int>
#define DBG              pf("Hi\n")
#define MOD              1000000007
#define CIN              ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)            (int)a.size()
#define sf(a)            scanf("%d",&a)
#define sfl(a)           scanf("%lld",&a)
#define sff(a,b)         scanf("%d %d",&a,&b)
#define sffl(a,b)        scanf("%lld %lld",&a,&b)
#define sfff(a,b,c)      scanf("%d %d %d",&a,&b,&c)
#define sfffl(a,b,c)     scanf("%lld %lld %lld",&a,&b,&c)
#define stlloop(v)       for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define loop(i,n)        for(int i=0;i<n;i++)
#define REP(i,a,b)       for(int i=a;i<b;i++)
#define RREP(i,a,b)      for(int i=a;i>=b;i--)
#define TEST_CASE(t)     for(int z=1;z<=t;z++)
#define PRINT_CASE       printf("Case %d: ",z)
#define CASE_PRINT       cout<<"Case "<<z<<": "
#define all(a)           a.begin(),a.end()
#define intlim           2147483648
#define infinity         (1<<28)
#define ull              unsigned long long
#define gcd(a, b)        __gcd(a, b)
#define lcm(a, b)        ((a)*((b)/gcd(a,b)))

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

vector<ll>v;

void process()
{
    ll maxn=1E12;
    for(ll i=1;i*i<=maxn;i+=2)
    {
        ll temp=i*i;
        for(ll j=1;j*temp<=maxn;j<<=1)
            v.pb(j*temp);
    }
    sort(all(v));
}

int main()
{

     ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    process();
    int t;
    sf(t);
    TEST_CASE(t)
    {
        ll n;
        sfl(n);
        ll cnt=upper_bound(all(v),n)-v.begin();
        PRINT_CASE;
        printf("%lld\n",n-cnt);
    }

    return 0;
}


/*
	When is the sum of divisors odd?
	The sum of even divisors of a number is even.
	So, when sigma(n) is odd, that means, n has odd number of odd divisors

	Thus the problems is reduced to this:
	Given a number n, find the number of integers in the range [1,n] that have
	an odd number of odd divisors. For ease, let's call them "special numbers".

	So how do we find the "special numbers"?
	Remember that sqare numbers have odd number of divisors?
	Thus, if we throw out the 2's power from a number's PPF and it becomes a full square,
	that means it is a special number.

	So, in order to find all the special numbers, we take the square of an odd number,
	then multiply 2 with it, as long as we can. Each result gives us a special number.
	We store them in a container so that we can use them to answer the queries.

	The question remains, how many special numbers are there that don't exceed 1e12 ?
	Let p be an odd number. Since p*p <= 1e12, so p <= 1e6.
	We can multiply 2 at most 50 times with each p. Thus 5*1e7 is a generous upperbound
	on the number of special numbers in this range.
	In reality, it is less than 2*1e6, as the code confirms.
*/
