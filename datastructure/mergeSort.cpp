/*
 * merge sort
 */
class MergeSort{
    public:
        int min(int x, int y) {
            return x < y ? x : y;
        }

        void mergeSort(int arr[], int len) {
            int* back = arr;
            int* tmp = new int[len]; 

            //外层循环是决定内层循环每次合并元素的个数,直到<len
            //依次为:1->2->4->8->16->---
            for (int step = 1; step < len; step += step) {
                //内层循环是完成一次合并
                //下一次循环的开始是上一次的结尾,所以start=start+step+step
                for (int start = 0; start < len; start += step + step) {
                    //取最小值:设10个元素,一次循环为0-2-4,4-6-8,8-10-10
                    int low = start, mid = min(low + step, len), high = min(mid + step, len);
                    int k = low;
                    int start1 = low, end1 = mid;
                    int start2 = mid, end2 = high;
                    while (start1 < end1 && start2 < end2)
                        tmp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
                    while (start1 < end1)
                        tmp[k++] = arr[start1++];
                    while (start2 < end2)
                        tmp[k++] = arr[start2++];
                }
                swap(tmp, arr);
            }
            //跳出外层循环后arr就是排好序的,但是我们必须把结果放到arr(back)中
            //因为上边tmp和arr不断交换,到底谁指向arr需要判断
            //如果back!=arr那么需要把arr的值赋值给back,然后把arr赋给tmp
            if (back != arr) {  //arr == tmp;
                for (int i = 0; i < len; i++) {
                    back[i] = arr[i];
                }
                tmp = arr;
            }
            delete[] tmp;
        }
};

