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

bool strIsMadeOf(const string& s, const string& part) {
    int n = s.size(), m = part.size();
    if (n % m != 0) return false;
    
    for (int i = 0; i < n; i+=m)
        if (s.substr(i, m) != part)
            return false;
    return true;
}

bool isInvalid(const string& s) {
    for (int m = s.size()/2; m > 0; m--) {
        if (strIsMadeOf(s, s.substr(0, m)))
            return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // prereq: reformat input to be only space separated
    ll a, b, sum=0;
    while (cin >> a >> b) {
        for (ll i = a; i <= b; i++) {
            string s = to_string(i);
            if (isInvalid(s))
                sum += i;
        }
    }
    cout << sum << endl;
}
