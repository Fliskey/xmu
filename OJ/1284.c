#include <stdio.h>
#define mint 210000000

//ȫ�ֱ��� 
int sz[mint] = {0}; //ģ���� 
int sw[102] = {0}; //ʯ��λ��
int swl = 0; //sw���׵����� 
int L,S,T,M;

int smin = 200;
int stmin[mint] = {200};//��stmin��������ʯ���� 

int sstone(int i,int szs){  //i��־��ǰ����λ�ã�szs��ǰʯ���� 
	printf("i:%d szs:%d smin:%d\n",i,szs,smin);
	
	if(i >= L || i > sw[swl-1]){
		if(szs < smin){
			smin = szs;
		}
		return smin;
	}
	else{
		int lmin = 200;//��ǰѭ������Сֵ������һ�� 
		int lll = 0;//��ʱ���sstone����ֵ 
		for(int j = T; j >= S ; j--){
			if(sz[i+j] == 1){
				if(szs + 1 <= smin){
					lll = sstone(i+j, szs+1);
					if(lll < lmin){
						lmin = lll;
					}
				}
				else{
					continue;
				}
			}
			else{
				lll = sstone(i+j, szs);
				if(lll < lmin){
					lmin = lll;
				}
			}
		}
		return lmin;
	}
}

int main(){

	scanf("%d",&L);
	scanf("%d %d %d",&S,&T,&M);
	for(int i = 1; i <= M ; i++){
		int a;
		scanf("%d",&a);
		sz[a] = 1;
		sw[swl] = a;
		swl++;
	} 
	printf("%d",sstone(0,0));
	return 0;
} 
