#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
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

const int BASE=(int)1e9;
const int WIDTH=9;

struct bign{
    int len,num[SZ];
    bign(){memset(num,0,sizeof(num)); len=1;}
    bign(LL x)
    {
        memset(num,0,sizeof(num)); len=0;
        do
        {
            num[++len]=x%BASE;
            x/=BASE;
        }while(x);
    }
}AA,BB,CC,DD;

void scanf(const string &in,bign &ans)
{
    int l=in.length();
    ans.len=(l-1)/WIDTH+1;
    for(int i=0;i<ans.len;i++)
    {
        int e=l-i*WIDTH;
        int s=max(0,e-WIDTH);
        sscanf(in.substr(s,e-s).c_str(),"%d",&ans.num[i+1]);
    }
}

bign operator +(const bign &a,const bign &b)
{
    bign ans;
    int i=1,x=0;
    while(i<=a.len||i<=b.len)
    {
        x=a.num[i]+b.num[i]+x;
        ans.num[i++]=x%BASE;
        x/=BASE;
    }
    ans.num[i]=x;
    ans.len=i;
    while(ans.len>1&&ans.num[ans.len]==0) ans.len--;
    return ans;
}

bool operator ==(const bign &a,const bign &b)
{
    if(a.len != b.len) return false;
    for(int i = 1;i <= a.len;i ++)
		if(a.num[i] != b.num[i]) return false;
	return true;
}

char sss[SZ * 10];
string s,A,B,C;

int main()
{
    scanf("%s",sss);
    s = sss;
    int n = strlen(sss);
    int len = n / 3,d = 2;
    for(int a = -d;a <= d;a ++)
		for(int b = -d;b <= d;b ++)
			for(int c = -d;c <= d;c ++)
			{
                int len1 = len + a,len2 = len + b,len3 = len + c;
                if(len1 <= 0 || len2 <= 0 || len3 <= 0 || len1 + len2 + len3 != n) continue;
                if((s[0] == '0' && len1 > 1) || (s[len1] == '0' &&len2 > 1) || (s[len1 + len2] == '0' && len3 > 1)) continue;
                A = s.substr(0,len1);
                B = s.substr(len1,len2);
                C = s.substr(len1 + len2,len3);
               // cout << len1 << " " << len2 << " " << len3 <<endl;
              //  cout << A << "+" << B << "=" << C << endl;
                scanf(A,AA),scanf(B,BB),scanf(C,CC);
                DD = AA + BB;
                if(DD == CC)
				{
                    cout << A << "+" << B << "=" << C << endl;
                    return 0;
				}
			}
	return 0;
}






