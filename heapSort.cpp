/*
 * 堆排序
 */
class HeadSort {
    public:
        //堆调整
        void heapAdjust(int arr[], int i, int len) {
            int left = 2 * i + 1;         //i的左孩子节点下标
            int right = 2 * i + 2;        //i的右孩子节点下标 
            int max = i;                  //记录最大值的下标
            //如果i是叶节点就不用进行调整 
            if(i <= len / 2 - 1) {
                if(left < len && arr[left] > arr[max]) {
                    max = left;
                }
                if(right < len && arr[right] > arr[max]) {
                    max = right;
                }
                if(max != i) {
                    swap(arr[i], arr[max]);
                    //避免调整之后以max为父节点的子树不是堆 
                    heapAdjust(arr, max, len);  
                }
            }
        }

        //堆排序 
        void heapSort(int arr[], int len) {
            //非叶节点最大序号值为len / 2 -1 
            for(int i = len / 2 - 1; i >= 0; i--) {
                heapAdjust(arr, i, len);    
            }

            for(int i = len - 1; i > 0; i--) {
                //交换堆顶和最后一个元素，即每次将剩余元素中的最大者放到最后面 
                swap(arr[0], arr[i]);
                //重新调整堆顶节点成为大顶堆
                heapAdjust(arr, 0, i);      
            }
        }
};
