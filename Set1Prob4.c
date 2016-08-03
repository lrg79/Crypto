#include <stdio.h>
#include <stdlib.h>

int highest = 0;
char highString[30];

int scoreCount(char *array){

	char hexvals[(sizeof(array)-1)/2];
	char xored[(sizeof(array)-1)/2];

	for(int i = 0; i < sizeof(array); i+=2){
		 sscanf(&array[i], "%02hhx", &hexvals[i/2]);
	}

   for(int i = 0; i <= 127; i++){
      int score = 0;
      for(int j = 0; j < sizeof(hexvals); j++){
         char c1 = i ^ hexvals[j];
         xored[j] = c1;
         if(((c1 >= 65 && c1 <= 90) || (c1 == 32 )|| (c1 >= 97 && c1 <= 122))){
            score++;
         }
      }
      if(score >= highest-1){
         for(int a = 0;a<sizeof(hexvals);a++)printf("%c",xored[a] );
         highest = score;
     	 for(int b = 0; b < sizeof(highString); b++){
     	 	highString[b] = xored[b];
     	 }
      }
   }
}

int main(){
	FILE *file = fopen("text.txt", "r");
	char buff[60];
	while(fgets(buff, 60, file)){
		scoreCount(buff);
	}
	fclose(file);

	for(int i = 0; i < sizeof(highString)-1; i++){
		printf("%c", highString[i]);
	}
}	
