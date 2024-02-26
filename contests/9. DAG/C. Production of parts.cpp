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
    int n;
    cin >> n;
    vector<int> p(n);
    for (int &x : p) cin >> x;
    vector<vector<int>> g(n);
    vector<int> vis(n), order;

    rep(v, n) {
        int m;
        cin >> m;
        while (m--) {
            int u;
            cin >> u;
            g[v].push_back(u - 1);
        }
    }

    ll ans = 0;

    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;

        for (int to : g[v]) {
            if (!vis[to]) {
                dfs(to);
            }
        }

        order.push_back(v);
        ans += p[v];
    };

    dfs(0);
    cout << ans << ' ' << sz(order) << '\n';
    for (int x : order) cout << x + 1 << ' ';
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
