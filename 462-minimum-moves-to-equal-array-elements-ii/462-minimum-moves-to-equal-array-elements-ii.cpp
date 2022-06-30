class Solution
{

public:
int minMoves2 (vector < int >&nums)
  {
    
sort (nums.begin (), nums.end ());
    

int n = nums.size ();
     
int a = -1;
     
int b = -1;
     
int mx = 0;
     
if (n % 2 == 0)
      {
	
a = n / 2 - 1;
	
b = n / 2;
	
int sum1 = 0;
	 

for (int i = 0; i < n; i++)
	  {
	    
sum1 += abs (nums[i] - nums[a]);
	  
} 

int sum2 = 0;
	
for (int i = 0; i < n; i++)
	  {
	    
sum2 += abs (nums[i] - nums[b]);
	  
} 
 
 
mx = max (mx, min (sum1, sum2));
      
}
    
    else
      {
	
a = (n + 1) / 2 - 1;
	
int sum1 = 0;
	
 
for (int i = 0; i < n; i++)
	  {
	    
sum1 += abs (nums[i] - nums[a]);
	  
} 
 
 

	
mx = max (mx, sum1);
      
} 
 
 
 
return mx;
  
 
}

};
