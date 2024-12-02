class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        int n=sentence.size();
        int m=searchWord.size();
        int wordIndex=1;
        int pos=0;
        while(pos<n)
        {
            int end=pos;
            while(end<n && sentence[end]!=' ')
                end++;
            if(end-pos>=m && sentence.substr(pos, m)==searchWord)
                return wordIndex;
            pos=end+1;
            wordIndex++;
        }
        return -1;
    }
};