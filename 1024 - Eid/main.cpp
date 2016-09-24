#include <bits/stdc++.h>

#define MAXL 1010
#define MAXS 1000010
#define MAXP 90000
#define INFIN 1001001001

#define pq priority_queue
#define btc(x) __builtin_popcount(x)
#define mp(x, y) make_pair(x, y)
#define paii pair< int, int >
#define pasi pair< string, int >
#define pais pair< int, string >
#define mem(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define pi (2*acos(0))
#define oo 1<<20
#define dd double
#define ll long long int
#define llu long long unsigned
#define ERR 1e-5
#define fst first
#define sec second
#define SZ(a) (int)a.size()
#define All(a) a.begin(),a.end()

#define SIZE 1000
#define REP(i,n) for(i=0; i<n; i++)
#define REV(i,n) for(i=n; i>=0; i--)
#define FOR(i,p,k) for(i=p; i<k; i++)
#define Sort(x) sort(x.begin() , x.end())
#define Reverse(x) reverse(x.begin() , x.end())


using namespace std;

string Addition(string a,string b);
string Multiplication(string a,string b);
string Multiplication(string a,int k);
string Subtraction(string a,string b);
string Division(string a,string b);
string Division(string a,int k);
string Div_mod(string a,string b);
int Div_mod(string a,int k);
string cut_leading_zero(string a);
int compare(string a,string b);

int prime[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89,97,101,103};

int factor_cnt[10005];

int main()
{
    int t, cnt_prime=sizeof(prime)/sizeof(int);
    scanf("%d",&t);
    for(int z=1;z<=t;z++)
    {
        int n,a;
        scanf("%d",&n);
        int limit=0;
        memset(factor_cnt,0,sizeof factor_cnt);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a);
            int root=sqrt(a);
            for(int j=0;j<cnt_prime && prime[j]<=root;j++)
            {
                if(a%prime[j]==0)
                {
                    limit=max(limit,prime[j]);
                    int cnt=0;
                    while(a%prime[j]==0)
                    {
                        cnt++;
                        a/=prime[j];
                    }
                    root=sqrt(a);
                    factor_cnt[prime[j]]=max(factor_cnt[prime[j]],cnt);
                }
            }
            if(a>1)
            {
                 limit=max(limit,a);
                factor_cnt[a]=max(factor_cnt[a],1);
            }
        }

        string ans="1";
        for(int i=2;i<=limit;i++)
        {
            if(factor_cnt[i])
            {
                for(int j=0;j<factor_cnt[i];j++)
                    ans=Multiplication(ans,i);
            }
        }
        printf("Case %d: %s\n",z,ans.c_str());

    }
    return 0;
}

string Multiplication(string a,string b)
{
    int i, j, multi, carry;
    string ans, temp;

    ans = "0";
    REV(j,SZ(b)-1)
    {
        temp = "";
        carry = 0;
        REV(i,SZ(a)-1)
        {
            multi = (a[i]-'0')*(b[j]-'0')+carry;
            temp += (multi%10+'0');
            carry = multi/10;
        }
        if( carry ) temp += (carry+'0');
        Reverse(temp);
        temp += string(SZ(b)-j-1,'0');
        ans = Addition(ans,temp);
    }
    ans = cut_leading_zero(ans);
    return ans;
}

string Multiplication(string a,int k)
{
    string ans;
    int i, sum, carry=0;

    REV(i,SZ(a)-1)
    {
        sum = (a[i]-'0')*k+carry;
        carry = sum/10;
        ans+=(sum%10)+'0';
    }
    while(carry)
    {
        ans += (carry%10)+'0';
        carry/=10;
    }
    Reverse(ans);
    ans = cut_leading_zero(ans);
    return ans;
}

string Addition(string a,string b)
{
    int carry=0, i;
    string ans;

    if( SZ(a)>SZ(b) ) b = string(SZ(a)-SZ(b),'0')+b;
    if( SZ(b)>SZ(a) ) a = string(SZ(b)-SZ(a),'0')+a;

    ans.resize(SZ(a));

    REV(i,SZ(a)-1)
    {
        int sum = carry+a[i]+b[i]-96;
        ans[i] = (char)(sum%10+'0');
        carry = sum/10;
    }
    if( carry ) ans.insert(0,string(1,carry+'0'));
    ans = cut_leading_zero(ans);
    return ans;
}

string Subtraction(string a,string b)
{
    int borrow = 0, i, sub;
    string ans;
    if( SZ(b)<SZ(a) ) b = string(SZ(a)-SZ(b),'0')+b;
    REV(i,SZ(a)-1)
    {
        sub = a[i]-b[i]-borrow;
        if( sub<0 )
        {
            sub += 10;
            borrow = 1;
        }
        else borrow = 0;
        ans += sub+'0';
    }
    Reverse( ans );
    ans = cut_leading_zero(ans);
    return ans;
}

string Division(string a,string b)
{
    string mod, temp, ans="0";
    int i, j;

    REP(i,SZ(a))
    {
        mod += a[i];
        mod = cut_leading_zero(mod);
        FOR(j,0,10)
        {
            temp = Multiplication(b,j);
            if( compare(temp,mod)==1 )
                break;
        }
        temp = Multiplication(b,j-1);
        mod = Subtraction(mod,temp);
        ans += (j-1)+'0';
    }
    mod = cut_leading_zero(mod);
    ans = cut_leading_zero(ans);
    return ans;
}

string Division(string a,int k)
{
    int i, sum=0;
    string ans = "0";

    REP(i,SZ(a))
    {
        sum = (sum*10+(a[i]-'0'));
        ans += (sum/k)+'0';
        sum = sum%k;
    }
    ans = cut_leading_zero(ans);
    return ans;
}

string Div_mod(string a,string b)
{
    string mod, temp, ans="0";
    int i, j;

    REP(i,SZ(a))
    {
        mod += a[i];
        mod = cut_leading_zero(mod);

        FOR(j,1,10)
        {
            temp = Multiplication(b,j);
            if( compare(temp,mod)>0 )
                break;
        }
        temp = Multiplication(b,j-1);
        mod = Subtraction(mod,temp);
        ans += (j-1)+'0';
    }
    mod = cut_leading_zero(mod);
    ans = cut_leading_zero(ans);
    return mod;
}

int Div_mod(string a,int k)
{
    int i, sum=0;
    REP(i,SZ(a))
        sum = (sum*10+(a[i]-'0'))%k;
    return sum;
}

int compare(string a,string b)
{
    int i;
    a = cut_leading_zero(a);
    b = cut_leading_zero(b);

    if( SZ(a)>SZ(b) ) return 1;
    if( SZ(a)<SZ(b) ) return -1;
    REP(i,SZ(a))
    {
        if( a[i]>b[i] ) return 1;
        else if( a[i]<b[i] ) return -1;
    }
    return 0;
}

string cut_leading_zero(string a)
{
    string s;
    int i;
    if( a[0]!='0' ) return a;
    REP(i,SZ(a)-1) if( a[i]!='0' ) break;
    FOR(i,i,SZ(a)) s+=a[i];
    return s;
}

