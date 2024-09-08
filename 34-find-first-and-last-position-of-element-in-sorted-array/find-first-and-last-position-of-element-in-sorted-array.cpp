class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int s=0, e=n-1;
        vector<int> pos(2, -1);
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                pos[0]=mid;
                e=mid-1;
            }
            else if(nums[mid]<target)
                s=mid+1;
            else
                e=mid-1;
        }
        s=0, e=n-1;
        while(s<=e)
        {
            int mid=s+(e-s)/2;
            if(nums[mid]==target)
            {
                pos[1]=mid;
                s=mid+1;
            }
            else if(nums[mid]<target)
                s=mid+1;
            else
                e=mid-1;
        }
        return pos;
    }
};