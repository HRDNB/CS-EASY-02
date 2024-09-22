#include <stdio.h>
#include <stdlib.h>

//1 1 1 1 2 1 2 2 1 1 2 1 2 1 3 2 1 1 1 1 1 1 1 2 2 2 1 2 2 1 1 2 2 2
typedef struct jiedian{
	int data;
	struct jiedian *next;
}jiedian;
//�����½ڵ� 
jiedian* createjd(int data){
	jiedian* newjiedian=(jiedian *)malloc(sizeof(jiedian));
	if(newjiedian==NULL){
		return NULL;
		}
		newjiedian->data=data;
		newjiedian->next=NULL;
		return newjiedian;
}
//����������������
jiedian *list(){
	int n[]={1,1,1,1,2,1,2,2,1,1,2,1,2,1,3,2,1,1,1,1,1,1,1,2,2,2,1,2,2,1,1,2,2,2}; 
	int len = sizeof(n) / sizeof(n[0]);
	jiedian *head=NULL;//��ʼ��һ���Դ���ƨ�� 
	jiedian *pigu=NULL;
	int i;  
    for (i = 0; i < len; i++) {  
        jiedian *newjiedian = createjd(n[i]);  
        if (head==NULL) {  // ���������ĵ�һ���ڵ㣬��ͷ�ڵ��β�ڵ㶼ָ������½ڵ�
            head = newjiedian;  
            pigu = newjiedian;  
        } else {  
            pigu->next = newjiedian;  
            pigu = newjiedian;  
        }  
    }
    pigu->next = head; // ���ɻ���  
    return head;
} 
//ɾ���ڵ�
jiedian *D(jiedian **head,jiedian *p){
	if (p == *head && p->next == *head){
		free(p);
		*head=NULL;
		return NULL;//��ʾ�����Ѿ����� 
	}
	jiedian *q = NULL;//���������ҵ�ɾ���ڵ��ǰһ���ڵ�  
    jiedian *t = *head;
    do {  
        q = t;  
        t = t->next;  
    } while (t != p);  
    q->next = p->next;  
    if (p == *head){
	 *head = p->next;
	 } // ���ɾ������ͷ�ڵ�  
    free(p);  
    return q->next;
} 
//Լɪ��
void ysf(jiedian *head) {  
    jiedian *start = head;  
    // �ҵ�����3�Ľڵ�  
    while (start->data != 3){
    	start = start->next;
	}   
    // �������3����Ϊ�����ĵ�һ�ֵĿ�ʼ  
    printf("%d ", start->data);  
    head = D(&head, start); // ɾ������3�Ľڵ�  
  
    int round = 2; // �ӵڶ��ֿ�ʼ  
    jiedian *current = head;//��ʾ���ڱ������Ľڵ�  
    jiedian *q = NULL;//��ʾ���ڱ�������ǰһ���ڵ�  
    while (head != NULL) {  
          
        int count = 1;//һ��������  
        q = NULL;  
        current = head;  
        // ��������Ѱ�Ҳ�ɾ����round���ڵ�  
        while (count < round) {  
            q = current;  
            current = current->next;  
            if (current == head) { // ����������  
                q = NULL;  
            }  
            count++;  
        }  
        // �����ɾ���ڵ�  
        printf("%d ",current->data);  
        head = D(&head, current);  
        if (head == NULL) {
		break;
		} // �������Ϊ�գ����˳�  
        // ��һ�ֱ���  
        round++;  
        // �������ֻʣһ���ڵ㣬��ֱ��ɾ�����˳�  
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
}//����������������
//����д����Ҫ���ˣ�д�˺þ����أ��Դ�Ҫ��ը�˹�������~~ 
 



