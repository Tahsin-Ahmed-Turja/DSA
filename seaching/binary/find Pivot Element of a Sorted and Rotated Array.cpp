#include <iostream>
#include <vector>
using namespace std;

int findPivot(vector<int> &arr) {
    int left = 0, right = arr.size()-1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(mid < right && arr[mid] > arr[mid+1]) {
            return arr[mid+1];
        }
        else if(mid > left && arr[mid] < arr[mid-1]) {
            return arr[mid];
        }
        else if(arr[mid] <= arr[left]) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {7, 8, 9, 10, 1, 2, 3, 4, 5, 6};
    int pivot = findPivot(arr);
    cout << "The pivot element of the array is " << pivot << endl;
    return 0;
}
