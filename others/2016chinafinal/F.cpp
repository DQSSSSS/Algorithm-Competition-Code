#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 50010;
const int INF = 1e9 + 10;
const int mod = 998244353;
const LD eps = 1e-8;
const LD PI = acos(-1);

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
	ULL a,b;
	const static ULL p1 = 1000056479;
	const static ULL p2 = 1000189471;
	haha() : a(0),b(0) {}
	haha(ULL a) : a(a),b(a) {}
	haha(ULL a,ULL b) : a(a),b(b) {}
	haha operator *(haha o) { return (haha){a*o.a     %p1, b*o.b    %p2}; }
	haha operator *(ULL o) {  return (haha){a*o       %p1, b*o      %p2}; }
	haha operator +(haha o) {return (haha){(a+o.a)    %p1,(b+o.b)   %p2}; }
	haha operator +(ULL o) { return (haha){(a+o)      %p1,(b+o)     %p2}; }
	haha operator -(haha o) {return (haha){(a-o.a+p1) %p1,(b-o.b+p2)%p2}; }
	haha operator -(ULL o) { return (haha){(a-o+p1)   %p1,(b-o+p2)  %p2}; }
	void print() { cout << a << " " << b << " "; }
}mi[250010];

bool operator <(haha a,haha b) { return a.a == b.a ? a.b < b.b : a.a < b.a; }

vector<haha> h[SZ];
map<haha,int> mp;
string s[SZ];

haha get(int id,int l,int r) {
	return h[id][r] - h[id][l - 1] * mi[r-l+1];
}

bool smaller(int x,int y,int len) {
	for(int i = 0;i < len;i ++) 
		if(s[1][x+i-1] != s[1][y+i-1]) return s[1][x+i-1] < s[1][y+i-1];
	return false;
	/*int l = 0,r = len + 1;
	while(r - l > 1) {
		int mid = l + r >> 1;
		if(get(1,x,x+mid-1) != get(1,y,y+mid-1)) r = mid;
		else l = mid;
	}
//	cout << x << " " << y << " " << l << endl;
//	cout << s[1][x+l-1] << " " << s[1][y+l-1] << endl;
	//if(r > len) return false;
	return s[1][x+l-1] < s[1][y+l-1];*/
}

bool cmp(const string &a,const string &b) { return a.size() > b.size(); }
char S[250010];
int Ans[250010],n;

bool check(int len) {
	mp.clear();
	int sz = 0;
//	puts("--------");
//	cout << len << endl;
	for(int i = 1;i + len - 1 <= s[1].length();i ++) {
		int l = i,r = i + len - 1;
		if(!mp[get(1,l,r)]) {
			mp[get(1,l,r)] = 1,sz ++;
		//	cout << l << " " << r << " ";
		//	get(1,l,r).print(); puts("");
		}
		//cout << get(1,l,r) << endl;
	
	}
	int t = 0;
	for(int i = 2;i <= n;i ++) {
		if(s[i].length() < len) break;
		for(int j = 1;j + len - 1 <= s[i].length();j ++) {
			haha x = get(i,j,j+len-1);
		//	cout << i << " " << j << " "<< j+len-1 << " ";
			//x.print();puts("");
			if(mp[x]) {
				mp[x] = 0,t ++;
				
			}
		}
	}
	//cout << len << " " << t << " " << sz << endl;
	if(t < sz) return true;
	return false;
}

bool ispri(LL n){
	for(LL i = 2;i * i < n;i ++) if(n % i == 0) return false;
	return true;
}

int main() {
//	for(int i = 1e9;;i ++) if(ispri(i)) cout << i << endl;
	mi[0] = 1;
	for(int i = 1;i <= 250000;i ++) mi[i] = mi[i - 1] * 27;
	int T = read(),cc = 0;
	while(T --) {
		Ans[0] = 0;
		n = read();
		for(int i = 1;i <= n;i ++) {
			scanf("%s",S);
			s[i] = S;
		}
		sort(s + 2,s + 1 + n,cmp);
		for(int i = 1;i <= n;i ++) {
			h[i].clear();
			h[i].resize(s[i].length() + 1);
			for(int j = 1;j <= s[i].length();j ++) {
				h[i][j] = h[i][j - 1] * 27 + s[i][j - 1] - 'a' + 1;	
			}
		}
		
		int l = 0,r = s[1].length() + 1;
		while(r - l > 1) {
			int mid = l + r >>1;
			if(check(mid)) r = mid;
			else l = mid;
		}
		//cout << check(r) << " " << check(r + 1) << endl;
		int len = r;
		check(len);
		//cout << len << endl;
		printf("Case #%d: ",++ cc);
		if(len > s[1].length()) puts("Impossible");
		else {
			for(int i = 1;i + len - 1 <= s[1].length();i ++) {
				int l = i,r = i + len - 1;
				haha x = get(1,l,r);
				if(mp[x]) Ans[++ Ans[0]] = i;
			}
			int id = Ans[1];
			//cout << Ans[0] << endl;
			//for(int i = 1;i <= Ans[0];i ++,puts("")) 
			//	for(int j = 0;j < len;j ++) 
			//	cout << s[1][Ans[i]+j-1] << " "; puts("");
			for(int i = 2;i <= Ans[0];i ++) {
				if(smaller(Ans[i],id,len)) id = Ans[i];
			}
			//if(cc == 42) cout << len << endl;
			//else
			for(int i = 0;i < len;i ++) printf("%c",s[1][i+id-1]); puts("");
		}
	}	
	return 0;
}

/**
3
2
aba
bab
3
qnu
cvbb
bnu
3
a
aa
aaa

233
5
aacaadaabaa
aa
aba
aca
ada
*/
