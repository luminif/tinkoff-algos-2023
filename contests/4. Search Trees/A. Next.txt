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

const int MOD = int(1e9);

class Treap {
    struct Node {
        int key, priority;
        Node *l = 0, *r = 0;
        Node(int _key) {key = _key, priority = rand();}
    };

    Node *root = 0;
    using Pair = pair<Node*, Node*>;

    Node* merge(Node *l, Node *r) {
        if (!l) return r;
        if (!r) return l;

        if (l->priority > r->priority) {
            l->r = merge(l->r, r);
            return l;
        } else {
            r->l = merge(l, r->l);
            return r;
        }
    }

    Pair split(Node *node, int key) {
        if (!node) return {0, 0};
        if (node->key < key) {
            Pair a = split(node->r, key);
            node->r = a.ff;
            return {node, a.ss};
        } else {
            Pair a = split(node->l, key);
            node->l = a.ss;
            return {a.ff, node};
        }
    }

    int min(Node *node) {
        if (!node) return -1;

        while (node->l) {
            node = node->l;
        }

        return node->key;
    }

    public:
        void add(int key) {
            Pair node = split(root, key);
            root = merge(node.ff, merge(new Node(key), node.ss));
        }

        int next(int key) {
            Pair node = split(root, key);
            int res = min(node.ss);
            root = merge(node.ff, node.ss);
            return res;
        }
};

void solve() {
    int n;
    cin >> n;
    Treap a;
    int y = 0;

    while (n--) {
        string type;
        int x;
        cin >> type >> x;

        if (type == "+") {
            a.add((x + y) % MOD);
            y = 0;
        } else {
            y = a.next(x);
            cout << y << '\n';
        }
    }
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
