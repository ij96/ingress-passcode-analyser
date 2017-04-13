#include "decoders.h"

// reverse
string reverse(string ciphertext){
	string plaintext = "";
	int len = ciphertext.size();
	for(int i = 0; i < len; i++){
		plaintext += ciphertext[len-i-1];
	}
	return plaintext;
}

// Atbash
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
				ciphertext[i] = 106 - ascii_val;
				break;
			case 65 ... 90:		//A-Z
				ciphertext[i] = 155 - ascii_val;
				break;
			case 97 ... 122:	//a-z
				ciphertext[i] = 219 - ascii_val;
				break;
		}
	}
	return ciphertext;
}

string atbash_hex(string ciphertext){
	//plaintext:  a-f0-9 (or A-F0-9)
	//ciphertext: 9-0f-a
	for(int i = 0; i < ciphertext.size(); i++){
		int ascii_val = int(ciphertext[i]);
		switch(ascii_val){
			case 48 ... 53:		//0-5
				ciphertext[i] = 150 - ascii_val;
				break;
			case 54 ... 57: 	//6-9
				ciphertext[i] = 111 - ascii_val;
				break;
			case 65 ... 70:		//A-F
				ciphertext[i] = 118 - ascii_val;
				break;
			case 97 ... 102:	//a-f
				ciphertext[i] = 150 - ascii_val;
				break;
		}
	}
	return ciphertext;
}

// ROT N
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

// two-letter digit
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

// grid
vector<int> factors(string ciphertext){
	// generate a list of factor of ciphertext length, excluding 1 and self
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

// skip N
string skip(int n, string ciphertext){
	string plaintext = "";
	for(int i = 0; i < n; i++){
		for(int j = 0; (i+j) < ciphertext.size(); j+=n){
			plaintext += ciphertext[i+j];
		}
	}
	return plaintext;
}

// Base64
string base64(string ciphertext){
	int len = ciphertext.size();
	if(len%4 != 0) throw invalid_argument("Invalid Base64 input (length not suitable)");
	const string base64_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	for(int i = 0; i < len; i++){
		int index = base64_chars.find(ciphertext[i]);
		if(index) ciphertext[i] = index;
		else if(ciphertext[i] != '='){
			ostringstream s;
			s<<"Invalid Base64 input (illegal character) at "<<i<<": "<<ciphertext[i];
			throw invalid_argument(s.str());
		}
	}
	string plaintext = "";
	unsigned char new_char[4];
	for(int i = 0; i < ciphertext.size(); i+=4){
		new_char[0] = (ciphertext[i]<<2) + ((ciphertext[i+1]&0x30)>>4);
		new_char[1] = ((ciphertext[i+1]&0xf)<<4) + ((ciphertext[i+2]&0x3c)>>2);
		new_char[2] = ((ciphertext[i+2]&0x3)<<6) + ciphertext[i+3];
		for(int j = 0; j < 3; j++) plaintext += new_char[j];
	}
	return plaintext;
}

// Morse
string swap_morse_bits(string ciphertext){
	for(int i = 0; i < ciphertext.size(); i++){
		switch(ciphertext[i]){
			case '.':
				ciphertext[i]='-';
				break;
			case '-':
				ciphertext[i]='.';
				break;
		}
	}
	return ciphertext;
}