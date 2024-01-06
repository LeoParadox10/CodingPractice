class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> r;
        vector<int> c;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(find(r.begin(), r.end(), i)!=r.end() || find(c.begin(), c.end(), j)!=c.end())
                    matrix[i][j]=0;
            }
        }
    }
};