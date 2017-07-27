/*图的邻接矩阵存储结构定义*/
#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;
typedef struct {
    VertexType Vex[MaxVertexNum];//顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];//邻接矩阵，边表
    int vexnum, arcnum;      //图的当前顶点数和弧数
} MGragh;

/*图的邻接表存储结构定义*/
typedef struct ArcNode {     //边表结点
    int adjvex;             //该弧所指向的顶点的位置
    struct ArcNode *next;   //指向下一个条弧的指针
    //InfoType info;        //网的边权值
} ArcNode;
typedef struct VNode {       //顶点表结点
    VertexType data;        //顶点信息
    ArcNode *first;         //指向第一条依附该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];
typedef struct {
    AdjList vertices;       //邻接表
    int vexnum, arcnum;      //邻接表的顶点数和弧数
} ALGraph;                   //ALGraph是以邻接表存储的图类型

/*图的十字链表存储结构定义(有向图)*/
typedef struct xArcNode {//边表结点
    int tailvex, headvex;//该弧的头尾结点
    struct xArcNode *hlink, *tlink;//分别指向弧头相同，弧尾相同的结点
    //InfoType info;
} xArcNode;
typedef struct xVNode {//顶点表结点
    VertexType data;//顶点信息
    xArcNode *firstin, *firstout;//指向第一条入弧和出弧
} xVNode;
typedef struct {
    xVNode xlist[MaxVertexNum];//邻接表
    int vexnum, arcnum;//图的顶点数和弧数
} GLGraph;

/*图的邻接多重表（无向图）*/
typedef struct mArcNode {//边表结点
    bool mark;//访问标记
    int ivex, jvex;//分别指向该弧的两个结点
    struct mArcNode *ilink, *jlinik;//分别指向两个顶点的下一条边
    //InfoType info;
} mArcNode;
typedef struct mVNode {//顶点表结点
    VertexType data;//顶点信息
    mArcNode *firstedge;//指向第一条依附该顶点的边
} mVNode;
typedef struct {
    mVNode adjmulist[MaxVertexNum];//邻接表
    int vexnum, arcnum;
} AMLGraph;

/*邻接表转化成邻接矩阵*/
void Conver(ALGraph &g,int arcs[M][N]){
    for(int i=0;i<n;i++){
        ArcNode p=g.vertices[i].first;//依次遍历各顶点表结点为头的边链表
        while(p!=NULL){//遍历边链表
            arcs[i][p.adjvex]=1;
            p=p.next;
        }
    }
}

/*广度优先搜索算法*/
bool visited[MaxVertexNum];
void BFSTraverse(Graph G){
    for(int i=0;i<G.vexnum;i++) visited[i]= false;
    InitQueue(Q);
    for(int i=0;i<G.vexnum;i++)//对每个连通分量调用一次BFS
        if(!visited[i])
            BFS(G,i);
}
void BFS(Graph G,int v){
    visit(v);
    visited[v]= true;
    EnQueue(Q,v);
    while(!isEmpty(Q)){
        DeQueue(Q,v);
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
            if(!visited[w]){
                visit(w);
                visited[w]= true;
                EnQueue(Q,w);
            }
    }
}

/*BFS求单源最短路径*/
void BFS_MIN_Distance(Graph G,int u){
    //d[i]表示从u到i结点的最短路径
    for(i=0;i<G.vexnum;i++)
        d[i]=INF;
    visited[u]= true;d[u]=0;
    EnQueue(Q,u);
    while(!isEmpty(Q)){
        DeQueue(Q,u);
        for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))
            if(!visited[w]){
                visited[w]=true;
                d[w]=d[u]+1;
                EnQueue(Q,w);
            }
    }
}

/*DFS深度优先搜索算法*/
void BFSTraverse(Graph G){
    for(v=0;v<G.vexnum;++v) visited[v]=false;
    for(v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}
void DFS(Graph G,int v){
    visit(v);
    visited[v]=true;
    for(w=FirstNeighbor(G,u);w>=0;w=NextNeighbor(G,u,w))
        if(!visited[w])
            DFS(G,w);
}