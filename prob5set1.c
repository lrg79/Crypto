#include <stdio.h>

int main(){

	char toEncrypt[] = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
	char encrypted[sizeof(toEncrypt)-1];

	for(int i = 0; i < sizeof(toEncrypt)-1; i++){
		char c = toEncrypt[i];
		char c1;
		if(i%3 == 0){
			c1 = c ^ 'I';
		}
		else if(i%3 == 1){
			c1 = c ^ 'C';
		}
		else if(i%3 == 2){
			c1 = c ^ 'E';
		}
		encrypted[i] = c1;
	}

	for(int i = 0; i < sizeof(encrypted)-1; i++){
		printf("%c", encrypted[i]);
	}				
	return 0;
}
