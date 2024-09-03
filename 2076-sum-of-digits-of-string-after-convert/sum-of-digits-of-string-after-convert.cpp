class Solution {
public:
    int getLucky(string s, int k) {
        string st="";
        int sum=0;
        int n=s.size();
        for(int i=0;i<n;i++)
            st+=to_string(s[i]-'a'+1);
        for(int i=0;i<st.size();i++)
            sum+=(st[i]-'0');
        k--;
        while(k--!=0)
        {
            int num=sum;
            sum=0;
            while(num!=0)
            {
                int d=num%10;
                num=num/10;
                sum+=d;
            }
        }
        return sum;
    }
};