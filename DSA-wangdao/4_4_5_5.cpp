//求以孩子兄弟表示法存储的树的高度
int Height(CSTree bt){
    int hc,hs;
    if(bt==NULL)
        return 0;
    else{
        hc=Height(bt->firstchild);
        hs=Height(bt->nextsibling);
        if(hc+1>hs)
            return hc+1;
        else
            return hs;
    }
}