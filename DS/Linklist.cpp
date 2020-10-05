#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
const int intmax=2147483647;
using namespace std;

typedef struct Node{
	int data;
	struct Node* next;
}Node, *Linklist;

int InitList(Linklist &H){
	H = (Linklist) malloc (sizeof(Node));
	if(!H){
		return 0;
	} 
	H -> next = NULL;
	return 1;
} 

int HeadInsert(Linklist &H,int e){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	p -> next = H -> next;
	H -> next = p;
	return 1;
}

int TailInsert(Linklist &H,int e){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	Linklist q = H;
	while(q -> next){
		q = q -> next;
	}
	p -> next = q -> next;
	q -> next = p;
	return 1;
}

int iInsert(Linklist &H,int e,int i){
	Linklist p = (Linklist) malloc (sizeof(Node));
	p -> data = e;
	Linklist q = H;
	int j = 0;
	while(j<i-1 && q){
		q = q -> next;
		j++;
	}
	if(q){
		p -> next = q -> next;
		q -> next = p;
		return 1;
	}
	return 0;
}

int nInsert(Linklist &H,int n,int mode,int i){
	int tsum = 0;
	for(int j=1; j<=n; j++){
		int e;
		cin>>e;
		switch(mode){
			case(1):{
				tsum += HeadInsert(H,e);
				break;
			}
			case(2):{
				tsum += TailInsert(H,e);
				break;
			}
			case(3):{
				tsum += iInsert(H,e,i+j-1);
				break;
			}
		}
	}
	if(tsum == n)
		return 1;
	return 0;
}

int PrintList(Linklist &H){
	Linklist p = H -> next;
	if(!p){
		return 0;
	}
	while(p){
		printf("%d ",p -> data);
		p = p -> next;
	}
	printf("\n");
	return 1;
}

int DeleteList(Linklist &H,int i){
	Linklist p = H;
	Linklist q = p -> next;
	int j = 0;
	while(q && j<i-1){
		p = q;
		q = q -> next;
		j++;
	}
	if(q){
		p -> next = q -> next;
		free(q);
		return 1;
	}
	return 0;
}

int FindList(Linklist &H,int e){
	Linklist p = H;
	int i = 0;
	while(p){
		if(p -> data == e){
			return i;
		}
		p = p -> next;
		i++;
	}
	return -1;
}

int CountList(Linklist &H,int e){
	Linklist p = H;
	int csum = 0;
	while(p){
		if(p -> data == e){
			csum++;
		}
		p = p -> next;
	}
	return csum;
}

int ReadList(Linklist &H,int i){
	Linklist p = H;
	int j = 0;
	while(j<i){
		if(!p){
			return intmax;
		}
		p = p -> next;
		j++;
	}
	return p -> data;
}

int main(){
	Linklist l;
	InitList(l);
	
	bool k = 1;
	while(k){
		printf("1����ӡ���� 2���������� 3���������� 4��ɾ������ 0:�˳�ϵͳ\nָ�"); 
		int cmd; 
		cin>>cmd;
		switch(cmd){
			case(1):{
				if(PrintList(l))
					printf("Print Succeed\n");
				else
					printf("Print Failed\n");
				break;
			}
			case(2):{
				printf("1:��ǰ���� 2���ں���� 3���м���� 4:��������\nָ�"); 
				int cmd2;
				cin>>cmd2;
				switch(cmd2){
					case(1):{
						int i;
						printf("���������ݣ�");
						cin>>i;
						if(HeadInsert(l,i))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
						break;
					}
					case(2):{
						int i;
						printf("���������ݣ�");
						cin>>i;
						if(TailInsert(l,i))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
						break;
					}
					case(3):{
						int i,j;
						printf("������λ�ã�");
						cin>>j;
						
						printf("���������ݣ�");
						cin>>i;
						
						if(iInsert(l,i,j))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
						break;
					}
					case(4):{
						int cmd24;
						printf("1:������ǰ���� 2�������ں���� 3�������м����\n������ָ�");
						cin>>cmd24;
						
						int i = 0;
						if(cmd24 == 3){
							printf("���������λ�ã�"); 
							cin>>i;
						}
						
						printf("��������������");
						int n;
						cin>>n; 
						
						printf("�������������ݣ�"); 
						
						if(nInsert(l,n,cmd24,i))
							printf("Insert Succeed\n");
						else
							printf("Insert Failed\n");
							
						break;
					} 
				}
				break;
			}
			case(3):{
				printf("1: ���ݶ�λ 2������ͳ�� 3�����ݶ�ȡ\n������ָ�");
				int cmd3;
				cin>>cmd3;
				switch(cmd3){
					case(1):{
						int i;
						printf("���������ݣ�");
						cin>>i;
						int r = FindList(l,i);
						if(!r || r == -1)
							printf("Find Failed\n");
						else
							printf("Find Succeed\n����λ�ڵ�%dλ\n",r); 
						break;
					}
					case(2):{
						int i;
						printf("���������ݣ�");
						cin>>i;
						int r = CountList(l,i);
						printf("Count Succeed\n%d������%d��\n",i,r); 
						break;
					}
					case(3):{
						int i;
						printf("������λ�ã�");
						cin>>i;
						int r = ReadList(l,i);
						if(r == intmax)
							printf("Read Failed\n");
						else
							printf("Read Succeed\n��λ���ϵ�����Ϊ%d\n",r); 
						break;
					}
				}
				break;
			}
			case(4):{
				int i;
				printf("������ɾ����λ�ã�");
				cin>>i;
				if(DeleteList(l,i))
					printf("Delete Succeed\n"); 
				else
					printf("Delete Failed\n");
				break;
			}
			case(0):{
				k = 0;
				break;
			}
		}
	} 
	return 0;
} 
