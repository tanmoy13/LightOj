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
//#define MAX             100005
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
//ll ara[MAX],tree1[MAX*3],tree2[MAX*3];
//ll n,d;
//
//void init1(int node, int b, int e)
//{
//    if(b==e)
//    {
//        tree1[node]=ara[b];
//        return;
//    }
//    init1(node*2,b,(b+e)/2);
//    init1((node*2)+1,((b+e)/2)+1,e);
//    tree1[node]=max(tree1[node*2],tree1[(node*2)+1]);
//}
//
//void init2(int node, int b, int e)
//{
//    if(b==e)
//    {
//        tree2[node]=ara[b];
////        pf("Tree [%d] == %lld\n",node,tree2[node]);
//        return;
//    }
//    init2(node*2,b,(b+e)/2);
//    init2((node*2)+1,((b+e)/2)+1,e);
//    tree2[node]=min(tree2[node*2],tree2[(node*2)+1]);
////    pf("Tree [%d] == %lld\n",node,tree2[node]);
//}
//
//ll query1(int node, int b, int e, int i, int j)
//{
//    if(i>e || j<b) return 0;
//    if(b>=i && e<=j) return tree1[node];
//    ll r1= query1(node*2,b,(b+e)/2,i,j);
//    ll r2= query1((node*2)+1,((b+e)/2)+1,e,i,j);
//    return max(r1,r2);
//}
//
//
//ll query2(int node, int b, int e, int i, int j)
//{
//    if(i>e || j<b) return 10000000000;
//    if(b>=i && e<=j) return tree2[node];
//    ll r1= query2(node*2,b,(b+e)/2,i,j);
//    ll r2= query2((node*2)+1,((b+e)/2)+1,e,i,j);
//    return min(r1,r2);
//}
//
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int t;
//    sf(t);
//    TEST_CASE(t)
//    {
//        sffl(n,d);
//        REP(i,1,n+1)
//        sfl(ara[i]);
//        PRINT_CASE;
//        if(d==1)
//        {
//            pf("0\n");
//            continue;
//        }
//        init1(1,1,n);
//        init2(1,1,n);
//        ll ans=-1;
//        d--;
//        for(int i=1; i<=n-d; i++)
//        {
//            ll a1=query1(1,1,n,i,i+d);
//            ll a2=query2(1,1,n,i,i+d);
//            ans=max(ans,a1-a2);
//        }
//
//        pf("%lld\n",ans);
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

int ara[100005];
deque<int> big,small;

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n,d;
        cin>>n>>d;
        loop(i,n) cin>>ara[i];

        big.clear();
        small.clear();

        big.pb(0);
        small.pb(0);

        int ans=0;

        REP(i,1,n)
        {
            while(!big.empty() && ara[big.back()]<=ara[i])
                big.pop_back();
            big.pb(i);
            while(i-big.front()>=d)
                big.pop_front();

            while(!small.empty() && ara[small.back()]>=ara[i])
                small.pop_back();
            small.pb(i);
            while(i-small.front()>=d)
                small.pop_front();
            ans=max(ans,ara[big.front()]-ara[small.front()]);
        }

        PRINT_CASE;
        cout<<ans<<endl;
    }

    return 0;
}
