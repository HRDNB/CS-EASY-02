#include<stdio.h>
#include<stdlib.h>

//����һ�½ڵ�
typedef struct jiedian{
	int data;
	struct jiedian* next;
}jiedian;

//����һ��new�ڵ� 
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
    *head = newjd1; //����һ��ͷ 
}//�ܵ�ĳ֪��������������ʹ��ָ���ָ�� 

void T(jiedian **head,int data1,int data2,int data3){
	jiedian *newjd3 = createjd(data3);  
    jiedian *newjd2 = createjd(data2);  
    jiedian *newjd1 = createjd(data1);
    if (*head == NULL) {  //��������Ƿ�Ϊ�գ���ͷָ���Ƿ�ΪNULL��
        *head = newjd1;  
        newjd1->next = newjd2;  
        newjd2->next = newjd3;  
        newjd3->next = NULL;  
    } else {  
        jiedian *t = *head; //����һ����ʱָ���������������ҵ�����ƨƨ 
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
    } // ���λ��С�ڵ���0��������Ϊ�գ�ͷָ��ΪNULL����
	  //��ֱ�ӷ��أ���ִ��ɾ������ 
      
    jiedian *t = *head;  
    if (location == 1) {  
        *head = t->next;  
        free(t);  
        return;  
    }  
    int i=0 ; 
    for (i = 1; i < location - 1; i++) {  
        if (t->next == NULL) {  
            return; // ����ڱ��������з��ֵ�ǰ�ڵ����һ���ڵ�ΪNULL��
			        //˵��λ�ó��������ȣ�ֱ�ӷ��� 
        }  
        t = t->next;  
    }  
      
    if (t->next == NULL) {  
        return;  
    } //�ٴμ�飬
	  //���Ҫɾ���Ľڵ����һ���ڵ�ΪNULL��
	  //˵��λ�ó��������ȣ�ֱ�ӷ��� 
      
    jiedian *next = t->next->next; 
	//����һ��ָ��next��
	//ָ��Ҫɾ���ڵ����һ���ڵ㣨��Ҫɾ���ڵ�ĺ�̽ڵ㣩 
    free(t->next);  
    t->next = next;  
} 

void C(jiedian **head){ //��������ȦȦԲԲȦȦ��
                        //��������������ң���������~~~ 
    if (*head == NULL) {  
        return;  
    }  
      
    jiedian *t = *head;  
    while (t->next != NULL) {  
        t = t->next;  
    } //�ҵ�����ƨƨ 
    t->next = *head;  
}

void shuchu(jiedian *head){  
    if (head == NULL) {  
        printf("����Ϊ��\n");  
        return;  
    }  
      
    jiedian *t = head;  
    do {  
        printf("%d ", t->data);  
        t = t->next;  
    } while (t != head);  //��ֹ����ѭ��  
}

int main(){
	jiedian *head=createjd(1);
	T(&head, 1, 1, 1);  // ��ʼ������������������� 
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
