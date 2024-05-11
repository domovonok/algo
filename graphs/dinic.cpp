struct dinic {
    struct edge {
        int v;
        ll cap, f;
    };
 
    int size, S, T;
 
    vector<edge> edges;
    vector<vector<int>> gr;
 
    void init(int n) {
        size = n + 2;
        S = size - 2;
        T = size - 1;
        edges.clear();
        gr.assign(size, vector<int>());
    }
 
    void add_edge(int u, int v, ll cap) {
        gr[u].push_back(edges.size());
        edges.emplace_back(v, cap, 0);
        gr[v].push_back(edges.size());
        edges.emplace_back(u, 0, 0);
    }
 
    vector<int> d;
 
    bool bfs() {
        d.assign(size, -1);
        d[S] = 0;
        queue<int> q;
        q.push(S);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int &i : gr[u]) {
                auto [v, cap, f] = edges[i];
                if (d[v] == -1 && cap - f > 0) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[T] != -1;
    }
 
    vector<int> ptr;
    vector<int> par;
 
    ll dfs(int u, ll flow) {
        if (flow == 0) return 0;
        if (u == T) return flow;
        for (int &j = ptr[u]; j < (int)gr[u].size(); j++) {
            int i = gr[u][j];
            auto [v, cap, f] = edges[i];
            if (d[v] == d[u] + 1) {
                ll pushed = dfs(v, min(flow, cap - f));
                if (pushed > 0) {
                    par[v] = i;
                    return pushed;
                }
            }
        }
        return 0;
    }
 
    ll max_flow() {
        ll ans = 0;
        while (bfs()) {
            ptr.assign(size, 0);
            par.assign(size, -1);
            ll flow = dfs(S, LLONG_MAX);
            ans += flow;
            int cur = T;
            while (cur != S) {
                int i = par[cur];
                edges[i].f += flow;
                edges[i ^ 1].f -= flow;
                cur = edges[i ^ 1].v;
            }
        }
        return ans;
    }
};
