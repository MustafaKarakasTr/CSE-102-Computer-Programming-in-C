#include<stdio.h>
#include<string.h>
#include<math.h>

struct point {
	float x;
	float y;
	char name[2];
};
struct line{
	char name[3];
	struct point start;
	struct point end;
};
struct polygon_points{
	struct point vertices[20];//You made me sure about that there will be 20 vertices at most
	char name[3];
};
struct polygon_lines{
	struct line borders[20];
	char name[3];
};

void point(FILE *fp,int number_of_points,struct point points[]){
	float a,b;
	char t;
	char arr[20];	
	fscanf(fp,"%f",&(points[number_of_points].x));
	
	fscanf(fp,"%f",&points[number_of_points].y);
	fscanf(fp,"%s",points[number_of_points].name);
	
	while(t!='\n'){
		fscanf(fp,"%c",&t);
	}
	
}
void take_point(FILE *fp,char str[20],struct point points[100]){
	float x,y;
	int index;
	
	sscanf(str,"%f",&x);//str holds our point's x value 
	fscanf(fp,"%f",&y);// the next of x is y
	fscanf(fp,"%s",str);//Name of the point
	index=str[1]-'0';// for ex: str="P1"---> str[1]='1' I will put it points[1] to be able to access it later
	
	
	points[index].x=x;
	points[index].y=y;
	strcpy(points[index].name,str);
	}
void take_line(FILE *fp,char first_point[20],char second_point[3],char name[3],struct line lines[100],struct point points[100]){
	int index;
	int start;
	int end;
	
	sscanf(first_point+1,"%d",&start);//FOR EX:first_point="P1"---> first_point[1]=1
	sscanf(second_point+1,"%d",&end);//FOR EX:second_point="P2"--->second_point[1]=2
	sscanf(name+1,"%d",&index);//FOR EX:name="L12" --> index=12
	
	/* İf line is L12 index=12 so when we try to access L12 we will look at lines[12]*/	

	strcpy(lines[index].name,name);
	strcpy(lines[index].start.name,points[start].name);
	strcpy(lines[index].end.name,points[end].name);
	
	lines[index].start.x=points[start].x;
	lines[index].start.y=points[start].y;
	lines[index].end.x=points[end].x;
	lines[index].end.y=points[end].y;
}
void take_polygon_with_point(FILE *fp,char str[20],char str2[3],char str3[3],struct point points[100],struct polygon_points poly_point[100]){
	char temp[4];
	char iter='a';
	char vertices[60];//20*3 at most 20 vertices 60 is enough
	int index,i=0,index2,index_of_points=0;
	sprintf(vertices,"%s %s %s ",str,str2,str3);
	fscanf(fp,"%s",temp);

	while(temp[1]!='G'){// If we havent reach to the name of polygon,add Point to vertices
		temp[2]=' ';// I have to put space between points to be able to access it by sscanf
		strncat(vertices,temp,3);//It appends 3 character to the end of vertices
		fscanf(fp,"%s",temp);
	}
	
	/*When it quits loop temp holds name of polygon FOR EX:temp="PG1" temp[2]='1' it is our index*/ 
	index=temp[2]-'0';
	strcpy(poly_point[index].name,temp);
	while(iter!='\0'){
		iter=vertices[i];// vertices consist of name of point FOR EX:P1 P2 P3 
		if(iter>='0' && iter <='9'){//If vertices[i]=(index of one of the point)
			index2=iter-'0';
			strcpy(poly_point[index].vertices[index_of_points].name,points[index2].name);
			poly_point[index].vertices[index_of_points].x=points[index2].x;//When we created point struct,We put every point to the index which is taken from its name
			poly_point[index].vertices[index_of_points].y=points[index2].y;//So now we can go there and copy this values to the polygon struct
			index_of_points++;//To be able to save points polygon struct in the order they are given
		}
		i++;
	}
	
}
void take_polygon_with_line(FILE *fp,char str[20],struct point points[100],struct line lines[100],struct polygon_lines poly_lines[100],struct polygon_points poly_point[100]){
	int number_of_borders=0,index_of_polygon=0,iter=0,index_of_line,index_of_start,index_of_end;
	char p,g;
	char line_array[60]={'\0'};
	
	while(str[0]!='P'){//We read every line of polygon and save it in line_array
		str[3]=' ';
		strncat(line_array,str,4);
		number_of_borders++;// I holds number of borders
		fscanf(fp,"%s",str);
	}
	
	
	sscanf(str,"%c %c %d",&p,&g,&index_of_polygon);//FOR EX PG2 p='P' g='G' index_of_polygon=2
	strcpy(poly_point[index_of_polygon].name,str);
	
	while(iter<number_of_borders){
		sscanf(line_array+1+(iter*4),"%d",&index_of_line);/*Let's say :line array consist of "L12 L23" to be able to read numbers,our first index should be 1,second index should be 5 by this formula we can read them*/
		index_of_start=index_of_line/10;
		index_of_end=index_of_line%10;
		strcpy(poly_point[index_of_polygon].vertices[iter].name,points[index_of_start].name);
		poly_point[index_of_polygon].vertices[iter].x=points[index_of_start].x;
		poly_point[index_of_polygon].vertices[iter].y=points[index_of_start].y;
		iter++;
		strcpy(poly_point[index_of_polygon].vertices[iter].name,points[index_of_end].name);
		poly_point[index_of_polygon].vertices[iter].x=points[index_of_end].x;
		poly_point[index_of_polygon].vertices[iter].y=points[index_of_end].y;
		iter++;

		
	}
}

int data(FILE *fp,struct point points[100],struct line lines[100],struct polygon_points poly_point[100],struct polygon_lines poly_lines[100]){
	
	int num_of_input,counter=0;
	char str[20],str2[3],str3[3],t;
	float y;
	
	fscanf(fp,"%d",&num_of_input);
	
	while(counter<num_of_input){
		fscanf(fp,"%s",str);//To determine if data is point or line or polygon...
		if((str[0]-'0'>=0 && str[0]-'0'<10) || str[0]=='-'){//If str[0] is number than data is point
			take_point(fp,str,points); 
			
		}
		else if(str[0]=='P'){// It could be line or polygon 
			fscanf(fp,"%s",str2);
			
			fscanf(fp,"%s",str3);
			
			if(str3[0]=='L')//If third string starts with L it is a line
				take_line(fp,str,str2,str3,lines,points);
			else if(str3[0]=='P')// If third string starts with P it is a polygon
				take_polygon_with_point(fp,str,str2,str3,points,poly_point);
			
		}
		else if(str[0]=='L'){//If the first character is 'L' then data is polygon  decleared by lines
			take_polygon_with_line(fp,str,points,lines,poly_lines,poly_point);
		}
		t='a';//to be able to go in while loop more than once
		while(t!='\n'){//To discard comments
			fscanf(fp,"%c",&t);
		}
		counter++;
	}
	
	
}
void distance(FILE *fp,FILE *fp2,struct point points[100]){
	float dist=0;
	char str[3],str2[3];
	float x1,y1,x2,y2;
	fscanf(fp,"%s",str);/* str="P1"---> str[1]='1' it is our index*/
	x1=points[(str[1])-'0'].x;
	y1=points[(str[1])-'0'].y;

	fscanf(fp,"%s",str2);
	if(str2[0]=='P'){//If second input is point,we fill find distance between two points
		x2=points[str2[1]-'0'].x;
		y2=points[str2[1]-'0'].y;
		dist=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));// Formula of distance between two points
		fprintf(fp2, "Distance(%s,%s)=%.1f\n",str,str2,dist);
	}
	else if(str2[0]=='L'){// If second input is line then we will find distance between the point and the line

	}
}
void angle(FILE *fp,FILE *fp2,struct line lines[100]){
	char str[4],str2[4];
	int index1,index2;
	float scalar_product;
	float lenght_of_line1;
	float lenght_of_line2;
	float x1,x2,y1,y2;
	float x3,x4,y3,y4;
	fscanf(fp,"%s",str);
	
	fscanf(fp,"%s",str2);

	sscanf(str+1,"%d",&index1);
	sscanf(str2+1,"%d",&index2);
	x1=lines[index1].start.x;
	y1=lines[index1].start.y;
	x2=lines[index1].end.x;
	y2=lines[index1].end.y;

	x3=lines[index2].start.x;
	y3=lines[index2].start.y;
	x4=lines[index2].end.x;
	y4=lines[index2].end.y;

	lenght_of_line1=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	lenght_of_line2=sqrt((x3-x4)*(x3-x4)+(y3-y4)*(y3-y4));
	scalar_product=(x2-x1)*(x4-x3)+(y2-y1)*(y4-y3);
	fprintf(fp2,"Angle(%s,%s)=%.1f\n",str,str2,acos(scalar_product/(lenght_of_line1*lenght_of_line2))*180/M_PI);
	
}
float between_two_points(struct polygon_points poly_point[100],int index,int i,int t){
	float x1=poly_point[index].vertices[t].x;
	float y1=poly_point[index].vertices[t].y;
	float x2=poly_point[index].vertices[i].x;
	float y2=poly_point[index].vertices[i].y;

	return (sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)));
}
void length(FILE *fp,FILE *fp2,struct line lines[100],struct polygon_points poly_point[100],struct polygon_lines poly_lines[100]){
 	char str[4];
 	float total=0,x1,x2,y1,y2;
 	int index=0,i=1,t=0 ;
	fscanf(fp,"%s",str);
	
	if(str[0]=='P'){
		
		sscanf(str+2,"%d",&index);
		
		if(!strcmp(poly_point[index].name,str)){
			
			while(poly_point[index].vertices[i].name[0]=='P'){   //If poly_point[index].vertices[0].name holds something relevant then this polygon consist of vertices
				
				total=total+between_two_points(poly_point,index,i,i-1);
				i++;
			}
			total=total+between_two_points(poly_point,index,0,i-1);
			fprintf(fp2,"Length(%s) = %0.1f\n",poly_point[index].name,total );
		}
	}
	else if(str[0]=='L'){
		sscanf(str+1,"%d",&index);
		if(!strcmp(lines[index].name,str)){
			x1=lines[index].start.x;
			y1=lines[index].start.y;
			x2=lines[index].end.x;
			y2=lines[index].end.y;
			total=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
			fprintf(fp2,"Length(%s) = %f\n",str,total);
		}

	}
}
void area_of_poly_point(FILE *fp2,struct polygon_points poly_point[100],int index_of_polygon){
	int i=1;
	float total=0;
	while(poly_point[index_of_polygon].vertices[i].name[0]=='P'){
		total=total+(poly_point[index_of_polygon].vertices[i-1].x)*(poly_point[index_of_polygon].vertices[i].y);
		i++;		
	}
	i=1;
	while(poly_point[index_of_polygon].vertices[i].name[0]=='P'){
		total=total-(poly_point[index_of_polygon].vertices[i-1].y)*(poly_point[index_of_polygon].vertices[i].x);
		i++;		
	}
	
	total=total-poly_point[index_of_polygon].vertices[0].x*poly_point[index_of_polygon].vertices[i-1].y;
	total=total+poly_point[index_of_polygon].vertices[0].y*poly_point[index_of_polygon].vertices[i-1].x;
	
	if(total<0)
		total=-total;

	while(poly_point[index_of_polygon].vertices[i].name[0]=='P'){
		i++;
	}

	fprintf(fp2,"Area(%s) = %f\n",poly_point[index_of_polygon].name,total/2 );
}

void actions(FILE *fp,struct point points[100],struct line lines[100],struct polygon_points poly_point[100],struct polygon_lines poly_lines[100]){
	char str[20],a;
	int number_of_actions=0,i=0,index_of_polygon;
	fscanf(fp,"%s",str);
	FILE *fp2=fopen(str,"w");
	fscanf(fp,"%d",&number_of_actions);
	while(i<number_of_actions){

		fscanf(fp,"%s",str);
		
		if(!strcmp(str,"Distance")){//Distance between points is done || Distance between point and line is not
			distance(fp,fp2,points);
		}
		else if(!strcmp(str,"Angle")){//It calculates angle between 2 lines
			angle(fp,fp2,lines);
		}
		else if(!strcmp(str,"Length")){//Length of line is done || polygon with vertices is done 
			
			length(fp,fp2,lines,poly_point,poly_lines);
		}
		else if(!strcmp(str,"Area")){
			fscanf(fp,"%s",str);
			sscanf(str+2,"%d",&index_of_polygon);
			if(!strcmp(poly_point[index_of_polygon].name,str)){			
				area_of_poly_point(fp2,poly_point,index_of_polygon);
			}
		}
		a='a';
		while(a!='\n'){
			fscanf(fp,"%c",&a);
		}
		i++;
	}
	fclose(fp2);
}
void main(){
	char str[20];
	struct point points[100];
	struct line lines[100];
	struct polygon_points poly_point[100];
	struct polygon_lines poly_lines[100];
	float a;
	FILE *fp=fopen("commands.txt","r");
	fscanf(fp,"%s",str);
	if(!strcmp(str,"data"))
		data(fp,points,lines,poly_point,poly_lines);
	fscanf(fp,"%s",str);
	if(!strcmp(str,"actions")){
		actions(fp,points,lines,poly_point,poly_lines);
	}
	printf("Results have been written to 'outputs.txt'.\n");
	fclose(fp);
}

