#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
int sequentialSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] == target) {
            return i;
        }

        
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
int rnumGen() {
    mt19937 rng(_Random_device());
    uniform_int_distribution<int> distribution(1, 100);
    int rnum = distribution(rng);
    return rnum;
}
int main() {
    vector<int> arr = {};
    for (int p = 0; p < 10; p++) {
        int rnum = rnumGen();
        arr.push_back(rnum);

    }
    sort(arr.begin(), arr.end());
    printVector(arr);
    int target1 = rnumGen();

    // recursive test code

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

    // iterative test code

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
 
    // sequential test code

    cout << "sequential search test" << endl;
    int f = sequentialSearch(arr, target1);
    cout << target1;
    if (f != -1) {
        cout << " found at location " << f + 1;
    }
    else {
        cout << " was not found.";
    }
    cout << endl;
 

	return 0;
}