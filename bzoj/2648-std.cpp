#include <cstdio>
#include <climits>
#include <algorithm>

const int MAXN = 500000;
const int MAXM = 500000;
const int MAXX = 1000000;

struct Triple {
    int id, x, y, *ans;

    Triple() {}

    Triple(const int x, const int y, int *ans = NULL) : x(x), y(y), ans(ans) {
        static int i = 0;
        id = i++;
    }
} a[MAXN + MAXM];

bool operator<(const Triple &a, const Triple &b) {
    return a.id < b.id;
}

int maxX, maxY;

struct BinaryIndexedTree {
    int a[MAXX + 2];

    static int lowbit(const int x) { return x & -x; }

    int query(const int x) const {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ans = std::max(ans, a[i - 1]);
        return ans;
    }

    void update(const int x, const int v) {
        for (int i = x; i <= maxY; i += lowbit(i)) a[i - 1] = std::max(a[i - 1], v);
    }

    void clear(const int x) {
        for (int i = x; i <= maxY; i += lowbit(i)) {
            if (a[i - 1]) a[i - 1] = 0;
            else break;
        }
    }
} bit;

inline void cdq(Triple *l, Triple *r) {
    if (l == r) return;

    Triple *mid = l + (r - l) / 2;

    cdq(l, mid);
    cdq(mid + 1, r);

    static Triple tmp[MAXN + MAXM];
    for (Triple *q = tmp, *p1 = l, *p2 = mid + 1; q <= tmp + (r - l); q++) {
        if ((p1 <= mid && p1->x <= p2->x) || p2 > r) {
            *q = *p1++;
            if (!q->ans) bit.update(q->y, q->x + q->y);
        } else {
            *q = *p2++;
            if (q->ans) {
                int res = bit.query(q->y);
                if (res) *q->ans = std::min(*q->ans, q->x + q->y - res);
            }
        }
    }

    for (Triple *q = tmp, *p = l; p <= r; p++, q++) {
        *p = *q;
        bit.clear(p->y);
    }
}

int main() {
	freopen("in.in","r",stdin);
	freopen("std.out","w",stdout);
    int n, m;
    scanf("%d %d", &n, &m);

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d\n", &x, &y), x += 2, y += 2;
        a[cnt++] = Triple(x, y);

        maxX = std::max(maxX, x);
        maxY = std::max(maxY, y);
    }

    static int ans[MAXM];
    int qCnt = 0;
    for (int j = 0; j < m; j++) {
        int t, x, y;
        scanf("%d %d %d", &t, &x, &y), x += 2, y += 2;
        if (t == 1) {
            a[cnt++] = Triple(x, y);
        } else {
            a[cnt++] = Triple(x, y, &ans[qCnt++]);
        }

        maxX = std::max(maxX, x);
        maxY = std::max(maxY, y);
    }

    for (int i = 0; i < qCnt; i++) ans[i] = INT_MAX;

    cdq(a, a + cnt - 1);

    for (int i = 0; i < cnt; i++) a[i].x = maxX - a[i].x + 1;
    std::sort(a, a + cnt);
    cdq(a, a + cnt - 1);

    for (int i = 0; i < cnt; i++) a[i].y = maxY - a[i].y + 1;
    std::sort(a, a + cnt);
    cdq(a, a + cnt - 1);

    for (int i = 0; i < cnt; i++) a[i].x = maxX - a[i].x + 1;
    std::sort(a, a + cnt);
    cdq(a, a + cnt - 1);

    for (int i = 0; i < qCnt; i++) printf("%d\n", ans[i]);

    return 0;
}
