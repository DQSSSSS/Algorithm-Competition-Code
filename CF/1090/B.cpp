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

char s[SZ];
map<string,int> mp;
int Ans[SZ];
char a[110][100010];

int main(){
	int id = 0;
	while(gets(s)) {
		if(s[0] == '\\' && s[1] == 'b') break; 
		int len = strlen(s);
		for(int i = 0;i < len;i ++) {
			if(s[i] == '{') {
				i ++;
				string ss;
				while(s[i] != '}') ss += s[i],i ++;
				mp[ss] = ++ id;
			}
		}
	}
	int n = 0;
	for(int i = 24;s[i] != '}';i ++) n = n * 10 + s[i] - '0';
	int l = 1;
	while(gets(a[l])) l ++; l --;
	//cout << n << " " << l << endl;
	//for(int i = 1;i <= l;i ++) cout << a[i] << endl;
	for(int i = 1;i <= id;i ++) {
		for(int j = 1;j <= l - 1;j ++) {
			int p = 9;
			string ss;
			while(a[j][p] != '}') ss += a[j][p ++];
			if(mp[ss] == i) {Ans[i] = j; break; }
		}
	}
	bool flag = 0;
	for(int i = 1;i <= id;i ++) if(Ans[i] != i) flag = 1;
	if(!flag) return puts("Correct"),0;
	else puts("Incorrect");
	puts(s);
	for(int i = 1;i <= id;i ++) puts(a[Ans[i]]);
	puts(a[l]);
	return 0;
}
