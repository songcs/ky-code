//求以孩子兄弟表示法存储的森林的叶子结点数
//以孩子兄弟表示法存储时，若结点没有左子树，则为叶结点
typedef struct node{
    ElemType data;  //数据域
    struct node *fch,*nsilb;
}*Tree;
int Leaves(Tree t){
    if(t==NULL)
        return 0;
    if(t->fch==NULL)
        return 1+Leaves(t->nsilb);
    else
        return Leaves(t->fch)+Leaves(t->nsilb);
}