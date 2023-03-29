#include <iostream>
#include <vector>
using namespace std;

int firstOccurrence(vector<int> &arr, int target) {
    int left = 0, right = arr.size()-1;
    int result = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] >= target) {
            right = mid - 1;
            if(arr[mid] == target) {
                result = mid;
            }
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}

int lastOccurrence(vector<int> &arr, int target) {
    int left = 0, right = arr.size()-1;
    int result = -1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(arr[mid] <= target) {
            left = mid + 1;
            if(arr[mid] == target) {
                result = mid;
            }
        }
        else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 3, 3, 3, 4, 5};
    int target = 3;
    int first = firstOccurrence(arr, target);
    int last = lastOccurrence(arr, target);
    cout << "First occurrence of " << target << " is at index " << first << endl;
    cout << "Last occurrence of " << target << " is at index " << last << endl;
    return 0;
}
