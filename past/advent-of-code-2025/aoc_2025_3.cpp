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

int largestI(const string& s, int start, int end) {
    int out = start;
    for (int i = start; i < end; i++) {
        if (s[i] > s[out])
            out = i;
    }
    return out;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    ll sum = 0;
    string s;
    while (cin >> s) {
        int currIndex = 0;
        for (int i = 11; i >= 0; i--) {
            currIndex = largestI(s, currIndex, s.size()-i);
            ll add = s[currIndex] - '0';
            for (int j = 0; j < i; j++)
                add *= 10;
            sum += add;
            currIndex++;
        }
    }
    cout << sum << endl;
}
