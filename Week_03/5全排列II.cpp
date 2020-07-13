class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int current_len = 0;
        vector<vector<int>> res;
        function<void(void)> backtrack = [&](void){
            if(current_len == nums.size()){
                res.push_back(nums);
                return;
            }
            current_len++;
            backtrack();
            current_len--;
            for(int i = 0; i < current_len; i++){
                swap(nums[i], nums[current_len]);
                current_len++;
                backtrack();
                current_len--;
                swap(nums[i], nums[current_len]);
            }
        };
        backtrack();
        return res;
    }
};

