#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) ((a).begin()), ((a).end())
#define rall(a) ((a).rbegin()), ((a).rend())
#define sz(a) int((a).size())
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n), comps;

    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        comps.push_back(v);
        for (int to : g[v]) if (!vis[to]) dfs(to);
    };

    int cnt = 0;

    rep(v, n) {
        if (!vis[v]) {
            dfs(v);
            cnt++;
        }
    }

    rep(v, n) vis[v] = 0;
    cout << cnt << '\n';

    rep(v, n) {
        if (!vis[v]) {
            comps.clear();
            dfs(v);
            sort(all(comps));
            cout << sz(comps) << '\n';
            for (int u : comps) cout << u + 1 << ' ';
            cout << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
