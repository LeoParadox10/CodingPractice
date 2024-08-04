typedef long long ll;
const ll mod=1e9+7;
class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<ll> tmp;
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            sum=nums[i];
            tmp.push_back(sum);
            for(int j=i+1;j<n;j++)
            {
                sum+=nums[j];
                tmp.push_back(sum);
            }
        }
        sort(tmp.begin(), tmp.end());
        sum=0;
        for(int i=left-1;i<=right-1;i++)
            sum=(sum+tmp[i])%mod;
        return sum;
    }
};