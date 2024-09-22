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

