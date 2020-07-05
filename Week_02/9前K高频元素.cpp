class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> ans;
        unordered_map<int,int> numToRate;
        priority_queue< pair<int,int> , vector< pair<int,int> >, greater< pair<int,int> > > pq;

        for(int i=0;i<(int)nums.size();i++)
        {
            numToRate[nums[i]]++;
        }
        int n=numToRate.size();
 
        for(auto it=numToRate.begin();it!=numToRate.end();it++)
        {
            if(k==pq.size())
            {
                if(it->second>pq.top().first)
                {
                    pq.pop();
                    pq.push(make_pair(it->second,it->first));
                }
            }
            else
            {
                pq.push(make_pair(it->second,it->first));
            }
        } 
        while(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};