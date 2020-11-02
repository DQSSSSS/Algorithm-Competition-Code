#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;


LL read()
{
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

struct haha
{
	int n;
	string s[250];
};

map<string,haha> mp;
map<string,bool> h;

bool issuf(string s1,string s2)
{
    if(s1.length() >= s2.length()) return false;
    int d = s2.length() - s1.length();
    for(int i = 0;i < s1.length();i ++)
	{
        if(s1[i] != s2[d + i]) return false;
	}
	return true;
}

string ans[250];

int main()
{
	int n = read();
    for(int i = 1;i <= n;i ++)
	{
        string s;
        cin >> s;
        int k = read();
        for(int j = 1;j <= k;j ++)
		{
            string ss;
            cin >> ss;
            mp[s].s[++ mp[s].n] = ss;
		}
	}
	cout << mp.size() << endl;
    for(map<string,haha> :: iterator it = mp.begin();it != mp.end();it ++)
	{
		haha t = it -> second;
		h.clear();
		cout << it -> first << " ";
		int tot = 0;
        for(int i = 1;i <= t.n;i ++)
		{
			bool flag = 0;
            for(int j = 1;j <= t.n;j ++)
			{
                if(issuf(t.s[i],t.s[j])) { flag = 1; break;}
			}
			if(flag) continue;
			if(h[t.s[i]]) continue;
			h[t.s[i]] = 1;
			ans[++ tot] = t.s[i];
		}
		cout << tot << " ";
		for(int i = 1;i <= tot;i ++) cout << ans[i] << " ";
		puts("");
	}
	return 0;
}




