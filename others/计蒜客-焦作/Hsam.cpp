#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

typedef long long LL;
const int SZ = 1000010;

struct node{
    node* ch[27];
    node *par;
    int val;
}T[SZ], *last, *root;

int Tcnt = 0;

node* newnode(int x)
{
    node *k = T + (Tcnt ++);
    k -> val = x;
    k -> par = NULL;
    k -> ch[0] = k -> ch[1] = NULL;
    return k;
}

LL ans = 0;
int a,b;

LL get_ans(node *p)
{
	LL d = p -> val - p -> par -> val;
	if(a <= d && d <= b) return d;
    return 0;
}

void insert(int x)
{
    node *p = last,*np = newnode(p -> val + 1);
    while(p && !p -> ch[x])
        p -> ch[x] = np,p = p -> par;
    if(!p)
        np -> par = root;
    else
    {
        node *q = p -> ch[x];
        if(q -> val == p -> val + 1)
            np -> par = q;
        else
        {
            node *nq = newnode(p -> val + 1);
            memcpy(nq -> ch,q -> ch,sizeof(q -> ch));
            nq -> par = q -> par;
            q -> par = nq;
            np -> par = nq;
            while(p && p -> ch[x] == q)
                p -> ch[x] = nq,p = p -> par;
        }
    }
    last = np;
}

void init() {
	Tcnt = 0;
    root = newnode(0);
    last = root;
}

char s[SZ];

int main() {
	while(~scanf("%s%d%d",s,&a,&b)) {
		init();
		int n = strlen(s);
		for(int i = 0;i < n;i ++) insert(s[i] - 'A');
		//puts("");
		LL ans = 0;
		for(int i = 0;i < Tcnt;i ++) ans += get_ans(T + i);
		printf("%lld\n",ans);
	}
    return 0;
}
