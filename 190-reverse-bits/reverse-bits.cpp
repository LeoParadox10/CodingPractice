class Solution {
typedef uint32_t u;
public:
    uint32_t reverseBits(uint32_t n) {
        u ans=0;
        for(int i=0;i<32;i++)
        {
            u bit=(n>>i)&1;
            ans=ans | (bit << (31-i)); // to store bit in reverse order
        }
        return ans;
    }
};