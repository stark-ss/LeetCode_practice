class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<int> dp(m+1,0);
        for(int i=0;i<=m;i++)
        dp[i]=i;
        for(int i=1;i<=n;i++){
            int prev=dp[0];
            dp[0]=i;
            for(int j=1;j<=m;j++){
                int temp=dp[j];
                if(word2[j-1]==word1[i-1])
                dp[j]=prev;
                else dp[j]=min({prev,dp[j],dp[j-1]})+1;
                prev=temp;
            }
        }
       
         return dp[m];

    }
};