//并查集
#define SIZE 100
int UFSets[SIZE];
//并查集的初始化操作（s即为并查集）
void Initial(int S[]){
    for (int i = 0; i < size; ++i) {
        s[i]=-1;
    }
}
//Find操作（函数在并查集S中查找并返回包含元素x的树的节点
int Find(int S[],int x){
    while (S[x]>=0)
        x=S[x];
    return x;
}
//Union操作（函数要求两个不相交的子集）
void Union(int S[],int Root1,int Root2){
    //要求Root1和Root2是不同的，且表示子集的名字
    S[Root2]=Root1;
}