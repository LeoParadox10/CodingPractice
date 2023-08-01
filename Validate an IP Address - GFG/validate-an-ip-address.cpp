//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
    public:
        int isValid(string s) {
            // code here
            s=s+'.';
            int c=0;
            for(char ch:s)
                if(ch=='.')
                    c++;
            string str="";
            if(c==4)
            {
                int m=0;
                int flag=0;
                for(char ch:s)
                {
                    if(ch!='.')
                        str=str+ch;
                    else
                    {
                        c--;
                        m++;
                        if(str=="")
                            return 0;
                        for(char x:str)
                            if(isalpha(x))
                                return 0;
                        if((str.size()>1 && str[0]=='0'))
                            return 0;
                        int n=stoi(str);
                        if( n>=0 && n<=255)
                            flag++;
                        str="";
                    }
                    if(c==0)
                        break;
                }
                if(m==4 && flag==4)
                    return 1;
            }
            else
                return 0;
            return 0;
        }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}
// } Driver Code Ends