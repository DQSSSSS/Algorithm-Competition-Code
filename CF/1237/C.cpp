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

struct haha {
    int x,y,z,id;
}a[SZ];

bool cmp(haha a,haha b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

vector<int> rst;

void work(int l,int r) {
    vector<int> tmp;
    for(int i = l,j = l;i <= r;i ++) {
        if(i == r || a[i+1].y != a[i].y) {
            for(int k = j;k+1<= i;k += 2) {
                printf("%d %d\n",a[k].id,a[k+1].id);
            }
            if((i-j+1)&1) tmp.push_back(a[i].id);
            j = i + 1;
        }
    }
    for(int i = 0;i + 1 < tmp.size();i += 2) {
        printf("%d %d\n",tmp[i],tmp[i+1]);
    }
    if(tmp.size()&1) rst.push_back(tmp[tmp.size()-1]);
}

int main() {
    int n = read();
    for(int i = 1;i <= n;i ++) {
        a[i].x = read();
        a[i].y = read();
        a[i].z = read();
        a[i].id = i;
    }
    sort(a+1,a+1+n,cmp);

    for(int i = 1,j = 1;i <= n;i ++){
        if(i == n || a[i+1].x != a[i].x) {
            work(j,i);
            j = i + 1;
        }
    }
    for(int i = 0;i + 1< rst.size();i += 2) {
        printf("%d %d\n",rst[i],rst[i+1]);
    }
}


