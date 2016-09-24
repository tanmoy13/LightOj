/*
MMP""MM""YMM   db      `7MN.   `7MF'`7MMM.     ,MMF' .g8""8q.`YMM'   `MM'
P'   MM   `7  ;MM:       MMN.    M    MMMb    dPMM .dP'    `YM.VMA   ,V
     MM      ,V^MM.      M YMb   M    M YM   ,M MM dM'      `MM VMA ,V
     MM     ,M  `MM      M  `MN. M    M  Mb  M' MM MM        MM  VMMP
     MM     AbmmmqMA     M   `MM.M    M  YM.P'  MM MM.      ,MP   MM
     MM    A'     VML    M     YMM    M  `YM'   MM `Mb.    ,dP'   MM
   .JMML..AMA.   .AMMA..JML.    YM  .JML. `'  .JMML. `"bmmd"'   .JMML.
*/


#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <string>
#include <map>

#define pii pair <int,int>
#define sc scanf
#define pf printf
#define Pi 2*acos(0.0)
#define ms(a,b) memset(a, b, sizeof(a))
#define pb(a) push_back(a)
#define MP make_pair
#define oo 1<<29
#define dd double
#define ll long long
#define EPS 10E-10
#define ff first
#define ss second
#define MAX 100
#define SZ(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define intlim 2147483648
#define rtintlim 46340
#define llim 9223372036854775808
#define rtllim 3037000499
#define ull unsigned long long
#define I int

using namespace std;

char ara[50][50];
int w,h,t;
bool valid[50][50];
bool visited[50][50];
int fx[]= {1,-1,0,0};
int fy[]= {0,0,1,-1};
bool test(int x,int y)
{
    if(!valid[x][y])
    {
        if((x>-1 && x<h) && (y>-1 && y<w) && !visited[x][y])
            return true;
    }
    return false;
}

int bfs(int a, int b)
{
    visited[a][b]=true;
    queue <pii> Q;
    Q.push(make_pair(a,b));
    int ans=1;
    while(!Q.empty())
    {
        pii fr=Q.front();
        Q.pop();
        for(int i=0; i<4; i++)
        {
            int p=fr.ff+fx[i];
            int q=fr.ss+fy[i];
            if(test(p,q))
            {
                visited[p][q]=true;
                ans++;
                Q.push(make_pair(p,q));
            }
        }
    }
    return ans;
}

int main()
{
    ///freopen("in.txt","r",stdin);
    ///freopen("out.txt","w",stdout);

    cin>>t;
    for(int z=1; z<=t; z++)
    {
        char ara[50][50]= {{0}};
        pii st;
        cin>>w>>h;
        getchar();
        for(int i=0; i<h; i++)
            for(int j=0; j<w; j++)
            {
                cin>>ara[i][j];
                if(ara[i][j]=='#')
                    valid[i][j]=true;
                if(ara[i][j]=='@')
                    st=make_pair(i,j);
            }
        cout<<"Case "<<z<<": "<<bfs(st.ff,st.ss)<<endl;
        for(int i=0; i<50; i++)
            for(int j=0; j<50; j++)
            {
                visited[i][j]=false;
                valid[i][j]=false;
                ara[i][j]=0;
            }
    }
    return 0;
}
