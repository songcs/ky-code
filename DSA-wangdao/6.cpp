/*一般线性表的顺序查找*/
typedef struct {
    ElemType *elem;//元素存储空间基址，建表时按实际长度分配，0号单元留空
    int TableLen;//表的长度
} SSTable;

int Search_Seq(SSTable ST, ElemType key) {
    ST.elem[0] = key;//哨兵
    for (i = ST.TableLen; ST.elem[i] != key; i--);
    return i;//若表中不存在关键字为key的元素，查找到i=0时，退出for循环
}

/*折半查找*/
int Binary_Search(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (L.elem[mid] == key) return mid;
        else if (L.elem[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

/*折半查找的递归算法*/
int Bin_Search_Rec(SSTable st, ElemType key, int low, int high) {
    if (low > high) return 0;
    mid = (low + high) / 2;
    if (key > st.elem[mid])
        Bin_Search_Rec(st, key, mid + 1, high);
    else if (key < st.elem[mid])
        Bin_Search_Rec(st, key, low, mid - 1);
    else
        return mid;
}

/*若找到指定的结点，将该结点和其前驱结点（若存在）交换*/
int SeqSrch(SSTable st, ElemType k) {
    int i = 0, n = st.TableLen;
    while ((st.elem[i] != key) && (i < n))
        i++;
    if (i < n && i > 0) {
        ElemType temp = st.elem[i];
        st.elem[i] = st.elem[i - 1];
        st.elem[i - 1] = temp;
        return i - 1;
    } else
        return -1;
}