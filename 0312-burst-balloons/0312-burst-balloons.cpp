class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        vector<int> ar;
        ar.push_back(1);
        for(auto& i:nums)
        ar.push_back(i);
        ar.push_back(1);
        int m=n+2;
        vector<vector<int>> dp(m,vector<int>(m,0));
        for(int len=1;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                for(int k=i;k<=j;k++){
                    int cost=ar[i-1]*ar[k]*ar[j+1];
                    int sub=dp[i][k-1]+dp[k+1][j];
                    dp[i][j]=max(dp[i][j],cost+sub);
                }
            }
        }
        return dp[1][n];
    }
};