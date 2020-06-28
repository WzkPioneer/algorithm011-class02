class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int adi=1;
        for(int i=(int)digits.size()-1;i>=0;i--)
        {
            int temp=adi+digits[i];
            if(temp>=10)
            {
                int now=temp%10;
                ans.push_back(now);
                adi=1;
            }
            else
            {
                ans.push_back(temp);
                adi=0;
            }
        }
        if(adi)
        {
            ans.push_back(1);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};