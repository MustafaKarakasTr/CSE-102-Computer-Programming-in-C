#include<stdio.h>

int sum(int n,int flag);
int mult(int n,int flag);

int main(){
	int a,b,c;
	printf("Enter an integer:");
	scanf("%d",&a);
	printf("Please enter '0' for sum,'1' for multiplication:");
	scanf("%d",&b);
	printf("Please enter '0' to work on even numbers, '1' to work on odd numbers:");
	scanf("%d",&c);
	switch(b){
		case 0:
			sum(a,c);
			break;
		case 1:
			mult(a,c);
			break;
		default:
			printf("Unsupported operation.\n");
			break;
			}
	return 0;	
	}

int sum(int n,int flag){
	int i,sumOfNumbers=0;
	switch(flag){
		case 0:
			i=2;//If user wants to see even numbers
			break;
		case 1:
			i=1;//If user wants to see odd numbers
			break;
		default:
			printf("Invalid value for odd/even selection.\n");
			i=n*10;//I will check it at the end of the function
			break;

	}
	if(n!=0){	
		for(;i<=n;i+=2){
			printf("%d",i);
			if(i<n-1){
			printf("+");
			}
			else{
				printf("=");
			}
			sumOfNumbers=sumOfNumbers+i;
		}
	}
	if(i!=10*n || sumOfNumbers==2){
	printf("%d\n",sumOfNumbers);
	}
	return 0;
}
int mult(int n,int flag){
	int i,mulOfNumbers=1;
	switch(flag){
		case 0:
			i=2;
			break;
		case 1:
			i=1;
			break;
		default:
			printf("Invalid value for odd/even selection.\n");
			i=n*10;//Now i is bigger than n so it won't enter the for loop.İf n is not equal 0
			break;
	}
	if(n==0){
		i=0;
		mulOfNumbers=0;
	}
	if(n!=0 && i!=0){
	for(;i<=n;i+=2){
		printf("%d",i);
		if(i<n-1){
		printf("*");
		}
		else{
			printf("=");
		}
		mulOfNumbers=mulOfNumbers*i;
	}
	}
	if(i!=10*n || i==0){//It checks if flag was invalid  or not.
		if(n==1 && i==2){
			mulOfNumbers=0;	
		}
		printf("%d\n",mulOfNumbers);
	}
	return 0;
}
