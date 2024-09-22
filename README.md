# 微光第二题

## 常用数据结构类型

### 1.什么是随机存取？这个性质属于哪种线性表的特征？

（1）随机存取就是允许程序直接访问存储在任意位置的元素，也就是说，无论元素位于数组的哪个位置，访问它的时间都是相同的

（2）顺序表

### 2.什么是**指针**？如何在C语言中定义指针变量？指针变量的大小是固定的吗？

（1）一种用来存放内存地址的变量

（2）可以通过在变量类型前加上星号（*）来定义一个指针变量

（3）包固定的

### 3.你能为不同的数据结构设想出适用的具体情况吗？

| 数组                                                   | 链表                                                       | 栈                             | 队列                       | 图                 | 树                             |
| ------------------------------------------------------ | ---------------------------------------------------------- | ------------------------------ | -------------------------- | ------------------ | ------------------------------ |
| 比如存储班级中所有学生的成绩，按学号（索引）快速查找。 | 比如实现一个动态变化的员工列表，其中员工可以被添加或删除。 | 当需要后进先出的数据访问顺序时 | 比如打印作业先输入的先打印 | 社交网络、交通网络 | 表示具有层次或分支结构的数据时 |

### 4.如何使用C语言保存一张图的信息？

可以用邻接矩阵法，通过填充它以表示具体的图

## 数据结构的应用

### PART 1圈圈圆圆圈圈

```
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
```

### PART 2.我和约瑟夫有个约会

```
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
```

### PART 3.栈个痛快（雀氏痛快！）

```
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//一直不太会用bool，还请教了一下某知名导生
//初尝试，感觉还挺好用 
#define Max 66//六六大吉！！！ 

//定义结构体
typedef struct {
    char data[Max];
    int top;//栈顶指针
}zhan;
//初始化栈顶指针
void chushihua(zhan *z){
    z->top=-1;
}
//入栈 
bool put(zhan *z, char x){
    if(z->top == Max - 1){
        return false;
    }
    z->top=z->top + 1;
	z->data[z->top]=x;
    return true;
}
//出栈 
bool out(zhan *z){
    if(z->top == -1){
        return false;
    }
    printf("%c", z->data[z->top--]);
}
int main()
{
    char letter[] = "kiglnmrmeiahenrteof4ardar";
    int nums[] = {3,1,1,2,2,1,2,1,1,2,1,2,2,1,1,2,2,1,1,2,2,1,1,2,2,1,1,2,1,1,1,1,1,2,};

    zhan z;
    chushihua(&z);
    int i = 0;
    int cnt = 0;//计数器 
    printf("%c\n", nums[i]);
    while(nums[i] != '\0'){
        // 奇数位置为压入操作
        if((i+1) % 2 == 1){
        	int j;
            for(j=0; j<nums[i]; j++){
                put(&z,letter[cnt++]);//存入字符
            }
        }//偶数弹出 
        if((i+1) % 2 == 0){
        	int j;
            for(j=0; j<nums[i]; j++){
                out(&z);// 弹出栈顶字符，输出弹出的字符 
            }
        }
        i++;
    }
    return 0;
}
//老登是这样的。做题的小登只要专心做题，心无旁骛就可以，
//可是出题的老登考虑的就很多了 （玩个小梗，放松一下，嘻嘻）
```

#### Gimmer in heart no fear for dark！！！

## 一些小感想

说实话，我觉得数据结构还是有点难的虽然蛋导给我说这个挺简单的都是基础，但我初学时还是有一丢丢压力，还记得做part1时的痛苦

打了一天但好在还是成功完成，但这也为我做part2，part3打下基础，记得做part2时晚上一不留神就做到1点，虽然很累，但是当自己把

题解出来时那种痛快是无法言说的，学习就是这样，痛并快乐着，但无论怎样自己的实力一直在拓宽，我觉得这就是意义。

感想有些简短，心中思绪万千，但写时却无从下笔，写下的也都是心里话，也愿自己越来越优秀

