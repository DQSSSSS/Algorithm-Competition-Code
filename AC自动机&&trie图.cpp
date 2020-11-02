void build_trieg() {
	fail[0] = 0;
	for(int i = 1;i <= 26;i ++) {
		int u = ch[0][i];
		if(u) { q.push(u); fail[u] = 0; }
	}
	while(q.size()) {
		int f = q.front(); q.pop();
		val[f] += val[fail[f]];
		for(int c = 1;c <= 26;c ++) {
			int u = ch[f][c];
			if(!u) { ch[f][c] = ch[fail[f]][c]; continue; }
			q.push(u);
			fail[u] = ch[fail[f]][c];
		}
	}
}
void build_ac() {
    fail[0] = 0;
    for(int i = 0;i < 26;i ++) {
        int u = ch[0][i];
        if(u) { q.push(u); fail[u] = 0; }
    }
    while(q.size()) {
        int f = q.front(); q.pop();
        for(int i = 0;i < 26;i ++) {
            int u = ch[f][i];
            if(!u) continue;
            q.push(u);
            int v = fail[f];
            while(v && !ch[v][i]) v = fail[v];
            fail[u] = ch[v][i];
        }
    }
}
