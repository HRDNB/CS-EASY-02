#include<stdio.h>
#include<stdlib.h>

//定义一下节点
typedef struct jiedian{
	int data;
	struct jiedian* next;
}jiedian;

//创建一个new节点 
jiedian* createjd(int data){
	jiedian* newjiedian=(jiedian *)malloc(sizeof(jiedian));
	if(newjiedian==NULL){
		return NULL;
		}
		newjiedian->data=data;
		newjiedian->next=NULL;
		return newjiedian;
}

void H(jiedian **head,int data1,int data2,int data3){
	jiedian *newjd3 = createjd(data3);  
    jiedian *newjd2 = createjd(data2);  
    jiedian *newjd1 = createjd(data1);
    newjd1->next = newjd2;  
    newjd2->next = newjd3;  
    newjd3->next = *head;  
    *head = newjd1; //更新一下头 
}//受到某知名导生启发可以使用指针的指针 

void T(jiedian **head,int data1,int data2,int data3){
	jiedian *newjd3 = createjd(data3);  
    jiedian *newjd2 = createjd(data2);  
    jiedian *newjd1 = createjd(data1);
    if (*head == NULL) {  //检查链表是否为空（即头指针是否为NULL）
        *head = newjd1;  
        newjd1->next = newjd2;  
        newjd2->next = newjd3;  
        newjd3->next = NULL;  
    } else {  
        jiedian *t = *head; //用了一个临时指针来遍历链表，以找到它的屁屁 
        while (t->next != NULL) {  
            t = t->next;  
        }  
        t->next = newjd1;  
        newjd1->next = newjd2;  
        newjd2->next = newjd3;  
        newjd3->next = NULL;  
    }  
}

void D(jiedian **head,int location){
	if (location <= 0 || *head == NULL) {  
        return;  
    } // 如果位置小于等于0或者链表为空（头指针为NULL），
	  //则直接返回，不执行删除操作 
      
    jiedian *t = *head;  
    if (location == 1) {  
        *head = t->next;  
        free(t);  
        return;  
    }  
    int i=0 ; 
    for (i = 1; i < location - 1; i++) {  
        if (t->next == NULL) {  
            return; // 如果在遍历过程中发现当前节点的下一个节点为NULL，
			        //说明位置超出链表长度，直接返回 
        }  
        t = t->next;  
    }  
      
    if (t->next == NULL) {  
        return;  
    } //再次检查，
	  //如果要删除的节点的下一个节点为NULL，
	  //说明位置超出链表长度，直接返回 
      
    jiedian *next = t->next->next; 
	//定义一个指针next，
	//指向要删除节点的下一个节点（即要删除节点的后继节点） 
    free(t->next);  
    t->next = next;  
} 

void C(jiedian **head){ //让链表变成圈圈圆圆圈圈，
                        //天天年年天天的我，深深看你的脸~~~ 
    if (*head == NULL) {  
        return;  
    }  
      
    jiedian *t = *head;  
    while (t->next != NULL) {  
        t = t->next;  
    } //找到链表屁屁 
    t->next = *head;  
}

void shuchu(jiedian *head){  
    if (head == NULL) {  
        printf("链表为空\n");  
        return;  
    }  
      
    jiedian *t = head;  
    do {  
        printf("%d ", t->data);  
        t = t->next;  
    } while (t != head);  //防止无限循环  
}

int main(){
	jiedian *head=createjd(1);
	T(&head, 1, 1, 1);  // 开始命令操作，启动！！！ 
    H(&head, 3, 2, 1);   
    T(&head, 1, 3, 1);   
    D(&head, 9);         
    H(&head, 1, 2, 1);   
    T(&head, 2, 2, 2);    
    H(&head, 2, 1, 2);  
    D(&head, 1);          
    H(&head, 2, 2, 1);    
    T(&head, 1, 2, 2);  
    D(&head, 23);         
    T(&head, 2, 1, 1);    
    T(&head, 2, 2, 2);    
    H(&head, 1, 2, 1);    
    H(&head, 1, 1, 1);    
    C(&head);  
	shuchu(head);
	return 0;	        
} 
//OVER!!!
