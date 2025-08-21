#include <bits/stdc++.h>

using namespace std;

// void printVector(vector<long long> v) {cout<<"[";int n=v.size();for(int i=0;i+1<n;i++)cout<<v[i]<<", ";if (n>0)cout<<v[n-1];cout<<"]\n";}

int main() {
    int n;
    cin >> n;
    vector<long long> values (n);
    
    for (int i = 0; i < n; i++) 
        cin >> values[i];
    
    sort(values.begin(), values.end());

    vector<long long> prefix_sums (n);
    prefix_sums[0] = values[0];
    for (int i = 1; i < n; i++)
        prefix_sums[i] = prefix_sums[i-1] + values[i];

    // printVector(prefix_sums);

    bool isFirst = true;
    long long minDiff;
    for (int i = 0; i < n; i++) {
        long long diffs = prefix_sums[n - 1];
        diffs -= prefix_sums[i] * 2;
        
        diffs += values[i] * (i+1 - (n-i-1));
        
        if (isFirst || diffs < minDiff) {
            minDiff = diffs;
            isFirst = false;
        }
    }
    cout << minDiff << endl;
}
