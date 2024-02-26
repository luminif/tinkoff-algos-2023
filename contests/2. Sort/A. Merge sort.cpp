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

int cnt = 0;

vector<int> merge(const vector<int> &a, const vector<int> &b) {
    int i = 0, j = 0;
    vector<int> ans;

    while (i < sz(a) && j < sz(b)) {
        if (a[i] <= b[j]) {
            ans.push_back(a[i++]);
        } else {
            cnt += sz(a) - i;
            ans.push_back(b[j++]);
        }
    }

    while (i < sz(a)) {
        ans.push_back(a[i++]);
    }

    while (j < sz(b)) {
        ans.push_back(b[j++]);
    }

    return ans;
}

vector<int> merge_sort(vector<int> &a) {
    if (sz(a) == 1) return a;
    int mid = sz(a) / 2;
    vector<int> l, r;

    rep(i, sz(a)) {
	(i < mid ? l : r).push_back(a[i]);
    }

    l = merge_sort(l);
    r = merge_sort(r);
    return merge(l, r);
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    a = merge_sort(a);
    cout << cnt << '\n';
    for (int &x : a) cout << x << ' ';
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
