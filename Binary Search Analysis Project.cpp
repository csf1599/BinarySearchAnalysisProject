#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int recursiveBinarySearch(const vector<int>& arr, int target, int left, int right) {
    if (left > right) {
        return -1;
    }
    int mid = left + (right - left) / 2;
    if (arr[mid] == target) {
        return mid;
    }
    if (arr[mid] > target) {
        return recursiveBinarySearch(arr, target, left, mid - 1);
    }
    else
        return recursiveBinarySearch(arr, target, mid + 1, right);
}
int iterativeBinarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return -1;
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
    cout << "iterative search test" << endl;
    int j = iterativeBinarySearch(arr, target1);
    cout << target1;
    if (j != -1) {
        cout << " found at location " << j + 1; 
    }
    else {
        cout << " was not found.";
    }
    cout << endl;
    
	return 0;
}