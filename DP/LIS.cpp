#include <iostream>
#include <vector>
#include <algorithm>

/*Longest increasing Subarray*/

int LIS(std::vector<int> nums){
    /*DP approach */

    std::vector<int> mem = {1};
    for (int i=1; i<nums.size(); i++){
        int resk = 1;
        for (int j=0; j< i; j++){
            if (nums[j] <= nums[i] && resk < mem[j]+1){
                resk = mem[j]+1;
            }
        }
        mem.push_back(resk);
    }
    return *std::max_element(mem.begin(), mem.end());
}






int main(){
    std::vector<int> nums = {10,9,2,5,3,7,101,18};
    std::cout << LIS(nums) << "\n";
}
