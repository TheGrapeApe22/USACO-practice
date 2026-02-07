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

bool isSquare(string s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n/2+i]) return false;
    }
    return true;
}

string remove(string s, char ex) {
    string out = "";
    for (char c : s) {
        if (c != ex)
            out += c;
    }
    return out;
}

string remove2(string s, char ex) {
    string out = "";
    for (int i = 0; i < s.size(); i+=3) {
        if (s[i] == ex) continue;
        out = ((out+s[i])+s[i+1])+s[i+2];
    }
    return out;
}

vec<int> solve(string s) {
    int n = s.size();
    vec<int> ans (n, 1);

    if (isSquare(s)) {
        cout << 1 << ln;
        return ans;
    }

    string letters = "COW";
    for (char A : letters) {
        string s1 = remove(s, A);
        if (isSquare(s1)) {
            for (int i = 0; i < n; i++) {
                if (s[i] != A)
                    ans[i] = 2;
            }
            cout << 2 << ln;
            return ans;
        }

        string s2 = remove2(s, A);
        if (isSquare(s2)) {
            for (int i = 0; i < n; i+=3) {
                if (s[i] != A)
                    ans[i] = ans[i+1] = ans[i+2] = 2;
            }
            cout << 2 << ln;
            return ans;
        }
    }
    
    // give up
    for (int i = 0; i < n; i++) {
        if (s[i] == 'C')
            ans[i] = 1;
        if (s[i] == 'O')
            ans[i] = 2;
        if (s[i] == 'W')
            ans[i] = 3;
    }
    cout << 3 << ln;
    return ans;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int t, k; cin >> t >> k;
    for (int t1 = 0; t1 < t; t1++) {
        int n; string s;
        cin >> n >> s;
        if (n%2==1) {
            cout << -1 << ln;
            continue;
        }
        vec<int> ans = solve(s);
        for (int i = 0; i < 3*n-1; i++)
            cout << ans[i] << " ";
        cout << ans[3*n-1];
        cout << ln;
    }
}
