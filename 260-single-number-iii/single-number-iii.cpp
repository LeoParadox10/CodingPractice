class Solution {
public:
    static vector<int> singleNumber(vector<int>& nums) {
        long long XOR=accumulate(nums.begin(), nums.end(), 0LL, bit_xor<>());

        int lastBit=XOR^(XOR &(XOR-1));

        int A=0, B=0;
        for(int x: nums){
            if ((x& lastBit) == 0)
                A^=x;
            else
                B^=x; 
        }
        return {A, B};
    }
};