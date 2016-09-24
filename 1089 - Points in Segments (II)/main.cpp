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
#define REP(i,a,b)      for(int i=a;i<=b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d:\n",z)
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

int ara[200006];


int main()
{
//    freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    int t;
    sf(t);
    TEST_CASE(t)
    {
        vector<int> v;
        vector<pii> segment;
        map<int,int>mp;
        map<int,bool> vis;
        int n,q,a,b,range=-1;
        sff(n,q);

        loop(i,n)
        {

            sff(a,b);
            if(a>b) swap(a,b);
            segment.pb(MP(a,b));
            if(!vis[a])
            {
                v.pb(a);
                vis[a]=1;
            }
            if(!vis[b])
            {
                v.pb(b);
                vis[b]=1;
            }
        }

        sort(all(v));

        int cnt=1;

        loop(i,SZ(v))
        {
            mp[v[i]]=cnt;
            cnt+=2;
        }

        loop(i,SZ(segment))
        {
            ara[mp[segment[i].ff]]++;
            ara[mp[segment[i].ss]+1]--;
        }

        REP(i,1,cnt) ara[i]+=ara[i-1];

//        loop(i,SZ(v)) cout<<v[i]<<" ";
//        cout<<endl;
//        D(mp[v[2]]);

        PRINT_CASE;
        while(q--)
        {
            sf(a);
            int x=lower_bound(all(v),a)-v.begin();
            if(x==SZ(v))
            {
                pf("0\n");
                continue;
            }
            int ans=mp[v[x]];
            if(v[x]>a)
                ans--;
            pf("%d\n",ara[ans]);
        }
        ms(ara,0);
    }


    return 0;
}
