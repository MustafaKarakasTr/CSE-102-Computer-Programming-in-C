#include<stdio.h>
#include<math.h>

int isprime(int a);

int main(){
	int a,i,divider;
	printf("Please enter an integer:");
	scanf("%d",&a);
	for(i=2;i<a;i++){
		divider=isprime(i);
		if(divider!=0){//If return value is 0 it means number is prime otherwise return value equals first divisor
			printf("%d is not a prime number. It is divisible by %d\n\n",i,divider);			
		}
		else{
			printf("%d is a prime number.\n\n",i);
		}
	}
	return 0;
}
int isprime(int a){
	int i,flag=0;
	for(i=2;i<=sqrt(a);i++){
		if(a%i==0){
			flag=i;
			i=a; //I used it to go out of loop without using break
		}
	}
	return (flag);// flag=0 if a is prime, otherwise least divisor of a
}
