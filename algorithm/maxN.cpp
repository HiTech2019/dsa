/*
 * 求一个数组中最大的n个数
 * 利用堆排序
 */
class MaxN {
    public:
        //调整堆
        void adjust(int* arr, int elem, int len) {
            int left = elem*2 + 1;
            int right = elem*2 + 2;
            int max = elem;
            if(left < len && arr[left] > arr[max]) {
                max = left;
            }
            if(right < len && arr[right] > arr[max]) {
                max = right;
            }
            if(max != elem) {
                swap(arr[max], arr[elem]);
                adjust(arr, max, len);
            }
        }

        //返回最大的n个数
        int* maxN(int* arr, int len, int* dst, int num) {
            int n = 0;
            for(int i = len / 2 - 1; i >= 0; i--) {
                adjust(arr, i, len);
            }
            for(int i = len -1; i > 0; i--) {
                swap(arr[0], arr[i]);
                if(n < num) {
                    dst[n++] = arr[i];
                }
                adjust(arr, 0, i);
            }
        }
};
