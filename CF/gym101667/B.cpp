#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int x,ex,ey,ans;
map<LL,int> H;
int mp[22][22];

bool check() {
    for(int i = 1;i <= 4;i ++) {
        for(int j = 1;j <= 4;j ++) {
            if(mp[i][j] == 1) continue;
            if(j >= 3 && mp[i][j] == mp[i][j-1] && mp[i][j]==mp[i][j-2])
                return true;
            if(i >= 3 && mp[i-1][j] == mp[i][j] && mp[i][j]==mp[i-2][j])
                return true;
            if(i+2<=4 && j+2<=4 && mp[i][j] == mp[i+1][j+1] && mp[i][j] == mp[i+2][j+2])
                return true;
            if(i+2<=4 && j-2>=1 && mp[i][j] == mp[i+1][j-1] && mp[i][j] == mp[i+2][j-2])
                return true;
        }
    }
    return false;
}

int get(int y) {
    for(int i = 1;i <= 4;i ++) {
        if(mp[i][y] == 1)
            return i;
    }
    return 0;
}

LL gethash() {
    LL ans = 0;
    for(int i = 1;i <= 4;i ++) {
        for(int j = 1;j <= 4;j ++) {
            ans = ans * 4 + mp[i][j];
        }
    }
    return ans;
}

void place(int y,int b) {
    int x = get(y);
    if(x == 0) return ;
    mp[x][y] = b;
    if(x == ex && y == ey) {
        if(b == 3) { mp[x][y] = 1; return ; }
        if(check()) {
            LL t = gethash();
            if(!H.count(t)) H[t] = 1,ans ++;
        }
        mp[x][y] = 1;
        return ;
    }
    /*puts("");
    for(int i = 1;i <= 4;i ++){
        for(int j = 1;j <= 4;j ++){
            printf("%d",mp[i][j]);
        }
        puts("");
    }*/

    if(check()) { mp[x][y] = 1; return ;}
    for(int i = 1;i <= 4;i ++) {
        place(i,b^1);
    }
    mp[x][y] = 1;
}

int main() {
    scanf("%d",&x);
    scanf("%d%d",&ex,&ey);
    for(int i = 1;i <= 4;i ++) {
        for(int j = 1;j <= 4;j ++)
            mp[i][j] = 1;
    }
    place(x,3);
    cout << ans << endl;
}
