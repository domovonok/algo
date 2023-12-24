template <typename T>
vector<int> z_function(const T &s, const int &n) {
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        z[i] = (r >= i ? min(z[i - l], r - i + 1) : 0);
        while (z[i] + i < n && s[z[i]] == s[z[i] + i]) {
            z[i]++;
        }
        if (r < z[i] + i - 1) {
            l = i;
            r = z[i] + i - 1;
        }
    }
    return z;
}
 
template <typename T>
vector<int> z_function(const T &s) {
    return z_function(s, s.size());
}
