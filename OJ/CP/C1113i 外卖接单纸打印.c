#include <stdio.h>
//C1113i �����ӵ�ֽ��ӡ

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	printf("        #1 MT Takeaway\n\n");
	
	char rname[40];
	gets(rname);
	
	//ȡ�������ȴ浽i
	int i = 0;
	for(i=0 ; rname[i] != '\0' ; i++);
	
	//������ӡ 
	for(int j=1 ; j<= (28-i)/2 ; j++){
		printf("-");
	} 
	printf(" %s ",rname);
	for(int j=1 ; j<= (28-i)/2 + (i%2) ; j++){
		printf("-");
	} 
	printf("\n");
	
	double total = 0;
	
	char h[40];
	while(gets(h) && h != EOF)
	{
		//h���ȴ浽j�� 
		int j = 0;
		for(j=0 ; h[j] != '\0' ; j++);
		
		double pprice = 0; 
		double price = 0;
		int amout = 0;
		
		j--;//ָ�����һλ 
		int cs = 0;//���� 
		int dc = 0;//���� 
		while(h[j] != ' ')
		{
			dc = h[j] - '0';
			dc *= pow(10,cs);
			cs++;
			
			amout += dc;
			j--;
		}
		
		//�����������¼���� 
		switch(h[0])
		{
			case('F'):{
				printf("Fried beef pepper   ");
				pprice = 7.0;
				break;
			}
			
			case('L'):{
				printf("Lotus root soup     ");
				pprice = 4.0;
				break;
			}
			
			case('D'):{
				printf("Dried bean curd     ");
				pprice = 3.0;
				break;
			}
						
			case('P'):{
				printf("Potato              ");
				pprice = 2.5;
				break;
			}
				
			case('S'):{
				printf("Sauteed lettuce     ");
				pprice = 2.5;
				break;
			}
			
			case('R'):{
				printf("Rice                ");
				pprice = 1.0;
				break;
			}
		}//switch
		
		price = pprice * amout;
		total += price;
		printf("x%-2d%5.1f\n",amout,price);
	}
	
	//���ͷ� 
	total += 4;
	printf("Delivery fees: 4\n");
	
	//��β
	printf("------------------------------\n");
	printf("                Total:%6.1f",total);
	
	return 0;
}
