#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define NUMBEROFFACES 13
#define NUMBEROFSUITS 4
#define NUMBEROFCARDS 52

struct card{
	const char *face;
	const char *suit;
}cards[52];

struct Hospital{
	char * name;
	char citiesServed[3];
};
int filled(struct Hospital results[4],char _cities[6],int index){
	int i=0,k=0,flag=0;
	
	if(index==6){
		return 1;
	}
	for(i=0;i<4;i++){
		for(k=0;k<3;k++){
			if(results[i].citiesServed[k]==_cities[index]){
				flag=1;
				break;
			}
		}
		
	}
		if(flag==1){
			
			filled(results,_cities,index+1);

		}
		else if(flag==0){
		    return 0;
		}
		
	

}

int is_it_taken(char locations[4][3],int numHospitals,int index,struct Hospital results[4]){
	int i,flag=1;

	if(numHospitals==3)
		return 1;
	
	if(locations[index][1]==results[numHospitals+1].citiesServed[1])//In the locations every[i][1] is different from each other checking them is enough to see if this city is covered before
		return 0;

	is_it_taken(locations,numHospitals+1,index,results);
}
int canOfferCovidCoverage(char _cities[6],char _locations[4][3],int _numHospitals,struct Hospital results[4]){
	int i,k,j;
	
	if(_numHospitals==0)
		return filled(results,_cities,0);

	/*if(_numHospitals>1 && filled(results,_cities,0)){
		printf("We can not afford this much\n");
		return 0;
	}*/
	if(_numHospitals>4)
	{
		return -1;
	}
	else {
	
	if(is_it_taken(_locations,(_numHospitals-1)%4,0,results)){
		for(i=0;i<3;i++){
			results[_numHospitals-1].citiesServed[i]=_locations[0][i];
		}
		canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	
	if( filled(results,_cities,0))
		return 1;
	}
	if(is_it_taken(_locations,(_numHospitals-1)%4,1,results)){
	for(i=0;i<3;i++){
		results[_numHospitals-1].citiesServed[i]=_locations[1][i];
	}
	canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	if( filled(results,_cities,0))
		return 1;
	}
	if(is_it_taken(_locations,(_numHospitals-1)%4,2,results)){
	for(i=0;i<2;i++){
		results[_numHospitals-1].citiesServed[i]=_locations[2][i];
	}
	canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	if( filled(results,_cities,0))
		return 1;
}
	if(is_it_taken(_locations,(_numHospitals-1)%4,2,results)){
	for(i=0;i<3;i++){
		results[_numHospitals-1].citiesServed[i]=_locations[3][i];
	}
	canOfferCovidCoverage(_cities,_locations,_numHospitals-1,results);
	if( filled(results,_cities,0))
		return 1;
	}
}
}
int numPathsHome(int street,int avenue){
	if(street==1 && avenue==1)
		return 1;
	if(street>1 && avenue>1){
		
		return numPathsHome(street-1,avenue)+numPathsHome(street,avenue-1);
	}
	else if(street>1 && avenue==1)
		return numPathsHome(street-1,avenue);
	else if(avenue>1 && street==1)
		return numPathsHome(street,avenue-1);
}
void part3(){
	char suits[NUMBEROFSUITS][10]={"Hearts","Diamonds","Clubs","Spades"};
	char faces[NUMBEROFFACES][10]={"Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Quenn","King"};
	int temp[NUMBEROFCARDS]={0},flag=1;// temp will hold number of cards displayed
	int i=0,y,x=0,a,b;
	srand(time(NULL));
	for(y=0;y<NUMBEROFCARDS;y++){
		cards[y].suit = suits[x];
		cards[y].face = faces[i];
		x++;
		if(x==NUMBEROFSUITS){
			i++;
			x=0;
		}
	}
		for(i=0;i<NUMBEROFCARDS;i++){
			//printf("%d\n",i);
			x=rand()%NUMBEROFCARDS;
			a=x;
			b=x;
			if(temp[x]==1){
				while(temp[a]==1 && temp[b]==1){
					while(a<51 && temp[a]==1)//a checks numbers bigger than x
						a++;
					if(temp[a]==1){
						while(b>0 && temp[b]==1)//b checks numbers smaller than x
							b--;
					}
					if(temp[a]==0)
					{
						flag=1;
						b=a;
						break;
					}
					else if(temp[b]==0)
					{
						flag=1;
						a=b;
						break;
					}
				}
				x=a;//a is the value which is not visited yet
			}
			if(flag==1){
				
				printf("   %s of %s \t",cards[x].face,cards[x].suit);
				if(i%2==0)
					printf(" \t");
				else
					printf("\n");
				temp[x]=1;

				//printf("\t\t %d\n",x );
			}
			else
				i--;
			flag=1;

		
	
		
}
	/*for(i=0;i<NUMBEROFCARDS;i++)
		printf("%s of %s\t\t %s of %s \n",cards[i].face,cards[i].suit);
	*/	
}

void menu(){
	char choice='a';
	int street,avenue;
	int a,answer;
	int i=0,k;

	struct Hospital results[4];
	char cities[6]={'A','B','C','D','E','F'};
	char locations[4][3]={{'A','B','C'},{'A','C','D'},{'B','F'},{'C','E','F'}};

	
	
	while(choice!='4'){
		printf("\nWELCOME TO 9. HOMEWORK\n\n");
		printf("1-)Part 1\n");
		printf("2-)Part 2\n");
		printf("3-)Part 3\n");
		printf("4-)Exit\n");
		printf("\nPlease make your choice:");
		scanf(" %c",&choice);
		switch(choice){
			case '1':
				printf("\nEnter the street number:");
				scanf("%d",&street);
				printf("Street:%d\n\n",street);
				printf("Enter the avenue number:");
				scanf("%d",&avenue);
				printf("Avenue:%d\n\n",avenue);
				printf("Number of optimal paths to take back home:%d\n",numPathsHome(street,avenue));
				break;
			case '2':
				printf("Enter the maximum number of hospitals that can be constructed:");
				scanf("%d",&a);
				answer=canOfferCovidCoverage(cities,locations,a,results);
				if(answer==1){
					for(i=0;i<a;i++){
						printf("Hospital-%d\nHospital locations:",i+1 );
						for(k=0;k<3;k++){
							if(results[i].citiesServed[k]>=65 && results[i].citiesServed[k]<71){//This borders here to avoid BF's third character
								printf("%c",results[i].citiesServed[k] );
								
						}
						
					}
					printf("\n");
					}
				}
				else if (answer==0)
						printf("No,some cities is not covered\n");	
				else if(answer==-1)
						printf("We can not afford for %d hospitals\n",a );

				for(i=0;i<4;i++){
					for(k=0;k<3;k++){
							results[i].citiesServed[k]='\0';//to make struct clear		
						}
				}
				break;

				case '3':
					part3();
					break;
		
	}
}
}
void main(){
	menu();
}
