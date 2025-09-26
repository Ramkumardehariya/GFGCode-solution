class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        if(type == 1){
            while(k != 0){
                int num = dq.back();
                dq.pop_back();
                dq.push_front(num);
                k--;
            }
        }
        else{
            while(k != 0){
                int num = dq.front();
                dq.pop_front();
                dq.push_back(num);
                k--;
            }
        }
    }
};