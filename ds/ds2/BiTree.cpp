//-------------- ��ʽ������ --------------
//-------- ������ 13720192200474 --------

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Type char //���ַ��ͽ��д洢

using namespace std;
 

//-------- ��ʵ��Ҫ����Ķ������ṹ --------
typedef struct BiTNode
{
	Type data;  //������Type: �û�������������
	struct BiTNode *Lchild;  //��ָ����
	struct BiTNode *Rchild;  //��ָ����
} BiTNode, *BiTree;



//---------------- �������� ---------------- 
int TreeInit(BiTree &T);
int TreeCreat(BiTree &T);
int TreeDepth(BiTree); 
int TreePrint(BiTree); 

int PreOrder(BiTree T);
int InOrder(BiTree T);
int PostOrder(BiTree T);

int Visit(BiTree T){
	Type value = T->data;
	printf("%c ",value);
	return 1;
}


//ȫ�ֱ���
string s_tree;
int TCk = 0;



//---------------- ������ ---------------- 
int main(){
	freopen("BiTreein.txt","r",stdin);
	BiTree root;
	TreeInit(root);
	
	cout<<"�������ַ���ʽ��ʾ�Ķ�������";
	
	//��������1��A(B(,b),C(D(d,),c))
	
	cin>>s_tree;
//	cout<<s_tree<<endl;
	
	TreeCreat(root);//creatǰҪ��TCk��0 
	root = root->Lchild;
	
	cout<<"�����������"; 
	TreePrint(root);
	cout<<endl; 
	
	cout<<endl<<"���������"; 
	PreOrder(root);
	
	cout<<endl<<"���������";
	InOrder(root);
	
	cout<<endl<<"���������";
	PostOrder(root);
	cout<<endl;
	
	printf("�����߶�Ϊ��%d\n",TreeDepth(root));
	
	return 0;
}



//---------------- �����Ǻ�������ʵ�� ---------------- 
int TreeInit(BiTree &T){
	T = (BiTree) malloc (sizeof(BiTNode));
	if (!T)
	{
		return 0;
	}
	T->Lchild = NULL;
	T->Rchild = NULL;
	return 1;
}

int isA(char c){
	if(c >= 'a' && c <= 'z'){
		return 1;
	}
	if(c >= 'A' && c <= 'Z'){
		return 1;
	}
	return 0;
}


int TreeCreat(BiTree &father){
	BiTree q;
	
	while(s_tree[TCk] != '\0'){
		Type c = s_tree[TCk];
		if(isA(c)){
			BiTree p;
			TreeInit(p);
			p->data = c;
			if(TCk-1 >= 0 && s_tree[TCk-1] == ','){
				father->Rchild = p;
			}
			else{
				father->Lchild = p;
			}
			TCk++;
			q = p;
		}
		else switch(c){
			case '(':{
				TCk++;
				TreeCreat(q);
				break;
			}
			case ')':{
				TCk++;
				return 1;
				break;
			}
			default:{
				TCk++;
				break;
			}
		}
	}
} 

int TreePrint(BiTree father){
	if(father){
		printf("%c",father->data);
		if(father->Lchild || father->Rchild){
			printf("(");
			if(father->Lchild){
			//	printf("%c",father->Lchild->data);
				TreePrint(father->Lchild);
			}
			printf(",");
			if(father->Rchild){
			//	printf("%c",father->Rchild->data);
				TreePrint(father->Rchild);
			}
			printf(")");
			return 1;
		}
		else{
			return 0;
		} 
		return 1;
	}
	return 0;
} 

int TreeDepth(BiTree T){
	if(!T)
	{
		return 0;
	}
	int l = TreeDepth(T->Lchild);
	int r = TreeDepth(T->Rchild);
	
	if (r > l)	l = r;
	
	return l+1;
}

int PreOrder(BiTree T){
	if(!T){
		return 0;
	}
	Visit(T);
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
	return 1;
}

int InOrder(BiTree T){
	if(!T){
		return 0;
	}
	InOrder(T->Lchild);
	Visit(T);
	InOrder(T->Rchild);
	return 1;
}

int PostOrder(BiTree T){
	if(!T){
		return 0;
	}
	PostOrder(T->Lchild);
	PostOrder(T->Rchild);
	Visit(T);
	return 1;
}