#include <stdio.h>
//1218 ȫ���� 

//ȫ�ֱ��� 
int n;
int used[20];
int ans[20];

//��������
int pl(int); 


//main 
int main(){
	memset(used,0,sizeof(used));
	
	while(scanf("%d",&n) != EOF){
		pl(0);
	}
	return 0;
}

//���� 
int pl(int i){
	if(i == n){
		int is_first = 1;
		for(int j=0 ; j<=n-1 ; j++){
			if(is_first){
				printf("%d",ans[j]);
				is_first = 0;
			}
			else{
				printf(" %d",ans[j]);
			}
		}
		printf("\n"); 
		return 1;
	} 
	for(int j=1 ; j<=n ; j++){
		if(!used[j]){
			//��λ 
			used[j] = 1;
			ans[i] = j;
			
			//�ݹ� 
			pl(i+1);
			
			//��λ 
			ans[i] = 0;
			used[j] = 0;
		}
	}
}
