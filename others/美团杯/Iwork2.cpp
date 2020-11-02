#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 3010;
const int INF = 1e9 + 10;
const int mod = 998244353;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

bool isNum(char c) {
    return '0' <= c && c <= '9';
}

struct matrix {
    int mp[130][130],n,m;

    void print() {
        puts("-----");
        for(int i = 0;i < n;i ++) {
            for(int j = 0;j < m;j ++) {
                printf("%d",mp[i][j]);
            }
            puts("");
        }
    }

}a[SZ];

matrix operator *(matrix a,matrix b) {
    matrix ans;
    memset(ans.mp,0,sizeof ans.mp);
    ans.n = a.n; ans.m = b.m;
    for(int i = 0;i < a.n;i ++) {
        for(int j = 0;j < b.m;j ++) {
            for(int k = 0;k < a.m;k ++) {
                ans.mp[i][j] ^= a.mp[i][k] & b.mp[k][j];
            }
        }
    }
    return ans;
}

matrix merge(matrix a,matrix b) {
    return a * b;
}

typedef unsigned long long ull;
ull ran(){
	static ull x=233;
	x^=x<<13;
	x^=x>>7;
	x^=x<<17;
	return x;
}

void printbit(ull a) {
    for(int i = 0;i < 64;i ++) {
        printf("%d",a>>i&1);
    }
    puts("");
}

char s[SZ];
int main() {
    printbit(ran());
    freopen("I/large.cpp","r",stdin);

    matrix s1; s1.n = s1.m = 64;
    a[1] = s1;
    for(int j = 0;j < 64;j ++) a[1].mp[j][j] = 1;

    memset(s1.mp,0,sizeof s1.mp);
    for(int j = 0;j < 64;j ++) {
        s1.mp[j][j] = 1;
        int i = j - 13;
        if(0 <= i && i < 64) {
            s1.mp[i][j] = 1;
        }
    }
    a[1] = a[1] * s1;
  //  a[1].print();

    memset(s1.mp,0,sizeof s1.mp);
    for(int j = 0;j < 64;j ++) {
        s1.mp[j][j] = 1;
        int i = j + 7;
        if(0 <= i && i < 64) {
            s1.mp[i][j] = 1;
        }
    }
    a[1] = a[1] * s1;
 //       a[1].print();


    memset(s1.mp,0,sizeof s1.mp);
    for(int j = 0;j < 64;j ++) {
        s1.mp[j][j] = 1;
        int i = j - 17;
        if(0 <= i && i < 64) {
            s1.mp[i][j] = 1;
        }
    }
    a[1] = a[1] * s1;
  //      a[1].print();




   /* for(int j = 0;j < 64;j ++) {
        vector<int> vec = {j,j-13,j+7,j-6,j-17,j-30,j-10,j-23};
        for(int i : vec) {
            if(0 <= i && i < 64) {
                a[1].mp[i][j] ^= 1;
            }
        }
    }*/
    for(int i = 64;i < 128;i ++) a[1].mp[i][i] = 1;

    for(int i = 0;i < 128;i ++) a[0].mp[i][i] = 1;
    for(int i = 0;i < 64;i ++) a[0].mp[i][i+64] = 1;

    a[0].n = a[0].m = 128;
    a[1].n = a[1].m = 128;

    a[0] = a[1] * a[0];
   // a[0].print();
   // a[1].print();

    string s;
    int line = 0;
    while(getline(cin,s)) {
        line ++;
        if(s[0] == 'v' && line >= 13) {
            int i = 6;
            vector<int> vec;
            while(i < s.size()) {
                int num = 0;
                while(i < s.size() && isNum(s[i])) {
                    num = num * 10 + s[i] - '0';
                    i ++;
                }
                while(i < s.size() && !isNum(s[i])) i ++;
                vec.push_back(num);
            }
            int now = vec[0],u = vec[1],v = vec[2];
            //printf("%d %d %d\n",now,u,v);
            a[now] = merge(a[u],a[v]);
         //   printf("%d %lld %lld\n",now,a[now].A,a[now].B);
        }
    }

    matrix f;
    f.n = 1; f.m = 128;
    for(int i = 0;i < 8;i ++)
        if(233 >> i & 1) f.mp[0][i] = 1;

    int ed = 10;

    f = f * a[ed];

    f.print();

    ull ans = 0;
    for(int i = 64;i < 128;i ++) {
        ans |= ((ull)f.mp[0][i]) << (i-64);
    }
    cout << ans << endl;
}
//250002325160

/*
10
my :16220815901847704926
std:16220815901847704926

0
250002325160

250002348712


2
my : 10392665599527563317
std: 10392665599527563317



7 1 3 4 8 6 2 9 5
2 4 9 3 5 7 8 6 1
8 5 6 2 1 9 4 7 3
6 7 5 9 4 8 1 3 2
4 2 8 7 3 1 9 5 6
3 9 1 6 2 5 7 8 4
1 8 2 5 9 3 6 4 7
9 3 7 1 6 4 5 2 8
5 6 4 8 7 2 3 1 9

*/
