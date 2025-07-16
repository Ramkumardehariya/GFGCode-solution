class Solution {
  public:
    int countNumbers(int n) {
        // Code Here
        int limit = sqrt(n)+1;
        vector<int> s(limit+1, 1);
        vector<int> primes;
        
        for(int i = 2; i<=limit; i++){
            if(s[i]){
                primes.push_back(i);
                for(int j = i*2; j<=limit; j+=i){
                    s[j] = 0;
                }
            }
        }
        
        int count =0;
        
        for(int i = 0; i<primes.size(); i++){
            if(pow(primes[i], 8) <= n){
                count++;
            }
            for(int j = i+1; j<primes.size(); j++){
                if(pow(primes[i],2) * pow(primes[j],2) <= n){
                    count++;
                }
            }
        }
        return count;
        
    }
};