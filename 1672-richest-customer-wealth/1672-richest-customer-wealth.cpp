class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int maxWealth = 0;
        
        for (const auto& customer : accounts) {
            int currentWealth = std::accumulate(customer.begin(), customer.end(), 0);
            maxWealth = std::max(maxWealth, currentWealth);
        }
        
        return maxWealth;
    }
};