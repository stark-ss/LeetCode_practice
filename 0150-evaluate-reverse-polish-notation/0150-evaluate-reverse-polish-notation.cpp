class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;
    
        for(auto& i:tokens){
            if(i=="+" || i=="-" ||i=="*" ||i=="/"){
                int b =q.top();
                q.pop();
                int a=q.top();
                q.pop();
                if(i=="+") q.push(a+b);
                else if(i=="-") q.push(a-b);
                else if(i=="*") q.push(a*b);
                else q.push(a/b);
            }
            else q.push(stoi(i));
        }

        return q.top();
    }
};