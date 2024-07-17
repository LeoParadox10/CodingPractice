class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int i=0;
        int j=n-1;
        int area=-1;
        while(i<j)
        {
            int tarea=min(height[i], height[j])*(j-i);
            area=max(area, tarea);
            if(height[i]>height[j])
                j--;
            else
                i++;
        }
        return area;
    }
};