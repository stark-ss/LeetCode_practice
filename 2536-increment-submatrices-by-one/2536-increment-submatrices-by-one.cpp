class Solution {
public:
    void query(vector<vector<int>>& ar,int r1,int c1,int r2,int c2,int n){

        ar[r1][c1]+=1;
        if(c2+1<n) ar[r1][c2+1]-=1;
        if(r2+1<n) ar[r2+1][c1]-=1;
        if(r2+1<n && c2+1<n) ar[r2+1][c2+1]+=1;
    }
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
       vector<vector<int>> res(n,vector<int>(n,0));
       for(auto& i:queries){
          query(res,i[0],i[1],i[2],i[3],n);
       } 
      for(int i=0;i<n;i++){
        for(int j=1;j<n;j++)
         res[i][j]=res[i][j]+res[i][j-1];
      }
       for(int i=1;i<n;i++){
        for(int j=0;j<n;j++)
         res[i][j]=res[i][j]+res[i-1][j];
      }
      return res;
    }
};