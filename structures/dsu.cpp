struct dsu {
    int size;
    vector<int> p, s;

    dsu(int n) {
        size = n;
        p.resize(size);
        iota(p.begin(), p.end(), 0);
        s.assign(size, 1);
    }

    int leader(int x) {
        return (x == p[x] ? x : p[x] = leader(p[x]));
    }

    bool merge(int a, int b) {
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

    int sz(int x) {
        return s[leader(x)];
    }
};
