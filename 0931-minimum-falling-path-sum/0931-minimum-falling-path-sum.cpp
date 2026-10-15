class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
       int n=matrix.size();
       if(n==1) return matrix[0][0];
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j==0)
                matrix[i][0]=matrix[i][0]+min(matrix[i-1][0],matrix[i-1][1]);
                else if(j==n-1)
                matrix[i][n-1]=matrix[i][n-1]+min(matrix[i-1][n-1],matrix[i-1][n-2]);
                else
                matrix[i][j]=matrix[i][j]+min({matrix[i-1][j],matrix[i-1][j-1],matrix[i-1][j+1]});
            }
        }
        int m=INT_MAX;
        for(int i=0;i<n;i++)
        m=min(m,matrix[n-1][i]);
        return m;
    }
};