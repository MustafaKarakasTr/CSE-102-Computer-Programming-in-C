#include<stdio.h>
int andop(int a,int b){
	int counter,tempa,tempb,sum,len=1,i;
	sum=0;
	i=1;
	tempa=a;
	counter=1;
	while(tempa>9){
		tempa=tempa/10;
		counter++;
	}
	tempa=a;
	tempb=b;
	while(tempa!=0){
		if((tempa%10==1) && (tempb%10==1)){
			sum=sum+(1*i);
		}
		i=i*10;//It increase the digit (For example tens to hundreds)
		tempa=tempa/10;
		tempb=tempb/10;
	}
	printf("%d AND %d = ",a,b);
	return (sum);
}
int main(){
	int a,t,b,x,error=0,flag=1,lena=1,lenb=1;
	while(flag==1){
		error=0;
		lena=1;
		lenb=1;
		printf("First integer:");
		scanf("%d",&a);
		t=a;
		printf("Second integer:");
		scanf("%d",&b);
		x=b;
		while(t>1){
			if(t%10==1 || t%10==0){
				t=t/10;
			}
			else{
				printf("Integers should be binary, Please enter 2 new integers\n");
				error=1;
				//break;
				t=1;
		}
	}
	while(x>1 && error==0){
		if(x%10==1 || x%10==0){
			x=x/10;
		}
		else{
			if(error==0){
			printf("Integers should be binary, Please enter 2 new integers\n");
			error=1;
			}
		}
	}
	if(error==0){
		t=a;//We used t to calculate length of a
		while(t>9){	
			t=t/10;
			lena++;
		}
		x=b;//We used x to calculate length of b
		while(x>9){	
			x=x/10;
			lenb++;
		}
		if(lena!=lenb){	
			printf("Integers should have the same length, please enter 2 new integers\n");
		}
		else{
			printf("%d\n",andop(a,b));
			return 0;	
		}
	}
	}	
}
