class Solution {
public:
    string simplifyPath(string path) {
        string temp;
        stack<string> st;
        for (int i=0; i<path.size(); i++){
            if (path[i]=='/') continue;
            while(i<path.size()&&path[i]!='/'){
                temp.push_back(path[i]);
                i++;
            }
            if (temp==".");
            else if(temp==".."){
                if (!st.empty()) st.pop();
            }
            else {
                st.push("/"+temp);
            }
            temp.clear();
        }
        
        if (st.empty()) return "/";
        string str="";
        while(!st.empty()){
            str.insert(0, st.top());
            st.pop();
        }
        return str;
    }
};