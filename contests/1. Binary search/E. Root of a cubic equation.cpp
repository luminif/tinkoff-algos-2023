#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ff first
#define ss second
#define rep(i, n) for (int i = 0; i < int(n); i++)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define make_unique(a) sort(all(a)); (a).resize(unique(all(a)) - (a).begin())
using namespace std;

const double EPS = 1e-6;

void solve() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    auto f = [&](double x) -> double {
        return a * x * x * x + b * x * x + c * x + d;
    };

    if (a < 0) {
        a = -a;
        b = -b;
        c = -c;
        d = -d;
    }

    double l = -5000, r = 5000;

    while (r - l > EPS) {
        double m = (l + r) / 2;

        if (f(m) > 0) {
            r = m;
        } else {
            l = m;
        }
    }

    cout << fixed << setprecision(4) << l;
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
