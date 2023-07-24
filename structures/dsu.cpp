struct dsu {

    int n;
    vt<int> p, s;

    dsu(int _n) : n(_n) {
        p.resize(n);
        iota(all(p), 0);
        s.assign(n, 1);
    }

    inline int leader(int x) {
        return (x == p[x] ? x : p[x] = leader(p[x]));
    }

    inline void unite(int a, int b) {
        a = leader(a);
        b = leader(b);
        if (s[a] < s[b]) {
            swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
    }

};
