class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n=asteroids.size();
        sort(asteroids.begin(), asteroids.end());
        long long mas=mass;
        if(asteroids[0]>mas)
            return false;
        for(int i=0;i<n;i++)
        {
            if(mas>=asteroids[i])
                mas+=asteroids[i];
            else
                return false;
        }
        return true;
    }
};