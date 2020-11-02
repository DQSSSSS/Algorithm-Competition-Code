#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9+7;
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

pii a[SZ];
int num[SZ];

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].first = read();
        a[i].second = read();
    }
    sort(a+1,a+1+n);
    int m = read();
    map<int,int> mp;
    for(int i = 1;i <= m;i ++) {
        int x = read();
        mp[x] = 1;
        for(int j = 1;j <= n;j ++) {
            if(a[j].first <= x && x <= a[j].second) {
                num[j] ++;
            }
        }
    }
    vector<int> ans;
    map<int,int> ban;
    for(int i = 1;i <= n;i ++) {
        if(num[i] > 2) {
            return puts("impossible"),0;
        }
    }
    for(int i = 1;i <= n;i ++) {
        if(num[i] < 2) {
            if(num[i] == 0) {
                for(int j = 1;j <= a[i].second;j ++) {
                    if(!mp.count(a[i].first + j)) {
                        ans.push_back(a[i].first + j);
                        mp[a[i].first + j] = 1;
                        break;
                    }
                }
                if(!mp.count(a[i].second) && i<n && a[i+1].first == a[i].second && num[i+1] < 2) {
                    ans.push_back(a[i].second);
                    num[i+1] ++;
                }
                else {
                    for(int j = 1;j <= a[i].second;j ++) {
                        if(!mp.count(a[i].first + j)) {
                            ans.push_back(a[i].first + j);
                            mp[a[i].first + j] = 1;
                            break;
                        }
                    }
                }
            }
            else {
                if(!mp.count(a[i].second) && i<n && a[i+1].first == a[i].second && num[i+1] < 2) {
                    ans.push_back(a[i].second);
                    num[i+1] ++;
                }
                else {
                    for(int j = 1;j <= a[i].second;j ++) {
                        if(!mp.count(a[i].first + j)) {
                            ans.push_back(a[i].first + j);
                            mp[a[i].first + j] = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
    printf("%d\n",ans.size());
    for(int x : ans) {
        printf("%d ",x);
    }
}
