class Solution {
  public:
  
    void merge(vector<int> &arr, int s, int e, int mid){
        int size1 = mid-s+1;
        int size2 = e-mid;
        
        int *first = new int[size1];
        int *second = new int[size2];
        int index = 0;
        
        for(int i = s; i<=mid; i++){
            first[index] = arr[i];
            index++;
        }
        
        index = 0;
        for(int i = mid+1; i<=e; i++){
            second[index] = arr[i];
            index++;
        }
        
        int mainIndex = s;
        int i = 0;
        int j = 0;
        
        while(i < size1 && j < size2){
            if(first[i] < second[j]){
                arr[mainIndex] = first[i];
                i++;
            }
            else{
                arr[mainIndex] = second[j];
                j++;
            }
            mainIndex++;
        }
        
        while(i < size1){
            arr[mainIndex++] = first[i++];
        }
        while(j < size2){
            arr[mainIndex++] = second[j++];
        }
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l >= r){
            return;
        }
        int mid = l+(r-l)/2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        
        merge(arr, l, r, mid);
    }
};