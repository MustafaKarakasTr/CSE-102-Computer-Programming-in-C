#include<stdio.h>
int main(){
float amount;
	int choice,choice2;
printf("*****Welcome to ABC Exchange Office*****\n");
	printf("Enter your amount:");
	scanf("%f",&amount);
	
	printf("Please select your currency\n1. Turkish Lira\n2. Euro\n3. Dollar\n");
	scanf("%d",&choice);
	
	switch(choice){
		case 1:
			printf("You have %f Turkish Liras\n",amount);
			break;
		case 2:
			printf("You have %f Euro\n",amount);
			amount=amount*(6.69);
			break;
		case 3:
			printf("You have %f Dollar\n",amount);
			amount=amount*6.14;
			break;
		default:
			printf("Your selection is invalid\n");
			return 0;//If selection is invalid there is no need to continue	
	}
	printf("Choose which currency you want to convert\n");
	scanf("%d",&choice2);
	switch(choice2){
		case 1:
			printf("You have %f Turkish Liras\n",amount);
			break;
		case 2:
			amount=amount/(6.69);
			printf("You have %f Euro\n",amount);
			break;
		case 3:
			amount=amount/(6.14);
			printf("You have %f Dollar\n",amount);
						
			break;
			
		default:
			printf("Your selection is invalid\n");
			return 0;	
	}
	return 0;
}
