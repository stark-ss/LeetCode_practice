class Solution {
public:
static bool compare(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();
        sort(courses.begin(),courses.end(),compare);
        priority_queue<int> q;
        int tot=0;
        for(auto& i:courses){
          int time=i[0];
          int end=i[1];
          tot+=time;
          q.push(time);
          if(tot>end){
            tot-=q.top();
            q.pop();
          }

        }
        return q.size();
    }
};