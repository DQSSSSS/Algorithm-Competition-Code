#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 2000010;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 +a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

string ss[110];

int main()
{
	//freopen("in.txt","r",stdin);
	int n = 0;
	while(getline(cin,ss[++ n])); n --;
	
	bool wx = 0,dl = 0,qd = 0;	
	for(int k = 1;k <= n;k ++)
	{
		string s = ss[k];
		if(!s.length()) continue;
		
		
		if(s[0] == '#')
		{
			int t = 0;
			for(int i = 0;i < s.length() && s[i] == '#';i ++)
				t ++;
			printf("<h%d>",t);
			for(int i = t - 1,f = 0;i < s.length();i ++)
			{
				if(s[i] == '#') continue;
				if(s[i] == ' ')
				{
					if(!f) continue;
					cout << s[i];
				}
				else
				{
					f = 1;
					if(s[i] == '_')
					{
						if(qd == 0) cout << "<em>",qd = 1;
						else cout << "</em>",qd = 0;
					}
					else if(s[i] == '[')
					{
						int l = i,r;
						string S;
						for(r = l + 1;r < s.length() && s[r] != ']';r ++)
						{
							if(s[r] == '_')
							{
								if(qd == 0) S += "<em>",qd = 1;
								else S += "</em>",qd = 0;
							}
							else S += s[r];
						}
						
						string text = S;
						l = r + 1;
						for(r = l + 1;r < s.length() && s[r] != ')';r ++);
						string link = s.substr(l + 1,r - l - 1);
						printf("<a href=\"%s\">%s</a>",link.c_str(),text.c_str());
						i = r;
					}
					else 
						cout << s[i];
				}
			}
			printf("</h%d>\n",t);
		}
		else if(s[0] == '*')
		{
			if(wx == 0) puts("<ul>"),wx = 1;
			cout << "<li>";
			for(int i = 1,f = 0;i < s.length();i ++)
				if(s[i] == ' ')
				{
					if(!f) continue;
					cout << s[i];
				}
				else
				{
					f = 1;
					if(s[i] == '_')
					{
						if(qd == 0) cout << "<em>",qd = 1;
						else cout << "</em>",qd = 0;
					}
					else if(s[i] == '[')
					{
						int l = i,r;
						string S;
						for(r = l + 1;r < s.length() && s[r] != ']';r ++)
						{
							if(s[r] == '_')
							{
								if(qd == 0) S += "<em>",qd = 1;
								else S += "</em>",qd = 0;
							}
							else S += s[r];
						}
						
						string text = S;
						l = r + 1;
						for(r = l + 1;r < s.length() && s[r] != ')';r ++);
						string link = s.substr(l + 1,r - l - 1);
						printf("<a href=\"%s\">%s</a>",link.c_str(),text.c_str());
						i = r;
					}
					else 
						cout << s[i];
				}
			printf("</li>\n");
			if(k == n || ss[k + 1].length() == 0) printf("</ul>\n"),wx = 0;
		}
		else
		{
			if(dl == 0) cout << "<p>",dl = 1;
			for(int i = 0,f = 0;i < s.length();i ++)
			{
				if(s[i] == '_')
				{
					if(qd == 0) cout << "<em>",qd = 1;
					else cout << "</em>",qd = 0;
				}
				else if(s[i] == '[')
				{
					int l = i,r;
					string S;
					for(r = l + 1;r < s.length() && s[r] != ']';r ++)
					{
						if(s[r] == '_')
						{
							if(qd == 0) S += "<em>",qd = 1;
							else S += "</em>",qd = 0;
						}
						else S += s[r];
					}
					
					string text = S;
					l = r + 1;
					for(r = l + 1;r < s.length() && s[r] != ')';r ++);
					string link = s.substr(l + 1,r - l - 1);
					printf("<a href=\"%s\">%s</a>",link.c_str(),text.c_str());
					i = r;
				}
				else 
					cout << s[i];
			}
			if(k == n || ss[k + 1].length() == 0) printf("</p>"),dl = 0;
			puts("");
		}
	}
	return 0;
}


