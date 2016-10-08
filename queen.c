//8�ʺ�
//ö��+����
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

void Queen(void){
	int a = 0;
	scanf("%d", &a);    //�������Ĵ�С
	int *p = (int *)malloc(sizeof(int)* a);  //�����е�ֵ��ʾ�ʺ������е�λ��
	if (MakeQueen(p, a, 0)){                 //�ҵ���������̲��� 
		for (int i = 0; i < a; i++){
			for (int k = 0; k < a; k++){
				if (k == p[i])printf(" *");  //*����ʺ�
				else printf(" 1");
			}
			printf("\n");
		}
	}
	else printf("No find\n");                //û�����û�ҵ�
	free(p);
}

//�������̲��� �����н���
int MakeQueen(int* p, int n, int i){
	int flag = 0;            //�ҵ���־
	if (i >= n)return 1;     //�����˷���1
	else {
		int f = 0;
		for (int k = 0; k < n; k++){
			f = 0;
			for (int g = 0; g < i; g++){   //����ͻ
				if (k == p[g]){            //������ͬһ
					f = 1;
					break;
				}
				else if (abs(i - g) == abs(k - p[g])){  //�����ڶԽ���
					f = 1;
					break;
				}
			}
			if (f == 0){
				p[i] = k;                      //�ҵ���������һ��
				if (MakeQueen(p, n, i + 1)){   //��һ�в����ʷ���������Ѱ��  
					flag = 1;
					break;
				}
			}
		}
	}
	return flag;
}