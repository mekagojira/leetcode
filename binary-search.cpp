// https: //leetcode.com/problems/binary-search/
#include <iostream>
#include <vector>

using namespace std;

int recursive_search(vector<int> &nums, int target);
int search_in_half(vector<int> &nums, int start, int end, int target);
int iterative_search(vector<int> &nums, int target);

int main(void)
{
    vector<int> arr = {-1, 0, 3, 5, 9, 12};
    int target = 1;

    int result = iterative_search(arr, target);
    cout << result << endl;

    return 0;
}

int iterative_search(vector<int> &nums, int target)
{
    int start = 0, end = nums.size() - 1;
    while (start <= end)
    {
        int med_idx = start + (end - start) / 2;
        int med_val = nums.at(med_idx);
        if (med_val == target)
            return med_idx;
        if (med_val < target)
            start = med_idx + 1;
        else
            end = med_idx - 1;
    }

    return -1;
}

int recursive_search(vector<int> &nums, int target)
{
    int first_element = nums.at(0);
    int last_element = nums.at(nums.size() - 1);

    return search_in_half(nums, 0, nums.size() - 1, target);
}

int search_in_half(vector<int> &nums, int start, int end, int target)
{
    if (start > end)
        return -1;
    int med_idx = start + (end - start) / 2;
    int med_value = nums.at(med_idx);

    if (med_value == target)
        return med_idx;

    return med_value < target ? search_in_half(nums, med_idx + 1, end, target) : search_in_half(nums, start, med_idx - 1, target);
}