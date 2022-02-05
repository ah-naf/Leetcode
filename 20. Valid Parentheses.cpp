class Solution {
public:
    bool isValid(string s) {
        std::stack<char> st;
        for(auto it: s) {
            if(it == '(' || it == '[' || it == '{') {
                st.push(it);
            } else {
                if(!st.size() && (it == ')' || it == ']' || it == '}')) {return false;}
                if(it == ')' && st.top() == '(') {
                    st.pop();
                } else if(it == '}' && st.top() == '{') {
                    st.pop();
                } else if(it == ']' && st.top() == '[') {
                    st.pop();
                } else break;
            }
        }
        return st.size() == 0;
    }
};
