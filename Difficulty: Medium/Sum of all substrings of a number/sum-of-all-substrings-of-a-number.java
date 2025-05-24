class Solution {
    
    
    public static int sumSubstrings(String s) {
        int ans = 0;
        
        for(int i = 0; i<s.length(); i++){
            for(int j = i+1; j<s.length()+1; j++){
                ans += Integer.parseInt(s.substring(i,j));
            }
        }
        return ans;
    }
}