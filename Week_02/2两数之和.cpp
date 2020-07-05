class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
         
        unordered_map<int,int> numToIndex;
        for(int i=0;i<(int)nums.size();i++)
        {
            numToIndex[nums[i]]=i;
        }
        for(int i=0;i<(int)nums.size();i++)
        {
            int targetNum=target-nums[i];
            if(numToIndex.count(targetNum)&&numToIndex[targetNum]!=i)
            {
                ans.push_back(i);
                ans.push_back(numToIndex[targetNum]);
                return ans;
            }
        }
        return ans;
    }
};