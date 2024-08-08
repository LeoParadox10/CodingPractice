class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        int totalCells = rows*cols;
        int steps = 1;  
        int dirIndex = 0; 
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};  // Right, down, left, up
        int r = rStart, c = cStart;
        result.push_back({r, c});
        totalCells--;
        while (totalCells > 0) 
        {
            for (int i = 0; i < 2; ++i) 
            {  
                for (int j = 0; j < steps; ++j) 
                {
                    r += directions[dirIndex][0];
                    c += directions[dirIndex][1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols) 
                    {
                        result.push_back({r, c});
                        totalCells--;
                        if (totalCells == 0)
                            return result;
                    }
                }
                dirIndex = (dirIndex + 1) % 4; 
            }
            steps++;  
        }
        return result;
    }
};
