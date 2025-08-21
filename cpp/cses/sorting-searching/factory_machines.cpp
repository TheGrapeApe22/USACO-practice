#include <bits/stdc++.h>

using namespace std;
using ll = long long;

long long numProducts(long long time, vector<long long>& machines) {
    long long out = 0;
    for (long long m : machines) {
        out += time / m;
    }
    return out;
}

// [low, high]
long long bsearch(vector<ll>& machines, long long target, long long low, long long high) {
    if (low > high) return -1;
    long long mid = (low + high) / 2;
    // cout << "mid = " << mid << "\n";
    long long result = numProducts(mid, machines);
    
    if (result >= target && numProducts(mid - 1, machines) < target)
        return mid;
    
    if (result >= target)
        return bsearch(machines, target, low, mid - 1);
    else
        return bsearch(machines, target, mid + 1, high);
}


int main() {
    // num machines, num products
    long long m, p;
    cin >> m >> p;

    vector<long long> machines (m);
    double rate = 0;
    for (long long i = 0; i < m; i++) {
        cin >> machines[i];
        rate += 1.0 / machines[i];
    }
    
    // cout << rate << endl;
    
    double totalTime = ceil(static_cast<double>(p) / rate);
    // cout << totalTime << endl;

    ll maxTime = totalTime;
    while (numProducts(maxTime, machines) < p) {
        maxTime *= 2;
    }

    ll minTime = totalTime / 2;

    // cout << minTime << endl;
    // cout << maxTime << endl;
    cout << bsearch(machines, p, minTime, maxTime) << endl;
}
