/*
给你一个整数数组 nums ，和一个表示限制的整数 limit，请你返回最长连续子数组的长度，该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit 。
如果不存在满足条件的子数组，则返回 0 。

示例 1：
输入：nums = [8,2,4,7], limit = 4
输出：2 

示例 2：
输入：nums = [10,1,2,4,7,2], limit = 5
输出：4 

示例 3：
输入：nums = [4,2,2,2,4,4,2,2], limit = 0
输出：3
 

提示：
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^9
0 <= limit <= 10^9
*/
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int res=0,left=0,right=0;
        multiset<int> s;
        while(right<nums.size()){
            s.insert(nums[right]);
            while(*s.rbegin()-*s.begin() > limit)
                s.erase(s.find(nums[left++]));
            res=max(res,++right-left);
        }
        return res;
    }
};
