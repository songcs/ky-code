/*直接插入排序*/
void InsertSort(ElemType A[], int n) {
    int i, j;
    for (i = 2; i <= n; i++)//依次将A[2]~A[n]插入到前面已排序序列
        if (A[i].key < A[i - 1].key) {//若A[i]的关键码小于前驱，需将A[i]插入有序表
            A[0] = A[i];//复制为哨兵，A[0]不存放元素
            for (j = i - 1; A[0].key < A[j].key; --j)//从后往前查找待插入位置
                A[j + 1] = A[j];//向后挪位
            A[j + 1] = A[0];//复制到插入位置
        }
}

/*折半插入排序*/
void InsertSort(ElemType A[], int n) {
    int i, j, low, high, mid;
    for (i = 2; i <= n; i++) {//依次将A[2]~A[n]插入到前面已排序序列
        A[0] = A[i];
        low = 1;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (A[mid].key > A[0].key) high = mid - 1;
            else low = mid + 1;
        }
        for (j = i - 1; j >= high + 1; j--)
            A[j + 1] = A[j];
        A[high + 1] = A[0];
    }
}

/*希尔排序*/
void ShellSort(ElemType A[], int n) {
    //A[0]只是暂存元素，不是哨兵，当j<0时，插入位置已到
    //前后记录位置的增量时dk
    for (dk = n / 2; dk >= 1; dk = dk / 2)
        for (i = dk + 1; i <= n; i++)
            if (A[i].key < A[i - dk].key) {
                A[0] = A[i];
                for (j = i - dk; j > 0 && A[0].key < A[j].key; j -= dk)
                    A[j + dk] = A[j];
                A[j + dk] = A[0];
            }
}

/*冒泡排序*/
void BubbleSort(ElemType a, int n) {
    //从小到大排序
    for (i = 0; i < n - 1; i++) {
        flag = false;//表示本堂冒泡是否发生交换的标志
        for (j = n - 1; j > i; j--)
            if (a[j - 1] > a[j]) {
                swap(a[j - 1], a[j]);
                flag = true;
            }
        if (flag == false)
            return;//本趟遍历没有发生交换，说明表已有序
    }
}

/*快速排序*/
void QuickSort(ElemType a[], int low, int high) {
    if (low < high) {
        //Partition就是划分操作，将表a划分为满足上述条件的两个子表
        int pivotpos = Partition(a, low, high);
        QuickSort(a, low, pivotpos - 1);
        QuickSort(a, pivotpos + 1, high);
    }
}

int Partition(ElemType a[], int low, int high) {
    ElemType pivot = a[low];//将当前表中第一个元素设为枢轴值，对表进行划分
    while (low < high) {
        while (low < high && a[high] >= pivot) --high;
        a[low] = a[high];//将比枢轴值小的元素移动到左端
        while (low < high && a[low] <= pivot) ++low;
        a[high] = a[low];//将比枢轴值大的元素移动到右端
    }
    a[low] = pivot;//枢轴值元素存放到最终位置
    return low;//返回存放枢轴的最终位置
}

/*双向冒泡*/
void DoubleBubbleSort(ElemType a[], int n) {
    int low = 0, high = n - 1;
    bool flag = true;
    while (low < high && flag) {
        flag = false;
        for (i = low; i < high; i++)
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                flag = true;
            }
        high--;
        for (i = high; i > low; i--)
            if (a[i] < a[i - 1]) {
                swap(a[i], a[i - 1]);
                flag = true;
            }
        low++;
    }
}

/*把所有奇数移动到所有偶数前面去*/
/*利用快排思想，先从前往后找到一个偶数元素，再从后向前找到一个奇数，交换*/
void move(ElemType a[], int len) {
    int i = 0, j = len - 1;
    while (i < j) {
        while (i < j && a[i] % 2 != 0) i++;//从前向后找到偶
        while (i < j && a[j] % 2 != 1) j--;//从后向前找到奇
        if (i < j)
            swap(a[i], a[j]);
        i++;
        j--;
    }
}

/*编写算法，使之能够再数组中找到第k小元素，即从小到大排序后处于第k个位置的元素*/
/*先排序，再直接提取第k个元素，平均复杂度O(nlogn)；用小顶堆，复杂度O(n+klogn)*/
/*这里采用快排划分来做*/
/*从数组l[1...n]中选择枢轴pivot，进行和快排一样的划分操作后，表l[1..n]被划分为l[1...m-1]和l[m+1...n]，其中l[m]=pivot
 * 讨论m和k的大小关系
 * 1)m=k时，显然pivot就是要找的元素
 * 2)m<k时，则要寻找的元素一定落在l[m+1...n]中，从而可以对l[m+1...n]递归查找第m-k小的元素
 * 3)m>k时，则要寻找的元素一定落在l[1...m-1]中，从而可以对l[1...m-1]递归查找第m-k小的元素
 *该算法平均复杂度O(n)*/
int kth_elem(int a[], int low, int high, int k) {
    int pivot = a[low];
    int low_temp = low;
    int high_temp = high;
    while (low < high) {
        while (low < high && a[high] >= pivot) --high;
        a[low] = a[high];
        while (low < high && a[low] <= pivot)++low;
        a[high] = a[low];
    }
    a[low] = pivot;
    //上面即为快排中的划分算法
    if (low == k)
        return a[low];
    else if (low > k)//在前一部分表中递归查找
        return kth_elem(a, low_temp, low - 1, k);
    else//在后一部分表中查找
        return kth_elem(a, low + 1, high_temp, m - k);
}

/*将红白蓝三色乱序的条块，在O(n)时间复杂度下排序成红白蓝顺序*/
/*三个指针,j为工作指针表示当前扫描的元素，i以前的元素全部为红色，k以后的元素全部为蓝色。*/
typedef enum {
    RED, WHITE, BLUE
} color;

void Color_Arrange(color a[], int n) {
    int i = 0, j = 0, k = n - 1;
    while (j <= k)
        switch (a[j]) {
            case RED://红色，则和i交换
                swap(a[i], a[j]);
                i++;
                j++;
                break;
            case WHITE:
                j++;
                break;
            case BLUE:
                swap(a[j], a[k]);
                k--;
                //蓝色，和k交换
                //这里没有j++语句以防止a[j]仍为蓝色的情况
        }
}

/*简单选择排序*/
void SelectSort(ElemType a[], int n) {
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        if (min != i)swap(a[i], a[min]);
    }
}

/*建立大根堆的算法*/
void BuildMaxHeap(ElemType a[], int len) {
    for (int i = len / 2; i > 0; i--)//从⌊n/2⌋~1，反复调整堆
        AdjustDown(a, i, len);
}

void AdjustDown(ElemType a[], int k, int len) {
    //函数将元素k向下调整
    a[0] = a[k];//a[0]暂存
    for (i = 2 * k; i <= len; i *= 2) {
        if (i < len && a[i] < a[i + 1])
            i++;//取k较大的子结点的下标
        if (a[0] >= a[i]) break;
        else {
            a[k] = a[i];//将较大子树根调整到k的位置
            k = i;//k下降到，原来k的位置变成了较大子树根，原来较大子树根位置还是原来元素
        }//
    }
    a[k] = a[0];
}

/*堆排序算法*/
void HeapSort(ElemType a[], int len) {
    BuildMaxHeap(a, len);
    for (i = len; i > 1; i--) {//n-1趟的交换和建堆过程
        swap(a[i], a[1]);//输出堆顶元素，并和堆底元素交换
        AdjustDown(a, 1, i - 1);//整理，把剩余的i-1个元素整理成堆
    }
}

/*堆向上调整操作*/
void AdjustUp(ElemType a[], int k) {
    //参数k为向上调整的结点，也为堆的元素个数
    a[0] = a[k];
    int i = k / 2;//若结点大于双亲结点，则将双亲向下调整，并继续向上比较
    while (i > 0 && a[i] < a[0]) {
        a[k] = a[i];
        k = i;
        i = k / 2;
    }
    a[k] = a[0];
}

/*在基于单链表表示的待排序关键字序列上进行简单选择排序*/
void selectSort(LinkedList &l) {
    //对不带头节点的单链表l进行简单选择排序
    LinkNode *h = l, *p, *q, *r, *s;
    l = NULL;
    while (h != NULL) {
        p = s = h;
        q = r = NULL;
        //指针s和r记忆最大结点和其前驱；p为工作指针,q为其前驱
        while (p != NULL) {//扫描原链表寻找最大结点s
            if (p->data > s->data) {//找到更大的，记忆它和它的前驱
                s = p;
                r = q;
            }
            q = p;
            p = p->link;//继续寻找
        }
        if (s == h)//最大结点在原链表前端
            h = h->link;
        else//最大结点在原链表表内
            r->rlink = s->link;
        s->link = l;//结点s插入到结果链前端
        l = s;
    }
}

/*判断一个数据序列是否构成一个小顶堆*/
bool IsMinHeap(ElemType a[], int len) {
    if (len % 2 == 0) {//len为偶数，有一个单分支结点
        if (a[len / 2] > a[len])//判断单分支结点
            return false;
        for (i = len / 2 - 1; i >= 1; i--)//判断所有双分支结点
            if (a[i] > a[i * 2] || a[i] > a[2 * i + 1])
                return false;
    } else {//len为奇数，没有单分支结点
        for (i = len / 2; i >= 1; i--)
            if (a[i] > a[i * 2] || a[i] > a[2 * i + 1])
                return false;
    }
    return true;
}