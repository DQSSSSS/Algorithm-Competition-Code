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

bool isPri(int x) {
    if(x <= 1) return false;
    for(int i = 2;i*i <= x;i ++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

bool islegal(int x) {
    int sum = 0;
    while(x) {
        if(x%10==5) sum ++;
        x /= 10;
    }
    return sum!=0;
}

int main() {
    int sum = 0;
    for(int i = 1;i <= 100000;i ++) {
        if(isPri(i) && islegal(i)) {
            sum ++;
//            cout << i << endl;
        }
    }
    cout << sum << endl;
}
