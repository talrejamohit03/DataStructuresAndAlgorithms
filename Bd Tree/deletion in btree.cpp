#include <iostream>
using namespace std;

const int d=2;

typedef
struct bdnode{
    int cnt;
    int keys[2*d+1];
    bdnode *ptr[2*d+2];
} *BDPTR;

typedef
struct lnode{
    BDPTR data;
    lnode *next;
} *LPTR;

struct bst_queue{
    LPTR f;
    LPTR r;
};
typedef bst_queue *QPTR;
int delete_bt(BDPTR &T,BDPTR Tp,BDPTR &Th,int k);
void bst_enq(QPTR &Q,BDPTR T){
    LPTR temp=new(lnode);
    temp->data=T;
    temp->next=NULL;
    if(Q->f==NULL){
        Q->f=temp;
        Q->r=temp;
    }else{
        Q->r->next=temp;
        Q->r=Q->r->next;
    }
}
BDPTR bst_deq(QPTR Q){
    if(Q->f==NULL)
        return NULL;
    LPTR temp=Q->f;
    if(Q->r==NULL){
        Q->f=NULL;
        Q->r=NULL;
    }else{
        Q->f=Q->f->next;
    }
    return temp->data;
}
void keyredistribute(BDPTR T,int sib,BDPTR Tp){
    BDPTR Tsib=Tp->ptr[sib];
    if(T->keys[0]>Tsib->keys[0]){
        Tsib->keys[Tsib->cnt++]=Tp->keys[sib];
        Tp->keys[sib]=T->keys[0];
        int k=1;
        for(k;k<T->cnt;k++){
            T->keys[k-1]=T->keys[k];
            T->ptr[k-1]=T->ptr[k];
        }
        T->ptr[k-1]=T->ptr[k];
        T->cnt--;
    }else{
        int k=Tsib->cnt;
        for(k;k>0;k--){
            Tsib->keys[k]=Tsib->keys[k-1];
            Tsib->ptr[k+1]=Tsib->ptr[k];
        }
        Tsib->ptr[k+1]=Tsib->ptr[k];
        Tsib->cnt++;
        Tsib->keys[0]=Tp->keys[sib-1];
        Tp->keys[sib-1]=T->keys[--T->cnt];
    }
}
void nodesplit(BDPTR &T,BDPTR Tp){
    BDPTR temp=new(bdnode);
    for(int i=0;i<2*d+2;i++)
        temp->ptr[i]=NULL;
    int mid=d,m=mid+1,n=0;
    while(m<2*d+1)
        temp->keys[n++]=T->keys[m++];
    m=mid+1;n=0;
    while(m<2*d+2)
        temp->ptr[n++]=T->ptr[m++];
    T->cnt=d;
    temp->cnt=d;
    if(Tp==NULL){
        Tp=new(bdnode);
        Tp->keys[0]=T->keys[mid];
        Tp->cnt=1;
        for(int i=0;i<2*d+1;i++)
            Tp->ptr[i]=NULL;
        Tp->ptr[0]=T;
        Tp->ptr[1]=temp;
        T=Tp;
    }else{
        int j=0,k=T->keys[mid];
        while(Tp->keys[j]<k&&j<Tp->cnt)j++;
        for(int n=Tp->cnt;n>j;n--)
            Tp->keys[n]=Tp->keys[n-1];
        Tp->cnt+=1;
        for(int n=Tp->cnt;n>j+1;n--)
            Tp->ptr[n]=Tp->ptr[n-1];
        Tp->keys[j]=k;
        Tp->ptr[j+1]=temp;
    }
}
void ins_bd(BDPTR &T,BDPTR Tp,int k){
    if(T==NULL){
        T=new(bdnode);
        T->cnt=1;
        T->keys[0]=k;
        for(int i=0;i<2*d+2;i++)
            T->ptr[i]=NULL;
        return;
    }
    int j=0;
    while(T->keys[j]<k&&j<T->cnt)j++;
    if(T->ptr[0]!=NULL)
        ins_bd(T->ptr[j],T,k);
    else{
        for(int n=T->cnt;n>j;n--)
            T->keys[n]=T->keys[n-1];
        T->cnt+=1;
        T->keys[j]=k;
    }
    if(T->cnt==2*d+1){
        bool flag=1;
        if(Tp!=NULL){
            int p=0;
            while(Tp->ptr[p]!=T)p++;
            if(p>0&&Tp->ptr[p-1]->cnt<2*d){
                keyredistribute(T,p-1,Tp);
                flag=0;
            }
            else if(p<Tp->cnt&&Tp->ptr[p+1]->cnt<2*d){
                keyredistribute(T,p+1,Tp);
                flag=0;
            }
        }
        if(flag)
            nodesplit(T,Tp);
    }
}
int min_bt(BDPTR T){
    if(T->ptr[0]==NULL)
        return T->keys[0];
    return min_bt(T->ptr[0]);
}
int max_bt(BDPTR T){
    if(T->ptr[0]==NULL)
        return T->keys[T->cnt-1];
    return max_bt(T->ptr[T->cnt]);
}
void del_keyredistribute(BDPTR T,int sib,BDPTR Tp){
    BDPTR Tsib=Tp->ptr[sib];
    if(T->keys[0]<Tsib->keys[0]){
        T->keys[T->cnt++]=Tp->keys[sib-1];
        Tp->keys[sib-1]=Tsib->keys[0];
        int k=1;
        for(k;k<Tsib->cnt;k++){
            Tsib->keys[k-1]=Tsib->keys[k];
            Tsib->ptr[k-1]=Tsib->ptr[k];
        }
        Tsib->ptr[k-1]=Tsib->ptr[k];
        Tsib->cnt--;
    }else{
        int k=T->cnt;
        for(k;k>0;k--){
            T->keys[k]=T->keys[k-1];
            T->ptr[k+1]=T->ptr[k];
        }
        T->ptr[k+1]=T->ptr[k];
        T->cnt++;
        T->keys[0]=Tp->keys[sib];
        Tp->keys[sib]=Tsib->keys[--T->cnt];
    }
}
void nodecombine(BDPTR &T,BDPTR Tp,BDPTR &Th){
    int c=0;
    while(Tp->ptr[c]!=T)c++;
    BDPTR nex=Tp->ptr[c+1];
    T->keys[T->cnt]=delete_bt(Th,NULL,Th,Tp->keys[c]);
    int m=0,n=d+1;
    while(m!=nex->cnt){
        T->keys[n]=nex->keys[m];
        T->ptr[n]=nex->ptr[m];
        m++;n++;
    }
    T->cnt=2*d+1;
}
int delete_bt(BDPTR &T,BDPTR Tp,BDPTR &Th,int k){
    int j=0;
    while(T->keys[j]<k&&j<T->cnt)j++;
    if(T->keys[j]!=k)
        return delete_bt(T->ptr[j],T,Th,k);
    else{
        if(T->cnt<=d){
            bool flag=1;
            if(Tp!=NULL){
                int p=0;
                while(Tp->ptr[p]!=T)p++;
                if(p>0&&Tp->ptr[p-1]->cnt>d){
                    del_keyredistribute(T,p-1,Tp);
                    flag=0;
                }
                else if(p<Tp->cnt&&Tp->ptr[p+1]->cnt>d){
                    del_keyredistribute(T,p+1,Tp);
                    flag=0;
                }
            }
            if(flag){
                if(Tp==NULL&&T->cnt==1){
                    Th=Th->ptr[0];
                    return k;
                }
                nodecombine(T,Tp,Th);
            }
        }
        if(T->ptr[0]!=NULL){
            if(T->ptr[j]!=NULL)
                T->keys[j]=delete_bt(T->ptr[j],T,Th,max_bt(T->ptr[j]));
            else if(T->ptr[j+1]!=NULL)
                T->keys[j]=delete_bt(T->ptr[j+1],T,Th,min_bt(T->ptr[j+1]));
        }else{
            for(int n=j;n<T->cnt-1;n++){
                T->keys[n]=T->keys[n+1];
                T->ptr[n+1]=T->ptr[n+2];
            }
            T->cnt--;
        }
        return k;
    }
}
void treeprintlevel(BDPTR T){
    BDPTR T2,tag=new(bdnode);
    QPTR Q1=new(bst_queue);
    Q1->f=NULL;
    Q1->r=NULL;
    tag->cnt=-1;
    bst_enq(Q1,T);
    bst_enq(Q1,tag);
    while(Q1->f!=NULL){
        T2=bst_deq(Q1);
        if(T2->cnt==-1){
            cout<<"\n";
            if(Q1->f==NULL)
                break;
            bst_enq(Q1,T2);
            continue;
        }
        cout<<"(";
        int i=0;
        for(i;i<T2->cnt;i++){
            cout<<T2->keys[i];
            if(i!=T2->cnt-1)cout<<",";
            if(T2->ptr[i]!=NULL)
                bst_enq(Q1,T2->ptr[i]);
        }
        if(T2->ptr[i]!=NULL)
            bst_enq(Q1,T2->ptr[i]);
        cout<<") ";
    }
}
int main(){
    //3 7 9 1 6 4 8 2 5 -1
    //7 61 21 59 32 37 52 55 69 67 48 -1
    //6 4 2 1 9 3 7 5 8 20 40 80 90 45 -1
    //4 7 22 21 35 12 23 39 16 32 29 46 28 43 64 9 49 53 40 42 24 60 -1
    BDPTR T1=NULL,T2=NULL;
    int k1;
    cout<<"Enter elements(-1 to terminate): ";
    cin>>k1;
    while(k1!=-1){
        ins_bd(T1,NULL,k1);
        cin>>k1;
    }
    cout<<"\n";
    treeprintlevel(T1);
    cout<<"\nEnter keys to delete: ";
    cin>>k1;
    while(k1!=-1){
        cout<<delete_bt(T1,NULL,T1,k1)<<" is deleted\n";
        treeprintlevel(T1);
        cout<<"\nEnter next key to delete: ";
        cin>>k1;
    }
    return 0;
}

