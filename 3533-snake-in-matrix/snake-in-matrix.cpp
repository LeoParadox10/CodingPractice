class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int pos=0;
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i]=="UP")
                pos-=n;
            else if(commands[i]=="DOWN")
                pos+=n;
            else if(commands[i]=="RIGHT")
                pos++;
            else
                pos--;
        }
        return pos;
    }
};