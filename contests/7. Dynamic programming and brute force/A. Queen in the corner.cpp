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

    if (n == 1 && m == 1) {
        cout << 1;
        return;
    }

    vector<vector<int>> a(n, vector<int>(m, -1));

    auto f = [&](int i, int j, int val) -> void {
        if (a[i][j] != -1) return;
        a[i][j] = val ^ 1;

        for (int k = 1; k < max(n, m); k++) {
            if (i + k < n && j + k < m) a[i + k][j + k] = val;
        }

        for (int k = 1; i + k < n; k++) {
            a[i + k][j] = val;
        }

        for (int k = 1; j + k < m; j++) {
            a[i][j + k] = val;
        }
    };

    rep(i, n) rep(j, m) {
        f(i, j, 1);
    }

    cout << (a.back().back() ? 1 : 2);
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