/*
binary search on time.
    find smallest time that is valid
function: check if t is possible
    for each friend:
        range = pos +/- vel*t = [a, b]
    find lowest b, highest a
    return a <= b
*/

// #include <format>
#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<double, double>;
const int INF = 1e9;
const double epsilon = 1e-6;
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

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    // pair <position, speed>
    vec<pii> friends (n);
    for (int i = 0; i < n; i++)
        cin >> friends[i].first;
    for (int i = 0; i < n; i++)
        cin >> friends[i].second;
    
    auto possible = [&](double t){
        double maxA = -1e18, minB = 1e18;
        for (auto [pos, vel] : friends) {
            double a = (double)pos - vel * t;
            double b = (double)pos + vel * t;
            maxA = max(maxA, a);
            minB = min(minB, b);
            if (maxA > minB) return false;
        }
        return true;
    };
    
    auto firstTrue = [&](double low, double high) {
        while (low < high) {
            double mid = (low+high) / 2;
            if (possible(mid))
                high = mid;
            else
                low = mid + epsilon;
            
            if (high-low < epsilon) break;
        }
        return low;
    };

    // cout << std::format("{}", firstTrue(0, 2e9)) << ln;
    cout << firstTrue(0, 2e9) << ln;
}
