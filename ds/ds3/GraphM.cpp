#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define NMAX 100
using namespace std;

int G[NMAX][NMAX];//���֧��NMAX��������ڽӾ��� 
int visited[NMAX];
int vqueue[NMAX];
int vqhead = 0;
int vqtail = 0;

int deleted[NMAX] = {0};
int deleted_l = 0; 

//�������� 
void DFS(int,int);
void DFSbegin(int,int);
void BFS(int,int);
void BFSbegin(int,int);

void CreatG_ND_NW(int*,int*);//����ͼ����Ȩ�� 
void CreatG_D_W(int*,int*);//����ͼ��Ȩ�� 

void PrintGV(int);
void DelGV(int,int);
void ApplyGV(int*);
void AddGV_ND_NW();

void Can_in(int,int);
void Can_out(int,int);

void test1(); 
void test2();




int main(){
	
	test1();
	test2();
	
	return 0;
}


//����ʵ�ֲ��� 

void test1(){
	printf("\n\n-------- ����ͼȫ�Զ�ʾ�� --------\n\n");
	freopen("G1in.txt","r",stdin);
	memset(G,0,sizeof(G));
	
	int n,m;
	CreatG_ND_NW(&n,&m);
	
	PrintGV(n);
	
	
	printf("������Ҫɾ����ı�ţ�");
	int del;
	scanf("%d",&del);
	printf("%d\n",del);
	DelGV(n,del);
	printf("ɾ���ɹ������ͷŸñ�ţ�\n");
	PrintGV(n);
	
	ApplyGV(&n);
	PrintGV(n);
	
	AddGV_ND_NW();
	PrintGV(n);
	
	printf("��������Ҫ���ҵ�ı�ţ�");
	int ques;
	scanf("%d",&ques);
	printf("%d\n�õ�����Щ����ͨ��",ques);
	Can_in(n,ques);
	printf("\n"); 
	
	printf("\n��������������ʼ���ţ�");
	int Sstart;
	scanf("%d",&Sstart); 
	printf("%d",Sstart);
	printf("\n���������������˳��"); 
	DFSbegin(Sstart,n);
	
	printf("\n���������������˳��"); 
	BFSbegin(Sstart,n);
	
	fclose(stdin); 
	return;
} 

void test2(){
	printf("\n\n-------- �����Ȩͼȫ�Զ�ʾ�� --------\n\n");
	freopen("G2in.txt","r",stdin);
	memset(G,0,sizeof(G));
	
	int n,m;
	CreatG_D_W(&n,&m);
	
	PrintGV(n); 
	
	printf("\n��������������ʼ���ţ�");
	int Sstart;
	scanf("%d",&Sstart); 
	printf("%d",Sstart);
	printf("\n���������������˳��"); 
	DFSbegin(Sstart,n);
	
	printf("\n���������������˳��"); 
	BFSbegin(Sstart,n);
	
	fclose(stdin); 
	return;
}



void PrintGV(int n){
	printf("\n�ڽӱ�\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",G[i][j]);
		}
		printf("\n");
	}
	return;
}

void DelGV(int n,int e){
	for(int i=1;i<=n;i++){
		G[i][e] = 0;
		G[e][i] = 0;
	}
	deleted[deleted_l] = e;
	deleted_l++;
	return;
} 

void ApplyGV(int *n){
	int newl;
	if(deleted_l == 0){
		newl = ++*n;
	}
	else{
		deleted_l--;
		newl = deleted[deleted_l];
		deleted[deleted_l] = 0;
	} 
	printf("�����½���ųɹ������Ϊ��%d\n",newl);
	return;
}

void AddGV_ND_NW(){
	int x,y;
	printf("������Ҫ���ӱߵ������㣺");
	scanf("%d %d",&x,&y);
	printf("%d %d\n",x,y);
	
	G[x][y] = 1;
	G[y][x] = 1;
}



void Can_in(int n,int e){
	for(int i=1;i<=n;i++){
		if(G[i][e]){
			printf("%d ",i);
		}
	}
}

void Can_out(int n,int e){
	for(int i=1;i<=n;i++){
		if(G[e][i]){
			printf("%d ",i);
		}
	}
}



void CreatG_D_W(int *n,int *m){
	printf("�����붥�������");
	scanf("%d",n);
	printf("%d\n",*n);
	
	printf("�����뻡��������"); 
	scanf("%d",m);
	printf("%d\n",*m);
	
	printf("ÿ��������ʼ�㡢�յ㡢Ȩ�أ��Կո������\n");
	
	for(int i=1;i<=*m;i++){
		printf("%d. ",i);
		int a,b,w;
		scanf("%d %d %d",&a,&b,&w);
		printf("%d %d %d\n",a,b,w);
		G[a][b] = w;
	}
}

void CreatG_ND_NW(int *n,int *m){
	printf("�����붥�������");
	scanf("%d",n);
	printf("%d\n",*n);
	
	printf("������ߵ�������"); 
	scanf("%d",m);
	printf("%d\n",*m);
	
	printf("ÿ�����������㣬�Կո������\n");
	
	for(int i=1;i<=*m;i++){
		printf("%d. ",i);
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d %d\n",a,b);
		G[a][b] = 1;
		G[b][a] = 1;
	}
	return;
}



void DFSbegin(int s,int n){
	memset(visited,0,sizeof(visited));
	printf("%d ",s);
	DFS(s,n);
}

void DFS(int s,int n){
	visited[s] = 1;
	
	int i;
	for(i=1;i<=n;i++){
		if(G[s][i]){
			if(!visited[i]){
				visited[i] = 1;
				printf("%d(%d) ",i,G[s][i]);
				DFS(i,n);
			}
		}
	}
	if(i>n){
		return;
	}
}

void BFSbegin(int s,int n){
	memset(vqueue,0,sizeof(vqueue)); 
	memset(visited,0,sizeof(visited));
	vqhead = 1;
	vqtail = 1;	
	vqueue[vqtail] = s;
	visited[s] = 1;
	vqtail++;
	printf("%d ",s);
	BFS(s,n);
} 

void BFS(int s,int n){
	if(vqhead > n){
		return;
	}
	vqhead++;
	
	int i;
	for(i=1;i<=n;i++){
		if(G[s][i]){
			if(!visited[i]){
				visited[i] = 1;
				vqueue[vqtail] = i;
				printf("%d(%d) ",i,G[s][i]);
				vqtail++;
			}
		}
	}
	int head = vqueue[vqhead];
	BFS(head,n);
}

