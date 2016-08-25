/*
 * merge sort
 */
class MergeSort{
    public:
        int min(int x, int y) {
            return x < y ? x : y;
        }

        void mergeSort(int arr[], int len) {
            int* a = arr;
            int* b = new int[len]; 

            //外层循环是决定内层循环每次合并元素的个数,直到<len
            //依次为:1->2->4->8->16->---
            for (int step = 1; step < len; step += step) {
                //内层循环是完成一次合并
                //下一次循环的开始是上一次的结尾,所以start=start+step+step
                for (int start = 0; start < len; start += step + step) {
                    //取最小值:设10个元素,一次循环为0-2-4,4-6-8,8-10-10
                    int low = start, mid = min(start + step, len), high = min(start + step + step, len);
                    int k = low;
                    int start1 = low, end1 = mid;
                    int start2 = mid, end2 = high;
                    while (start1 < end1 && start2 < end2)
                        b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
                    while (start1 < end1)
                        b[k++] = a[start1++];
                    while (start2 < end2)
                        b[k++] = a[start2++];
                }
                //a是本次合并的结果,b本来没用但是需要保存arr的地址,所以只能交换
                swap(a, b);
            }
            //跳出外层循环后a就是排好序的,但是我们必须把结果放到arr中
            //因为上边a和b不断交换,到底谁指向arr需要判断
            //如果a!=arr那么需要把a的值赋值给arr(即b),然后把a赋给b,释放b
            if (a != arr) {
                for (int i = 0; i < len; i++) {
                    b[i] = a[i]; //=>arr[i] = a[i]
                }
                b = a;
            }
            delete[] b;
        }
};

