class Solution {
    public boolean exist(char[][] b, String word) {
    /*Find word's first letter.  Then call method to check it's surroundings */
    for(int r=0; r<b.length; r++)
        for(int c=0; c<b[0].length; c++)
            if(b[r][c]==word.charAt(0) && dfs(b,word,0,r,c))
                return true;
    
    return false;
}

public boolean dfs(char[][] b, String word, int start, int r, int c){
    /* once we get past word.length, we are done. */
    if(word.length() <= start)
        return true;
    
    /* if off bounds, letter is seen, letter is unequal to word.charAt(start) return false */
    if(r<0 ||c<0 || r>=b.length || c>=b[0].length || b[r][c]=='0' || b[r][c]!=word.charAt(start))
        return false;
    
    /* set this board position to seen. (Because we can use this postion) */
    char tmp = b[r][c];
    b[r][c] = '0';
    
    /* recursion on all 4 sides for next letter, if works: return true */
    if(dfs(b,word,start+1,r+1,c) ||
      dfs(b,word,start+1,r-1,c) ||
      dfs(b,word,start+1,r,c+1) ||
      dfs(b,word,start+1,r,c-1))
        return true;
    
    //Set back to unseen
    b[r][c] = tmp;
    
    return false;
}
}