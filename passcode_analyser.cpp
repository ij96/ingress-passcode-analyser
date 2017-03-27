// Ingress passcode analyser

#include <iostream>
#include <string>
using namespace std;

#include "decoders.h"
#include "format_check.h"

void analyse();
void show_help();

int main(int argc, char** argv){
	if(argc == 1){
		analyse();
	}
	else if(argc == 2){
		string arg = argv[1];
		if(arg == "-help"){
			show_help();
		}
	}
	return 0;
}

void analyse(){
	string code;
	cout<<"\n\n********** Ingress passcode analyser **********\n\n";
	cout<<"Enter code:\n";
	cin>>code;
	int format_case = format_check(code);
	cout<<'\n';
	switch(format_case){
		case 1:
			cout<<"Investigate Blog format\n";
			break;
		case 2:
			cout<<"Ingress Report format\n";
			break;
		case 3:
			cout<<"Anomaly format\n";
			break;
		case 4:
			cout<<"All letters\n";
			cout<<"Try look for two letter written digits.\n";
			cout<<"Replace two letter written digits:\n\t"<<replace_two_letter_digit(code)<<'\n';
			break;
		case 11:
			cout<<"Fits the Investigate Blog format but with 0 and/or 1.\n";
			cout<<"Try alphanumeric Atbash or ROT.\n";			
			cout<<"Alphanumberic Atbash:\n\t"<<atbash_alphanum(code)<<'\n';
			cout<<"Alphanumberic ROT 13:\n\t"<<ROT_alphanum(13, code)<<'\n';
			break;
		default:
			cout<<"Does not match any recent patterns (could be WOTD or Old format).";
			break;
	}
}

void show_help(){
	string code_format = "\nPasscode formats: (from ingress.codes)\n\n";
	
	code_format += "Investigation Blog:\n";
	code_format += "xxx##keyword###xx\n";
	code_format += "(# are 2 to 9)\n\n";
	
	code_format += "WOTD:\n";
	code_format += "x#x#keywordx#xx\n";
	code_format += "(# are 0 to 9)\n";
	code_format += "[not supported]\n\n";
	
	code_format += "Ingress Report (forever code):\n";
	code_format += "keyword#xx##xx#\n";
	code_format += "(# are 0 to 9)\n\n";
	
	code_format += "Anomaly:\n";
	code_format += "xxxxxxxx#keyword#\n";
	code_format += "(# are 2 to 9)\n\n";
	
	code_format += "Old formats:\n";
	code_format += "#xxx#keywordx#x#x\n";
	code_format += "(# are 2 to 9)\n";
	code_format += "[not supported]\n\n";
	
	cout<<code_format;
}