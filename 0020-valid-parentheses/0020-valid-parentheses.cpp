class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            // Push opening brackets
            if (c == '(' || c == '{'|| 
 c == '[') {
                st.push(c);
            } 
            else {
                // If stack is empty → invalid
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                // Check matching
                if ((c == ')' && top != '(')|| 
                    (c == '}' && top != '{') ||

                    (c == ']' && top != '[')) {
                    return false;
                }
            }
        }

        // Stack should be empty
        return st.empty();
    }
};
