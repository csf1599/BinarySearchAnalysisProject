#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int recursiveBinarySearch(const vector<int>& arr, int target, int left, int right) {
    if (left > right)
        return -1;
    int mid = left + (right - left) / 2;
    if (arr[mid] == target)
        return mid;
    if (arr[mid] > target)
        return recursiveBinarySearch(arr, target, left, mid - 1);
    else
        return recursiveBinarySearch(arr, target, mid + 1, right);
}
void printVector(const vector<int>& arr) {
    cout << "Vector contents: ";
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    vector<int> arr = { 4, 2, 6, 8, 1, 10, 7, 9, 5 };
    sort(arr.begin(), arr.end());
    printVector(arr);
    int target1 = 4;
    int target2 = 12;
    cout << "Recursive Binary Search" << endl;
    int index = recursiveBinarySearch(arr, target1, 0, arr.size() - 1);
    cout << target1;
    if (index != -1) {
        cout << " found at location " << index + 1;
    }
    else {
        cout << " was not found.";
    }
    cout << endl;
    index = recursiveBinarySearch(arr, target2, 0, arr.size() - 1);
    cout << target2;
    if (index != -1) {
        cout << " found at location " << index + 1;
    }
    else {
        cout << " was not found.";
    }
    cout << endl;
	return 0;
}