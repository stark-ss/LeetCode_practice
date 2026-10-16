class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0]=0;
        int r[]={-1,0,1,0};
        int c[]={0,1,0,-1};
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> q;
        q.push({0,0,0});
        while(!q.empty()){
            auto[effort,i,j]=q.top();
            q.pop();
            if(effort>dp[i][j]) continue;
            for(int k=0;k<4;k++){
                int row=i+r[k];
                int col=j+c[k];
                if(row>=0 && row<m && col>=0 && col<n){
                    int ef=max(effort,abs(heights[i][j]-heights[row][col]));
                    if(ef<dp[row][col]){
                    dp[row][col]=ef;
                    q.push({ef,row,col});
                    }

                }
            }
        }
        return dp[m-1][n-1];
    }
};