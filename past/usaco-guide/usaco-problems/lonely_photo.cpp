#include <bits/stdc++.h>
#define ln "\n"
using namespace std;

int main() {
    #define int long long
    
    cin.tie(nullptr); ios::sync_with_stdio(false);
    
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j-1 >= 0 && s[j-1] != s[i]) j--;
        int k = i;
        while (k+1 < n && s[k+1] != s[i]) k++;
        
        count += (i-j) * (k-i);
        if (k-i >= 2) count += k-i-1;
        if (i-j >= 2) count += i-j-1;
    }
    cout << count << ln;
}
