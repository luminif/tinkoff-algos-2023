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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    deque<int> d;

    auto get_min = [&](int i) -> void {
        while (!d.empty() && a[i] < a[d.back()]) {
            d.pop_back();
        }

        d.push_back(i);
    };

    rep(i, k) {
        get_min(i);
    }

    for (int i = k; i <= n; i++) {
        cout << a[d.front()] << ' ';

        while (!d.empty() && d.front() <= i - k) {
            d.pop_front();
        }

        get_min(i);
    }
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
