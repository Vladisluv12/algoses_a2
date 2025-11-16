#define _USE_MATH_DEFINES
#include "bits/stdc++.h"
#include "ArrayGenerator.hpp"
#include "SortTester.cpp"
#include "merge_sort.hpp"
using namespace std;

#define pii pair<long long, long long>

int main() {
    ArrayGenerator gen;
    SortTester srtTest(gen);

    auto clTests = srtTest.testMergeSort();
    auto notclTests = srtTest.testMixedSort();
    srtTest.saveResultsToCSV(clTests, "mergeSortTests.csv");
    srtTest.saveResultsToCSV(notclTests, "mixedSortTests.csv");
}