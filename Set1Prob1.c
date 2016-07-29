#include <stdio.h>

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};

int main(){
	char string[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
	char check[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";
	char hexvals[sizeof(string)-1];
	char answer[(2 * (sizeof(string)-1))/ 3];

	//putting it into hexvals bc no parseint bc c is lame
	for(int i = 0; i < sizeof(string)-1; i++){
		sscanf(&string[i], "%01hhx", &hexvals[i]); //same thing as hexvals + i
	}

	int place = 0;

	for(int i = 0; i < sizeof(hexvals)-4; i+=3){
		int toSixFour = (hexvals[i] << 8) + (hexvals[i+1] << 4) + (hexvals[i+2]);
		int num1 = toSixFour / 64;
		int num2 = toSixFour % 64;

		char c1 = encoding_table[num1];
		char c2 = encoding_table[num2];

		answer[place] = c1;
		answer[place+1] = c2;
		place+=2;
	}

	printf("%s\n", answer);
	printf("%s", check);

	return 0;
}
