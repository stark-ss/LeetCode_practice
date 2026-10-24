class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> deg(n,0);
        vector<vector<int>> list(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<graph[i].size();j++){
                deg[i]++;
                list[graph[i][j]].push_back(i);
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(deg[i]==0) q.push(i); 
        }
        vector<int> res;
        while(!q.empty()){
            int start=q.front();
            q.pop();
            res.push_back(start);
            for(int i=0;i<list[start].size();i++){
              int node=list[start][i];
              deg[node]--;
              if(deg[node]==0) q.push(node);
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};