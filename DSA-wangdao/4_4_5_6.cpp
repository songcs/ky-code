//已知一棵树的层次序列以及每个结点的度，构造此树的孩子-兄弟链表
//pointer[]，存储新建树的各结点的地址
typedef struct CSNode{
    ElemType data;
    struct CSNode *firstchild,*nextsibling;
}CSNode,*CSTree;
#define maxNodes 15
void createCSTree_Degree(CSTree &t,DataType e[],int degree[],int n){
    //根据树的层次遍历序列e[]和各个结点的度degree[]构造，n是结点个数
    CSNode *pointer=new CSNode[maxNodes];
    int i,j,d,k=0;
    for (i = 0; i < n; ++i) {
        pointer[i]=new CSNode;
        pointer[i].data=e[i];
        pointer[i].firstchild=pointer[i].nextsibling=NULL;
    }
    for (i = 0; i < n; ++i) {
        d=degree[i];
        if(d){
            k++;    //k为子女结点序号
            pointer[i].firstchild=pointer[k];//建立i与子女k的链接
            for (j = 2; j <= d; ++j)
                pointer[k-1].nextsibling=pointer[k];
        }
    }
    T=pointer[0];
    delete [] pointer;
}