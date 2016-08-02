#include <stdio.h>

int main(){
	char encrypted[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	char hexvals[(sizeof(encrypted)-1)/2];
	char xored[(sizeof(encrypted)-1)/2];

	for(int i = 0; i < sizeof(encrypted)-1; i+=2){
		 sscanf(&encrypted[i], "%02hhx", &hexvals[i/2]);
	}

   printf("%s", hexvals);
   int highest = 0;
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
         printf("\n");
         highest = score;
      }
   }
}
