#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define make_unique(a) sort(all(a)); (a).resize(unique(all(a)) - (a).begin())
#define sz(a) int((a).size())
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), gr(n);
    vector<int> vis(n), order;
    int color = 0;

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        gr[v].push_back(u);
    }

    function<void(int)> dfs1 = [&](int v) {
        vis[v] = 1;

        for (int to : g[v]) {
            if (!vis[to]) {
                dfs1(to);
            }
        }

        order.push_back(v);
    };

    function<void(int)> dfs2 = [&](int v) {
        vis[v] = color;

        for (int to : gr[v]) {
            if (!vis[to]) {
                dfs2(to);
            }
        }
    };

    rep(v, n) if (!vis[v]) dfs1(v);
    reverse(all(order));
    rep(v, n) vis[v] = 0;
    for (int v : order) if (!vis[v]) color++, dfs2(v);
    vector<int> a(color, 1);

    rep(v, n) {
        for (int to : g[v]) {
            if (vis[v] != vis[to]) {
                a[vis[v]] = 2;
            }
         }
    }

    int ans = count(all(a), 1);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    //cerr << "runtime: " << clock() / 1000.0 << '\n';
    return 0;
}
