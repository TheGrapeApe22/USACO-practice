#include <bits/stdc++.h>

using namespace std;

long long smallestDifference(vector<long long> pool, long long total) {
    // goal: add up ints from pool, make 2*sum = total. return (total-2*sum).
    if (pool.size() == 1)
        return abs(total - 2*pool[0]);
    
    long long largest = pool[pool.size() - 1];
    pool.pop_back();
    // using largest
    long long diff1 = smallestDifference(pool, total - largest*2);
    // excluding largest
    long long diff2 = smallestDifference(pool, total);

    return min(diff1, diff2);
}

int main() {
    int n;
    cin >> n;
    long long sum = 0;
    vector<long long> inputs (n);
    for (int i = 0; i < n; i++) {
        cin >> inputs[i];
        sum += inputs[i];
    }
    sort(inputs.begin(), inputs.end());
    cout << smallestDifference(inputs, sum) << endl;
}
