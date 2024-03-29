#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

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
    int N = 15000;
    double sumRBS = 0.0;
    double sumIBS = 0.0;
    double sumSeqS = 0.0;
    for (int i = 0; i < 10; i++) {
        vector<int> arr = {};
        for (int p = 0; p < N; p++) {
            int rnum = rnumGen();
            arr.push_back(rnum);

        }
        sort(arr.begin(), arr.end());
        int target = rnumGen();

        // time test for RBS
        auto start = chrono::high_resolution_clock::now();
        recursiveBinarySearch(arr, target, 0, arr.size() - 1);
        auto stop = chrono::high_resolution_clock::now();
        auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
        sumRBS = sumRBS + static_cast<double>(duration.count());

        // time test for IBS
        auto start2 = chrono::high_resolution_clock::now();
        iterativeBinarySearch(arr, target);
        auto stop2 = chrono::high_resolution_clock::now();
        auto duration2 = chrono::duration_cast<chrono::microseconds>(stop2 - start2);
        sumIBS = sumIBS + static_cast<double>(duration2.count());

    }
    cout << "The average time for Recursive Search is : " << sumRBS / 10 << " micro-seconds. " << endl;
    cout << "The average time for Iterative Search is : " << sumIBS / 10 << " micro-seconds. " << endl;


	return 0;
}