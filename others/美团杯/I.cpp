#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
const int SZ = 2000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

struct node {
    node *ch[28],*par;
    int val;
    node(int x) {
        memset(ch,0,sizeof ch);
        par = NULL;
        val = x;
    }
}*root;

node* newnode(int x) {
    return new node(x);
}

LL ask(node *p) {
    return p -> val - p -> par -> val;
}

LL nowT,ans,sum[28];

node* insert(int x,node *lst,node *root) {
	LL tmp = nowT;
	node *p = lst,*np = newnode(p -> val + 1);
	while(p && !p -> ch[x]) p -> ch[x] = np,p = p -> par;
	if(!p) {
        np -> par = root;

        tmp += ask(np);
        sum[x] += ask(np);

	}
	else {
		node *q = p -> ch[x];
		if(q -> val == p -> val + 1) {
            np -> par = q;

            tmp += ask(np);
            sum[x] += ask(np);

		}
		else {
			node *nq = newnode(p -> val + 1);
			memcpy(nq -> ch,q -> ch,sizeof nq -> ch);

			nq -> par = q -> par;
            tmp += ask(nq);
            sum[x] += ask(nq);

            tmp -= ask(q);
            sum[x] -= ask(q);
			q -> par = nq;
            tmp += ask(q);
            sum[x] += ask(q);

			np -> par = nq;

            tmp += ask(np);
            sum[x] += ask(np);

			while(p && p -> ch[x] == q) p -> ch[x] = nq,p = p -> par;
		}
	}
	//printf("%lld\n",tmp+1);
	//for(int i = 0;i < 26;i ++) printf("%lld ",sum[i]); puts("");
    ans += tmp + 1;
    ans -= sum[x];
    nowT = tmp;
	return np;
}

char s[SZ];
int main() {
    scanf("%s",s+1);
    int n = strlen(s+1);
    root = newnode(0);
    node *p = root;
    for(int i = n;i >= 1;i --) {
        int x = s[i] - 'a';
        p = insert(x,p,root);
    }
    printf("%lld\n",ans+1);
}

