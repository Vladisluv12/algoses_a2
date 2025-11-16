#pragma once
#include "merge_sort.hpp"
#include "ArrayGenerator.hpp"
#include <string>
#include <vector>
#include <chrono>
#include <iostream>

class SortTester {
public:
    struct TestResult {
        int size;
        long long timeMicros;
        int arrayType;
        int threshold;
    };

    ArrayGenerator arrGen;

    SortTester(ArrayGenerator& generator) {
        arrGen = generator;
    }

    std::vector<TestResult> testMergeSort() {
        std::vector<TestResult> results;

        for (int i = 0; i < 3; i++) {
            for (int size = 500; size < 10000; size += 100) {
                long long totalTime = 0;
                const int RUNS = 5;
                for (int run = 0; run < RUNS; ++run) {
                    std::vector<int> arr = arrGen.gen_test_arr(i, size);
                    
                    auto start = std::chrono::high_resolution_clock::now();
                    mergeSort(arr);
                    auto elapsed = std::chrono::high_resolution_clock::now() - start;
                    
                    totalTime += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
                }
                long long avgTime = totalTime / RUNS;
                results.push_back({size, avgTime, i, 0});
                if (size % 10000 == 0) {
                    cout << "so much tests made" << i << '\n';
                }
            }
        }
        cout << "Tested" << '\n';
        return results;
    }

    std::vector<TestResult> testMixedSort(const std::vector<int>& thresholds = {5, 10, 20, 30, 50}) {
        std::vector<TestResult> results;
        for (int i = 0; i < 3; i++) {
            for (int threshold : thresholds) {
                for (int size = 500; size < 10000; size += 100) {
                    long long totalTime = 0;
                    const int RUNS = 5;
                    
                    for (int run = 0; run < RUNS; ++run) {
                        std::vector<int> arr = arrGen.gen_test_arr(i, size);
                        
                        auto start = std::chrono::high_resolution_clock::now();
                        mixedSort(arr, threshold);
                        auto elapsed = std::chrono::high_resolution_clock::now() - start;
                        
                        totalTime += std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();
                    }
                    long long avgTime = totalTime / RUNS;
                    results.push_back({size, avgTime, i, threshold});
                    if (size % 10000 == 0) {
                        cout << "so much tests made" << i << '\n';
                    }
                }
            }
        }
        return results;
    }

    void saveResultsToCSV(vector<TestResult>& results, const string& filename) {
        ofstream file(filename);
        file << "Size,TimeMicros,ArrayType,Threshold\n";
        
        for (const auto& result : results) {
            file << result.size << "," << result.timeMicros << "," << result.arrayType << ","  << "," << result.threshold << "\n";
        }
        
        file.close();
    }
};