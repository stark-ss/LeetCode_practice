class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        unordered_map<int,int> look;
        int c=0;
        look[0]=1;
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                matrix[i][j]+=matrix[i][j-1];
                
            }
        }

        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
                int sum=0;
                unordered_map<int,int> look;
                look[0]=1;
                for(int r=0;r<n;r++){
                    int rowsum=matrix[r][c2];
                    if(c1>0)
                    rowsum-=matrix[r][c1-1];
                    sum+=rowsum;
                    if(look.find(sum-target)!=look.end()){
                     c+=look[sum-target];
                    }
                    look[sum]++;
                }
            }
        }
        return c;
    }
};