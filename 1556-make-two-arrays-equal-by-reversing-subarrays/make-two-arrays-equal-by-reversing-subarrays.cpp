class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> m1, m2;
        for(auto i:arr)
            m1[i]++;
        for(auto i:target)
            m2[i]++;
        for(auto i:arr)
        {
            if(m2.find(i)==m2.end())
                return false;
            else if(m1[i]!=m2[i])
                return false;
        }
        return true;
    }
};