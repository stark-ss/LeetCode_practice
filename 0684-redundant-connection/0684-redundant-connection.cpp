class Solution {
public:
int find(int node,vector<int>& parent){
    if(parent[node]==node) return node;
    return parent[node]=find(parent[node],parent);
}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> parent(n+1);
        for(int i=1;i<=n;i++)
         parent[i]=i;
        for(auto& i:edges){
             int u=find(i[0],parent);
             int v=find(i[1],parent);
             if(u==v) return i;
             parent[v]=u;
        } 
        return {};
     }
};