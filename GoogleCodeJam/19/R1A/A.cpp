#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int INF = 1e9 + 10;
const int SZ = 1e6 + 10;
const int mod = 1e9 + 7;
const double PI = acos(-1);
const double eps = 1e-7;

LL read(){
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
    if(flag) n = -n;
    return n;
}

int n,m,flag;
bool use[22][22];
vector<pii> ans;

bool dfs(int x,int y,int sum) {
    if(sum == n * m) {
        flag = 1; return true;
    }
    //if(flag) return true;

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(i == x) continue;
            if(j == y) continue;
            if(i-j == x-y) continue;
            if(i+j == x+y) continue;
            //if(abs(x-i)+abs(y-j)!=3) continue;
            if(use[i][j]) continue;
            use[x][y] = 1;
            if(dfs(i,j,sum+1)) {
                ans.push_back(make_pair(i,j));
                return true;
            }
            use[x][y] = 0;
        }
    }
    return false;
}

int main() {
    int B = 8;
    //printf("    "); for(n = 1;n <= B;n ++) printf("%3d",n); puts("");
    for(n = 4;n <= 4;n ++) {
       // printf("%3d:",n);
        for(m = 4;m <= 4;m ++) {
            if(m < n) {
            //    printf("   ");
                continue;
            }
            flag = 0;
            for(int i = 1;i <= n;i ++)
                for(int j = 1;j <= m;j ++) {
                    if(flag) continue;
                    memset(use,0,sizeof use);
                    use[i][j] = 1;
                    dfs(i,j,1);
                    if(flag) {
                     //   puts("---------");
                        //printf("%d %d:\nans.push_back(make_pair(%d+dx,%d+dy));\n",n,m,i,j);
                        printf("%d %d\n",i,j);
                        reverse(ans.begin(),ans.end());
                        for(pii x : ans) {
                           // printf("ans.push_back(make_pair(%d+dx,%d+dy));\n",x.first,x.second);
                            printf("%d %d\n",x.first,x.second);
                        }
                        ans.clear();
                    }
                }
            //if(flag) printf("%3d",1);
           // else printf("   ");
        }
        //puts("");
    }
}
/**
      1  2  3  4  5  6  7  8
  1:  1
  2:              1  1  1  1
  3:           1  1  1  1  1
  4:           1  1  1  1  1
  5:              1  1  1  1
  6:                 1  1  1
  7:                    1  1
  8:                       1

      1  2  3  4  5  6  7  8
  1:  1
  2:
  3:           1        1  1
  4:              1  1  1  1
  5:              1  1  1  1
  6:                 1  1  1
  7:                    1  1
  8:                       1
*/
