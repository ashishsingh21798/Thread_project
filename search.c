#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <math.h>
#include <string.h>
#include <fcntl.h>
#include <stdbool.h>

char keyword[20];

void  search_key(char buffer[])
{

 
  int i,j=0,count=0;
  int buff_len,key_len;
  

  buff_len=strlen(buffer);
  key_len=strlen(keyword);
  //printf("%d\n",buff_len );
  //printf("%d\n",key_len );
  //printf("%s\n", buffer);
  
    
      for(i=0;i<key_len;i++)
      {
      while(j<buff_len)
    { 
      //printf("%d\n", 4);
      if(keyword[i]==buffer[j])
      {
          count++;
          j++;
          break;
        }
      else{        
        j++;
        i=0;
        count=0;
      }
      }
    }
    if(count==key_len){
      printf("yoo!!..word found...\n");
    }
    else{
      printf("not found...\n");
    }
    }
  /*for(i=0;i<key_len;i++){
    while(j<buff_len && !isspace(buffernew[i+1])){
      if(keyword[i]==buffernew[j]){
        i++;
        count++;
        j++;
      }
      else{
        if(isspace(buffernew[j]) && count==key_len){
          printf("full word find\n");
          break;
        }
        else{
          printf("%d char found\n",count);
          break;
        }
      }
    }
  }
}*/
/*if(i==0)
  {
    for(i=0,j=0;i<buff_len && j<key_len ;i++)
    {
      if(keyword[j]==buffernew[i] && buffernew[i] !="\0")
      {

        count++;
        if(count==key_len)
        {
          printf("keyword found without space\n");
          break;
        }

      }

    }
  }
  else
  {
    for(i=0,j=0;i<buff_len && j<key_len ;i++)
    {
      if( buffernew[i-1]=="\0" && keyword[j]==buffernew[i] && buffernew[i] !="\0")
      {
        count++;
        if(count==key_len)
        {
          printf("keyword found with space\n");
          break;
        }
      }
    }
  }

     // else
     //   printf("keyword find in file\n");
}
  if(flag)
  {
    printf("found\n");
    printf("%d\n",j);
  }

*/

int main(int agrc,char *argv[])
{
	//int w;
	//char keyword[20];
	printf("Enter keyword to search\n");
	scanf("%s",&keyword);

	int fd;
	//char *path;
	//path=argv[1];
	fd=open("/home/ashish/project2/ashish.txt",O_RDWR);

  char buffer[10000];
/*	fseek(fd,0,SEEK_END);


	long filelen;
	char * buffer;
	filelen=ftell(fd);
	printf("file lenght=%ld\n",filelen);
	rewind(fd);
	buffer=(char *)malloc((filelen+1)*sizeof(char));
	//fread(buffer,filelen,1,fd);
	//printf("%s\n",buffer);
	//printf("length of buffer=%d\n",strlen(buffer+1));
  */
  //buffer=(char *)malloc((filelen+1)*sizeof(char));

  //pthread_t tid;

  int j=1;

  int count=1,i=0;
  int w=0;
  char ch;
  while(count)
  {
   // buffer=realloc(buffer,1);
    count=read(fd,&ch,1);
    if(ch==' ' || ch=='\n') 
        w++;
    buffer[i]=ch;
    //printf("%s\n", buffer);
    i++;
  }
  // printf("%s\n", buffer);
    search_key(buffer);
    /*if(w==j*100){

      pthread_create(&tid,NULL,&search_key,(void *)buffer);
        j++;
    }
    i++;
  }
 // printf("buffer=%s\n",buffer);*/
    printf("word=%d\n",w);
      
	
	return 0;

}
