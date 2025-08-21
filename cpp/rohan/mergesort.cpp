#include <iostream>
#include <vector>

using namespace std;

void sort(vector<int>& list, int start, int end);
void merge(vector<int>& list, int start, int mid, int end);

int main() {
    int n;
    cin >> n;
    vector<int> list1 (n);
    for (int i = 0; i < n; i++) {
        cin >> list1[i];
    }
    
    sort(list1, 0, list1.size());
    for (int i = 0; i < list1.size(); i++) {
        cout << list1[i] << " ";
    }
}

void sort(vector<int>& list, int start, int end) { // [start, end)
    // cout << start << ", " << end << "\n";
    if (start >= end - 1) return;
    int mid = (start + end) / 2;
    sort(list, start, mid);
    sort(list, mid, end);
    merge(list, start, mid, end);
}
void merge(vector<int>& list, int start, int mid, int end) { // [start, mid), [mid, end)
    vector<int> temp(end - start);

    int i = start;
    int j = mid;
    int tempI = 0;

    while (i < mid && j < end) {
        if (list[i] < list[j])
            temp[tempI++] = list[i++];
        else
            temp[tempI++] = list[j++];
    }
    while (i < mid)
        temp[tempI++] = list[i++];
    
    while (j < end)
        temp[tempI++] = list[j++];

    for (int k = 0; k < temp.size(); k++)
        list[start + k] = temp[k];
}
