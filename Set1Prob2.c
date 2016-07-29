#include <stdio.h>


int main(){
	char string[] = "1c0111001f010100061a024b53535009181c";
	char xored[] = "686974207468652062756c6c277320657965";
	char hexvals1[sizeof(string)-1];
	char hexvals2[sizeof(string)-1];

	for(int i = 0; i < sizeof(xored)-1; i++){
		 sscanf(&string[i], "%01hhx", &hexvals1[i]);
		 sscanf(&xored[i], "%01hhx", &hexvals2[i]); 
	}	
	
	for(int i = 0; i < sizeof(xored)-1; i++){
		char c1 = hexvals1[i];
		char c2 = hexvals2[i];

		printf("%x", c1 ^ c2);
	}


	return 0;
}
