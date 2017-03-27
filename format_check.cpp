#include "format_check.h"

int format_check(string code){
	if(pattern_match(code, "xxx##k###xx"))	return 1;	// Investigate Blog
	if(pattern_match(code, "k@xx@@xx@"))	return 2;	// Ingress Report
	if(pattern_match(code, "xxxxxxxx#k#"))	return 3;	// Anomaly
	if(pattern_match(code, "k"))			return 4;	// all text
	if(pattern_match(code, "xxx@@k@@@xx"))	return 11;	// Investigate Blog with 0 and/or 1
	return 0;
}

bool is_digit_2_9(char c){
	// check if character represents a number in range of 2 to 9 inclusive
	return c >= 50 && c <= 57;
}

bool pattern_match(string str, string pattern){
	//check if str matches the pattern
	//pattern syntax:
	//	x: alphabetic
	//	#: numberic 2-9
	//	@: numberic 0-9
	//	k: keyword (alphabetic of any length)
	for(int i = 0; i < pattern.size(); i++){
		if(pattern[i]=='x'){
			if(!isalpha(str[0])) return false;
			str.erase(0,1);
		}
		else if(pattern[i]=='#'){
			if(!is_digit_2_9(str[0])) return false;
			str.erase(0,1);
		}
		else if(pattern[i]=='@'){
			if(!isdigit(str[0])) return false;
			str.erase(0,1);
		}
		else if(pattern[i]=='k'){
			string keyword = "";
			bool keyword_complete = false;
			int j = 0;
			while(j < str.size() && !keyword_complete){
				if(isalpha(str[j])) keyword += str[j];
				else if(isdigit(str[j])) keyword_complete = true;
				j++;
			}
			str.erase(0,keyword.size());
		}
		else return false; //Pattern not valid!
	}
	return str == "";
}