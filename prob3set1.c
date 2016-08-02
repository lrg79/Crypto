#include <stdio.h>
#include <stdbool.h>

int main(){
	char encrypted[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
	int a = 33;
	char hexvals[sizeof(encrypted)-1];
	char xored[sizeof(encrypted)-1];
	//store so is hexadecimal values
	for(int i = 0; i < sizeof(xored)-1; i++){
		 sscanf(&encrypted[i], "%01hhx", &hexvals[i]);
	}

	printf("%x", hexvals);
	
	while(a<=126){
		int boolean = 1;
		
		char c = a; //turning int into ascii

		//xoring items in encrypted with char c
		// and storing into xored
		for(int i = 0; i < sizeof(encrypted)-1; i++){
			char c1 = encrypted[i] ^ c;
			sscanf(&xored[i], "%c", &c1);
		}

		//checking if all english
		for(int i = 0; i < sizeof(xored)-1; i++){
			int a = xored[i];
			if(!((a > 32) && (a < 91))){
				boolean = 0;
			}
		}

		if(boolean == 1){
			printf(xored);
			a = 126;
		}else{
			a++;
		}
	}
	return 0;
}