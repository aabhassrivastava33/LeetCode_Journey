class Solution {
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        int n = temperatures.size();
        std::vector<int> answer(n, 0);
        std::stack<int> st; // Stores indices of temperatures

        for (int i = 0; i < n; ++i) {
            // While the current day is warmer than the day at the top of the stack
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDay = st.top();
                st.pop();
                answer[prevDay] = i - prevDay;
            }
            st.push(i);
        }

        return answer;
    }
};