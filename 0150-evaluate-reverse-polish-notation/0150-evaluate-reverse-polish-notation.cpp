class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string token : tokens) {
            // Check if operator
            if (token =="+"|| token == "-" ||
 token == "*" || token == "/") {
                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token =="+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b);  // division truncates toward zero
            } 
            else {
                // Convert string to integer and push
                st.push(stoi(token));
            }
        }

        return st.top();
    }
};