#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int n,k;

int work() {
    LL sum = 1ll * n * (n+1) / 2;
    if(sum % k) return puts("no");
    else {
        if(n/k%2==0) {
            sum /= k;
            vector<vector<int>> a;
            int l = 1,r = n;
            for(int i = 0;i < k;i ++) {
                vector<int> tmp;
                LL now = 0;
                while(now < sum) {
                    now += l + r;
                    tmp.push_back(l);
                    tmp.push_back(r);
                    l ++; r --;
                }
                a.push_back(tmp);
            }
            puts("yes");
            for(int i = 0;i < k;i ++) {
                for(int j = 0;j < a[i].size();j ++) {
                    printf("%d%c",a[i][j],j+1==a[i].size()?'\n':' ');
                }
            }
            return 0;
        }
        sum /= k;
        if(sum < n) { return puts("no"); }
        set<int> s;
        for(int i = 1;i <= n;i ++) s.insert(i);
        vector<vector<int>> a;
//        cout << sum << endl;
        for(int i = 0;i < k;i ++) {
            vector<int> tmp;
            LL now = 0;
            while(now < sum) {
                LL rst = sum - now;
                auto it = s.upper_bound(rst);
                if(it == s.begin()) {
                    //printf("%d %d\n",n,k);
                    //assert(0);
                    return puts("no");
                }
                it --;
                now += *it;
                tmp.push_back(*it);
                s.erase(it);
            }
            a.push_back(tmp);
        }
        puts("yes");
        for(int i = 0;i < k;i ++) {
            for(int j = 0;j < a[i].size();j ++) {
                printf("%d%c",a[i][j],j+1==a[i].size()?'\n':' ');
            }
        }
    }
}

int main() {
    int T = read();
    while(T --) {
        n = read(),k = read();
        work();
       /* for(n = 1;n <= 100;n +=2) {
            for(k = 1;k <= 100;k ++) {
                if(n%k==0)
                    work();
            }
        }*/
    }
}
