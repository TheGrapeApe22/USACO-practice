#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define _ << " " <<
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
namespace {
    template<typename it> void print(it, it);
    template<typename T> void print(T& v) {print(all(v));}
    template<typename T, typename U> void print(pair<T, U> p) { cout << "("<<p.first<<", "<<p.second<<")"; }
    template<typename T, typename U>ostream& operator<<(ostream& out, pair<T, U> p) { print(p); return out; }
    template<typename T> ostream& operator<<(ostream& out, const vector<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const set<T>& v) { print(v); return out; }
    template<typename T> ostream& operator<<(ostream& out, const multiset<T>& v) { print(v); return out; }
    template<typename T, typename U> ostream& operator<<(ostream& out, const map<T, U>& v) { print(v); return out; }
    template<typename it> void print(it begin, it end) {
        cout << "[";
        if (begin != end) {
            auto last = --end;
            for (; begin != last; begin++)
                cout << *begin << ", ";
            cout << *last;
        }
        cout << "]";
    }
    template<typename T> void println(T v) {print(v); cout << "\n";}
}

/*
    vectors a, b
    // maxlen[i] = length of longest common subsequence in b ending at i
    map instance[x] = [i1, i2, ...]
    for i in a:
        for each instance j of a[i] in b: (right to left)
            maxlen[j] = max(maxlen[j-1]+1, itself)
            if changed: also element[j] = b[j]
        fix maxlen array from left to right, erasing elems that don't increase the length
*/

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;

    vec<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    unordered_map<int, set<int, greater<int>>> instances;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        instances[b[i]].insert(i);
    }

    vec<int> maxLen (m);
    vec<int> element (m, -1);
    auto getMaxLen = [&](int i) {
        return i==-1 ? 0 : maxLen[i];
    };

    auto firstTrue = [](int low, int high, function<bool(int)> f) {
        while (low < high) {
            int mid = (low+high) / 2;
            if (f(mid))
                high = mid;
            else
                low = mid + 1;
        }
        if (f(low)) return low;
        return -1;
    };

    for (int i = 0; i < n; i++) {
        auto currInstances = instances[a[i]];
        for (int j : currInstances) {
            if (getMaxLen(j-1)+1 > maxLen[j]) {
                maxLen[j] = getMaxLen(j-1)+1;
                element[j] = firstTrue(0, j, [&](int k){return maxLen[k] == maxLen[j]-1;});
                if (maxLen[j] == 1)
                    element[j] = -1;
            }
        }
        for (int j = 1; j < m; j++) {
            if (maxLen[j] < maxLen[j-1]) {
                maxLen[j] = maxLen[j-1];
                element[j] = -1;
            }
        }
        // cout << maxLen << ln << element << ln << ln;
    }

    // cout << maxLen << ln << element << ln << ln;
    int i = m-1;
    while (i>=0 && element[i] == -1) i--;
    vec<int> ans;
    while (element[i] != -1) {
        ans.push_back(b[i]);
        i = element[i];
    }
    ans.push_back(b[i]);

    cout << ans.size() << ln;
    for (int j = ans.size()-1; j >= 0; j--)
        cout << ans[j] << " ";
    cout << ln;
}
