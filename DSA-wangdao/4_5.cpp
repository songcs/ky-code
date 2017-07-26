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
//二叉排序树的插入
int BST_Insert(BiTree &T,KeyType k){
    if(T==NULL){
        T=(BiTree)malloc(sizeof(BSTNode));
        T->data=k;
        T->lchild=T->rchild=NULL;
        return 1;
    }
    else if(k==T->data)
        return 0;
    else if(k<T->data)
        return  BST_Insert(T->lchild,k);
    else
        return  BST_Insert(T->rchild,k);
}
//二叉树的构造
void Creat_BST(BiTree &T,KeyType str[],int n){
    T=NULL;
    int i=0;
    while(i<n){
        BST_Insert(T,str[i]);
        i++;
    }
}