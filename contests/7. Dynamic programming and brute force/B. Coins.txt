#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) ((a).begin()), ((a).end())
#define rall(a) ((a).rbegin()), ((a).rend())
#define sz(a) int((a).size())
using namespace std;

void gen(vector<int> &a, vector<int> &b, vector<vector<int>> &subs, int cur) {
    subs.push_back(b);
    for (int i = cur; i < sz(a); i++) {
        b.push_back(a[i]);
        gen(a, b, subs, i + 1);
        b.pop_back();
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), ans, b;
    ll s = 0;
    for (int &x : a) cin >> x, s += 2 * x;

    if (s < n) {
        cout << -1;
        return;
    }

    a.resize(2 * m);

    for (int i = m; i < 2 * m; i++) {
        a[i] = a[i - m];
    }

    vector<vector<int>> subs;
    gen(a, b, subs, 0);
    bool ok = false;
    int kek = 1e9;

    rep(i, sz(subs)) {
        ll cs = 0;
        vector<int> tmp;
        rep(j, sz(subs[i])) {
            cs += subs[i][j];
            tmp.push_back(subs[i][j]);

            if (cs == n) {
                ok = true;

                if (kek > sz(tmp)) {
                    kek = sz(tmp);
                    ans = tmp;
                }
            }
        }
    }

    if (!ok) {
        cout << 0;
        return;
    }

    cout << sz(ans) << '\n';
    for (int &x : ans) cout << x << ' ';
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
