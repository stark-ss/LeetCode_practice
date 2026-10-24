class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        int m=edges.size();
        vector<vector<pair<int,double>>> cost(n);
        for(int i=0;i<m;i++){
          int u=edges[i][0];
          int v=edges[i][1];
          double p=succProb[i];
          cost[u].push_back({v,p});
          cost[v].push_back({u,p});
        } 
        priority_queue<pair<double,int>> q;
        vector<double> vis(n,0);
        vis[start_node]=1;
        q.push({1,start_node});
        while(!q.empty()){
            auto[prob,start]=q.top();
            q.pop();
            if(prob<vis[start]) continue;
            for(auto& i:cost[start]){
                if(prob*i.second>vis[i.first]){
                    vis[i.first]=prob*i.second;
                    q.push({ vis[i.first],i.first});
                }
            }

        }
        return vis[end_node];
    }
};