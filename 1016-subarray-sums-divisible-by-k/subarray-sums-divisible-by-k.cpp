class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> mod(k, 0);
        int curr=0;
        int sub=0;
        mod[0]=1;
        for(int i=0;i<nums.size();i++)
        {
            curr=((curr+nums[i]%k)+k)%k;
            sub+=mod[curr];
            mod[curr]++;
        }
        return sub;
    }
};