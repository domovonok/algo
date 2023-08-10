struct dsu {

    int size;
    vt<int> p, s;

    dsu(int n) {
        size = n;
        p.resize(size);
        iota(all(p), 0);
        s.assign(size, 1);
    }

    int leader(int x) {
        return (x == p[x] ? x : p[x] = leader(p[x]));
    }

    bool unite(int a, int b) {
        a = leader(a);
        b = leader(b);
        if (a == b) return false;
        if (s[a] < s[b]) {
            swap(a, b);
        }
        p[b] = a;
        s[a] += s[b];
        return true;
    }

};
