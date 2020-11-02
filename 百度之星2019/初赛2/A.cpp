#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
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

int get(int n) {
    int ans = 0;
    while(n) ans += n%10,n /= 10;
    return ans;
}

vector<int> work(int n) {
    int sum = get(n);
    vector<int> ans;
    for(int i = 1;i <= sum;i ++) {
        if(sum % i == 0) {
            if(n%i==0) ans.push_back(i);
        }
    }
    return ans;
}

int main() {
    int T = read();
    while(T --) {
        int n = read();
        vector<int> ans = work(n);
        printf("%d\n",ans.size());
        for(int i = 0;i < ans.size();i ++) {
            printf("%d%c",ans[i],i+1==ans.size()?'\n':' ');
        }
    }
}
