#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;


char s[SZ];
int a[SZ];

int main() {
    scanf("%s",s+1);
    int n = strlen(s+1);
    for(int i = 1;i <= n;i ++) a[i] = s[i] - '0';
    set<int> s;
    for(int i = 1;i <= n;i ++) {
        if(a[i] == 0) s.insert(i);
    }
    for(int i = 1;i <= n;i ++) {
        if(a[i] == 2) {
            s.insert(0); s.insert(n+1);
            if(s.find(i) != s.end()) {
                s.erase(i);
                continue;
            }
            auto nx = s.lower_bound(i); auto pr = nx; pr --;
            int r = *nx,l = *pr;
           // cout << i << " " << l + r - i <<endl;
            s.insert(l+r-i);
            s.erase(l); s.erase(r);
        }
    }

    for(int i = 1;i <= n;i ++) {
        printf("%d",s.find(i) == s.end() ? 1 : 0);
    }
}
/*
0000001112111111000000000
00000012111111000000000
0000000002111111000000000
*/
