#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 200010;
const LL INF = 1e18;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

LL f[55][55][22][22],a[55][55];

vector<int> g;
bool cmp(int a,int b) { return a > b; }

int main() {
    int T = read();
    while(T --) {
		int n = read(),m = read(),k = read();
		for(int i = 1;i <= n;i ++) {
			for(int j = 1;j <= m;j ++)
				a[i][j] = read();
		}
		for(int i = 0;i <= n;i ++)
			for(int j = 0;j <= m;j ++)
				for(int x = 0;x <= k;x ++)
					for(int y = 0;y <= k;y ++)
                        f[i][j][x][y] = -INF;
        f[1][1][0][0] = a[1][1];
        f[1][1][1][0] = 0;
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= m;j ++) {
				if(i == 1 && j == 1) continue;
				g.clear();
				if(i > 1)
	                for(int x = j + 1;x <= m;x ++) g.push_back(a[i - 1][x]);
                for(int x = 1;x < j;x ++) g.push_back(a[i][x]);
                sort(g.begin(),g.end(),cmp);
       //         cout << i << " " << j << endl;
        //        for(int x = 0;x < g.size();x ++) cout << g[x] << " "; puts("");
				for(int x = 0;x <= k;x ++) ///路径上x个没算
					for(int y = 0;y <= k;y ++)  { ///外面的算了y个
                        f[i][j][x][y] = f[i][j - 1][x][y] + a[i][j];
                        if(x > 0)
	                        f[i][j][x][y] = max(f[i][j][x][y],f[i][j - 1][x - 1][y]);
                        LL sum = 0;
                        for(int z = 0;z <= min(m,y);z ++) {
                            //if(g[i - 1][z - 1].second != j)
                            f[i][j][x][y] = max(f[i][j][x][y],f[i - 1][j][x][y - z] + sum + a[i][j]);
                            if(x > 0)
	                            f[i][j][x][y] = max(f[i][j][x][y],f[i - 1][j][x - 1][y - z] + sum);
	                        if(z == g.size()) break;
                    		sum += g[z];
                    	}
//                    	if(i == 3 && j == 3) cout << i << " " << j << " " << x << " " << y << " " << f[i][j][x][y] << endl;
  //                  	if(i == 4 && j == 3) cout << i << " " << j << " " << x << " " << y << " " << f[i][j][x][y] << endl;
    //                	if(i == 5 && j == 3) cout << i << " " << j << " " << x << " " << y << " " << f[i][j][x][y] << endl;
                    }
            }
        LL ans = 0;
      //  for(int x = 0;x <= k;x ++) cout << f[n][m][x][x] << endl;
        for(int x = 0;x <= k;x ++) ans = max(ans,f[n][m][x][x]);
        printf("%lld\n",ans);
    }
    return 0;
}
