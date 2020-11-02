#include<bits/stdc++.h>
using namespace std;

const int SZ = 1e5;

int a[SZ];

short mp[200000010];

void add(int x) {
    mp[x] = 1;
}

bool check(int x) {
    return mp[x];
}

int main() {
    int r,m;
    scanf("%d%d",&r,&m);
    add(r);
    a[1] = r;
    for(int i = 1;;i ++) {
        if(check(m)) return printf("%d\n",i),0;
        int d;
        for(int j = 1;;j ++) {
            if(!check(j)) { d = j; break; }
        }
        a[i+1] = a[i] + d;
        add(a[i+1]);
        for(int j = 1;j <= i;j ++) {
            add(a[i+1]-a[j]);
        }
    }
}
