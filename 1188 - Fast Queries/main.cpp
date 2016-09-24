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
#define PRINT_CASE       printf("Case %d:\n",z)
#define CASE_PRINT       cout<<"Case "<<z<<":"<<endl
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

struct data
{
    int l,r,i,ans;
};

int ara[100005];
int tree[100005];
int last[100005];

void update(int idx, int val)
{
    while(idx < 100005)
    {
        tree[idx]+=val;
        idx += idx & -idx;
    }
}

int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-= idx & -idx;
    }
    return sum;
}

bool comp(data a, data b)
{
    return a.r<b.r;
}

bool comp1(data a, data b)
{
    return a.i<b.i;
}

int main()
{
//    CIN;
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
//    cin>>t;
    sf(t);
    TEST_CASE(t)
    {
        vector<data>v;
        int n,q;
//        cin>>n>>q;

        sff(n,q);

        loop(i,n)
        {
            sf(ara[i+1]);
//            cin>>ara[i+1];
//            ara[i+1]++;
        }
        data temp;

        loop(i,q)
        {
//            cin>>temp.l>>temp.r;
            sff(temp.l,temp.r);
            temp.i=i;
//            temp.l++;
//            temp.r++;
            v.pb(temp);
        }

        int indx=0;

        sort(all(v),comp);

        for(int i=1;i<=n;i++)
        {
            int a=ara[i];
            if(last[a]!=0)
                update(last[a],-1);
            update(i,1);
            last[a]=i;
            while(v[indx].r==i)
            {
                v[indx].ans=query(v[indx].r)-query(v[indx].l-1);
                indx++;
            }
        }

        sort(all(v),comp1);

//        CASE_PRINT;
            PRINT_CASE;
        loop(i,q)
        {
//            cout<<v[i].ans<<endl;
            printf("%d\n",v[i].ans);
        }
        ms(last,0);
        ms(tree,0);
    }
    return 0;
}
