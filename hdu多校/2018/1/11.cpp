#include<bits/stdc++.h>
using namespace std;

const int SZ = 100010;
const int INF = 1000000010;
const int MOD = 1000000007;

int get_num(char s[],int l,int len) {
    int ans = 0;
    for(int i = l;i < l + len;i ++)
		ans = ans * 10 + s[i] - '0';
	return ans;
}

int find(char s[],char c) {
    int ans = -1;
    int len = strlen(s);
    for(int i = 0;i < len;i ++)
		if(s[i] == c)
			return i;
	return ans;
}

void calc(int &hh,int &mm,int x,int y,int f) {
//	cout << x << " "<< y << " " << f << endl;
    if(f == 1) x = -x,y = -y;
    x = x - 8;
	hh += x;
	mm += y * 6;
	hh += mm / 60; mm %= 60;
	hh %= 24;
    if(mm < 0) mm += 60,hh --;
    if(hh < 0) hh += 24;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T --) {
		int hh,mm;
		scanf("%d%d",&hh,&mm);
        char s[20];
        scanf("%s",s);
        int x = 0,y = 0,f = 0;
		if(find(s,'.') != -1) {
            int p = find(s,'-');
            int d = find(s,'.');
			if(p == -1) {
                p = find(s,'+');
                x = get_num(s,p + 1,d - p - 1);
                y = get_num(s,d + 1,strlen(s) - d - 1);
			}
			else {
				f = 1;
				p = find(s,'-');
                x = get_num(s,p + 1,d - p - 1);
                y = get_num(s,d + 1,strlen(s) - d - 1);
			}
        }
        else {
			int p = find(s,'+');
			if(p == -1) p = find(s,'-'),f = 1;
            x = get_num(s,p + 1,strlen(s) - p - 1);
        }
        calc(hh,mm,x,y,f);
        printf("%02d:%02d\n",hh,mm);
    }
	return 0;
}
