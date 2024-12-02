class Solution {
public:
    bool f(string t, string search)
    {
        for(int i=0;i<search.size();i++)
        {
            if(search[i]!=t[i])
                return false;
        }
        return true;
    }
    int isPrefixOfWord(string sentence, string searchWord) {
        int k=0;
        for(int i=0;i<sentence.size();i++)
        {
            string t="";
            while(i<sentence.size() && sentence[i]!=' ')
            {
                t+=sentence[i];
                i++;
            }
            for(int i=0;i<sentence.size();i++)
            {
                if(sentence[i]!=' ')
                    t+=sentence[i];
                else
                    break;
            }
            k++;
            if(f(t, searchWord))
                return k;
        }
        return -1;
    }
};