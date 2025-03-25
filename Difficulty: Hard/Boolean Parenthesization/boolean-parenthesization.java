//{ Driver Code Starts
import java.io.*;
import java.lang.*;
import java.util.*;
import java.util.stream.*;

class GFG {

    public static void main(String[] args) throws IOException {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            String s = br.readLine();
            Solution obj = new Solution();
            System.out.println(obj.countWays(s));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends


// User function Template for Java


// User function Template for Java


// User function Template for Java
class Solution {
    static int countWays(String s){
        
        int n = s.length();
       String op="", bool="";
       for(int i=0; i<n; i++)
          if(s.charAt(i)=='T' || s.charAt(i)=='F')
             bool+=s.charAt(i);
          else
             op+=s.charAt(i);
       int boolLen=bool.length();
       int[][] dpt=new int[boolLen][boolLen], dpf=new int[boolLen][boolLen];
       for(int g=0; g<boolLen; g++)
          for(int i=0, j=g; j<boolLen; i++, j++)
             if(g==0){
                dpt[i][j]=(bool.charAt(i)=='T') ? 1 : 0;
                dpf[i][j]=(bool.charAt(i)=='T') ? 0 : 1;
             }else
                for(int k=i; k<j; k++){
                   int ltc=dpt[i][k], rtc=dpt[k+1][j], lfc=dpf[i][k], rfc=dpf[k+1][j];
                   if(op.charAt(k)=='&'){
                      dpt[i][j]+=(ltc*rtc);
                      dpf[i][j]+=(ltc*rfc+rfc*lfc+rtc*lfc);
                   }else if(op.charAt(k)=='|'){
                      dpt[i][j]+=(ltc*rtc+ltc*rfc+lfc*rtc);
                      dpf[i][j]+=(lfc*rfc);
                   }else{
                      dpt[i][j]+=(lfc*rtc+ltc*rfc);
                      dpf[i][j]+=(lfc*rfc+rtc*ltc);
                   }
                }
       return dpt[0][boolLen-1];
}
}
 
