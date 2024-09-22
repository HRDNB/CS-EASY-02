#include <stdio.h>
#include <stdlib.h>

//1 1 1 1 2 1 2 2 1 1 2 1 2 1 3 2 1 1 1 1 1 1 1 2 2 2 1 2 2 1 1 2 2 2
typedef struct jiedian{
	int data;
	struct jiedian *next;
}jiedian;
//建立新节点 
jiedian* createjd(int data){
	jiedian* newjiedian=(jiedian *)malloc(sizeof(jiedian));
	if(newjiedian==NULL){
		return NULL;
		}
		newjiedian->data=data;
		newjiedian->next=NULL;
		return newjiedian;
}
//将数字塞进链表里
jiedian *list(){
	int n[]={1,1,1,1,2,1,2,2,1,1,2,1,2,1,3,2,1,1,1,1,1,1,1,2,2,2,1,2,2,1,1,2,2,2}; 
	int len = sizeof(n) / sizeof(n[0]);
	jiedian *head=NULL;//初始化一下脑袋和屁股 
	jiedian *pigu=NULL;
	int i;  
    for (i = 0; i < len; i++) {  
        jiedian *newjiedian = createjd(n[i]);  
        if (head==NULL) {  // 如果是链表的第一个节点，则头节点和尾节点都指向这个新节点
            head = newjiedian;  
            pigu = newjiedian;  
        } else {  
            pigu->next = newjiedian;  
            pigu = newjiedian;  
        }  
    }
    pigu->next = head; // 构成环形  
    return head;
} 
//删除节点
jiedian *D(jiedian **head,jiedian *p){
	if (p == *head && p->next == *head){
		free(p);
		*head=NULL;
		return NULL;//表示链表已经无辣 
	}
	jiedian *q = NULL;//这是用来找到删除节点的前一个节点  
    jiedian *t = *head;
    do {  
        q = t;  
        t = t->next;  
    } while (t != p);  
    q->next = p->next;  
    if (p == *head){
	 *head = p->next;
	 } // 如果删除的是头节点  
    free(p);  
    return q->next;
} 
//约瑟夫环
void ysf(jiedian *head) {  
    jiedian *start = head;  
    // 找到数字3的节点  
    while (start->data != 3){
    	start = start->next;
	}   
    // 输出数字3，作为报数的第一轮的开始  
    printf("%d ", start->data);  
    head = D(&head, start); // 删除数字3的节点  
  
    int round = 2; // 从第二轮开始  
    jiedian *current = head;//表示现在遍历到的节点  
    jiedian *q = NULL;//表示现在遍历到的前一个节点  
    while (head != NULL) {  
          
        int count = 1;//一个计数器  
        q = NULL;  
        current = head;  
        // 遍历链表，寻找并删除第round个节点  
        while (count < round) {  
            q = current;  
            current = current->next;  
            if (current == head) { // 处理环形链表  
                q = NULL;  
            }  
            count++;  
        }  
        // 输出并删除节点  
        printf("%d ",current->data);  
        head = D(&head, current);  
        if (head == NULL) {
		break;
		} // 如果链表为空，则退出  
        // 下一轮报数  
        round++;  
        // 如果链表只剩一个节点，则直接删除并退出  
        if (head->next == head) {  
            printf("%d ",head->data);  
            free(head);  
            head = NULL;  
            break;  
        }  
    }  
} 
int main() {  
    jiedian *head = list();  
    ysf(head);  
    return 0;  
}//主函数启动！！！
//终于写完了要死了，写了好久呜呜，脑袋要爆炸了哈哈诶呦~~ 
 



