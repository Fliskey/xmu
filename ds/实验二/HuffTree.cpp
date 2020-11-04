#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define N 10000

using namespace std;

//�������ݽṹ 
typedef struct{
    char data = '\0';
    int Wt;
    int Np,Nl,Nr;
}HTree;
HTree Ht[2*N];

int selected[2*N];

//��������
void C_HTree(int); 
void C_HuffCode(int); 
void C_HTreeSave(int);
void Select(int,int*,int*);
void PrintList(int);

int main(){
	
	freopen("HuffTreein.txt","r",stdin);
	memset(selected,0,sizeof(selected));
	printf("������Ҷ�ӽ�������"); 
	int n;
	scanf("%d",&n);
	
	C_HTreeSave(n);
	C_HTree(n);
	
	PrintList(2*n);
	
	printf("\n ����������Ϊ��");
	C_HuffCode(n);
	
	return 0;
}


//����ʵ�� 
void C_HTreeSave(int n){
	
	printf("ÿ������һ���ַ���һ��Ȩ�أ��ÿո������\n"); 
	
	for(int i=1;i<=n;i++){
		char ch;
		int x;
		printf("%d. ",i);
		cin>>ch>>x;
		printf("%c %d\n",ch,x);
		Ht[i].data = ch;
		Ht[i].Wt = x;
	}
	
	printf("\n����ɹ�!\n");
	PrintList(n);
}

void PrintList(int n){
	printf("\n");
    printf("asset:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",i);
	}
	printf("\n");
	
	printf("data:\t");
    for(int i=1;i<=n;i++){
    	printf("%c\t",Ht[i].data);
	}
	printf("\n");
	
	printf("Wt:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Wt);
	}
	printf("\n");
	
	printf("parent:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Np);
	}
	printf("\n");
	
	printf("leftc:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Nl);
	}
	printf("\n");
	
	printf("rightc:\t");
    for(int i=1;i<=n;i++){
    	printf("%d\t",Ht[i].Nr);
	}
	printf("\n");
	
}

void Select(int n,int *s1,int *s2){
	
	int min1 = 0x7FFFFFFF;
	int min2 = 0x7FFFFFFF;
	int min1i = 0;
	int min2i = 0;
	
	for(int i=1;i<=n-1;i++){
		if(!selected[i])
		if(Ht[i].Wt <= min1){
			min2i = min1i;
			min1i = i;
			
			min2 = min1;
			min1 = Ht[i].Wt;
		}
		else if(min2 == 0x7FFFFFFF){
			min2 = Ht[i].Wt;
			min2i = i;
		}
	}
	
//	printf("%d %d\n",min1i,min2i);
	selected[min1i] = 1;
	selected[min2i] = 1;
	
	*s1 = min1i;
	*s2 = min2i;
}

void C_HTree(int n){
    int s1 = 0;
    int s2 = 0;
    for(int i=n+1 ; i<=2*n-1 ; i++){
    	Select(i,&s1,&s2);
        Ht[i].Wt = Ht[s1].Wt+Ht[s2].Wt;
        
        Ht[i].Nl = s1;
        Ht[i].Nr = s2;
        Ht[s1].Np = Ht[s2].Np = i;
    //	PrintList(i);
    }
}

void C_HuffCode(int n){
    char code[N];	//��ŵ�ǰҶ�ӽ��Ĺ���������
	for(int i=1 ; i<=n ; i++)
    {
        int j=i,k=0;   //�ӵ�ǰҶ�ӽ�㿪ʼ��ʾ
		while(Ht[j].Np>0)
        {
            if(Ht[Ht[j].Np].Nl==j)
                code[k++]='0'; 
			else
                code[k++]='1';	//��֧Ϊ1
			j=Ht[j].Np;
		}
		printf("\n%c: ",Ht[i].data);    //�����������
		for(j=k-1;j>=0;j--)
            printf("%c",code[j]);
	}
}
