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

#define M 150005

int tree[4*M];
int ara[M];

//void init(int n, int b, int e)
//{
//    if(b==e)
//    {
//        if(ara[b-1]) tree[n]=1;
//        else
//            tree[n]=0;
//        return;
//    }
//
//    int l=n*2;
//    int r=l+1;
//    int mid=(b+e)/2;
//    init(l,b,mid);
//    init(r,mid+1,e);
//    tree[n]=tree[l]+tree[r];
//}

void update(int n, int b, int e, int i, int x)
{
    if(b>i || e<i) return;
    if(b==i && e==i)
    {
        tree[n]+=x;
        return;
    }
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
//    if(i<=mid)
    update(l,b,mid,i,x);
//    else
    update(r,mid+1,e,i,x);
    tree[n]=tree[l]+tree[r];
}

int query(int n, int b, int e, int x)
{
    tree[n]--;
    if(b==e)
    {
//        tree[n]=0;
        return b;
    }
    int l=n*2;
    int r=l+1;
    int mid=(b+e)/2;
    if(tree[l]>=x)
    {
        int y=query(l,b,mid,x);
//        tree[n]=tree[l]+tree[r];
        return y;
    }
    else
    {
        int y=query(r,mid+1,e,x-tree[l]);
//        tree[n]=tree[l]+tree[r];
        return y;
    }
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        int n,q;
        sff(n,q);
        int total=n+q;
        ms(tree,0);
        ms(ara,0);
        loop(i,n)
        {
            sf(ara[i]);
            update(1,1,total,i+1,1);
        }
        int temp=n,a;
        int cnt=n;
//        init(1,1,total);
        PRINT_CASE;
        while(q--)
        {
            getchar();
            char ch[5];
            sc("%s",ch);
            if(ch[0]=='c')
            {
                sf(a);
                if(a>cnt)
                {
                    pf("none\n");
                    continue;
                }
                cnt--;
                int x=query(1,1,total,a);
                pf("%d\n",ara[x-1]);
            }
            else
            {
                sf(a);
                cnt++;
                ara[temp++]=a;
                update(1,1,total,temp,1);

            }
        }
    }

    return 0;
}
