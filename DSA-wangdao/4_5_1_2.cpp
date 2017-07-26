//二叉排序树非递归查找算法
typedef struct BiNode{
    ElemType data;
    struct BiTree *lchild,*rchild;
}BSTNode,*BiTree;
BSTNode *BST_Search(BiTree T,ElemType key,BSTNode *&p){
    p=NULL;
    while (T!=NULL && key!=T->data){
        p=T;
        if(key<T->data) T=T->lchild;
        else T=T->rchild;
    }
    return T;
}