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

vector<int> prefix_function(string s) {
    int n = sz(s);
    vector<int> pi(n);

    for (int i = 1; i < n; i++) {
        int k = pi[i - 1];

        while (1) {
            if (s[i] == s[k]) {
                pi[i] = k + 1;
                break;
            }

            if (k == 0) break;
            k = pi[k - 1];
        }
    }

    return pi;
}

vector<int> kmp(string s, string t) {
    vector<int> a = prefix_function(t + "#" + s);
    vector<int> res;
    int n = sz(s), m = sz(t);

    rep(i, n + m + 1) {
        if (a[i + m] == m) {
            res.push_back(i + m - 2 * m);
        }
    }

    return res;
}

void solve() {
    string s, t;
    cin >> s >> t;
    vector<int> ans = kmp(s, t);
    for (int x : ans) cout << x << ' ';
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
