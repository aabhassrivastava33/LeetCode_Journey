class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int i = 0;
    int j = 0;
    long long  sum = 0 ;
    long long maxi= INT_MIN;
    double average;
    while (j<nums.size())
    {
        if(j-i+1<k)
        {
            sum += nums[j];
            j++;
        }
        else if(j-i+1==k)
        {
            sum += nums[j];
            maxi = max (maxi , sum);
            sum -= nums[i];
            i++;
            j++;
        }
    }
    average = (double)maxi/k;
    return average;
    }
};