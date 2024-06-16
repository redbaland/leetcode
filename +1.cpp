class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> nummap;
        for(int i = 0; i< nums.size(); i++){
            if(nummap.find(target - nums[i]) != nummap.end())
                return {nummap[target - nums[i]], i};
            else nummap[nums[i]] = i;
        }
        return {};
    }
};
