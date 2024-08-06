class Solution {
public:
    int convertTime(string current, string correct) {
        string curr=current.substr(0, 2);
        string corr=correct.substr(0, 2);
        int currh=stoi(curr)*60;
        int corrh=stoi(corr)*60;
        curr=current.substr(3);
        corr=correct.substr(3);
        int currm=stoi(curr);
        int corrm=stoi(corr);
        int diff=corrh+corrm-currh-currm;
        vector<int> ops={60, 15, 5, 1};
        int ans=0;
        for(int it:ops)
        {
            ans+=diff/it;
            diff%=it;
        }
        return ans;
    }
};