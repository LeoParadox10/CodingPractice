class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int, int>> mapped(n);
        for(int i=0;i<n;i++)
        {
            int org=nums[i];
            string mappedValue="";
            if(org==0)
                mappedValue=to_string(mapping[0]);
            else
            {
                while(org>0)
                {
                    mappedValue=to_string(mapping[(org%10)])+mappedValue;
                    org/=10;
                }
            }
            mapped[i]={stoi(mappedValue), i};
        }
        sort(mapped.begin(), mapped.end());
        vector<int> ans;
        for(auto &pair:mapped)
            ans.push_back(nums[pair.second]);
        return ans;
    }
};