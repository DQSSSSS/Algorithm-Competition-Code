#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 200100;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-12;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}


int ask(int a) {
    for(int i = 30;i >= 0;i --) {
        if(a>>i&1)
            return (1<<(i+1))-1;
    }
}

map<int,int> biao;

int main() {
    biao[2]=3;
    biao[3]=1;
    biao[7]=1;
    biao[15]=5;
    biao[31]=1;
    biao[63]=21;
    biao[127]=1;
    biao[255]=85;
    biao[511]=73;
    biao[1023]=341;
    biao[2047]=89;
    biao[4095]=1365;
    biao[8191]=1;
    biao[16383]=5461;
    biao[32767]=4681;
    biao[65535]=21845;
    biao[131071]=1;
    biao[262143]=87381;
    biao[524287]=1;
    biao[1048575]=349525;
    biao[2097151]=299593;
    biao[4194303]=1398101;
    biao[8388607]=178481;
    biao[16777215]=5592405;
    biao[33554431]=1082401;
    int q = read();
    while(q--) {
            int a = read();
        if(biao[a]) printf("%d\n",biao[a]);
        else printf("%d\n",ask(a));
    }
}
