
// kmp

void getnxt(char s[]) {
    nxt[0] = nxt[1] = 0;
    int l = strlen(s);
    for(int i = 1;i < l;i ++) {
        int j = nxt[i];
        while(j && s[i] != s[j]) j = nxt[j];
        nxt[i + 1] = s[i] == s[j] ? j + 1 : 0;
    }
}
int kmp(char s1[],char s2[]) {
    getnxt(s1);
    int ans = 0;
    int n = strlen(s1),m = strlen(s2);
    for(int i = 0,j = 0;i < m;i ++) {
        while(j && s1[j] != s2[i]) j = nxt[j];
        if(s1[j] == s2[i]) j ++;
        if(j == n) ans ++;
    }
    return ans;
}

// trie


void insert(char s[],int x) {
    int n = strlen(s),p = 0;
    for(int i = 0;i < n;i ++) {
        int c = s[i] - 'a' + 1;
        if(!ch[p][c]) ch[p][c] = ++ Tcnt;
        p = ch[p][c];
    }
    val[p] = x;
}

// manacher

void prepare() {
    n = strlen(s1 + 1);
    s2[++len] = '@';
    s2[++len] = '#';
    for (int i = 1; i <= n; i++) {
        s2[++len] = s1[i];
        s2[++len] = '#';
    }
    s2[++len] = '\0';
}

void manacher() {
    int right = 0, pos = -1;
    for (int i = 1; i <= len; i++) {
        int x;
        if (right < i) x = 1;
        else x = std::min(r[2 * pos - i], right - i);
        while (s2[i - x] == s2[i + x]) x++;
        if (x + i > right) {
            right = x + i;
            pos = i;
        }
        r[i] = x;
    }
}



