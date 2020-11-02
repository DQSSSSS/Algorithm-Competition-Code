#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int SZ = 200010;
const int INF = 1e9 + 10;

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

int sz,numb,n,m;

struct haha {
    haha *pr,*nx;
    vector<int> g;
    haha(haha *pr,haha *nx) :pr(pr),nx(nx) { g.clear(); }
}*a[325], *head, *tmp[1010];
int tmpsz;


void print() {
//	puts("a : ");
	for(haha *p = head;p != nullptr;p = p -> nx) {
		if(p -> nx != nullptr) assert(p -> nx -> pr == p);
		if(p -> pr != nullptr) assert(p -> pr -> nx == p);
        for(int i = 0;i < p -> g.size();i ++)
            cout << p -> g[i] << " ";
//		puts("");
	}
	puts("");
}


void link(haha *a,haha *b) {
	if(a != nullptr) a -> nx = b;
    if(b != nullptr) b -> pr = a;
}

void merge(haha* &a,haha *b) {
    if(a -> g.size() + b -> g.size() > 2 * sz) return ;
   // if(a -> g.size() > b -> g.size()) {
	//	puts("haha1");
       // for(int i = 0;i < b -> g.size();i ++)
		a -> g.insert(a -> g.end(),b -> g.begin(),b -> g.end());
        link(a,b -> nx);
        delete b;
	//	b = a -> nx;
    //}
   /* else {
    //	puts("haha2");
		//for(int i = 0;i < a -> g.size();i ++)
		b -> g.insert(b -> g.begin(),a -> g.begin(),a -> g.end());
        link(a -> pr,b);
        if(a == head) head = b;

        delete a;
        a = b -> pr;
	}*/
}

void maintain() {
	//print();
    for(haha *p = head;p != nullptr && p -> nx != nullptr;p = p -> nx) {
        merge(p,p -> nx);
        //if(p == nullptr) puts("fuck");
     //   cout << p -> g.size() << endl;
     //   cout << p -> nx -> g.size() << endl;
     //   system("pause");
    }
   // print();
}

int main(){
    n = read(),m = read();
	sz = sqrt(n) + 1; numb = 0;

	haha *lst = nullptr;
    for(int i = 0; i * sz + 1 <= n; i ++,numb ++) {
        haha *p = new haha(nullptr,nullptr);
		if(i == 0) head = p;
        link(lst,p);
        for(int j = i * sz + 1;j <= min(i * sz + sz,n);j ++) {
            p -> g.push_back(j);
        }
        lst = p;
    }

    while(m --) {

      //  print();

        int l = read(),r = read();
        r = l + r - 1;
        haha *lp, *rp, *p = head;
        int nowSz = 0, lpos, rpos;
		while(p != nullptr) {
			if(nowSz + p -> g.size() >= l) { lp = p,lpos = l - nowSz - 1; break; }
			nowSz += p -> g.size();
			p = p -> nx;
		}
		while(p != nullptr) {
			if(nowSz + p -> g.size() >= r) { rp = p,rpos = r - nowSz - 1; break; }
			nowSz += p -> g.size();
			p = p -> nx;
		}

		//cout << "pos : " << lpos << " " << rpos << endl;

		haha *lb = new haha(nullptr,nullptr);
		haha *rb = new haha(nullptr,nullptr);
        for(int i = 0       ;i < lpos          ;i ++) lb -> g.push_back(lp -> g[i]);   /// before l
        for(int i = rpos + 1;i < rp -> g.size();i ++) rb -> g.push_back(rp -> g[i]); ///after r
		link(lp -> pr,lb); link(lb,rb); link(rb,rp -> nx);

		//..puts("fuck before [l,r]");

        haha *nlp = nullptr, *nrp = nullptr;
        if(lp == rp) {
			nlp = nrp = new haha(nullptr,nullptr);
            for(int i = lpos;i <= rpos;i ++)
                nlp -> g.push_back(lp -> g[i]);
        }
        else {
			nlp = new haha(nullptr,nullptr);
			nrp = new haha(nullptr,nullptr);
			for(int i = lpos;i < lp -> g.size();i ++) nlp -> g.push_back(lp -> g[i]);  ///l_blk's end
			if(lp -> nx != rp)
				link(nlp,lp -> nx),link(rp -> pr,nrp);
			else
                link(nlp,nrp);
			for(int i = 0;i <= rpos;i ++) nrp -> g.push_back(rp -> g[i]);   ///r_blk's begin
        }

        //puts("fuck after [l,r]");

        if(head == lp) {
            //while(head != nullptr && head != rp) head = head -> nx;
            //if(head == rp) head = head -> nx;
            head = lb;
        }
        link(nrp,head);

        head = nlp;
        if(lp != rp) {
			delete lp;
			delete rp;
        }
        else
			delete lp;

		maintain();
    }
    print();
    return 0;
}

