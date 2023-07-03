//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

typedef long long ll;
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    ll merge(ll arr[], ll temp[], ll left, ll mid,  ll right)
    {
        ll i, j, k;
        ll inv_cnt=0;
        
        i=left; // i is index for left subarray
        j=mid;  // j is index for right subarray
        k=left; // k is index for resultant merged subarray
        
        while(i<=mid-1 && j<=right)
        {
            if(arr[i]<=arr[j])
                temp[k++]=arr[i++];
            else
            {
                temp[k++]=arr[j++];
                inv_cnt+=mid-i;
            }
        }
            
        while(i<=mid-1)
            temp[k++]=arr[i++];
        while(j<=right)
            temp[k++]=arr[j++];
                
        for(i=left;i<=right;i++)
            arr[i]=temp[i];
        
        return inv_cnt;
    }
    ll merge_sort(ll arr[], ll temp[], ll left, ll right)
    {
        ll inv_cnt=0, mid=0;
        if(left<right)
        {
            mid=left+(right-left)/2;
        
            //left part
            inv_cnt+=merge_sort(arr, temp, left, mid);
            //right part
            inv_cnt+=merge_sort(arr, temp, mid+1, right);
        
            //merge operation
            inv_cnt+=merge(arr, temp, left, mid+1, right);
        }
        return inv_cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        ll temp[N];
        return merge_sort(arr, temp, 0, N-1);
    }
};

//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends