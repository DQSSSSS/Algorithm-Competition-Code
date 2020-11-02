#include <bits/stdc++.h>
using namespace std;

typedef uint64_t ULL;
const int mod = 998244353;

uint64_t G(uint64_t x) {
    x^=x<<13;
    x^=x>>7;
    x^=x<<17;
    return x;
}

typedef pair<ULL,int> pui;
ULL a[1<<22];

vector<int> A[4][1<<17];
int n,m;

void save() {
    int B = 16;
    int S = (1<<B)-1;
    for(int i = 0;i < 4;i ++) {
        for(int j = 0;j < n;j ++) {
            A[i][a[j] >> (i*B)&S].push_back(j);
        }
    }
}

int ask(ULL x) {
    int B = 16;
    int S = (1<<B)-1;
    for(int i = 0;i < 4;i ++) {
        int SS = x >> (i*B)&S;
        for(auto id : A[i][SS]) {
            if(__builtin_popcountll(a[id]^x) <= 3)
                return 1;
        }
    }
    return 0;
}

mt19937_64 gen;

int main() {
    //scanf("%d%d",&n,&m);
    n=m=1e6;
    ULL s=gen();
//    scanf("%llu",&s);
    for(int i = 0;i < n;i ++) {
        a[i] = s;
        s = G(s);
    }
    save();

    vector<int> ans;
    int sum = 0;
    for(int i = 0;i < m;i ++) {
        ULL x=gen();
        //scanf("%llu",&x);
        (sum = sum * 2 % mod + ask(x)) %= mod;
    }
    cout << sum <<endl;
}
