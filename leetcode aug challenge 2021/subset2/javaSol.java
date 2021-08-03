class Solution {
    public List<List<Integer>> subsetsWithDup(int[] nums) {
          Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList();
           Set<List<Integer>> seen = new HashSet();
  
        int n = nums.length;
        
        for(int counter =0; counter< (1<<n) ; counter++){
            List<Integer>temp = new ArrayList<Integer>();
            for( int j =0; j<n; j++){
                if((counter&(1<<j))!=0)
                    temp.add(nums[j]);
               
            }
              
            if(!seen.contains(temp)){
               ans.add(temp); 
                seen.add(temp);
        }
    }
        
       return ans; 
    }
}
