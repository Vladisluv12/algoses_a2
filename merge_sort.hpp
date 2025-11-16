#pragma once

using namespace std;
#include <vector>
#include <algorithm>

void mergeSort(vector<int>& arr) {
    if (arr.size() == 1) return;
    auto middle = arr.begin() + arr.size() / 2;
    vector<int> left(arr.begin(), middle);
    vector<int> right(middle, arr.end());
    mergeSort(left);
    mergeSort(right);
    arr.clear();
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(arr));
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int k = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

void mixedSort(vector<int>& arr, int threshold) {
    int n = arr.size();
    if (n <= threshold) {
        insertionSort(arr);
        return;
    }
    auto middle = arr.begin() + arr.size() / 2;
    vector<int> left(arr.begin(), middle);
    vector<int> right(middle, arr.end());
    mixedSort(left, threshold);
    mixedSort(right, threshold);
    arr.clear();
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(arr));
}