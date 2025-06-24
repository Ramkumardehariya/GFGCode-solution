class Solution {
  public:
    string minSum(vector<int> &arr) {
        // code here
        string res="";
        int s=0,r=0;
        priority_queue<int>pq(arr.begin(),arr.end());
        while(!pq.empty()){
            
            int d1=pq.top(),d2=0;
            pq.pop();
            
            if(!pq.empty()){
                d2=pq.top();
                pq.pop();
            }
            
            s= (d1+d2+r)%10;
            r=(d1+d2+r)/10;
            res+='0'+s;
           
        }
        
        if(r){
            res+='0'+r;
        }
        
        reverse(res.begin(),res.end());
        
        int pos = res.find_first_not_of("0");
        // gets index of first character which is not "0"
        
        res.erase(0,pos);
        //erases pos number of characters from from index 0
        //e.g. 00043, pos = 3 (index), this is same as number of zeroes too.
        
        return res;
    }
};