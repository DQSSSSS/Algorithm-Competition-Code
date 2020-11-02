#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int MAXN=1e7+10;
const int mod=1e9+7;

int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int mp[105][105],n=12,m=12;

int randlr(int l,int r) {
    return rand()%(r-l+1)+l;
}

struct Point {
    int x,y;
    void read() {
        scanf("%d%d",&x,&y);
        /*do {
            x = randlr(1,n);
            y = randlr(1,m);
        }while(mp[x][y]);*/
        //mp[x][y] = 2;
    }
    Point work(int d) {
        int nx = x + dx[d];
        int ny = y + dy[d];
        if(1<=nx&&nx<=n && 1<=ny&&ny<=m&&!mp[nx][ny]) {
            return (Point){nx,ny};
        }
        return (Point){x,y};
    }

    void print() {
        printf("%d %d\n",x,y);
    }
};

char get(int ty) {
    if (ty==0) return 'L';
    if (ty==1) return 'R';
    if (ty==2) return 'D';
    if (ty==3) return 'U';
}

int getdir2(char c) {
    if (c == 'L') return 0;
    if (c == 'R') return 1;
    if (c == 'D') return 2;
    if (c == 'U') return 3;
    return 4;
}


int getdir(char c) {
    if (c == 'A') return 0;
    if (c == 'D') return 1;
    if (c == 'S') return 2;
    if (c == 'W') return 3;
    return 4;
}

void init() {
    memset(mp,0,sizeof mp);
    mp[6][6]=mp[6][7]=mp[7][6]=mp[7][7]=1;
    mp[9][2]=mp[9][3]=mp[10][2]=1;
    mp[9][10]=mp[9][11]=mp[10][11]=1;

    Point a,b,c,d;
    a.read();
    b.read();
    c.read();
    d.read();
    /*a.x = 1; a.y = 1;
    b.x = 2; b.y = 1;
    c.x = 3; c.y = 1;
    d.x = 4; d.y = 1;*/

    mp[a.x][a.y] = 2;
    mp[b.x][b.y] = 2;
    mp[c.x][c.y] = 2;
    mp[d.x][d.y] = 2;

   /* a.print();
    b.print();
    c.print();
    d.print();*/
}

int check() {
    if(mp[1][1] && mp[1][2] && mp[2][1] && mp[2][2]) return 1;
    if(mp[1][1] && mp[1][2] && mp[1][3] && mp[1][4]) return 2;
    if(mp[1][1] && mp[1][2] && mp[1][3] && mp[2][1]) return 3;
    if(mp[1][1] && mp[1][2] && mp[2][1] && mp[3][1]) return 4;
    if(mp[1][1] && mp[2][1] && mp[3][1] && mp[4][1]) return 5; /// GOAL
    return 0;
}

void moveRobot(int d) {
    if(d == 0) {
        for(int i = 1;i <= n;i ++) {
             for(int j = 1;j <= m;j ++) {
                if(mp[i][j] == 2) {
                    Point a = (Point){i,j};
                    Point na = a.work(d);
                    mp[a.x][a.y] = 0;
                    mp[na.x][na.y] = 2;
                }
            }
        }
    }
    if(d == 1) {
        for(int i = 1;i <= n;i ++) {
            for(int j = m;j >= 1;j --) {
                if(mp[i][j] == 2) {
                    Point a = (Point){i,j};
                    Point na = a.work(d);
                    mp[a.x][a.y] = 0;
                    mp[na.x][na.y] = 2;
                }
            }
        }
    }
    if(d == 2) {
        for(int j = 1;j <= m;j ++)  {
            for(int i = n;i >= 1;i --) {
                if(mp[i][j] == 2) {
                    Point a = (Point){i,j};
                    Point na = a.work(d);
                    mp[a.x][a.y] = 0;
                    mp[na.x][na.y] = 2;
                }
            }
        }
    }
    if(d == 3) {
        for(int j = 1;j <= m;j ++)  {
            for(int i = 1;i <= n;i ++) {
                if(mp[i][j] == 2) {
                    Point a = (Point){i,j};
                    Point na = a.work(d);
                    mp[a.x][a.y] = 0;
                    mp[na.x][na.y] = 2;
                }
            }
        }
    }
}

void print() {
    puts("-----------");
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            char c;
            if(mp[i][j] == 2) c = 'x';
            else if(mp[i][j] == 1) c = '#';
            else {
                if(i == 3 && j == 3) c = '+';
                else if(i == 3 && j == 10) c = '+';
                else if(i == 10 && j == 3) c = '+';
                else if(i == 10 && j == 10) c = '+';
                else c = '.';
            }
            printf("%c",c);
        }
        puts("");
    }
}

char deal(char c) {
    if(c == 'W') return 'U';
    if(c == 'A') return 'L';
    if(c == 'S') return 'D';
    if(c == 'D') return 'R';
}

string covert[11];

int main(){
    srand(time(0));
    covert[1] = "DDDDDDDDLUUUUUU";
    covert[2] = "DDDDDDDDLDLUDLLUUUUUUU";
    covert[3] = "DDDDDDDDLDLUUUUUUU";
    covert[4] = "DDDDDDDDLUUUUUUU";
    string get_ans = "DDDDDDDURRRRDDDDUURRRURRRULLLLLRRLLDDRRRRRDRRRUDLLUUUUUUUUUUDDRRUUUUULLLDDDDRDLLRRUUU";
    int T; scanf("%d",&T);
    while(T--){
        init();
        int t = 0;
        string ans;
        while(!check()) {
            int x = rand() % 100,dir;
            if(x < 40) dir = 0;
            else if(x < 80) dir = 3;
            else if(x < 90) dir = 1;
            else dir = 2;
            moveRobot(dir);
            t ++;
            ans += get(dir);
         //   cout << dir << endl;
         //   print();
        }
        string tt = covert[check()]; tt += get_ans;
        for(int i = 0;i < tt.length();i ++) moveRobot(getdir2(tt[i]));
        ans += tt;
        cout << ans.length() << endl << ans << endl;
        //print();
        /*cout << t << endl;

        cout << check() << endl;
        print();
        char s[2];
        string ans;
        while(~scanf("%s",s)) {
            char c = s[0];
            int dir = getdir(c);
            if(dir == 4) continue;
            moveRobot(dir);
            ans += deal(c);
            print();
            cout << ans << endl;
        }*/
    }
    return 0;
}
