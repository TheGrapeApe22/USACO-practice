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

int mod(int a, int b) {
    return ((a%b)+b)%b;
}

int main() {
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int pointer = 50;
    int count = 0;
    string turn;
    while (cin >> turn) {
        int diff = stoi(turn.substr(1));
        count += diff/100;
        diff %= 100;
        if (pointer != 0) {
            if (turn[0] == 'L' && pointer-diff<=0)
                count++;
            else if (turn[0] == 'R' && pointer+diff>=100)
                count++;
        }
        
        if (turn[0] == 'L')
            pointer -= diff;
        else
            pointer += diff;
        pointer = mod(pointer, 100);
        // cout << pointer _ count << ln;
    }
    cout << count << ln;
}
