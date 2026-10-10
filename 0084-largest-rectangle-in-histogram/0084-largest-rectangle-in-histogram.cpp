class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> s;
        int area=0;
        for(int i=0;i<=n;i++){
            int h=(i==n)?0:heights[i];
            while(!s.empty() && h<heights[s.top()]){
                int limit=s.top();
                s.pop();
                int width=0;
                if(s.empty())
                width=i;
                else width=i-s.top()-1;
                area=max(area,width*heights[limit]);
            }
            s.push(i);
        }
        return area;
        
    }
};