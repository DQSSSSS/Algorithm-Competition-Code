#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ULL;
typedef long long LL;
typedef pair<int,int> pii;
const int SZ = 100010;
const LL INF = 1000000010;
const LL mod = 1000000007;
const int Dx[] = {0,1,0,-1};
const int Dy[] = {1,0,-1,0};

LL read()
{
    LL n = 0;
    char a = getchar();
    int flag = 0;
    while(a < '0' || a > '9') { if(a == '-') flag = 1; a = getchar(); }
    while(a >= '0' && a <= '9') n = n * 10 + a - '0',a = getchar();
    if(flag) n = -n;
    return n;
}

bool b[2333];

int main()
{
    int T = read();
    while(T --)
	{
        int rk,id;
        string name,zt;
        cin >> rk >> name >> id >> zt;
		printf("%3d|%-16s|%d|",rk,name.c_str(),id);
		printf("[");
        if(zt == "Running")
		{
            int d;
            cin >> d;
            for(int i = 1;i <= 10;i ++)
				if(i <= d) cout << "X";
				else cout << " ";
		}
		else
		{
			int l = 0,r = 0;
            if(zt == "FB") zt = "AC*";
			if(zt.length() == 3) l = 4,r = 3;
            else l = r = 4;
            while(l --) cout << " ";
            cout << zt;
            while(r --) cout << " ";
		}
		puts("]");
	}
	return 0;
}


