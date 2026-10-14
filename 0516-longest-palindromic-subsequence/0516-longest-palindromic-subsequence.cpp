class Solution {
public:
   int palindrome(string& s,int i,int j,vector<vector<int>>& dp){
    if(i>j) return 0;
    if(i==j) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s[i]==s[j]) {
      return dp[i][j]=2+palindrome(s,i+1,j-1,dp);
    } 
    else{
        return dp[i][j]= max(palindrome(s,i+1,j,dp),palindrome(s,i,j-1,dp));
    }
    return dp[i][j];
   }
    int longestPalindromeSubseq(string s) {
      int n=s.size();
      vector<vector<int>> dp(n,vector<int>(n,-1));
      return palindrome(s,0,n-1,dp);
    }
};