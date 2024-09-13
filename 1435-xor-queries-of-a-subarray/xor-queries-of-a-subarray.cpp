class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int size = arr.size();
        vector<int> prefXor(size);
        
        for(int indx = 0; indx < size; indx++) {
            if(indx == 0) 
                prefXor[indx] = arr[indx];
            else 
                prefXor[indx] = prefXor[indx - 1] ^ arr[indx];
        }
        
        vector<int> res(queries.size());
        int indx = 0;

        for(const auto& quer : queries) {
            int left = quer[0], right = quer[1];
            res[indx++] = prefXor[right] ^ ((left == 0) ? 0 : prefXor[left - 1]);
        }

        return res;
    }
};