class Solution {
public:
    bool ispossible(vector<int>&piles , int mid , int h)
    {
        int hour = 0;
        for(int i=0;i<piles.size();i++)
        {
            if(piles[i]<=mid)
            {
                hour++;
            }
            else if(piles[i]%mid==0)//current box contains multiple of mid 
            {
                hour +=(piles[i]/mid); 
            }
            else if(piles[i]%mid != 0)//current box does not contain multiple of mid 
            {
                hour +=(piles[i]/mid)+1;
            }
            if(hour>h)
            return false;
        }
        return true;
    }


    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = INT_MIN;
        for (int i=0;i<piles.size();i++)
        {
            if(piles[i]>maxi)
            {
                maxi=piles[i];
            }
        }
    int n=piles.size();
    int s = 1;
    int e = maxi;
    int ans;
    while(s<=e)
    {
      //Assume atmost mid speed of koko
      int mid = (s+e)/2;
      if(ispossible(piles,mid,h))
      {
        ans = mid;
        e = mid-1;  
      }
      else
      {
        s = mid+1;
      }

    }
    return ans;
    }
};