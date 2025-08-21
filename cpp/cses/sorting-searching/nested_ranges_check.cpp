#include <bits/stdc++.h>

using namespace std;

// cout << vector
template <typename it>
ostream& operator<<(ostream& out, const vector<it>& v) {
    out << "[";
    for (int i = 0; i+1 < (int)v.size(); i++)
        out << v[i] << ", ";
    if (v.size() > 0) out << v[(int)v.size() - 1];
    out << "]\n";
    return out;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> inputs;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        inputs.push_back({x, y});
    }

    vector<pair<int, int>> v = inputs;
    sort(v.begin(), v.end());

    vector<int> maxY (n, -1);
    vector<int> minY (n, 1e9);

    int y = -1;
    for (int a = 0; a < n; a++) {
        y = max(y, v[a].second);
        maxY[a] = y;
    }
    y = 1e9;
    for (int a = n-1; a >= 0; a--) {
        y = min(y, v[a].second);
        minY[a] = y;
    }
    
    map<pair<int, int>, int> indexes;
    for (int i = 0; i < n; i++) {
        indexes[v[i]] = i;
    }

    cout << minY;
    for (int i = 0; i < n; i++) {
        // auto it = find(v.begin(), v.end(), inputs[i]);
        int sortedI = indexes[inputs[i]];
        // cout << sortedI << " ";
        cout << ((sortedI+1 < n) && minY[sortedI+1] <= inputs[i].second) << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++) {
        // auto it = find(v.begin(), v.end(), inputs[i]);
        int sortedI = indexes[inputs[i]];
        // cout << sortedI << " ";
        cout << ((sortedI > 0) && maxY[sortedI - 1] >= inputs[i].second) << " ";
    }
    cout << "\n";
}
