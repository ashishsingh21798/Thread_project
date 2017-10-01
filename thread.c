#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <string.h>

char *keyword[20];
void * search_func(i) {
	i=(int)i;
	char * buf;

	 FILE *p; 
    char ch; 
    int w=1; 
  
    p=fopen("ashish","r"); 
    fseek(p,100,SEEK_SET);
    if(p==NULL) 
     { 
         printf("file not found"); 
      } 
    else 
      { 
          ch=fgetc(p); 
          while(ch!=EOF) 
                 { 
                 	i=0;
                       // printf("%c",ch); 
                        if(ch==' '||ch=='\n') 
                          { 
                               w++; 
                               if(w==100)
                               	break;
                               else
                               {
                               		buf=realloc(buf,i+1);
                               		buf[i]=ch;
                               		i++;
                               }
                          } 
                               ch=fgetc(p); 
                 } 

       	                        printf("\nWords in a file are=%d\n",w);
 								printf("buf is = %s",buf);      	        
     } 
                              fclose(p); 

	int j;
	for(j=i*100;j<(i+1)*100;j++){


	}

}
/*
int wordcount(char *buffer) 
{ 
  
    char ch; 
    int w=1; 
  
    
 

          ch=getc(buffer); 
          while(ch!=NULL) 
                 { 
                       // printf("%c",ch); 
                        if(ch==' '||ch=='\n') 
                          { 
                               w++; 
                          } 
                               ch=fgetc(p); 
                 } 
                               printf("\nWords in a file are=%d\n",w); 
      
                               
   return w;                         
}
*/

int wordcount() 
{ 
    FILE *p; 
    char ch; 
    int w=1; 
  
    p=fopen("ashish","r"); 
    fseek(p,100,SEEK_SET);
    if(p==NULL) 
     { 
         printf("file not found"); 
      } 
    else 
      { 
          ch=fgetc(p); 
          while(ch!=EOF) 
                 { 
                       // printf("%c",ch); 
                        if(ch==' '||ch=='\n') 
                          { 
                               w++; 
                          } 
                               ch=fgetc(p); 
                 } 
                             //  printf("\nWords in a file are=%d\n",w); 

     } 
                              fclose(p); 
   return w;                         
}



int main(int agrc,char *argv[])
{
	int w;
	//char keyword[20];
	printf("Enter keyword to search\n");
	scanf("%s",&keyword);

	FILE *fd;
	char *path;
	path=argv[1];
	fd=fopen(path,"r");
	fseek(fd,0,SEEK_END);


	long filelen;
	char * buffer;
	filelen=ftell(fd);
	printf("file lenght=%ld\n",filelen);
	rewind(fd);
	buffer=(char *)malloc((filelen+1)*sizeof(char));
	fread(buffer,filelen,1,fd);
	printf("%s\n",buffer);
	printf("length of buffer=%d\n",strlen(buffer+1));


	w = wordcount();
	int no_of_pth;
	no_of_pth=(int)ceil((double)w/100);
	printf("no of pth %d\n",no_of_pth);
	//no_of_pth+=1;



	/*int i;
	pthread_t pth[no_of_pth];
	for(i=0;i<no_of_pth;i++)
	{

		pthread_create(&pth[i],NULL,&search_func,(void *)i);
	}
	*/
	return 0;

}