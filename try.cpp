#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#include "ArrayGenerator.hpp"
using namespace std;

#define pii pair<long long, long long>

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
    for (int i = 0; i < v.size(); i++) {
        out << v[i] << ' ';
    }
    return out;
}

void mergeSort(vector<int>& arr) {
    if (arr.size() == 1) {
        return;
    }
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
        while (j >= 0 && arr[j] > k) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = k;
    }
}

void mixedSort(vector<int>& arr) {
    int n = arr.size();
    if (n <= 15) {
        insertionSort(arr);
        return;
    }
    auto middle = arr.begin() + arr.size() / 2;
    vector<int> left(arr.begin(), middle);
    vector<int> right(middle, arr.end());
    mixedSort(left);
    mixedSort(right);
    arr.clear();
    merge(left.begin(), left.end(), right.begin(), right.end(), back_inserter(arr));
}

int main() {
    ArrayGenerator gen;
    vector<int> smth = gen.gen_test_arr(0, 99900);
    mergeSort(smth);
}