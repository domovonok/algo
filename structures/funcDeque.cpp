template <typename T>
struct funcDeque {
    T func(T a, T b) {
        return max(a, b);
    }

    deque<pair<T, T>> u, v;

    bool empty() {
        return u.empty() && v.empty();
    }

    void push_front(T x) {
        u.emplace_back(x, u.empty() ? x : func(x, u.back().second));
    }

    void push_back(T x) {
        v.emplace_back(x, v.empty() ? x : func(x, v.back().second));
    }

    void pop_front() {
        assert(!empty());
        if (u.empty()) {
            int h = (v.size() + 1) / 2;
            for (int i = 0; i < h; i++) {
                u.emplace_front(v.front().first, v.front().first);
                v.pop_front();
            }
            for (int i = 1; i < h; i++) {
                u[i].second = func(u[i].first, u[i - 1].second);
            }
            for (int i = 0; i < (int)v.size(); i++) {
                if (i == 0) {
                    v[i].second = v[i].first;
                } else {
                    v[i].second = func(v[i].first, v[i - 1].second);
                }
            }
        }
        u.pop_back();
    }

    void pop_back() {
        assert(!empty());
        if (v.empty()) {
            int h = (u.size() + 1) / 2;
            for (int i = 0; i < h; i++) {
                v.emplace_front(u.front().first, u.front().first);
                u.pop_front();
            }
            for (int i = 1; i < h; i++) {
                v[i].second = func(v[i].first, v[i - 1].second);
            }
            for (int i = 0; i < (int)u.size(); i++) {
                if (i == 0) {
                    u[i].second = u[i].first;
                } else {
                    u[i].second = func(u[i].first, u[i - 1].second);
                }
            }
        }
        v.pop_back();
    }

    T get() {
        assert(!empty());
        if (u.empty()) {
            return v.back().second;
        } else if (v.empty()) {
            return u.back().second;
        } else {
            return func(u.back().second, v.back().second);
        }
    }
};
