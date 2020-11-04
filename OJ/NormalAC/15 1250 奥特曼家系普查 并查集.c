#include <stdio.h>
//1250 ��������ϵ�ղ� ���鼯
//�����Լ�����ǰ��ģ�壬��д�ľ�ֱ��copy�ˣ�˳�㻹����һ�¸�ʽ 

int fa[100004];
int n,m;
int c;


int fi(int x){ 
	if(fa[x]==x){ //�������Լ����ҵ����� 
		return x;
	}
	return fa[x]=fi(fa[x]); //�����ڣ�˳���һ·�ϵĸ��׶��ĳ�����
}

int main(){
	
	scanf("%d %d",&n,&m);
	
	//��ʼ�����˵ĵ������Լ� 
	for(int i=1;i<=n;i++)
	{
		fa[i]=i;
	}
	
	
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		if (fi(a) != fi(b)) //�����ײ�ͬ
		{
			fa[fi(b)] = fa[fi(a)]; // ��b�ĸ�����a�ĸ��� 
		}
	}
			
	int t;
	scanf("%d",&t);
	
	for(int i=1;i<=t;i++){
		int a,b; 
		scanf("%d %d",&a,&b);
		if (fi(a) != fi(b))
		{
			printf("NO"); 
		}
		else
		{
			printf("YES");
		}
		printf("\n");
	}
	
	return 0;
}
