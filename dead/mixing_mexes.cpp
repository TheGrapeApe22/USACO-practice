#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std; using ll = long long; using pii = pair<int, int>;
template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) {
    cout << "["; for (size_t i = 0; i+1 < v.size(); i++) cout << v[i] << ", "; cout << *v.rbegin() << "]"; return out;
}

struct group {
    vec<int> arr;
    vec<int> mexes {-1, -1};
    unordered_map<int, int> freq;
};

void solve (int n, vec<group>& a, unordered_map<int, int>& total_freq, int total_count) {
    for (int i = 0; i < n; i++) {
        int outerCount = total_count - a[i].arr.size();
        cout << outerCount - total_freq[a[i].mexes[0]] _ total_freq[a[i].mexes[0]] << ln;
        
        int outward_score = 0;
        for (int x : a[i].arr) {
            if (x < a[i].mexes[0] && a[i].freq[x] == 1)
                outward_score += x;
            else
                outward_score += a[i].mexes[0];
        }
        outward_score *= n-1;

        

        cout << outward_score << ln << ln;
    }
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int t; cin >> t;
    for (int t1 = 0; t1 < t; t1++) {
        int n; cin >> n;
        vec<group> a (n);
        int total_count = 0;
        unordered_map<int, int> total_freq;
        for (group& g : a) {
            int l; cin >> l;
            for (int i = 0; i < l; i++) {
                int k; cin >> k;
                g.arr.push_back(k);
                g.freq[k]++;
                total_freq[k]++;
                total_count++;
            }
            sort(all(g.arr));
            // finding first two mexes can be done with binsearch, but i'm lazy so i do linear search
            for (int x = 0; x <= 2e5+2; x++) {
                if (g.freq[x] > 0) continue;
                if (g.mexes[0] == -1)
                    g.mexes[0] = x;
                else {
                    g.mexes[1] = x;
                    break;
                }
            }
        }
        solve(n, a, total_freq, total_count);
    }
}
