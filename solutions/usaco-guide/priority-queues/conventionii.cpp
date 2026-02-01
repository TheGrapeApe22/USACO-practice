/*
sort cows (time)
pq ongoing (seniority)

i=0
t=0

while i<n || ongoing:
	// add to ongoing
	while cows[i].time <= t
		ongoing.push(cows[i] by seniority)
		i++
	if ongoing:
        cout << t - ongoing.top().time;
		t += ongoing.top()
		ongoing.pop()
	else
		t = cows[i].time
        t += cows[i].duration
        i++
*/

#include <bits/stdc++.h>
#define vec vector
#define ln "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int INF = 1e9;
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
    // freopen("convention2.in", "r", stdin);
    // freopen("convention2.out", "w", stdout);
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    cin >> n;

    // time, seniority, duration
    vec<vec<int>> cows (n, vec<int> (3));
    for (int i = 0; i < n; i++) {
        cows[i][1] = i;
        cin >> cows[i][0] >> cows[i][2];
    }
    sort(all(cows));
    // cout << cows << ln;

    // -seniority, time, duration
    priority_queue<vec<int>> waiting;

    int t = 0, i = 0;
    int maxWait = -1;
    while (i < n || waiting.size()) {
        // cout << t << ln;
        while (i < n && cows[i][0] <= t) {
            waiting.push({-cows[i][1], cows[i][0], cows[i][2]});
            i++;
        }
        if (waiting.size()) {
            maxWait = max(maxWait, t - waiting.top()[1]);
            t += waiting.top()[2];
            waiting.pop();
        }
        else {
            t = cows[i][0] + cows[i][2];
            i++;
        }
    }
    cout << maxWait << ln;
}
