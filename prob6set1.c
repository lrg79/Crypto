#include <stdio.h>
int hamming(char *array, char *array1, int length){
	int hamming = 0;

	for(int i = 0; i < length; i++){
		char c = array[i];
		char c1 = array1[i];
		for(int j = 0; j < 8; j++){
			char tmp = 1 << j;
			int bit1 = (c1 & tmp)>>j;
			int bit = (c & tmp)>>j;
			if(bit1 != bit){
				hamming++;
			}
			bit = bit>>1;
			bit1 = bit1>>1;
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
