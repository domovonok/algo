struct sparsetable {

    int size;
    vector<vector<int>> table;

    sparsetable(const vector<int> &a) {
        size = a.size();
        int logn = __lg(size);
        table.resize(logn + 1);
        table[0] = a;
        for (int l = 1; l <= logn; l++) {
            table[l].resize(size - (1 << l) + 1);
            for (int i = 0; i + (1 << l) <= size; i++) {
                table[l][i] = min(table[l - 1][i], table[l - 1][i + (1 << (l - 1))]);
            }
        }
    }

    int rmq(int l, int r) {
        int logn = __lg(r - l);
        return min(table[logn][l], table[logn][r - (1 << logn)]);
    }

};
