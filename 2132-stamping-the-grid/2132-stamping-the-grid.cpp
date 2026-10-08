class Solution {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> pre(m+1,vector<int>(n+1,0));
        vector<vector<int>> dif(m+2,vector<int>(n+2,0));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pre[i][j]=grid[i-1][j-1]-pre[i-1][j-1]+pre[i-1][j]+pre[i][j-1];
            }
        }
        for(int i=0;i<=m-stampHeight;i++){
            for(int j=0;j<=n-stampWidth;j++){
                    int r2=i+stampHeight;
                    int c2=j+stampWidth;
                    int sum=pre[r2][c2]+pre[i][j]-pre[r2][j]-pre[i][c2];
                    if(sum==0){
                        dif[i+1][j+1]+=1;
                        dif[i+1][c2+1]-=1;
                        dif[r2+1][j+1]-=1;
                        dif[r2+1][c2+1]+=1;
                    }
                }
            
        } 

        for(int i=1;i<m+2;i++){
            for(int j=1;j<n+2;j++){
                dif[i][j]+=-dif[i-1][j-1]+dif[i-1][j]+dif[i][j-1];
            }
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(grid[i-1][j-1]==0 && dif[i][j]==0)
                return false;
            }
        }
       return true;
    }
};