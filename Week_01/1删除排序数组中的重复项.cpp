class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if((int)nums.size()==0)return 0;

        int lastNonCoyAt=0;
        for(int cur=0;cur<(int)nums.size();cur++)
        {
            while(cur<(int)nums.size()&&nums[cur]==nums[lastNonCoyAt])
            {
                cur++;
            }
            if(cur<(int)nums.size())swap(nums[++lastNonCoyAt],nums[cur]);
        }
        return lastNonCoyAt+1;
    }
};