class Solution {
public:
    int countSeniors(vector<string>& details) {
        int senior=0;
        for(int i=0;i<details.size();i++)
        {
            int age;
            age=(details[i][11]-'0')*10 + (details[i][12]-'0');
            if(age>60)
                senior++;
        }
        return senior;
    }
};