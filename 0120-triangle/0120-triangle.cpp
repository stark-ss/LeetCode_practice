class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<int> dp(n,0);
        dp[0]=triangle[0][0];
        for(int i=1;i<n;i++){
            int prev=dp[0];
            for(int j=0;j<=i;j++){
                int temp=dp[j];
                 if(j==0) dp[j]+=triangle[i][j];
                 else if(i==j) dp[j]=prev+triangle[i][j];
                 else if(j>0) dp[j]=triangle[i][j]+min(prev,temp);
               
                prev=temp;
            }
        }
        int m=INT_MAX;
        for(auto& i:dp){
            m=min(m,i);
        }
        return m;
    }
};