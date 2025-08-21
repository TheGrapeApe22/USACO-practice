#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long n, x;
    cin >> n >> x;
    vector<long long> children (n);
    for (long long i = 0; i < n; i++)
        cin >> children[i];
    
    sort(children.begin(), children.end(), greater<long long>());
    
    long long numDoubled = 0;
    for (long long i = 0; i < n - numDoubled - 1; i++) {
        if (children[i] + children[n - numDoubled - 1] <= x)
            numDoubled++;
    }

    cout << n - numDoubled << endl;
}
