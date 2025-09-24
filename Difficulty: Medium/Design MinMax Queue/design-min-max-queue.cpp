class SpecialQueue {

  public:
    int mini;
    int maxi;
    int front;
    int rear;
    int *arr;
    
    SpecialQueue(){
        front = 0;
        rear = 0;
        mini = INT_MAX;
        maxi = INT_MIN;
        arr = new int[1000000];
    }
    void enqueue(int x) {
        arr[rear++] = x;
        maxi = max(maxi, x);
        mini = min(mini, x);
    }

    void dequeue() {
        front++;
        if(mini == arr[front-1]){
            mini = INT_MAX;
            for(int i = front; i<rear; i++){
                mini = min(mini, arr[i]);
            }
        }
        if(maxi == arr[front-1]){
            maxi = INT_MIN;
            for(int i = front; i<rear; i++){
                maxi = max(maxi, arr[i]);
            }
        }
    }

    int getFront() {
        return arr[front];
    }

    int getMin() {
        return mini;
    }

    int getMax() {
        return maxi;
    }
};