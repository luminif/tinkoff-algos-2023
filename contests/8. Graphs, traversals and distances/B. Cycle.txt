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
    }

    vector<int> vis(n);
    bool ok = false;

    function<void(int)> dfs = [&](int v) {
        vis[v] = 1;
        for (int to : g[v]) {
            if (!vis[to]) {
                dfs(to);
            } else if (vis[to] == 1) {
                ok = true;
            }
        }

        vis[v] = 2;
    };

    rep(v, n) if (!vis[v]) dfs(v);
    cout << ok;
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
