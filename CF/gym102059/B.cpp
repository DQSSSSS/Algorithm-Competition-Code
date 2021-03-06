#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pll;
typedef pair<int,int> pii;
const int SZ = 2000100;
const int INF = 1e9 + 10;
const int mod = 998244353;
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

const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

char mp[55][55];
int bj[55][55],n,m;

bool isin(int x,int y) {
    return 1<=x&&x<=n&&1<=y&&y<=m;
}

stack<pii> S;

int main() {
    n = read(),m = read();
    for(int i = 1;i <= n;i ++) scanf("%s",mp[i]+1);
    int sx,sy;
    int tot = 0;
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            if(mp[i][j] == 'O') {
                sx = i; sy = j;
            }
            if(mp[i][j] == '*') tot ++;
        }
    }

    for(int i = 0;i < 4;i ++) {
        int x = sx,y = sy;
        int now = 0;
        while(isin(x+dx[i],y+dy[i]) && mp[x+dx[i]][y+dy[i]] != '#') {
            x += dx[i]; y += dy[i];
            if(mp[x][y] == '*') bj[x][y] = 1,now ++;
        }
        while(S.size()) S.pop();
        S.push(make_pair(x,y));
        int sum = 10000000;
        while(sum --) {
            int mb = rand() % 100 + 1;
            if(mb <= 20 && S.size() > 1) {
                S.pop();
                int nx = S.top().first;
                int ny = S.top().second;
                while(x!=nx||y!=ny) {
                    if(mp[x][y] == '*') {
                        if(-- bj[x][y] == 0) now --;
                    }
                    if(x>nx) x--;
                    else if(x<nx) x++;
                    else if(y>ny) y --;
                    else y++;
                }
            }
            else {
                int d = rand()%4;
                while(isin(x+dx[d],y+dy[d]) && mp[x+dx[d]][y+dy[d]] != '#') {
                    x += dx[d]; y += dy[d];
                    if(mp[x][y] == '*') {
                        if(bj[x][y] ++ == 0) now ++;
                    }
                }
                if(now == tot) return puts("YES"),0;
                S.push(make_pair(x,y));
            }
        }
        for(int j = 1;j <= n;j ++)
            for(int k = 1;k <= m;k ++)
                bj[j][k] = 0;
    }
    puts("NO");
}
/**
50 50
**************************************************
**************************************************
*************************************************#
#*************************************************
************************************************##
##************************************************
***********************************************###
###***********************************************
**********************************************####
####**********************************************
*********************************************#####
#####*********************************************
********************************************######
######********************************************
*******************************************#######
#######*******************************************
******************************************########
########******************************************
*****************************************#########
#########*****************************************
****************************************##########
##########****************************************
***************************************###########
###########***************************************
**************************************############
############**************************************
*************************************#############
#############*************************************
************************************##############
##############************************************
***********************************###############
###############***********************************
**********************************################
################**********************************
*********************************#################
#################*********************************
********************************##################
##################********************************
*******************************###################
###################*******************************
******************************####################
####################******************************
*****************************#####################
#####################*****************************
****************************######################
######################****************************
***************************#######################
#######################***************************
**************************########################
########################**************************
*/
