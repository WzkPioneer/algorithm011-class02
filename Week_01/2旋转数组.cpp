class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        vector<int> temp=nums;
        for (int i = 0; i <(int)nums.size(); ++i) {
            temp[(i+k)%(int)nums.size()]=nums[i];
        }
        for(int i=0;i<(int)temp.size();i++)
        {
            nums[i]=temp[i];
        }
    }
};
