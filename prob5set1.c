#include <stdio.h>

int main(){

	char toEncrypt[] = "Burning 'em, if you ain't quick and nimble I go crazy when I hear a cymbal";
	char encrypted[sizeof(toEncrypt)-1];
	char xor[] = "ICE";

	for(int i = 0; i < sizeof(toEncrypt)-1; i++){
		int index = i%(sizeof(xor)-1);
		char c1 = xor[index];
		printf("%c", c1);
		encrypted[i] = c1 ^ toEncrypt[i];
	}

	for(int i = 0; i < sizeof(encrypted)-1; i++){
		printf("%x", encrypted[i]);
	}

	return 0;
}
