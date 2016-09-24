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
#define PRINT_CASE      printf("Case %d:\n",z)
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

struct data
{
    int sum,prop;
};

data tree[3*100005];
char str[100005];

void update(int n, int b, int e, int i, int j)
{
    if(i>e || j<b) return;
    if(b>=i && e<=j)
    {
//        tree[n].sum+=1;
        tree[n].prop+=1;
        return;
    }
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    update(l,b,mid,i,j);
    update(r,mid+1,e,i,j);
}

void init(int n, int b, int e)
{
    if(b==e)
    {
        tree[n].prop=tree[n].sum=0;
        return;
    }
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    init(l,b,mid);
    init(r,mid+1,e);
    tree[n].prop=tree[n].sum=0;
}

int query(int n, int b, int e, int i, int carry)
{
    if(e<i || b>i) return 0;
    if(b==e && b!=i) return 0;
    if(b==e && b==i)
    {
        return carry+tree[n].prop;
    }
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    int p1=0,p2=0;
    p1=query(l,b,mid,i,carry+tree[n].prop);
    p2=query(r,mid+1,e,i,carry+tree[n].prop);
    return p1+p2;
}

int main()
{
//    CIN;
//    freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);
    getchar();
    TEST_CASE(t)
    {
        sc("%s",str+1);
        int l=strlen(str+1);
        int n;
        init(1,1,l);
        sf(n);
        PRINT_CASE;
        while(n--)
        {
            char ch;
            int a,b;
            getchar();
            sc("%c",&ch);
            if(ch=='I')
            {
                sff(a,b);
                update(1,1,l,a,b);
            }
            if(ch=='Q')
            {
                sf(a);
                b=query(1,1,l,a,0);
                if(b & 1)
                {
                    if(str[a]=='0') pf("1\n");
                    else pf("0\n");
                }
                else
                    pf("%c\n",str[a]);
            }
        }
    }
    return 0;
}
