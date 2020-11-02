#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
const int SZ = 1e6 + 10;
const int INF = 1e9 + 10;

int get(string s,int l,int r)
{
	int ans = 0;
	for(int i = l;i <= r;i ++)
		ans = ans * 10 + s[i] - '0';
	return ans;
}

int dd;

void change(int &a,int &b,int y)
{
	for(int i = 2;i <= 128;i <<= 1)
	{
		for(int j = 1;j < i;j += 2)
		{
			int ta = j * dd,tb = i;
		//	if(tb == 16) cout << ta << " " << tb << " " << ta / tb << endl;
			if(y == ta / tb || y == ta / tb + 1 || y == (int)(ta * 1.0 / tb + 0.5)) 
			{
				a = ta / dd,b = tb;
				return ;
			}
		}
	}	
}
		
int main()
{
	int T;
	cin >> T;
	while(T --)
	{
		int x = 0,y = 0,ws;
		string s;
		cin >> s;
		int n = s.length();
		if(s[0] == '.') y = get(s,1,n - 1),ws =  n - 1;
		else
		{
			int pos = -1;
			for(int i = 0;i < n;i ++) if(s[i] == '.') pos = i;
			if(pos == -1) x = get(s,0,n - 1),ws = 0;
			else x = get(s,0,pos - 1),y = get(s,pos + 1,n - 1),ws = n - pos - 1;
		}
		dd = 1;
		for(int k = 1;k <= ws;k ++) dd *= 10;
		//cout << x << " "<< y << endl;
		if(x != 0 && y == 0) cout << x << "\"" << endl;
		else
		{
			if(x) cout << x << " ";
			int a,b;
			change(a,b,y);
			cout << a << "/" << b << "\"" << endl;
		}
	}
	return 0;
}



