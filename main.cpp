// Ingress passcode analyser

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "decoders.h"
#include "format_check.h"

void analyse(string& code);
void action(string code);
void show_help();

int main(int argc, char** argv){
	if(argc == 1){
		string code;
		cout<<"\n\n********** Ingress passcode analyser **********\n\n";
		cout<<"Enter code\n>> ";
		cin>>code;
		analyse(code);
		action(code);
	}
	else if(argc == 2){
		string arg = argv[1];
		if(arg == "--help" or arg == "-h"){
			show_help();
		}
	}
	return 0;
}

void action(string code){
	const string original_code = code;
	string act_buff = "";
	char act = ' ';
	int shift = 0;
	while(act!='e'){
		cout<<">> "; cin>>act_buff;
		act = act_buff[0];
		switch(act){
			case 'a':
				code = atbash_alphanum(code);
				cout<<"Alphanumberic Atbash:\n\t"<<code;
				break;
			case 'b':
				try{
					code = base64(code);
					cout<<"Base64:\n\t"<<code;
				}
				catch(const invalid_argument& e){
					cout<<e.what();
				}
				break;
			case 'h':
				code = atbash_hex(code);
				cout<<"Hex Atbash:\n\t"<<code;
				break;
			case 'r':
				code = reverse(code);
				cout<<"Reverse:\n\t"<<code;
				break;
			case 't':
				cin>>shift;
				code = ROT_alphanum(shift, code);
				cout<<"Alphanumberic ROT"<<shift<<":\n\t"<<code;
				break;
			case 'o':
				cout<<"Original code:\n\t"<<original_code;
				break;
			case 'O':
				code = original_code;
				cout<<"Reset code:\n\t"<<code;
				break;
			case 'l':
				code = replace_two_letter_digit(code);
				cout<<"Replace two-letter written digits:\n\t"<<code;
				break;
			case 's':
				cin>>shift;
				code = skip(shift, code);
				cout<<"Skip "<<shift<<":\n\t"<<code;
				break;
			case 'e':	// exit
				cout<<"Exit\n";
				return;
		}
		cout<<"\n\n";
	}
}

void analyse(string& code){
	cout<<"\nLength = "<<code.size()<<", ";
	int format_case = format_check(code);
	string format_name = "", tips = "";
	switch(format_case){
		case 1:
			format_name = "all letters";
			tips = "Try looking for two-letter written digits.";
			break;
		case 10:
			format_name = "Investigate Blog format";
			break;
		case 11:
			format_name = "Investigate Blog format reversed.";
			tips = "Try reversing first.";
			break;
		case 12:
			format_name = "fits the Investigate Blog format but has 0 and/or 1.";
			tips = "Try alphanumeric Atbash or ROT.";
			break;
		case 20:
			format_name = "Ingress Report format";
			break;
		case 21:
			format_name = "Investigate Report format reversed.";
			tips = "Try reversing first.";
			break;
		case 30:
			format_name = "Anomaly format";
			break;
		case 40:
			format_name = "WOTD format";
			break;
		case 50:
			format_name = "Old format";
			break;
		default:
			format_name = "does not match any known patterns";
			break;
	}
	cout<<format_name<<'\n'<<tips<<'\n';
}

void show_help(){
	ifstream help_file("./help.txt");
	string line = "";
	if(!help_file.is_open()){
		cout<<"cannot find help.txt!"<<'\n';
		return;
	}
	while(getline(help_file,line)){
		cout<<line<<'\n';
	}
	help_file.close();
}