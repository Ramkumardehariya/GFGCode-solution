class Solution {
  public:
  
    int getPowerInFactorial(int n, int p){
        int count = 0;
        while(n > 0){
            n /= p;
            count += n;
        }
        return count;
    }
    int maxKPower(int n, int k) {
        // code here
        map<int,int> primeFactors;
        
        for(int i = 2; i*i <= k; ++i){
            
            while(k%i == 0){
                primeFactors[i]++;
                k /= i;
            }
        }
        
        if(k > 1){
            primeFactors[k]++;
        }
        int minX = INT_MAX;
        
        for(auto mp : primeFactors){
            
            int powerInFactorial = getPowerInFactorial(n, mp.first);
            int x = powerInFactorial / mp.second;
            
            minX = min(minX, x);
        }
        
        return minX;
    }
};