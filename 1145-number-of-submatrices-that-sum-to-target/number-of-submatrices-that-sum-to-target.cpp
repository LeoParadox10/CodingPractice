class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int ans=0;
        int m=matrix.size(), n=matrix[0].size();
        for(int row=0;row<m;row++)
            for(int col=1;col<n;col++)
                matrix[row][col]+=matrix[row][col-1];

        for(int colStart=0;colStart<n;colStart++)
        {
            for(int colEnd=colStart;colEnd<n;colEnd++)
            {
                for(int rowStart=0;rowStart<m;rowStart++)
                {
                    int sum=0;
                    for(int rowEnd=rowStart;rowEnd<m;rowEnd++)
                    {
                        sum+=matrix[rowEnd][colEnd]-(colStart ? matrix[rowEnd][colStart-1] : 0);
                        if(sum==target)
                            ans++;
                    }
                }
            }
        }
        return ans;
    }
};