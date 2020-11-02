#include<bits/stdc++.h>
using namespace std;

typedef unsigned int UI;
typedef unsigned long long ULL;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
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

struct haha {
	string s;
	int S;
	int id;
}a[SZ];

bool cmp(const haha &a,const haha &b) { 
	if(a.S == b.S) return a.s < b.s;
	return a.S < b.S;
}

bool operator !=(const haha &a,const haha &b) { 
	return a.S != b.S || a.s != b.s;
}

char s1[SZ],s2[SZ];
	
int main() {
	int n = read();
	for(int k = 1;k <= n;k ++) {
		scanf("%s%s",s1,s2);
		int l1 = strlen(s1),l2 = strlen(s2);
		int S = 0;
		for(int i = 0;i < l2;i ++) S |= 1 << (s2[i] - 'a');
		a[k].S = S;
		int l = l1 - 1;
		while(S & (1 << (s1[l] - 'a'))) l --;
		for(int i = 0;i <= l;i ++) a[k].s += s1[i];
		a[k].id = k;
	}
	sort(a + 1,a + 1 + n,cmp);
	int tot = 0;
	//for(int i = 1;i <= n;i ++) cout << a[i].S << " " << a[i].s << " " << a[i].id << endl;
	for(int i = 1;i <= n;i ++){
		if(i == n || (a[i] != a[i + 1])) tot ++;
	}
	printf("%d\n",tot);
	for(int i = 1,l = 1;i <= n;i ++){
		if(i == n || (a[i] != a[i + 1])) {
			printf("%d ",i - l + 1);
			while(l <= i) printf("%d ",a[l].id),l ++;	
			puts("");
		}
	}
	return 0;
}
	
