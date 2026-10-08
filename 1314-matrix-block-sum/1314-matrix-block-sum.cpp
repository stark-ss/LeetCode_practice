class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m+1,vector<int>(n+1,0));
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                ans[i][j]=mat[i-1][j-1]+ans[i-1][j]+ans[i][j-1]-ans[i-1][j-1];
            
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
              int r1=max(1,i-k);
              int c1=max(1,j-k);
              int r2=min(m,i+k);
              int c2=min(n,j+k);

            mat[i-1][j-1]=ans[r2][c2]-ans[r2][c1-1]-ans[r1-1][c2]+ans[r1-1][c1-1];

        }
        }
        return mat;
    }
};