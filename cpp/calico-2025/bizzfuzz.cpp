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

string convert (int x) {
    string ans = "";
    if (x % 3 == 0) ans += "bizz";
    if (x % 5 == 0) ans += "fuzz";
    if (ans == "") ans = to_string(x);
    return ans;
};

string solve (string a, string b) {
    if (a != "fuzz" && a != "bizz" && a != "bizzfuzz")
        return convert(stoi(a) + 2);
    if (b != "fuzz" && b != "bizz" && b != "bizzfuzz")
        return convert(stoi(b) + 1);
    return "crap";
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string a, b; cin >> a >> b;
        cout << solve(a, b) << ln;
    }
}
