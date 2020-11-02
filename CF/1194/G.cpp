#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool belong(int a,int b) {
    while(b) {
        if(a==b%10) return true;
        b /= 10;
    }
    return false;
}

int main() {
    int n = read(),ans = 0;

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            bool flag = 0;
            for(int ii = 1;ii <= 9;ii ++) {
                for(int jj = 1;jj <= 9;jj ++) {
                    if(i * jj == j * ii) {
                        if(belong(ii,i) && belong(jj,j))
                            flag = 1;
                    }
                }
            }
            if(flag) {
                cout << __gcd(i,j) << endl;
                printf("%d/%d\n",i,j),ans ++;
            }
        }
    }
    cout << ans << endl;
}

/**
1/1
1/2
1/3
1/4
1/5
1/6
1/7
1/8
1/9
2/1
2/2
2/3
2/4
2/5
2/6
2/7
2/8
2/9
3/1
3/2
3/3
3/4
3/5
3/6
3/7
3/8
3/9
4/1
4/2
4/3
4/4
4/5
4/6
4/7
4/8
4/9
5/1
5/2
5/3
5/4
5/5
5/6
5/7
5/8
5/9
6/1
6/2
6/3
6/4
6/5
6/6
6/7
6/8
6/9
7/1
7/2
7/3
7/4
7/5
7/6
7/7
7/8
7/9
8/1
8/2
8/3
8/4
8/5
8/6
8/7
8/8
8/9
9/1
9/2
9/3
9/4
9/5
9/6
9/7
9/8
9/9
10/10
10/20
10/30
10/40
11/11
11/22
11/33
12/12
12/24
12/36
13/13
13/26
13/39
14/14
14/28
15/15
16/16
16/32
17/17
18/18
19/19
20/10
20/20
20/30
20/40
21/21
21/42
22/11
22/22
22/33
24/12
24/24
24/36
25/25
26/13
26/26
26/39
28/14
28/28
30/10
30/20
30/30
30/40
31/31
32/16
32/32
33/11
33/22
33/33
35/35
36/12
36/24
36/36
39/13
39/26
39/39
40/10
40/20
40/30
40/40
41/41
42/21
42/42
*/

