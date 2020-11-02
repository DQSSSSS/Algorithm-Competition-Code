#include <bits/stdc++.h>
using namespace std;
const int N = 20000 + 5;
int a[N], n, m, card[205][14], num[205], ans[205], L;
void getcard(int x) {
    if(L >= m) return;
    num[x]++;
    card[x][a[++L]]++;
}
int pr, er, now, cnt;
void update(int x, int y) {
    cnt = 0;
    er = x; now = y; card[x][y]--; num[x]--;
}
int getnex(int x) { x = x + 1; if(x == 14) x = 1; return x; }
void play(int x) {
    //cout << "play" << x << endl;;
    if(now == -1) {
        for(int i = 3; i <= 13; i++)
            if(card[x][i]) { update(x, i); return; }
        if(card[x][1]) { update(x, 1); return; }
        if(card[x][2]) { update(x, 2); return; }
    } else if(now != 2) {
        if(card[x][getnex(now)]) { update(x, getnex(now)); return; }
        if(card[x][2]) {update(x, 2); return; }
        cnt++;
    } else cnt++;
}
void debug() {
    for(int i = 1; i <= n; i++) {
        cout << i << ": ";
        for(int j = 1; j <= 13; j++) cout << card[i][j] << " ";
        cout << endl;
    }
}
int main() {
	freopen("in.txt","r",stdin);
	freopen("std.txt","w",stdout);
    int T, cas = 1; cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 1; i <= m; i++) cin >> a[i];
        L = 0;
        memset(card, 0, sizeof card);
        memset(num, 0, sizeof num);
        for(int i = 1; i <= n; i++) for(int j = 1; j <= 5; j++) getcard(i);
        //debug();
        pr = er = 1, now = -1;
        while(true) {
            int i = pr;
            cnt = 0;
            while(cnt < n - 1) {
                play(i);
            //    cout << pr << " " << cnt << " " << er << " " << now << endl;
                if(num[i] == 0) goto gameover;
                i = i % n + 1;
            }
            //cout << er << endl;
            for(int p = er, i = 1; i <= n; i++, p = p % n + 1) getcard(p);
            now = -1, pr = er;

        }
        gameover:
        printf("Case #%d:\n", cas++);
        for(int i = 1; i <= n; i++) {
            ans[i] = 0;
            for(int j = 1; j <= 13; j++) ans[i] += j * card[i][j];
            if(ans[i] == 0) printf("Winner\n");
            else printf("%d\n", ans[i]);
        }
    }
}
