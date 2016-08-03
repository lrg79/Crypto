#include <stdio.h>
int hamming(char *array, char *array1, int length){
	int hamming = 0;
	for(int i = 0; i < length * 8; i++){
		int bit1 = (array[i/8] >> i) & 1;
		int bit2 = (array1[i/8] >> i) & 1;
		printf("%d %d", bit1, bit2);
		if(bit1 != bit2){
			hamming++;
		}
	}

	return hamming;
}

int main(){
	char array[] = "this is a test";
	char array1[] = "wokka wokka!!!";
	int distance = hamming(array, array1, sizeof(array)-1);
	printf("%d", distance);
	return 0;
}
