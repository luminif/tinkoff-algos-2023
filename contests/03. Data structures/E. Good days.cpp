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

void lol() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (ll &x : a) cin >> x;
    ll ans = 0, mi = 0, l = 0, r = 0;

    rep(i, n) {
        ll s = 0;
        ll mn = 1e9;

        for (int j = i + 1; j < n; j++) {
            s += a[j];
            mn = min(mn, a[j]);

            if (ans < mn * s) {
                ans = mn * s;
                l = i;
                r = j;
                mi = mn;
            }
        }
    }

    cout << ans << '\n';
    cout << l << ' ' << r << ' ' << mi;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<ll> pref(n + 1);
    rep(i, n) pref[i + 1] = pref[i] + a[i];
    vector<int> prevl(n), prevr(n);
    stack<int> st;

    rep(i, n) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        prevl[i] = (!st.empty() ? st.top() + 1 : 0);
        st.push(i);
    }

    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && a[st.top()] >= a[i]) {
            st.pop();
        }

        prevr[i] = (!st.empty() ? st.top() - 1 : n - 1);
        st.push(i);
    }

    ll ans = 0;

    rep(i, n) {
        int l = prevl[i], r = prevr[i] + 1;
        ans = max(ans, a[i] * (pref[r] - pref[l]));
    }

    cout << ans;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
        //lol();
    }

    //cerr << "runtime: " << clock() / 1000.0 << '\n';
    return 0;
}
