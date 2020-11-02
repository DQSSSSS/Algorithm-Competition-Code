#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1e6 + 10;

int ans = 10000,n;
string a[111];
char suit[] = "shdc";
char suitOrder[11];
string goal[111];
string b[111];

int getid(char a) {
    if(a >= '3' && a <= '9') return a - '0';
    if(a == 'T') return 10;
    if(a == 'J') return 11;
    if(a == 'Q') return 12;
    if(a == 'K') return 13;
    if(a == 'A') return 14;
    if(a == '2') return 2;
}

bool bj(char a,char b,bool d) {
    int f = getid(a) < getid(b);
    if(d) f ^= 1;
    return f;
}

void work(int l,int r,int b) {
    for(int j = l+1;j <= r;j ++) {
        int i = j;
        while(i > l && !bj(goal[i][0],goal[i-1][0],b))
            swap(goal[i],goal[i-1]),i --;
    }
}

int f[55][55];

void check(int S) {
    for(int t = 1,tot = 0;t <= 4;t ++) {
        int l = tot + 1;
        for(int i = 1;i <= n;i ++) {
            if(a[i][1] == suitOrder[t])
                goal[++ tot] = a[i];
        }
        int r = tot;
        //if(suitOrder[1] == 'd' && suitOrder[2] == 's' && suitOrder[3] == 'c') cout << tot << endl;
        work(l,r,S>>(t-1)&1);
    }

    for(int i = 1;i <= n;i ++) b[i] = a[i];

    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            f[i][j] = 0;
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= n;j ++) {
            if(goal[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else {
                f[i][j] = max(f[i-1][j],f[i][j-1]);
            }
        }
    }

    ans = min(ans,n-f[n][n]);

    //if(suitOrder[1] == 'd' && suitOrder[2] == 's' && suitOrder[3] == 'c') {
   //     for(int i = 1;i <= n;i ++) cout << goal[i] << " ";
   //     cout << t << " " << suitOrder+1 << endl;
   // }
}


bool use[11];
void dfs(int d) {
    if(d == 5) {
        suitOrder[d] = '\0';
        for(int i = 0;i < 16;i ++) {
            check(i);
        }
        return ;
    }
    for(int i = 0;i < 4;i ++) {
        if(!use[i]) {
            use[i] = 1;
            suitOrder[d] = suit[i];
            dfs(d+1);
            use[i] = 0;
        }
    }
}

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) {
        cin >> a[i];
    }
    dfs(1);
    cout << ans << endl;
}

/*
6
9h 4h 5h 6h 7h 3h
*/
