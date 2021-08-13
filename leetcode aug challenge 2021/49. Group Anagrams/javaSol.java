class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String ,List<String>> map = new HashMap<>();
        for(int i=0;i<strs.length;i++)
        {
            char[] c = strs[i].toCharArray();
            Arrays.sort(c) ;
            String temp = String.valueOf(c);
            if(map.containsKey(temp))
            {
                List<String> list = map.get(temp);
                list.add(strs[i]);
                map.put(temp,list);
            }
            else
            { 
                List<String> list = new ArrayList<>();
                list.add(strs[i]);
                map.put(temp, list);
            }            
        }
        List<List<String>> ans = new ArrayList<>();
        ans.addAll(map.values());
        return ans;
    }
}