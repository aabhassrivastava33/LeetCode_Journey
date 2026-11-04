class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st; // Using vector directly as a stack to avoid transferring elements later

        for (int ast : asteroids) {
            bool alive = true;

            // A collision occurs only when a right-moving asteroid (top > 0)
            // meets a left-moving asteroid (ast < 0)
            while (!st.empty() && ast < 0 && st.back() > 0) {
                if (st.back() < -ast) {
                    // Previous asteroid is smaller: it explodes, current keeps going
                    st.pop_back();
                } else if (st.back() == -ast) {
                    // Both are identical size: both explode
                    st.pop_back();
                    alive = false;
                    break;
                } else {
                    // Current asteroid is smaller: it explodes
                    alive = false;
                    break;
                }
            }

            if (alive) {
                st.push_back(ast);
            }
        }

        return st;
    }
};