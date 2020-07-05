class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[1700];
        dp[0]=1;
        int a=0,b=0,c=0;
        for(int i=1;i<=n;i++)
        {
            int n2=dp[a]*2;
            int n3=dp[b]*3;
            int n5=dp[c]*5;
            dp[i]=min(min(n2,n3),n5);
            if(dp[i]==n2)a++;
            if(dp[i]==n3)b++;
            if(dp[i]==n5)c++;
        }

        return dp[n-1];
    }
};