#pragma once

#include <random>
#include <algorithm>
#include <vector>
using namespace std;

random_device rd;
mt19937 gen(rd());

class ArrayGenerator {
    int mn = 0, mx = 6000;
private:
     vector<int> gen_arr_rnd(int sz) {
        uniform_int_distribution dis(mn, mx);
        vector<int> nums(sz);
        for (int i = 0; i < sz; i++) {
            nums[i] = dis(gen);
        }
        return nums;
    }

    vector<int> gen_arr_uns(int sz) {
        vector<int> nums = gen_arr_rnd(sz);
        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());
        return nums;
    }

    vector<int> gen_arr_almost_sorted(int sz) {
        vector<int> nums = gen_arr_rnd(sz);
        sort(nums.begin(), nums.end());
        uniform_int_distribution hz(0, sz - 1);
        for (int i = 0; i < (hz(gen) % 5) + 1; i++) {
            int k = hz(gen), f = hz(gen);
            swap(nums[k], nums[f]);
        }
        return nums;
    }

public:
    vector<int> gen_test_arr(int i, int sz) {
        if (i == 0) {
            return gen_arr_rnd(sz);
        } else if (i == 1) {
            return gen_arr_uns(sz);
        } else {
            return gen_arr_almost_sorted(sz);
        }
    }
};