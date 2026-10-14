class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<int> path(n,0);
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1)
            break;
            path[i]=1;
        }
        for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(obstacleGrid[i][j]==1)
                path[j]=0;
                else if(j>0)
                path[j]=path[j]+path[j-1];
            }
        }
        return path[n-1];
    }
};