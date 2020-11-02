#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 500010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
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

int sg[SZ];

struct node {
	node *par,*ch[27];
	int val;
}T[SZ], *root1, *lst1, *root2, *lst2;

int Tcnt = 0;

node *newnode(int x) {
	node *p = T + (++ Tcnt);
	sg[Tcnt] = -1;
	p -> par = 0;
	memset(p -> ch,0,sizeof p -> ch);
	p -> val = x;
	return p;
}

node* insert(int x,node *lst,node *root) {
	node *p = lst,*np = newnode(p -> val + 1);
	while(p && !p -> ch[x]) p -> ch[x] = np,p = p -> par;
	if(!p) np -> par = root;
	else {
		node *q = p -> ch[x];
		if(q -> val == p -> val + 1) np -> par = q;
		else {
			node *nq = newnode(p -> val + 1);
			memcpy(nq -> ch,q -> ch,sizeof nq -> ch);
			nq -> par = q -> par;
			q -> par = nq; np -> par = nq;
			while(p && p -> ch[x] == q) p -> ch[x] = nq,p = p -> par;
		}
	}
	return np;
}

LL sgsz[SZ][28],nxsz[SZ];

void dfs(node *p) {
	if(sg[p - T] != -1) return ;
	bool vis[33] = {0};
	for(int i = 0;i < 26;i ++) {
		if(p -> ch[i] != NULL) {
			dfs(p -> ch[i]);
			vis[sg[p -> ch[i] - T]] = 1;
			for(int j = 0;j <= 26;j ++) 
				sgsz[p - T][j] += sgsz[p -> ch[i] - T][j];
		}
	}
	for(int i = 0;i <= 30;i ++) if(!vis[i]) { sg[p - T] = i; break; }
	sgsz[p - T][sg[p - T]] ++;
	return ;
}

int Ans1[SZ],Ans2[SZ];
char s1[SZ],s2[SZ];
LL tmp[SZ];

int main() {
	lst1 = root1 = newnode(0);
	LL k = read();
	scanf("%s",s1);
	int len1 = strlen(s1);
	for(int i = 0;i < len1;i ++) lst1 = insert(s1[i] - 'a',lst1,root1);
	sg[lst1 - T] = 0; sgsz[lst1 - T][0] ++;
	int sz1 = lst1 - T;
	
	lst2 = root2 = newnode(0);
	scanf("%s",s2);
	int len2 = strlen(s2);
	for(int i = 0;i < len2;i ++) lst2 = insert(s2[i] - 'a',lst2,root2);
	sg[lst2 - T] = 0; sgsz[lst2 - T][0] ++;
	int sz2 = lst2 - T;
		
	dfs(root1); dfs(root2);
	
	
	node *p1 = root1,*p2 = root2;
	
	{
		LL sum = 0;
		for(int i = 0;i <= 26;i ++) sum += sgsz[p2 - T][i];
		for(int i = 0;i <= 26;i ++) tmp[i] = sum - sgsz[p2 - T][i];
		for(int i = 1;i <= sz1;i ++) {
			for(int j = 0;j <= 26;j ++)
				nxsz[i] += sgsz[i][j] * tmp[j];
		}
		
		while(233) {
			if(k - tmp[sg[p1 - T]] <= 0) break;
			k -= tmp[sg[p1 - T]];
			bool flag = 0;
			for(int i = 0;i < 26;i ++) {
				if(p1 -> ch[i]) {
					if(nxsz[p1 -> ch[i] - T] >= k) { 
						Ans1[++ Ans1[0]] = i; 
						p1 = p1 -> ch[i];
						flag = 1;
						break;
					}
					else k -= nxsz[p1 -> ch[i] - T];
				}
			}
			if(!flag) { puts("NO"); return 0; }
		}
	}
	
	for(int i = sz1 + 1;i <= sz2;i ++) {
		LL sum = 0;
		for(int j = 0;j <= 26;j ++)
			sum += sgsz[i][j];
		nxsz[i] = sum - sgsz[i][sg[p1 - T]];
	}

	while(k) {
		if(sg[p1 - T] != sg[p2 - T]) k --;
		if(!k) break;
		bool flag = 0;
		for(int i = 0,ls = -1;i < 26;i ++) {
			if(p2 -> ch[i]) {
			//	cout << i << endl;
				if(nxsz[p2 -> ch[i] - T] >= k) { 
					Ans2[++ Ans2[0]] = i; 
					p2 = p2 -> ch[i];
					flag = 1;
					break;
				}
				else {
					k -= nxsz[p2 -> ch[i] - T];
				}
			}
		}
		if(!flag) break;
	}
	
	for(int i = 1;i <= Ans1[0];i ++) printf("%c",Ans1[i] + 'a'); puts("");
	for(int i = 1;i <= Ans2[0];i ++) printf("%c",Ans2[i] + 'a'); puts("");
	
	return 0;
}
