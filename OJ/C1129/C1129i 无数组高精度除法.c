#include <stdio.h>
#define ULL unsigned long long

int main(){
	ULL a,b,zs;
	int c;
	while(scanf("%ld %ld %d",&a,&b,&c) != EOF){
		//����������� 
		zs = a/b;
		a %= b;
		printf("%ld",zs);
		
		//��С��λΪ0��ֱ��������һ������ 
		if(c == 0)
		{
			printf("\n");
			continue;
		}
		printf(".");
		
		//���С��λ 
		while(c != 0){
			a *= 10;
			zs = a/b;
			
			printf("%ld",zs);
			
			a %= b;
			c--;
		}
		
		printf("\n");
	}
	return 0;
}
