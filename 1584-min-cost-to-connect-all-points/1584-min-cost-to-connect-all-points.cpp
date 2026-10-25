class Solution {
public:
int find(int i,vector<int>& node){
    if(node[i]==i) return i;
    return node[i]=find(node[i],node);
}
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<int> node(n);
        for(int i=0;i<n;i++)
        node[i]=i;
        priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>> edges;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int dis=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
              edges.push({dis,i,j});
            }
        }
        int k=0;
        int cost=0;
        while(k<n-1){
          auto[d,i,j]=edges.top();
          edges.pop();
          int a=find(i,node);
          int b=find(j,node);
          if(a!=b){
           cost+=d;
           k++;
           node[b]=a;
          }
        }

   return cost;
    }
};