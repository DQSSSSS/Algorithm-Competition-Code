#include <bits/stdc++.h>
using namespace std;
const int SZ = 2e5 + 5;
using pii = pair<int, int>;
const double eps = 1e-8;
typedef long long LL;

vector<pii> vec;



bool check(int x, int y){ // check if we can get the point(x,y)
    for(pii p : vec) {
        if(x % p.first == 0 && y % p.second == 0)
            return true;
    }
    return false;
}

void gao(int a,int b){ // update the unit x and unit y

}



int main() {
    int T = read(),cc = 0;
    while(T --) {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        for(int i = 1;i <= n;i++) {
            int opt, a, b, w;
            scanf("%d", &opt);
            if (opt == 1) {
                scanf("%d%d",&a,&b);
                if (check(a,b))
                    continue;
                gao(a,b);

            } else {
                scanf("%d%d",&a,&b,&w);
                if (check(a,b))) {
                    ans = ans + 1LL* w;
                }
            }
        }
        printf("Case #%d: %lld\n",++ cc,ans);

    }
}

