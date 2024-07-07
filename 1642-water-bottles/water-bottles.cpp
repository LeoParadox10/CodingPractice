class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=numBottles;
        while(numBottles>=numExchange)
        {
            int d=numBottles/numExchange;
            ans+=d;
            numBottles=(numBottles%numExchange)+d;
        }
        return ans;
    }
};