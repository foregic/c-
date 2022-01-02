/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <vector>
#include <map>
using std::map;
using std::vector;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            auto iter=m.find(nums[i]);
            if(iter !=m.end()){
                return {m[nums[i]],i};
            }
            else{
                m[target-nums[i]]=i;
            }
        }
        return {};
        
    }
};
// @lc code=end
