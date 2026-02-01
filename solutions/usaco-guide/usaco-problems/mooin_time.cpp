// https://usaco.org/index.php?page=viewproblem2&cpid=1445
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
helper function: given letters m and o, can moo appear f times?
    count the number of moos and store a sparse array (mooIndexes) of all the moo characters
    if it's >= f, return true
    if it's not f-1, return false
    for all indexes not in mooIndexes:
        if it is in m_o or _oo or mo_
            return true
    return false
*/

bool solve(const string& s, int n, char m, char o, int f) {
    // count the number of moos and store a sparse array (mooIndexes) of all the moo characters
    int count = 0;
    vec<bool> mooIndexes (n);
    for (int i = 0; i+2 < n; i++) {
        if (s[i] == m && s[i+1] == o && s[i+2] == o) {
            mooIndexes[i] = mooIndexes[i+1] = mooIndexes[i+2] = true;
            count++;
        }
    }
    if (count >= f) return true;
    if (count < f-1) return false;
    for (int i = 0; i < n; i++) {
        if (mooIndexes[i]) continue;
        // m_o
        if (i > 0 && i+1 < n && s[i-1] == m && s[i+1] == o)
            return true;
        // mo_
        if (i > 1 && s[i-2] == m && s[i-1] == o)
            return true;
        // _oo
        if (i+2 < n && s[i+1] == o && s[i+2] == o)
            return true;
    }
    return false;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n, f;
    string s;
    cin >> n >> f >> s;

    vec<string> ans;

    for (char m = 'a'; m <= 'z'; m++) {
        for (char o = 'a'; o <= 'z'; o++) {
            if (m == o) continue;
            if (solve(s, n, m, o, f))
                ans.push_back(string {m, o, o});
        }
    }

    cout << ans.size() << ln;
    for (string& z : ans)
        cout << z << ln;
}
