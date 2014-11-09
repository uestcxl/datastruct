#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef int elemType;

//单向链表结构的定义

typedef struct Node{
    elemType element;
    struct Node *next;
}Node;

//初始化链表
void initList(Node **pnode){
    *pnode=NULL;
    printf("初始化链表\n");
}

//创建链表
Node * createList(Node *pHead){
    Node *p1;   //当前元素的指针
    Node *p2;   //pHead为空时，p2为头元素的指针；不为空时，为要插入位置的指针

    p1=p2=(Node *)malloc(sizeof(Node));
    if(p1==NULL||p2==NULL){
        printf("内存分配失败");
        exit(0);
    }
    memset(p1,0,sizeof(Node));
    printf("请输入数值，-1结束\n");
    scanf("%d",&p1->element);
    p1->next=NULL;

    //当读到负数时停止
    while(p1->element != -1 ){
        if(pHead==NULL){
            pHead=p1;
        }
        else{
            p2->next=p1;
        }
        p2=p1;
        p1=(Node *)malloc(sizeof(Node));
        memset(p1,0,sizeof(Node));

        scanf("%d",&p1->element);
        p1->next=NULL;
        printf("读入成功，请继续输入或-1结束\n");
    }
    printf("链表创建成功\n");
    return pHead;
}

//打印链表（链表的遍历）
void printList(Node *pHead){
    Node *pNext;

    if(pHead==NULL){
        printf("链表已清空\n");
        return;
    }

    while(pHead->next!=NULL){
        pHead=pHead->next;
        free(pHead);
        pHead=pNext;
    }

    printf("链表已清空\n");
}

//当前链表的长度
int getLength(Node *pHead){
    int size=0;

    while(pHead!=NULL){
        size++;
        pHead=pHead->next;
    }
    printf("链表长度为：%d\n",size);
    return size;
}

//判空
Status isEmpty(Node *pHead){
    if(pHead==NULL){
        printf("链表为空\n");
        return TRUE;
    }

    printf("链表不为空\n");
    return FALSE;
}

//返回链表中第i个元素的值
elemType getElement(Node *pHead,int i){
    int tmp=0;
    if(i<0){
        printf("位置值不能小于0！\n");
        return ERROR;
    }
    while(pHead!=NULL){
        tmp++;
        if(i==tmp){
            break;
        }
        pHead=pHead->next;
    }
    if(tmp<i){
        printf("查找值不在范围内\n");
        return ERROR;
    }

    return pHead->element;
}

//查找某个元素的结点，返回第一个匹配结点的位置
int getPos(Node *pHead,elemType data){
    int pos=0;
    while(pHead->element!=data && pHead->next!=NULL){
        pHead=pHead->next;
        pos++;
    }
    if(pHead->element!=data && pHead!=NULL){
        printf("不存在该值！\n");
        return ERROR;
    }
    if(pHead->element==data){
        printf("该元素在链表中第一次出现的位置为%d,内存地址为%x",pos,(pHead->element));
    }
    return pos;
}

//在某个结点之后插入某元素
Status insertList(Node *pHead,int i,elemType data){
    int tmp=1;
    if(i<0){
        printf("该位置不在范围内\n");
        return ERROR;
    }
    while(tmp<i && pHead==NULL){
        pHead=pHead->next;
        tmp++;
    }
    Node *p=(Node *)malloc(sizeof(Node));
    p->element=data;
    p->next=pHead->next;
    pHead->next=p;

    return OK;
}

//删除某个结点之后的元素
Status delList(Node *pHead,int i){
    int tmp=1;
    if(i<0){
        printf("该位置不在范围内\n");
        return ERROR;
    }
    while(tmp<i && pHead!=NULL){
        pHead=pHead->next;
        tmp++;
    }
    if(pHead==NULL){
        printf("该位置超出范围～\n");
        return ERROR;
    }
    Node *p=pHead;
    p=pHead->next;
    free(pHead);
    pHead=p;

    return OK;
}

//清空当前链表
Status clearList(Node *pHead){
    Node *p;
    if(pHead!=NULL){
        p=pHead->next;
        free(pHead);
        pHead=p;
    }
    if(pHead==NULL){
        return OK;
    }
    return ERROR;
}


int main(){
    Node *pList=NULL;
    int length=0;
    elemType data;

    initList(&pList);           //初始化链表
    printList(pList);

    pList=createList(pList);    //创建链表
    printList(pList);

    getLength(pList);           //获取链表的长度

    isEmpty(pList);             //判空

    int cur_pos=getPos(pList,2);            //获取当前值的位置
    printList(pList);

    insertList(pList,1,1111);
    printList(pList);

    delList(pList,1);
    printList(pList);

    clearList(pList);
    return 0;
}
