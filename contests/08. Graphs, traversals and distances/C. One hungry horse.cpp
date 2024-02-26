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

const int INF = int(1e9);
const vector<int> dx = {-2, -2, -1, -1, +1, +1, +2, +2};
const vector<int> dy = {-1, +1, -2, +2, -2, +2, -1, +1};

void solve() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<pair<int, int>> moves;
    vector<vector<pair<int, int>>> from(n + 1, vector<pair<int, int>>(n + 1, {-1, -1}));

    function<void()> bfs = [&]() {
        dist[x1][y1] = 0;
        queue<pair<int, int>> q;
        q.push({x1, y1});

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            rep(d, 8) {
                int tx = x + dx[d];
                int ty = y + dy[d];

                if (0 < tx && tx <= n && 0 < ty && ty <= n
                    && dist[tx][ty] > dist[x][y] + 1) {
                    dist[tx][ty] = dist[x][y] + 1;
                    from[tx][ty] = {x, y};
                    q.push({tx, ty});
                }
            }
        }

        if (dist[x2][y2] != INF) {
            int x = x2;
            int y = y2;

            while (x != -1 && y != -1) {
                moves.push_back({x, y});
                auto [tx, ty] = from[x][y];
                x = tx;
                y = ty;
            }
        }
    };

    bfs();
    reverse(all(moves));
    cout << sz(moves) - 1 << '\n';
    for (auto &[x, y] : moves) cout << x << ' ' << y << '\n';
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
