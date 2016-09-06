/*
 * quick sort
 */
#include <iostream>
using namespace std;

class QuickSort{
    public:
        void quickSort(int arr[], int left, int right) {
            int i = left;
            int j = right;
            int temp = arr[i];
            if(left >= right) {
                return;
            }
            while(i < j) {
                while(i < j && arr[j] >= temp) {
                    j--;
                }
                if(i < j) {
                    arr[i] = arr[j];
                }
                while(i < j && arr[i] <= temp) {
                    i++;
                }
                if(i < j) {
                    arr[j] = arr[i];
                }
            }
            arr[i] = temp;

            if(left < i - 1) {
                quickSort(arr, left, i - 1);
            }
            if(right > i + 1) {
                quickSort(arr, i + 1, right);
            }
        }
};

int main(void) {
    int arr[]  =  {3,1,2,34,7,36,5,8,9,0,9};
    int len = sizeof(arr) / sizeof(arr[0]);
    QuickSort qs;
    qs.quickSort(arr, 0, len - 1);
    for(int i = 0; i < len; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
