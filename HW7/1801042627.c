#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void menu(float arr[2000][7],char names[2000][100],char genre[15][20],char platform[10][20]){
	int q,year,untilSince,i,t,flag=0,gen,plat,flag2=0,d=0,numofGenre[12],numofPlatform[10],p;
	char a,game[100];
	float average=0;
	for(p=0;p<sizeof(numofGenre)/sizeof(numofGenre[0]);p++){
		numofGenre[p]=0;
	}
	for(p=0;p<sizeof(numofPlatform)/sizeof(numofPlatform[0]);p++){
		numofPlatform[p]=0;
	}
	
	while(a!='8'){
	
	printf("0: List of the Genres\n1: List of the Platforms\n");
	printf("2: List of the Games Through the Years\n3: All Informations of a Single Game\n");
	printf("4: Average of the User Scores\n5: Georographical Information of a Single Game\n");
	printf("6: Frequence of the Genres\n7: Frequence of the Platforms\n8: Exit\n\nPlease select an operation:");
	scanf(" %c",&a);
	printf("\n");
	switch(a){
		case '0':
			for(q=0;q<12;q++){
				printf("%s\n",genre[q]);
			}
			printf("\n");
			break;

		case '1':
			for(q=0;q<10;q++){
				printf("%s\n",platform[q]);
			}
			printf("\n");
			break;
		case '2':
			i=0;
			while(i==0){
			printf("Enter a year:\n");
			scanf("%d",&year);
			printf("Until (0) or Since (1) %d:",year);
			scanf("%d",&untilSince);
			printf("\n");
			
			if(untilSince==0){
				if(year<1986){
					printf("TRY AGAIN\n\n");
				}
				else{
					i=0;
					while(arr[i][2]<year && i<2000){/*We do not want to go too far so I added i<2000*/
						printf("%s\n",names[i]);
						i++;
					}
				}
			}
			else if(untilSince==1){
				if(year>2005){
					printf("TRY AGAIN\n");
				}
				else{
					i=0;
					while(arr[i][2]<year){
						i++;
					}
					while(arr[i][2]>=year){
						printf("%s\n",names[i]);
						i++;
					}	
				}
			}
			}
			printf("\n");
			break;

		case '3':
			while(flag==0){
			printf("Please enter the name of the game:\n");
			scanf("%s",game);
			t=0;
			flag=0;
			while(t<=2000 && flag==0){
				if(strcmp(game,names[t])==0){
					gen=(int)arr[t][0];
					plat=(int)arr[t][1];
					flag=1;
					printf("Name:    \t%s\n",names[t]);
					printf("Genre:   \t%s\n",genre[gen]);
					printf("Platform:\t%s\n",platform[plat]);
					printf("Year:    \t%.0f\n",arr[t][2]);
					printf("Sales In NA:\t%f\n",arr[t][3]);
					printf("Sales In EU:\t%f\n",arr[t][4]);
					if(arr[t][5]==0)
						printf("Total Sales:\tNot Available\n");
					else
						printf("Total Sales:\t%f\n",arr[t][5]);
					printf("User Score:\t%f\n\n",arr[t][6]);

				}
				t++;
			}
			if(flag==0){
				printf("This game does not exist\n\n");
			}
			}
			flag=0;
			break;

			case '4':
				t=0;
				average=0;
				while(t<=2000){
					average=average+arr[t][6];
					t++;
				}
				printf("Average:%f\n\n",average/2000);
				break;

			case '5':
				flag2=0;
				t=0;
				d=1;
				while(flag2==0){
					t=0;
					printf("Please enter the name of the game:\n");
					scanf("%s",game);
					while(t<=2000){
						d=strcmp(game,names[t]);
						
						if(d==0){
							flag2=1;
							break;
						}
						else{
							t++;
						}
					}
					if(t<2001){
				if(arr[t][3]+0.01>arr[t][4] && arr[t][3]-0.01<arr[t][4])
					printf("This game's popularity equals in Europa and North America\n\n");
				else if(arr[t][3]>arr[t][4])
					printf("This game is more popular in North America\n\n");
				else if(arr[t][3]<arr[t][4])
					printf("This game is more popular in Europe\n\n");
				}
				}
				break;
			case '6':
				for(p=0;p<sizeof(numofGenre)/sizeof(numofGenre[0]);p++){/*to calculate numbers of them everytime We clear them*/
					numofGenre[p]=0;
				}
				
				t=0;
				while(t<2000){
					numofGenre[(int)arr[t][0]]++;
					t++;
				}
				for(t=0;t<12;t++){
					if(t==4){
						printf("%s:\t%d\n",genre[t],numofGenre[t] );/*role playing is to much long and it ruins my order,if and else are only for it*/
					}
					else{
					printf("%s:    \t%d\n",genre[t],numofGenre[t]);
					}
				}
				printf("\n");
				break;

				case '7':
					t=0;
					for(p=0;p<=sizeof(numofPlatform)/sizeof(numofPlatform[0]);p++){/*to calculate numbers of them everytime We clear them*/
						numofPlatform[p]=0;
				}
					while(t<2000){
						numofPlatform[(int)arr[t][1]]++;
						t++;
				}
				for(t=0;t<10;t++){
					printf("%s:\t%d\n",platform[t],numofPlatform[t]);
					
				}
				printf("\n");
				break;
		}
	}
	
	
		
		
	
}
void ArrayofTypes(char str[][20],int *a){//It is used for genre and platform
	int q;	
	for(q=0;q<*a;q++)
		{
			if(strcmp(str[q],str[*a])==0){//If there is this element already in array we wont take it
				strcpy(str[*a],"\0");//I make it empty
				(*a)--;//It helps to take this index again
				break;// We dont have to check other elements	
			}
		}
}
void main(){
	int d,r,t=0,q,y=0,u=0,o=0,n=0;
	float arr[2000][7],Year_of_Release;
	FILE *fp=fopen("Video_Games.txt","r");
	char c[101],all[2000][101],names[2000][100],a,genre[15][20],platform[10][20],genretemp[20],platformtemp[20],not_available[15];	
	d=fscanf(fp,"%s",c);
	//while(d!=EOF){
	while(y<2000){	
		r=0;
		d=fscanf(fp,"%s",c);
		for(q=0;q<strlen(c);q++){
			if(c[q]==',')//To use sscanf I need spaces between elements" IF THERE IS COMMA MAKE IT SPACE"
				c[q]=' ';
		}
		sscanf(c,"%s %s %s %f %f %f %f %f",names[y],genre[u],platform[o],&arr[y][2],&arr[y][3],&arr[y][4],&arr[y][5],&arr[y][6]);
		
		if(arr[y][5]==0){/*It means that global_sales is not available because of that we cannot know what is user_score we'll find out that*/
			sscanf(c,"%s %s %s %f %f %f %s %f",names[y],genre[u],platform[o],&arr[y][2],&arr[y][3],&arr[y][4],not_available,&arr[y][6]);
			//printf("%s not available\n",names[y]);		
		}
		
		/*
		arr[y][2] holds value of 'Year_of_Release'
		arr[y][3] holds value of 'na_sales'
		arr[y][4] holds value of 'eu_sales'
		arr[y][5] holds value of 'global_sales'
		arr[y][6] holds value of 'user_score'
		*/
		strcpy(genretemp,genre[u]);
		strcpy(platformtemp,platform[o]);
		ArrayofTypes(genre,&u);
		ArrayofTypes(platform,&o);
		for(q=0;q<y;q++){
			if(strcmp(genretemp,genre[q])==0){
				arr[y][0]=q;
				
			}
		}
		for(q=0;q<y;q++){
			if(strcmp(platformtemp,platform[q])==0){
				arr[y][1]=q;
				
			}
		}		
		u++;
		y++;
		o++;
		
	/*printf("names[%d]:%s\n",n,names[n]);
	n++;*/
	
	}
	/*for(q=0;q<12;q++){
		printf("%s %f \n",names[q],arr[q][1]);	
	}*/
	/*printf("Dongunun disinda:%s",names[0]);
	printf("Dongunun disinda:%s",names[y-1]);*/
	
		
	fclose(fp);
	menu(arr,names,genre,platform);
}
