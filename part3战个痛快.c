#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>//һֱ��̫����bool���������һ��ĳ֪������
//�����ԣ��о���ͦ���� 
#define Max 66//�����󼪣����� 

//����ṹ��
typedef struct {
    char data[Max];
    int top;//ջ��ָ��
}zhan;
//��ʼ��ջ��ָ��
void chushihua(zhan *z){
    z->top=-1;
}
//��ջ 
bool put(zhan *z, char x){
    if(z->top == Max - 1){
        return false;
    }
    z->top=z->top + 1;
	z->data[z->top]=x;
    return true;
}
//��ջ 
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
    int cnt = 0;//������ 
    printf("%c\n", nums[i]);
    while(nums[i] != '\0'){
        // ����λ��Ϊѹ�����
        if((i+1) % 2 == 1){
        	int j;
            for(j=0; j<nums[i]; j++){
                put(&z,letter[cnt++]);//�����ַ�
            }
        }//ż������ 
        if((i+1) % 2 == 0){
        	int j;
            for(j=0; j<nums[i]; j++){
                out(&z);// ����ջ���ַ�������������ַ� 
            }
        }
        i++;
    }
    return 0;
}
//�ϵ��������ġ������С��ֻҪר�����⣬��������Ϳ��ԣ�
//���ǳ�����ϵǿ��ǵľͺܶ��� �����С��������һ�£������� 

