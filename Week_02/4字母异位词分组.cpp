class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,int> stringToInt;
        int index=0;
        for(int i=0;i<(int)strs.size();i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());
            if(stringToInt.count(temp))
            {
                ans[stringToInt[temp]].push_back(strs[i]);
            }
            else
            {
                vector<string> tep;
                tep.push_back(strs[i]);
                ans.push_back(tep);
                stringToInt[temp]=index++;
                
            }
        }
        return ans;
    } 
};