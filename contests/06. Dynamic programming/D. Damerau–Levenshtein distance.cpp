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
    string s, t;
    cin >> s >> t;
    int n = sz(s), m = sz(t);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    rep(i, n + 1) dp[i][0] = i;
    rep(j, m + 1) dp[0][j] = j;

    //https://ru.wikipedia.org/wiki/Расстояние_Дамерау_—_Левенштейна

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + (s[i - 1] != t[j - 1])});
            if (i > 1 && j > 1 && s[i - 1] == t[j - 2] && s[i - 2] == t[j - 1]) {
                dp[i][j] = min(dp[i][j], dp[i - 2][j - 2] + 1);
            }
        }
    }

    cout << dp.back().back();
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
