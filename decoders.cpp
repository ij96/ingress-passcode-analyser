#include "decoders.h"

string reverse(string ciphertext){
	string plaintext = "";
	int len = ciphertext.size();
	for(int i = 0; i < len; i++){
		plaintext += ciphertext[len-i];
	}
	return plaintext;
}

string atbash(string ciphertext){
	//plaintext:  a-zA-Z
	//ciphertext: z-aZ-A
	for(int i = 0; i < ciphertext.size(); i++){
		int ascii_val = int(ciphertext[i]);
		char converted_char = 0;
		switch(ascii_val){
			case 65 ... 90:		//A-Z
				converted_char = 155 - ascii_val;
				ciphertext[i] = converted_char;
				break;
			case 97 ... 122:	//a-z
				converted_char = 219 - ascii_val;
				ciphertext[i] = converted_char;
				break;
		}
	}
	return ciphertext;
}

string atbash_alphanum(string ciphertext){
	//plaintext:  a-zA-Z1-9
	//ciphertext: z-aZ-A9-1
	for(int i = 0; i < ciphertext.size(); i++){
		int ascii_val = int(ciphertext[i]);
		char converted_char = 0;
		switch(ascii_val){
			case 49 ... 57:		//1-9
				converted_char = 106 - ascii_val;
				ciphertext[i] = converted_char;
				break;
			case 65 ... 90:		//A-Z
				converted_char = 155 - ascii_val;
				ciphertext[i] = converted_char;
				break;
			case 97 ... 122:	//a-z
				converted_char = 219 - ascii_val;
				ciphertext[i] = converted_char;
				break;
		}
	}
	return ciphertext;
}

string ROT(int n, string ciphertext){
	n = n % 26;
	for(int i = 0; i < ciphertext.size(); i++){
		int ascii_val = int(ciphertext[i]);
		char converted_char = 0;
		switch(ascii_val){
			case 65 ... 90:		//A-Z
				converted_char = (ascii_val - 65 + n) % 26 + 65;
				ciphertext[i] = converted_char;
				break;
			case 97 ... 122:	//a-z
				converted_char = (ascii_val - 97 + n) % 26 + 97;
				ciphertext[i] = converted_char;
				break;
		}
	}
	return ciphertext;
}

string ROT_alphanum(int n, string ciphertext){
	n = n % 26;
	for(int i = 0; i < ciphertext.size(); i++){
		int ascii_val = int(ciphertext[i]);
		char converted_char = 0;
		switch(ascii_val){
			case 48 ... 57:		//0-9
				converted_char = (ascii_val - 48 + n) % 10 + 48;
				ciphertext[i] = converted_char;
				break;
			case 65 ... 90:		//A-Z
				converted_char = (ascii_val - 65 + n) % 26 + 65;
				ciphertext[i] = converted_char;
				break;
			case 97 ... 122:	//a-z
				converted_char = (ascii_val - 97 + n) % 26 + 97;
				ciphertext[i] = converted_char;
				break;
		}
	}
	return ciphertext;
}

string replace_two_letter_digit(string ciphertext){
	string combo_list[8] = {"tw","th","fo","fi","si","se","ei","ni"};
	for(int j = 0; j < 8; j++){
		int found = ciphertext.find(combo_list[j]);
		while(found < ciphertext.size()-1){
			string s(1, j+50);
			ciphertext.replace(found, 2, s);					// replace two letters with the corresponding digit
			found = ciphertext.find(combo_list[j], found+1);	// keep searching
		}
	}
	return ciphertext;
}

vector<int> factors(string ciphertext){
	vector<int> result;
	int len = ciphertext.size();
	int square_root = (int)sqrt(len)+1;
	for(int i = 2; i < len; i++){
		if(len % i == 0){
			result.push_back(i);
			if(len/i != i) result.push_back(len/i);
		}
	}
}