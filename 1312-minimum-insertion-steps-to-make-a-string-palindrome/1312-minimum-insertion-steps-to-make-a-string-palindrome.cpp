class Solution {
public:
   int insert(int i,int j,string& s,vector<vector<int>>& dp){
    if(i==j) return 0;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) return dp[i][j]=insert(i+1,j-1,s,dp);
    else return dp[i][j]=min(1+insert(i+1,j,s,dp),1+insert(i,j-1,s,dp));
   }
    int minInsertions(string s){
        int n=s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return insert(0,n-1,s,dp);
    }
};