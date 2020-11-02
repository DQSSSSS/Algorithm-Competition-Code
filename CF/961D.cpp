#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 100010;
const LL INF = 1e17 + 10;

LL read()
{
	LL n = 0;
	char a = getchar();
	bool flag = 0;
	while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
	while(a <= '9' && a >= '0') n = n * 10 + a - '0',a = getchar();
	if(flag) n = -n;
	return n;
}

int n;

int randint()
{
	return rand() << 16 | rand();
}

int randlr(int l,int r)
{
	return randint() % (r - l + 1) + l;
}

struct haha
{
	LL x,y;
}l[SZ];

bool b[SZ];

bool online(int x,int y,int z)
{
	LL dx1 = l[x].x - l[z].x,dy1 = l[x].y - l[z].y;
	LL dx2 = l[x].x - l[y].x,dy2 = l[x].y - l[y].y;
	if(dx1 * dy2 == dx2 * dy1) return true;
	return false;
}

bool check()
{
	if(n <= 4) return true;
	for(int i = 1;i <= 100;i ++)
	{
		for(int i = 1;i <= n;i ++) b[i] = 0;
		int id1,id2,id3,id4;
		do
		{
			id1 = randlr(1,n);
			id2 = randlr(1,n);
		}while(id1 == id2);
		int t = 0;
		for(int i = 1;i <= n;i ++)
			if(i == id1 || i == id2 || online(id1,id2,i)) 
				t ++,b[i] = 1;
		if(n - t <= 2) return true; //{ cout << id1 << " "<< id2 << " " << id3 << " " << id4 << endl; return true;} 
	//	cout << t << endl;
		int t1,t2;
		do
		{
			t1 = randlr(1,n - t);
			t2 = randlr(1,n - t);
		}while(t1 == t2);
		for(int i = 1;i <= n;i ++)
			if(b[i] == 0)
			{
				if(-- t1 == 0) id3 = i;
				if(-- t2 == 0) id4 = i;	
			}
	//	cout << id1 << " "<< id2 << " " << id3 << " " << id4 << endl;
		for(int i = 1;i <= n;i ++)
			if(b[i] == 0 && (i == id3 || i == id4 || online(id3,id4,i))) 
				t ++,b[i] = 1;
		//puts("233");
		if(t == n) return true; //{ cout << id1 << " "<< id2 << " " << id3 << " " << id4 << endl; return true;} 
	}
	return false;
}

int main()
{
	srand(3);
	n = read();
	for(int i = 1;i <= n;i ++)
		l[i].x = read(),l[i].y = read();
	if(check()) puts("YES");
	else puts("NO");
	return 0;
}

/*
13
1 0
2 0
3 0
4 0
5 0
6 0
7 0
8 0
9 0
10 0
11 1
12 1
13 3
*/
