#include <bits/stdc++.h>
using namespace std;

auto firstTrue = [](int low, int high, function<bool(int)> f) {
    while (low < high) {
        int mid = (low+high) / 2;
        if (f(mid))
            high = mid;
        else
            low = mid + 1;
    }
    if (f(low)) return low;
    return -1;
};

auto lastTrue = [](int low, int high, function<bool(int)> f) {
    while (low < high) {
        int mid = (low+high+1) / 2;
        if (f(mid))
            low = mid;
        else
            high = mid - 1;
    }
    if (f(low)) return low;
    return -1;
};
