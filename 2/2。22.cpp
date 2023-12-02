// 带头结点的单链表的逆置
Status ListOppose_L(LinkList &L)
{
    LinkList p,q;
    p=L;
    p=p->next;
    L->next=NULL;
    while(p){
        q=p;
        p=p->next;
        q->next=L->next;
        L->next=q;
    }
    return OK;
}