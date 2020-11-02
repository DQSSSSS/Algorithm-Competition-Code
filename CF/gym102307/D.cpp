#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int,int> pii;
typedef pair<LL,int> pli;
const int SZ = 1e5 + 10;
const int INF = 1e9 + 10;
const LL mod = 1e9 + 7;
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

struct pq {
    priority_queue<int> q;
    bool tag[SZ];

    void del(int x) {
        tag[x] = 1;
    }

    int top() {
        while(q.size() && tag[q.top()]) tag[q.top()] = 0,q.pop();
        return q.top();
    }

    bool empty() {
        while(q.size() && tag[q.top()]) tag[q.top()] = 0,q.pop();
        return q.empty();
    }

    void push(int x) {
        q.push(x);
    }

    void clear() {
        while(q.size()) {
            tag[q.top()] = 0;
            q.pop();
        }
    }
}Q;

char s[SZ];
int tim[SZ];
int col[SZ];

vector<pair<int,pii> > A[333][333];
vector<int> Add[SZ];
vector<int> Del[SZ];

int main() {
    scanf("%s",s+1);
    int B = 1000,n = strlen(s+1);
    int q = read();
    for(int cc = 1;cc <= q;cc ++) {
        int i = read(),a = read(),k = read();
        char ss[2]; scanf("%s",ss);
        char c = ss[0];
        if(k <= B) {
            for(int j = 0;j <= k;j ++) {
                int p = i+j*a;
                tim[p] = cc;
                s[p] = c;
            }
        }
        else {
            int r = i % a;
            A[a][r].push_back(make_pair(cc,make_pair(i/a,i/a+k)));
            col[cc] = c;
        }
    }
    for(int p = 1;p < n / B;p ++) {
        for(int r = 0;r < p;r ++) {
            if(A[p][r].size() == 0) continue;
            int len = 0;
            for(;r + p*len <= n;len ++);
            for(pair<int,pii> pp : A[p][r]) {
                Add[pp.second.first].push_back(pp.first);
                Del[pp.second.second].push_back(pp.first);
            }


            for(int i = 0;i < len;i ++) {
                for(int x : Add[i]) Q.push(x);
                if(!Q.empty()) {
                    int x = Q.top();
                    if(tim[i*p+r] < x) tim[i*p+r] = x,s[i*p+r] = col[x];
                }
                for(int x : Del[i]) Q.del(x);
            }

            for(pair<int,pii> pp : A[p][r]) {
                Add[pp.second.first].clear();
                Del[pp.second.second].clear();
            }
        }
    }
    printf("%s\n",s+1);
}

/**
xaabacabcdacabdbacad
xaabacabcdacabdbacad
xaabacabcdacabdbacad
*/
