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
//#define MAX             105
//#define CIN             ios_base::sync_with_stdio(0); cin.tie(0)
//#define SZ(a)           (int)a.size()
//#define sf(a)           scanf("%d",&a)
//#define sff(a,b)        scanf("%d%d",&a,&b)
//#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
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
//int ara[MAX],sorted[MAX],par[MAX];
//
//int main()
//{
//    ///freopen("in.txt","r",stdin);
//    ///freopen("out.txt","w",stdout);
//    int t;
//    sf(t);
//    TEST_CASE(t)
//    {
//        int n,m;
//        sf(n);
//
//        loop(i,n)
//        {
//            sf(m);
//            ara[i]=sorted[i]=m;
//            par[m]=i;
//        }
//
//        sort(sorted,sorted+n);
//        int ans=0;
//        loop(i,n)
//        {
//            if(ara[i]==sorted[i]) continue;
//            else
//            {
//                ans++;
//                int temp=ara[i];
//                swap(ara[i],ara[par[sorted[i]]]);
//                swap(par[temp],par[sorted[i]]);
//            }
//        }
//        PRINT_CASE;
//        pf("%d\n",ans);
//    }
//    return 0;
//}


#include<stdio.h>

int main()
{
    float salary, tax, rent,total;
    printf("Enter the basic salary ammount:\n");
    scanf("%f",&salary);
    tax=salary*.15;
    rent=salary*.60;
    total=salary+rent+2000.0-tax;
    printf("Tax ammount: %.2f\n",tax);
    printf("Toal ammount: %.2f\n",total);
    return 0;
}
