class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) 
    {
        int nrow=rowSum.size();
        int mcol=colSum.size();

        vector<vector<int>> ansMat(nrow, vector<int> (mcol, 0));

        int r=0, c=0;
        
        while(r<nrow && c<mcol)
        {
            int val=min(rowSum[r], colSum[c]);

            ansMat[r][c]=val;

            rowSum[r]-=val;
            colSum[c]-=val;

            if(rowSum[r]==0)
                r++;
            else
                c++;
        }
        return ansMat;
    }
};