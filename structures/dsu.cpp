struct dsu {

    int size;
    vt<int> p, s;

    void init(int n) {
        size = n;
        p.resize(size);
        iota(all(p), 0);
        s.assign(size, 1);
    }

    int leader(int x) {
        return (x == p[x] ? x : p[x] = leader(p[x]));
    }

    void unite(int a, int b) {
        a = leader(a);
        b = leader(b);
        if (s[a] < s[b]) {
            swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
    }

};
