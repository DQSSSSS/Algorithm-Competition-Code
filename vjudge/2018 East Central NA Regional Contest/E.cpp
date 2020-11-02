#include<bits/stdc++.h>
using namespace std;

const int SZ = 110;
const double eps = 1e-6;

int n,m;
int a[SZ][SZ];
int A[SZ][SZ];
int D[SZ][SZ];
int id[SZ][SZ];
char mp[SZ][SZ];

bool isEnd() {
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j] == '.' && !a[i][j])
                return false;
        }
    }
    return true;
}

double get(int x,int y,int dr) {
    if(dr == 1) {
        int ans = 0,len = 0,yy = y;
        while(y <= m && mp[x][y] != '#') len ++,y ++;
        y = yy;
        int t = len;
        while(y <= m && mp[x][y] != '#') {
            if(a[x][y]) ans += t;
            y ++; t --;
        }
        return 1.0*ans/(len*(len+1)/2);
    }
    else {
        int ans = 0,len = 0,xx = x;
        while(x <= n && mp[x][y] != '#') len ++,x ++;
        x = xx;
        int t = len;
        while(x <= n && mp[x][y] != '#') {
            if(a[x][y]) ans += t;
            x ++; t --;
        }
        return 1.0*ans/(len*(len+1)/2);
    }
}

void fil(int x,int y,int dr) {
    if(dr == 1) {
        while(y <= m && mp[x][y] != '#') {
            a[x][y] = 1;
            y ++;
        }
    }
    else {
        while(x <= n && mp[x][y] != '#') {
            a[x][y] = 1;
            x ++;
        }
    }
}

bool hasWork(int x,int y,int dr) {
    if(dr == 1) {
        while(y <= m && mp[x][y] != '#') {
            if(!a[x][y]) return false;
            y ++;
        }
    }
    else {
        while(x <= n && mp[x][y] != '#') {
            if(!a[x][y]) return false;
            x ++;
        }
    }
    return true;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i ++){
        scanf("%s",mp[i]+1);
    }
    int tot = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j]=='#') continue;
            if(j==1||mp[i][j-1]=='#') {
                A[i][j] = 1; /// across
                id[i][j] = ++ tot;
            }
            if(i==1||mp[i-1][j]=='#'){
                D[i][j] = 1; /// down
                if(!id[i][j]) id[i][j] = ++ tot;
            }
            if(mp[i][j] != '.' && mp[i][j] != '#') {
                a[i][j] = 1;
            }
        }
    }

    while(!isEnd()) {
        double maxv = -1;
        int x,y,dr;
        for(int i = 1;i <= n;i ++) {
            for(int j = 1;j <= m;j ++) {
                if(id[i][j]) {
                    int nd;
                    if(A[i][j] && !hasWork(i,j,nd=1)) {
                        double v = get(i,j,nd);
                   //     printf("%d %d %.3f\n",i,j,v);
                        if(fabs(v-maxv)<eps) {
                            if(nd<dr) x=i,y=j,dr=nd;
                            else if(id[i][j] < id[x][y]) x=i,y=j,dr=nd;
                        }
                        else {
                            if(maxv < v) maxv=v,x=i,y=j,dr=nd;
                        }
                    }
                    if(D[i][j] && !hasWork(i,j,nd=2)) {
                        double v = get(i,j,nd);
                   //     printf("%d %d %.3f\n",i,j,v);
                        if(fabs(v-maxv)<eps) {
                            if(nd<dr) x=i,y=j,dr=nd;
                            else if(id[i][j] < id[x][y]) x=i,y=j,dr=nd;
                        }
                        else {
                            if(maxv < v) maxv=v,x=i,y=j,dr=nd;
                        }
                    }
                }
            }
        }
        fil(x,y,dr);
        printf("%d%c\n",id[x][y],dr==1?'A':'D');
    }
}
/**
3 3
...
.#.
...
*/
