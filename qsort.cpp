/*
 * quick sort
 */
class QuickSort{
    public:
    void quickSort(int arr[], int left, int right) {
        int i = left, j = right;
        int pivot = arr[(left + right) / 2];

        /* partition */
        while(i < j) {
            while(arr[i] < pivot) {
                i++;
            }
            while(arr[j] > pivot) {
                j--;
            }
            if(i < j) {
                swap(arr[i], arr[j]);
                i++;
                j--;
            }
        }

        /* recursion */
        if(left < j - 1) {
            quickSort(arr, left, j);
        }
        if(right > i + 1) {
            quickSort(arr, i, right);
        }
    }
};

