#include <bits/stdc++.h>

using namespace std;

// cout << iterable
ostream& operator<<(ostream& out, const vector<int>& v) {
    out << "[";
    if (v.size() > 0) {
        auto last = --v.end();
        for (auto it = v.begin(); it != last; it++)
            out << *it << ", ";
        out << *last;
    }
    out << "]";
    return out;
}
ostream& operator<<(ostream& out, const multiset<vector<int>>& v) {
    out << "[";
    if (v.size() > 0) {
        auto last = --v.end();
        for (auto it = v.begin(); it != last; it++)
            out << *it << ", ";
        out << *last;
    }
    out << "]\n";
    return out;
}


int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> inputs;
    multiset<vector<int>> events;
    vector<int> output (n);

    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        b++;
        inputs.push_back({a, b});

        events.insert({a, 1, i});
        events.insert({b, -1, i});
    }

    // cout << events;

    set<int> roomsFree;
    set<int> roomsTaken;
    roomsFree.insert(1);

    for (vector<int> event : events) {
        // 1 for arrival, -1 for departure
        int flag = event[1];
        
        if (flag == 1) {
            // arrival
            int assignRoom;
            if (roomsFree.empty()) {
                // make a new room
                assignRoom = *roomsTaken.crbegin() + 1;
            } else {
                // get room from roomsFree
                auto room = roomsFree.begin();
                assignRoom = *room;
                roomsFree.erase(room);
            }
            roomsTaken.insert(assignRoom);
            output[event[2]] = assignRoom;
        } else {
            // departure
            roomsTaken.erase(output[event[2]]);
            roomsFree.insert(output[event[2]]);
        }
    }
    cout << *roomsFree.crbegin() << "\n";
    for (int x : output)
        cout << x << " ";
    cout << "\n";
}
