class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
      vector<vector<pair<int,int>>> nodes(n+1);
      for(auto& i:times){
        int u=i[0];
        int v=i[1];
        int d=i[2];
        nodes[u].push_back({v,d});
      }  
      vector<int> dis(n+1,INT_MAX);
      dis[k]=0;
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
      q.push({0,k});
      while(!q.empty()){
        auto[cost,start]=q.top();
        q.pop();
        for(int i=0;i<nodes[start].size();i++){
            if(cost+nodes[start][i].second<dis[nodes[start][i].first]){
                dis[nodes[start][i].first]=cost+nodes[start][i].second;
                q.push({cost+nodes[start][i].second,nodes[start][i].first});
            }
        }
      }
      int time=0;
      for(int i=1;i<n+1;i++){
        if(dis[i]==INT_MAX) return -1;
        time=max(time,dis[i]);
      }
      return time;


    }
};