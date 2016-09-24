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
#define MOD             1000000007
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

#define M 100005

int tree[3*M];
int ara[M];

int query(int n, int b, int e, int i, int j)
{
    if(b>j || e<i) return 0;
    if(b>=i && e<=j) return tree[n];
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    return (query(l,b,mid,i,j)%MOD+query(r,mid+1,e,i,j)%MOD)%MOD;
}

void update(int n, int b, int e, int idx, int val)
{
    if(b>idx || e<idx) return;
    if(b==idx && idx==e)
    {
        tree[n]=(tree[n]%MOD+val%MOD)%MOD;
        return;
    }
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    update(l,b,mid,idx,val);
    update(r,mid+1,e,idx,val);
    tree[n]=(tree[l]+tree[r])%MOD;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    TEST_CASE(t)
    {

        int n;
        sf(n);
        loop(i,n) sf(ara[i]);
        set<int>S(ara,ara+n);
        vector<int>v(all(S));
//        loop(i,SZ(v)) cout<<v[i]<<" ";
        ms(tree,0);
        loop(i,n)
        {
            int x=lower_bound(all(v),ara[i])-v.begin();
            if(x==0)
            {
                update(1,1,SZ(v),1,1);
            }
            else
            {
                int y=query(1,1,SZ(v),1,x);
                update(1,1,SZ(v),x+1,y+1);
            }
        }
        PRINT_CASE;
        pf("%d\n",tree[1]);
    }
    return 0;
}
