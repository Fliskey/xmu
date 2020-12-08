#include <stdio.h>
#include <stdlib.h>

int A[1004];

int cmp(const void *x,const void *y){
    return *(int*)x-*(int*)y;
}

int search(int left,int right,int *arr,int *target){
    int mid = (left + right) / 2;
    int value = *target - arr[mid];
    if(!value){
        return mid;
    }
    else if(left > right)
        return -1;
    else if(value > 0)
        return search(mid+1,right,arr,target);
    else
        return search(left,mid-1,arr,target);
}

int main(){
    int n;
    printf("����������Ԫ�ظ�����");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("%d. ",i+1);
        scanf("%d",&A[i]);
    }
    printf("����ǰ���飺");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    qsort(A,n,sizeof(int),cmp);
    printf("��������飺");
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }
    printf("\n");

    int x;
    printf("����������ҵ�����");
    scanf("%d",&x);
    int value = search(0,n,A,&x);
    if(value == -1){
        printf("δ�ҵ�������");
    }
    else{
        printf("����λ��Ϊ��%d",value+1);
    }
    return 0;
}