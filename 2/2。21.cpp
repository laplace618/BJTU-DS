// 顺序表的逆置
Status ListOppose_Sq(SqList &L)
{
    int i;
    ElemType x;
    for(i=0;i<L.length/2;i++){
        x=L.elem[i];
        L.elem[i]=L.elem[L.length-1-i];
        L.elem[L.length-1-i]=x;
    }
    return OK;
}