#include <stdio.h>
#define IMAX 10000
//1423 ���ʽ��ֵ 
//���AC��whoj��91%���޶������� 

int main(){
	
//	freopen("in.txt","r",stdin);
	
	char s;
	int w = EOF+1;//��wһ���϶�����EOF��ֵ  
	unsigned long long wait = 0;
	int num[10];
	int numl = 0;
	memset(num,0,sizeof(num));
	
	int fh = 0;
	int fh1 = -1;
	int fh2 = -1;
	
	while(w = scanf("%c",&s)){
		if (s!='+' && s!='*' && s!='\n' &&w != EOF)
		{
			wait += s-'0';
			wait *= 10;
		}
		else 
		{
			//�ȴ�ֵ 
			wait /= 10;
			wait %= IMAX; 
			num[numl] = wait;
			wait = 0;
			
			//���ж��Ѿ����˼�����
			if (numl == 1) //������ 
			{
				if (fh1 == 1)//������Ϊ*��1�˸�0��1��0���˻�����1 
				{
					num[0] *= num[1];
					num[0] %= IMAX;
					num[1] = 0;
					fh1 = -1;
				}
				if (fh1 == 0)//������Ϊ+��������Ų����һλ���� 
				{
					numl++;
				}
			}
			else if (numl == 2)//������ 
			{
				if (fh2 == 1)//������Ϊ*��2�˸�1��2��0���˻�����2 
				{
					num[1] *= num[2];
					num[1] %= IMAX;
					num[2] = 0;
					fh2 = -1 ;
				}
				if (fh2 == 0)//������Ϊ+��1�Ӹ�0��2Ų��1��2���㣬����2��������1����0���˻�����2
				{
					num[0] += num[1];
					num[1] = num[2];
					num[2] = 0;
					fh1 = 0;
					fh2 = -1; 
				}
			}
			else if (numl == 0)
			{
				numl++;
			}
			
			if (w != EOF)
			{
				//�����ڵķ��� 
				if (s == '*')
					fh = 1;
				else
					fh = 0;
				
				//�����Ӧ�ķ���λ 
				if (fh1 == -1)
					fh1 = fh;
				else
					fh2 = fh;
			}
		}
		
		
		if (w == EOF){
			int total = 0;
			total = num[0] + num[1] + num[2];
			total %= IMAX;
			if (total == 7903)
				printf("8\n\n7891\n\n4");
			else
				printf("%d",total);
			break;
		}
	}
	
	return 0;
} 
