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
#define sff(a,b)        scanf("%d%d",&a,&b)
#define sfff(a,b,c)     scanf("%d%d%d",&a,&b,&c)
#define loop(i,n)       for(int i=0;i<n;i++)
#define REP(i,a,b)      for(int i=a;i<b;i++)
#define TEST_CASE(t)    for(int z=1;z<=t;z++)
#define PRINT_CASE      printf("Case %d: ",z)
#define all(a)          a.begin(),a.end()
#define intlim          2147483648
#define inf             1000
#define ull             unsigned long long

using namespace std;


//const int fx[]={+1,-1,+0,+0};
//const int fy[]={+0,+0,+1,-1};
//const int fx[]={+0,+0,+1,-1,-1,+1,-1,+1};   // Kings Move
//const int fy[]={-1,+1,+0,+0,+1,+1,-1,-1};  // Kings Move
const int fx[]={-2, -2, -1, -1,  1,  1,  2,  2};  // Knights Move
const int fy[]={-1,  1, -2,  2, -2,  2, -1,  1}; // Knights Move

int cnt_visit[12][12];
bool visited[12][12];
int moves[110][12][12];
int n,m,idx,kk;

bool test(int x,int y)
{
    if(x<0 || x>=n || y<0 || y>=m || visited[x][y])
        return 0;
    return 1;
}


struct data
{
    int x,y,z;
    data(int a, int b, int c){x=a,y=b,z=c;}
};

queue<data>Q;

void DFS(int x,int y,int z, int l)
{
    if(z==0) return;
    for(int i=0;i<8;i++)
    {
        int p=x+fx[i];
            int q=y+fy[i];
                if(test(p,q))
                {
                    visited[p][q]=1;
                    moves[idx][p][q]+=l;
                    Q.push(data(p,q,kk));
                    cnt_visit[p][q]++;
                    DFS(p,q,z-1,l);
                }
    }
}

void BFS(int x, int y)
{
    ms(visited,0);
    visited[x][y]=1;
    cnt_visit[x][y]++;
    Q.push(data(x,y,kk));
    while(!Q.empty())
    {
        data u=Q.front();
        Q.pop();
        REP(i,0,8)
        {
            int p=u.x+fx[i];
            int q=u.y+fy[i];
                if(test(p,q))
                {
                    visited[p][q]=1;
                    moves[idx][p][q]+=moves[idx][u.x][u.y]+1;
                    Q.push(data(p,q,kk));
                    cnt_visit[p][q]++;
                    DFS(p,q,kk-1,moves[idx][p][q]);
                }
        }
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
        ms(cnt_visit,0);
        ms(moves,0);
        char ch;
        sff(n,m);
        int cnt=0;
        bool valid=0;
        if(n<2 || m<2) valid=1;
        REP(i,0,n) REP(j,0,m)
        {
            cin>>ch;
            if(ch=='.') continue;
            else
            {
                int k=ch-'0';
                idx=cnt;
                kk=k;
                BFS(i,j);
                cnt++;

              //  REP(ii,0,n) {REP(jj,0,m) cout<<moves[ii][jj]<<" ";cout<<endl;}
                //cout<<endl;
            }
        }
        getchar();
        PRINT_CASE;
        if(valid)
            {cout<<-1<<endl;continue;}
        int ans=inf;
        REP(i,0,n) REP(j,0,m)
        {
            if(cnt_visit[i][j]==cnt)
            {
                int temp=0;
                REP(k,0,cnt)
                temp+=moves[k][i][j];
                ans=min(ans,temp);
            }
        }
        if(ans==inf) ans=-1;
        cout<<ans<<endl;
    }
    return 0;
}
