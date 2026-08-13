class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
    int i=0 , j=0 ;
    long long sum=0 ;
    double maxi =-1e18;
    while(j<nums.size())
    {
     if(j-i+1<k){
     sum +=nums[j];
     j++;
     }
     else if(j-i+1==k)
     {
     sum +=nums[j];
     maxi = max(maxi,(double)sum);
     sum -=nums[i];
     i++;
     j++;
     }
    }
    double avg = (maxi)/k;
    return avg;
    }
};