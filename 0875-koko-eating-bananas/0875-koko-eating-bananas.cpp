class Solution {
public:
    bool ispossible(vector<int>& piles, int mid ,int h)
    {
        long long hour = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<mid)
            hour++;
            else if (piles[i]%mid==0)
            {
                hour +=(piles[i]/mid);
            }
            else if(piles[i]%mid!=0)
            {
                hour +=(piles[i]/mid)+1;
            }
            if(hour>h)
            {
                return false;
            }
        
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
    int maxi=INT_MIN;
    for(int i=0;i<piles.size();i++)
    {
        if(piles[i]>maxi)
        {
            maxi=piles[i];
        }
    }
    int start = 1;
    int end = maxi;
    int ans = 1;
    while(start<=end)
    {
        int mid = start + (end - start) / 2;
        if(ispossible(piles,mid,h))
        {
            ans=mid;
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return ans;
    }
};