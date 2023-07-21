//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    bool ispar(string x)
    {
        stack<char> s;
        for(int i=0;i<x.length();i++)
        {
            char c=x[i];
            if(c=='{' || c=='(' || c=='[')
                s.push(c);
            else
            {
                if(!s.empty())
                {
                    char top=s.top();
                    if(c=='}' && top=='{' || 
                       c==']' && top=='[' ||
                       c==')' && top=='(')
                       s.pop();
                    else
                        return false;
                }
                else
                    return false;
            }
        }
        if(!s.empty())
            return false;
        return true;
    }
};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends