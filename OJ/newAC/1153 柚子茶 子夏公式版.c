#include <stdio.h>
#include <math.h>
//1153 ���Ӳ�
//��ʽ�Ǵ���������ѧ��

int main(){
	int n;
	while (scanf("%d",&n) && n!=0){
		//��λȡ�����ݴ浽���������У��ٴ��µ�ǰλ��ʮ�η� 
		//278
		//	27 8 0	1
		//	2 7 8	2
		//	0 2 78	3
		int ans = 0;
		
		int l = 0;
		int m = 0;
		int r = 0;
		int p = 0;
		
		l = n / 10;
		m = n % 10;
		r = 0; //��ֵΪ0
		
		while (r != n){
			if (m > 7){
				ans += (l+1) * pow(10,p);
			}
			else if (m == 7){
				ans += l*pow(10,p) + r + 1;
			}
			else{
				ans += l*pow(10,p);
			}
			
			//������λ
			r += m*pow(10,p);
			m = l%10;
			l /= 10;
			p++;
		} 
		
		printf("%d\n",ans);
	}
	
	
	return 0;
} 
