#include <stdio.h>

int main(){

	char toEncrypt[] = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
	char encrypted[sizeof(toEncrypt)-1];
	char xor[] = "ICE";

	for(int i = 0; i < sizeof(toEncrypt)-1; i++){
		char c = toEncrypt[i];
		printf("%c", c);
		int index = i%(sizeof(xor)-1);
		char c1 = xor[index];
		encrypted[i] = c1 ^ c;
	}

	for(int i = 0; i < sizeof(encrypted)-1; i++){
		printf("%c", encrypted[i]);
	}				
	return 0;
}
