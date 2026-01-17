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
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    // m = number of number rows
    int m = 4;
    
    string operators;
    getline(cin, operators);
    vec<string> problems (m);
    for (string& s : problems) getline(cin, s);
    
    ll totaltotal = 0;
    for (int i = 0; i < operators.size(); i++) {
        if (operators[i] != ' ') {
            ll total = (operators[i] == '*') ? 1 : 0;
            // j == column, goes from the current operator to the next operator
            for (int j = i; j < operators.size() && (j == operators.size()-1 || operators[j+1] == ' '); j++) {
                // r = row
                ll currNum = 0;
                for (int r = 0; r < m; r++) {
                    if (problems[r][j] == ' ') continue;
                    currNum = currNum*10LL + (ll)(problems[r][j] - '0');
                }
                // cout << currNum << ln;
                if (operators[i] == '*')
                    total *= currNum;
                else
                    total += currNum;
            }
            // cout << total << ln;
            totaltotal += total;
        }
    }
    cout << totaltotal << endl;
}
