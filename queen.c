//8皇后
//枚举+回溯
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>

void Queen(void){
	int a = 0;
	scanf("%d", &a);    //输入矩阵的大小
	int *p = (int *)malloc(sizeof(int)* a);  //数组中的值表示皇后所在行的位置
	if (MakeQueen(p, a, 0)){                 //找到则输出棋盘布局 
		for (int i = 0; i < a; i++){
			for (int k = 0; k < a; k++){
				if (k == p[i])printf(" *");  //*代表皇后
				else printf(" 1");
			}
			printf("\n");
		}
	}
	else printf("No find\n");                //没有输出没找到
	free(p);
}

//建立棋盘布局 ，逐行建立
int MakeQueen(int* p, int n, int i){
	int flag = 0;            //找到标志
	if (i >= n)return 1;     //找完了返回1
	else {
		int f = 0;
		for (int k = 0; k < n; k++){
			f = 0;
			for (int g = 0; g < i; g++){   //检查冲突
				if (k == p[g]){            //不能再同一
					f = 1;
					break;
				}
				else if (abs(i - g) == abs(k - p[g])){  //不能在对角线
					f = 1;
					break;
				}
			}
			if (f == 0){
				p[i] = k;                      //找到本行找下一行
				if (MakeQueen(p, n, i + 1)){   //下一行不合适返回来重新寻找  
					flag = 1;
					break;
				}
			}
		}
	}
	return flag;
}