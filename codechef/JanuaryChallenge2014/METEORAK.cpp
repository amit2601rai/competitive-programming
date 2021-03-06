/*Author:Amit(IIIT-H)*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<cmath>
#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<list>
#include<bitset>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef set<int> si;
typedef map<string, int> msi;
typedef map<int, int> mi;

#define INF INT_MAX
#define MINF INT_MIN
#define pb push_back
#define mp make_pair
#define FOR(i,a, b) for (int i = a; i <= b; i++)
#define print2d(a,m,n)FOR(i,0,m){FOR(j,0,n){printf("%d ",a[i][j]);}printf("\n");}
#define memset1d(a,n,value) FOR(i,0,n)a[i]=value;
#define memset2d(a,m,n,value) FOR(i,0,m) FOR(j,0,n) a[i][j]=value;
#define Traverse(container,it) for(it = container.begin(); it!= container.end(); it++)

int up[1001][1001],l[1001][1001],r[1001][1001],c[1001][1001],d[1001][1001];

int main(){
    int n,m,k,i,j;
    cin>>n>>m>>k;
    memset2d(up,n,m,1);
    while(k--){
        cin>>i>>j;
        up[i][j] = 0;
    }
    FOR(i,2,n){
        FOR(j,1,m){
            if(up[i][j] != 0)up[i][j] = up[i-1][j]+1;
        }
    }
    stack<int>s;
    FOR(i,1,n){
        FOR(j,1,m){
            while(!s.empty() && up[i][s.top()]>up[i][j]){
                r[i][s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while(!s.empty()){
            r[i][s.top()] = m+1;
            s.pop();
        }
    }
    FOR(i,1,n){
        for(int j = m;j>=1;j--){
            while(!s.empty() && up[i][s.top()]>up[i][j]){
                l[i][s.top()] = j;
                s.pop();
            }
            s.push(j);
        }
        while(!s.empty()){
            l[i][s.top()] = 0;
            s.pop();
        }
    }
    FOR(i,1,n){
        FOR(j,1,m){
            if(up[i][j] != 0){
                c[i - up[i][j]+1][i] = max(c[i - up[i][j]+1][i],r[i][j] - l[i][j] - 1);
            }
        }
    }
    for(int len = n; len>= 2; len--){
            for(int l=1; l<=n-len+1; l++){
                int r = l + len - 1;
                c[l + 1][r] = max(c[l + 1][r], c[l][r]);
                c[l][r - 1] = max(c[l][r - 1], c[l][r]);
            }
    }
    for(int len = 1; len<=n; len++){
        for(int l=1; l<=n-len+1; l++){
            int r = l + len - 1;
            if(l == r)d[l][r] =  c[l][r];
            else d[l][r] = max(c[l][r]*(r-l+1),max(d[l][r-1],d[l+1][r]));
        }
    }
    int Q;
    cin>>Q;
    while(Q--){
        int x,y;
        scanf("%d%d",&x,&y);
        printf("%d\n",d[x][y]);
    }
return 0;
}
