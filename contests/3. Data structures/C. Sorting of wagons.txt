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
    vector<int> a(n);
    for (int &x : a) cin >> x;
    vector<pair<int, int>> ans;
    stack<int> st;
    int x = 1, cnt = 0;

    for (int i = 0, j = 0; i < n; i = j) {
        st.push(a[j++]);
        cnt++;

        while (j < n && a[j] < st.top()) {
            st.push(a[j++]);
            cnt++;
        }

        if (x != st.top()) {
            cout << 0;
            return;
        }

        ans.push_back({1, cnt});
        cnt = 0;

        while (!st.empty() && x == st.top()) {
            cnt++;
            x++;
            st.pop();
        }

        ans.push_back({2, cnt});
        cnt = 0;
    }

    if (!st.empty()) {
        cout << 0;
        return;
    }

    cout << sz(ans) << '\n';

    for (auto &[x, y] : ans) {
        cout << x << ' ' << y << '\n';
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
