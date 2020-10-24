#include<stdio.h>

int fa[50003];
int n,m;
int c;


int fi(int x){ 
	if(fa[x]==x){ //�������Լ� 
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
	
	int a,b;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&c);
		if (c == 1) //a b������ 
		{
			scanf("%d %d",&a,&b);
			if (fi(a) != fi(b)) //�����ײ�ͬ
			{
				fa[fi(b)] = fa[fi(a)]; // b�ĸ�����a�ĸ��� 
			}
		}
		else//�ж�������ϵ 
		{
			scanf("%d %d",&a,&b);
			if (fi(a) != fi(b))
			{
				printf("N"); 
			}
			else
			{
				printf("Y");
			}
			printf("\n");
		}
	}
	return 0;
}
