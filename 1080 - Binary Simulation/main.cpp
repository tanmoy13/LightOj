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
//#define MAX             100010
//#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)           (int)a.size()
//#define sf(a)           scanf("%d",&a)
//#define sff(a,b)        scanf("%d%d",&a,&b)
//#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
//#define loop(i,n)       for(int i=0;i<n;i++)
//#define REP(i,a,b)      for(int i=a;i<b;i++)
//#define TEST_CASE(t)    for(int z=1;z<=t;z++)
//#define PRINT_CASE      printf("Case %d:\n",z)
//#define all(a)          a.begin(),a.end()
//#define intlim          2147483648
//#define inf             1000000
//#define ull             unsigned long long
//
//using namespace std;
//
//int tree[MAX],n;
//char str[MAX];
//
//void update2(int indx, int v)
//{
//    while(indx<=n)
//    {
//        tree[indx]+=v;
//        indx += (indx & (-indx));
//    }
//}
//
//void update(int i, int j)
//{
//    update2(i,1);
//    update2(j+1,-1);
//}
//
//int query(int indx)
//{
//    int sum=0;
//    while(indx)
//    {
//        sum+=tree[indx];
//        indx-=(indx & (-indx));
//    }
//    return sum;
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
//        ms(tree,0);
//        sc("%s",&str[1]);
//        n=strlen(&str[1]);
//        char ch;
//        int m;
//        sf(m);
//        PRINT_CASE;
//        while(m--)
//        {
//            getchar();
//            sc("%c",&ch);
//
//            if(ch=='I')
//            {
//                int a,b;
//                sff(a,b);
//                update(a,b);
//            }
//            else
//            {
//                int a;
//                sf(a);
//                if(query(a)%2==1)
//                {
//                    if(str[a]=='0') pf("1\n");
//                    else pf("0\n");
//                }
//                else
//                    pf("%c\n",str[a]);
//            }
//        }
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
#define MAX             100010
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
#define SZ(a)           (int)a.size()
#define sf(a)           scanf("%d",&a)
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d:\n",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000000
#define ull             unsigned long long

using namespace std;

int tree[3*MAX];
char str[MAX];
int n,m;

void init_and_update(int node, int b, int e, int i, int j)
{
    if(b>=i && e<=j)
    {
        tree[node]++;
        return;
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    if(j<=mid)
        init_and_update(left,b,mid,i,j);
    else if(i>mid)
        init_and_update(right,mid+1,e,i,j);
    else
    {
        init_and_update(left,b,mid,i,mid);
        init_and_update(right,mid+1,e,mid+1,j);
    }
}

int query(int node, int b, int e, int target)
{
    if(b==target && e==target)
    {
        return tree[node];
    }

    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;

    if(target<=mid)
        return tree[node]+query(left,b,mid,target);
    else
        return tree[node]+query(right,mid+1,e,target);

}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);
    int t;
    sf(t);

    TEST_CASE(t)
    {
        ms(tree,0);
        sc("%s",str);
        sf(m);
        n=strlen(str);
        loop(i,n)
            if(str[i]=='1')
            init_and_update(1,1,n,i+1,i+1);

        PRINT_CASE;
        while(m--)
        {
            getchar();
            char ch;
            sc("%c",&ch);
            if(ch=='I')
            {
                int a,b;
                sff(a,b);
                init_and_update(1,1,n,a,b);
            }
            else
            {
                int a;
                sf(a);
                pf("%d\n",query(1,1,n,a)%2);
            }
        }
    }
    return 0;
}
