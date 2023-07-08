//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        map<int, bool> m;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0 && arr[i]<=n)
                if(m.find(arr[i])==m.end())
                    m[arr[i]]=true;
        }
        if(m.size()==0)
            return 1;
        for(int i=1;;i++)
        {
            if(m.find(i)==m.end())
                return (i);
        }
        return 1;
    } 
};


// class Solution {
// public:
//     int missingNumber(int arr[], int n) {
//         vector<bool> present(n + 1, false);

//         for (int i = 0; i < n; i++) {
//             if (arr[i] >= 0 && arr[i] <= n)
//                 present[arr[i]] = true;
//         }

//         for (int i = 1; i <= n; i++) {
//             if (!present[i])
//                 return i;
//         }

//         return n + 1;
//     }
// };



//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends