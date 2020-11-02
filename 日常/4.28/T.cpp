#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

ULL f[110][22];

void pre()
{
	for(int i = 1;i <= 9;i ++) f[1][i] = 1;
	for(int i = 2;i <= 100;i ++)
		for(int j = 0;j <= 9;j ++)
			for(int k = j;k <= 9;k ++)
				f[i][j] += f[i - 1][k];
}

int ws(int x)
{
	int t = 0;
	if(x == 0) return 1;
	while(x) x /= 10,t ++;
	return t;
}

string s;

bool check(int d)
{
	for(int i = 0;i < s.length();i ++) if(d == s[i] - '0') return false;
	
	int n = s.length(),x = 0,y = 0,z = 0,pos,fz = 0;
	for(int i = 0;i < s.length();i ++) if(s[i] == '=') pos = i;
	for(int i = pos + 1;i < n;i ++)
	{
		if(i == pos + 1 && s[i] == '-') { fz = 1; continue; }
		int c = s[i] == '?' ? d : s[i] - '0';
		z = z * 10 + c;
	}
	
	bool fx = 0,fy = 0;
	int pos2 = 0;
	for(int i = 0;i < pos;i ++)
	{
		if(i == 0 && s[i] == '-') { fx = 1; continue; }
		if(s[i] == '-' || s[i] == '+' || s[i] == '*') {pos2 = i; break;} 
		int c = s[i] == '?' ? d : s[i] - '0';
		x = x * 10 + c;
	}
	for(int i = pos2 + 1;i < pos;i ++)
	{
		if(i == pos2 + 1 && s[i] == '-') { fy = 1; continue; }
		int c = s[i] == '?' ? d : s[i] - '0';
		y = y * 10 + c;
	}
	if(fx) x = -x;
	if(fy) y = -y;
	if(fz) z = -z;
	
	if((fx && ws(x) != pos2 - 1) || (!fx && ws(x) != pos2)) return false;
	if((fy && ws(y) != pos - pos2 - 2) || (!fy && ws(y) != pos - pos2 - 1)) return false;
	if((fz && ws(z) != n - pos - 2) || (!fz && ws(z) != n - pos - 1)) return false;
	
	if(s[pos2] == '-') { if(x - y == z) return true; }
	if(s[pos2] == '*') { if(x * y == z) return true; }
	if(s[pos2] == '+') { if(x + y == z) return true; }
	return false;
}

int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		cin >> s;	
		int ans = -1;
		for(int i = 0;i <= 9;i ++)
			if(check(i))
			{
				ans = i; break;
			}
		cout << ans << endl;
	}
	return 0;
}

