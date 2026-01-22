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

int main() {
    #define int long long
    
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    string s;
    cin >> n >> s;
    n = s.size();

    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j-1 >= 0 && s[j-1] != s[i]) j--;
        int k = i;
        while (k+1 < n && s[k+1] != s[i]) k++;
        
        count += (i-j) * (k-i);
        if (k-i >= 2) count += k-i-1;
        if (i-j >= 2) count += i-j-1;

        // cout << i _ j _ k _ count << ln;
    }
    cout << count << ln;
}
