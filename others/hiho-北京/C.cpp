#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> pii;
const int SZ = 1000010;
const int INF = 1e9 + 10;
const int mod = 1e9 + 7;
const LD eps = 1e-8;
const int dx[] = {0,1,0,-1};
const int dy[] = {1,0,-1,0};

LL read() {
    LL n = 0;
    char a = getchar();
    bool flag = 0;
    while(a > '9' || a < '0') { if(a == '-') flag = 1; a = getchar(); }
    while(a <= '9' && a >= '0') { n = n * 10 + a - '0',a = getchar(); }
	if(flag) n = -n;
	return n;
}

int change_to_num(string a) {
	int ans = 0;
	if(a == "A") ans = 1;
	else if(a == "J") ans = 11;
	else if(a == "Q") ans = 12;
	else if(a == "K") ans = 13;
	else if(a == "10") ans = 10;
	else ans = a[0] - '0';
	return ans;
}

string change_to_string(int a) {
	string ans;
	if(a == 1) return "A";
	else if(a == 11) ans = "J";
	else if(a == 12) ans = "Q";
	else if(a == 13) ans = "K";
	else if(a == 10) ans = "10";
	else ans += a + '0';
	return ans;
}

const int lexi_order[] = {0,10,2,3,4,5,6,7,8,9,1,11,13,12};

bool cmp_lexi_order(int a,int b) {
	return lexi_order[a] < lexi_order[b];
}

vector<int> g[8],table;

int get_num(int id,int x) {
	int num = 0;
	for(int i = 0;i < g[id].size();i ++)
		if(g[id][i] == x) num ++;
	return num;
}

void del(int id,int x,int num) {
	static vector<int> tt;
	tt.clear();
	for(int i = 0;i < g[id].size();i ++) {
		if(g[id][i] == x && num) { num --; continue; }
		tt.push_back(g[id][i]);
	}
	g[id].clear();
	for(int i = 0;i < tt.size();i ++) {
		g[id].push_back(tt[i]);
	}
}

void ins(int x,int num) {
	while(num --) table.push_back(x);
}

int true_ans,num,true_ans2,num2;

void statement(int id,int x) {
	true_ans = -1,num = 0;
	true_ans2 = -1,num2 = 0;
	if(id == 1) {	
		for(int i = 0;i < g[id].size();i ++) {
			if(g[id][i] == x) true_ans = x;
		}
		if(true_ans != -1) num = 1;
		else {
			sort(g[id].begin(),g[id].end(),cmp_lexi_order);
			true_ans = g[id][0];
			num = 1;
		}
		del(id,true_ans,num); ins(true_ans,num);
		return ;
	}
	else if(id == 2) {
		for(int i = 0;i < g[id].size();i ++) {
			if(g[id][i] == x) true_ans = x;
		}
		if(true_ans != -1) num = get_num(id,true_ans);
		else {
			sort(g[id].begin(),g[id].end(),cmp_lexi_order);
			true_ans = g[id][0];
			num = 1;
		}
		del(id,true_ans,num); ins(true_ans,num);
		return ;
	}
	else if(id == 3) {
		for(int i = 0;i < g[id].size();i ++) {
			if(g[id][i] == x) true_ans = x;
		}
		if(true_ans != -1) num = get_num(id,true_ans);
		else {
			sort(g[id].begin(),g[id].end(),cmp_lexi_order);
			int minnum = 233;
			for(int i = 0,j;i < g[id].size();i = j) {
				int t = 0;
				for(j = i;j < g[id].size() && g[id][j] == g[id][i];j ++)
					t ++;
				minnum = min(minnum,t);
			}
			for(int i = 0,j;i < g[id].size();i = j) {
				int t = 0;
				for(j = i;j < g[id].size() && g[id][j] == g[id][i];j ++)
					t ++;
				if(minnum == t) {
					true_ans = g[id][i];
					num = get_num(id,true_ans);
					break;
				}
			}
		}
		del(id,true_ans,num); ins(true_ans,num);
		return ;
	}
	else {
		int tmp = get_num(id,x);
		if(tmp == 3 || tmp == 4) {	
			true_ans = x; num = tmp;
			del(id,true_ans,num); ins(true_ans,num);
			return ;
		}
		else {
			if(tmp) {
				true_ans = x; num = tmp;
				del(id,true_ans,num); ins(true_ans,num);
				sort(g[id].begin(),g[id].end(),cmp_lexi_order);
				if(g[id].size()) {
					true_ans2 = g[id][0];
					num2 = 1;
					del(id,true_ans2,num2); ins(true_ans2,num2);
				}
			}
			else {
				sort(g[id].begin(),g[id].end(),cmp_lexi_order);
				if(g[id].size()) {
					true_ans = g[id][0];
					num = 1;
					del(id,true_ans,num); ins(true_ans,num);
				}
			}
			return ;
		}
	}
}

bool ischallenge(int nowid,int x,int id) {
	if(id == 1) {
		int nx = x + 1; if(nx == 14) nx = 1;
		if(nowid == 4 && get_num(id,nx) == 0) return true;
		if(num + num2 + get_num(id,x) > 4) return true;
		return false;
	}
	else if(id == 2) {
		int nx = x + 1; if(nx == 14) nx = 1;
		if(nowid == 1 && get_num(id,nx) == 0) return true;
		return false;
	}
	else if(id == 3) {
		if(get_num(id,x) == 4) return true;
		return false;
	}
	else {
		if(g[nowid].size() == 0) return true;
		return false;
	}
}


int main() {
	string s;
	while(cin >> s) {
		table.clear();
		for(int i = 1;i <= 4;i ++) g[i].clear();
		g[1].push_back(change_to_num(s));
		for(int i = 2;i <= 13;i ++) {
			cin >> s; g[1].push_back(change_to_num(s));
		}
		for(int k = 2;k <= 4;k ++)
			for(int i = 1;i <= 13;i ++) {
				cin >> s; g[k].push_back(change_to_num(s));
			}
		int nowid = 1,now = 1;
		while(233) {
			if(nowid == 5) nowid = 1;
			if(now == 14) now = 1;
			bool flag = 0;
			for(int i = 1;i <= 4;i ++) if(g[i].size() == 0u) { flag = 1; break; }
			if(flag) break;
		/*	
			cout << nowid << " "<< now << endl;
			int sum = 0;
			for(int i = 1;i <= 4;i ++) cout << g[i].size() << " "; cout << table.size() << " "; puts("");
			for(int i = 1;i <= 4;i ++) {
				if(g[i].size() == 0) puts("WINNER");
				else {
					sort(g[i].begin(),g[i].end());
					for(int j = 0;j < g[i].size();j ++) {
						cout << change_to_string(g[i][j]);
						if(j + 1 == g[i].size()) puts("");
						else cout << " ";
					}
				}
			}
			for(int i = 1;i <= 4;i ++) sum += g[i].size(); sum += table.size(); assert(sum == 52);
		*/	
			statement(nowid,now);
			
		//	cout << true_ans << " " << num << " " << true_ans2 << " " << num2 << endl;
			
			for(int i = nowid + 1 == 5 ? 1 : nowid + 1;i != nowid;i = i + 1 == 5 ? 1 : i + 1) {
				if(ischallenge(nowid,now,i)) {
			//		cout << i << " ";
					if(now == true_ans && true_ans2 == -1) {
						for(int j = 0;j < table.size();j ++)
							g[i].push_back(table[j]);
						table.clear();
				//		puts("failed");
					}
					else {
						for(int j = 0;j < table.size();j ++)
							g[nowid].push_back(table[j]);
						table.clear();
				//		puts("successful");
					}
					break;
				}
			}
		//	puts("----------------------");			
			nowid ++; now ++;
		}
		for(int i = 1;i <= 4;i ++) {
			if(g[i].size() == 0) puts("WINNER");
			else {
				sort(g[i].begin(),g[i].end());
				for(int j = 0;j < g[i].size();j ++) {
					cout << change_to_string(g[i][j]);
					if(j + 1 == g[i].size()) puts("");
					else cout << " ";
				}
			}
		}
	}
	return 0;
}
/**
A A A A 2 2 2 2 3 3 3 3 K
4 4 4 4 5 5 5 5 6 6 6 6 K
7 7 7 7 8 8 8 8 9 9 9 9 K
10 10 10 10 J J J J Q Q Q Q K
*/
