// User function Template for Java

class Solution {
    public int rowWithMax1s(int arr[][]) {
        // code here
    // This problem can be solved using many ways.
    //brute force (n*m)
    //binary search(n*logm)
    //top right traversal(n+m)
    int j =arr[0].length-1;
    int ans=-1;
    
    for(int i=0;i<arr.length;i++)
    {
        while(j>=0&&arr[i][j]==1)
        {
            ans=i;
            //here we are decrementing the j as we need to have atleast one more 1 
            //in the next row.
            j--;
        }
    }
    
    return ans;
    
    }
}