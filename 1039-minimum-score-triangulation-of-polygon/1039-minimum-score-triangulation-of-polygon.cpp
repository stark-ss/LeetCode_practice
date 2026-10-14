class Solution {
public:
int calculate(int i,int j,vector<int>& val,vector<vector<int>>& dp){
    if(dp[i][j]!=-1) return dp[i][j];
    long cost=INT_MAX;
    if(j-i==1) return 0;
    for(int k=i+1;k<j;k++){
        int left=calculate(i,k,val,dp);
        int right=calculate(k,j,val,dp);
        long tot=val[i]*val[j]*val[k]+left+right;
        cost=min(cost,tot);
    }
    return dp[i][j]=cost;
}
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return calculate(0,n-1,values,dp);
    }
};