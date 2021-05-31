#include "GameHeader.h"
#include <iostream>
#include <string>
using namespace std;

//display the content on the console in custom layout
//string content 
void ScreenHeadings::screenOutput(string head, string content) {
	int x_len = head.length();
	int y_len = content.length();
	int add = y_len + 8;
	int dash=0,equal=0;
	if (y_len < 50 && add<50) {
		dash = y_len + 8;
	}
	else dash = 50;

	equal = (dash - 2 - x_len)/2;

		heading(head, dash, equal);
		cout << endl;
		blank(dash);
		cout << endl;
		
		contenting(content, dash);


		cout << "\n";
		dashing(dash);
}

//display the content on the console in custom layout
//without equal sign in the heading 
//string array content
void ScreenHeadings::screenOutput(string head,int n,string strArr[]) {
	int headLen = head.length();
	int dash = headLen + 8;
	int maxLen = 0;

	heading(head, dash);

	int len;
	string str[12];
	for (int i = 0; i < n; i++) {
		//cout << endl << strArr[i];
		str[i] = to_string(i + 1) + ". " + strArr[i];
		len = str[i].length();
		if (maxLen < len) {
			maxLen = len;
		}
	}
	if (headLen > maxLen) {
		maxLen = headLen;
	}

	cout << endl;

	for (int i = 0; i < n; i++) {
		//str[i] = to_string(i+1)+". "+strArr[i];
		contenting(str[i], dash);
		if (i < n - 1)
			cout << endl;
	}

	cout << "\n";
	dashing(dash);
}

//display the content on the console in custom layout
//string array content
void  ScreenHeadings::screenOutput(string head, string strArr[],int n) {
	int maxLen=0;
	int headLen = head.length();
	int len;
	string str[12];
	for (int i = 0; i < n; i++) {
		//cout << endl << strArr[i];
		str[i] = to_string(i + 1) + ". " + strArr[i];
		len = str[i].length();
		if (maxLen < len) {
			maxLen = len;
		}
	}
	if (headLen > maxLen) {
		maxLen = headLen;
	}
	//cout << "\nMAxlen: " << maxLen << endl;
	int add = maxLen + 8;
	int dash = 0, equal = 0;
	if (maxLen < 50 && add < 50) {
		dash = maxLen + 8;
	}
	else dash = 50;

	equal = (dash - 2 - headLen) / 2;

	/*cout << "\n dash : " << dash;
	cout << "\n Equal : " << equal;
	cout << "\n add : " << add;
	cout << "\n Heading : " << head.length() << endl;*/

	heading(head, dash, equal);
	cout << endl;
	blank(dash);
	cout << endl;

	for (int i = 0; i < n; i++) {
		//str[i] = to_string(i+1)+". "+strArr[i];
		contenting(str[i], dash);
		if(i<n-1)
		cout << endl;
	}

	cout << "\n";
	dashing(dash);
}

//display the final score on the console in custom layout
void ScreenHeadings::finalScore(string head, string strArr[], int n) {
	int maxLen = 0;
	int headLen = head.length();
	int len;
	string str[5];
	for (int i = 0; i < n; i++) {
		//cout << endl << strArr[i];
		str[i] = to_string(i + 1) + ". " + strArr[i];
		len = str[i].length();
		//cout << str[i] << endl << "Length: " << str[i].length()<<endl;
		if (maxLen < len) {
			maxLen = len;
		}
	}
	if (headLen > maxLen) {
		maxLen = headLen;
	}
	//cout << "\nMAxlen: " << maxLen << endl;
	int add = maxLen + 8;
	int dash = 0, equal = 0;
	dash = add;

	equal = (dash - 2 - headLen) / 2;

	/*cout << "\n dash : " << dash;
	cout << "\n Equal : " << equal;
	cout << "\n add : " << add;
	cout << "\n Heading : " << head.length() << endl;*/

	heading(head, dash, equal);
	cout << endl;
	blank(dash);
	cout << endl;

	for (int i = 0; i < n; i++) {
		//str[i] = to_string(i+1)+". "+strArr[i];
		contenting(dash,str[i]);
		if (i < n - 1)
			cout << endl;
	}

	cout << "\n";
	dashing(dash);
}

//display heading without equal sign
void ScreenHeadings::heading(string head, int dash) {
	dashing(dash);
	cout << "\n|";
	space(3);
	cout << head;
	space(3);
	cout << "|\n";
	dashing(dash);
}

//display heading with equal sign
void ScreenHeadings::heading(string head, int dash, int equal) {
	int len = head.length();
	int totalEqual = len + 2 * equal + 2;
	dashing(dash);
	cout << "\n|";
	equaling(equal);
	cout << head;
	if (totalEqual < dash) {
		equal++;
	}
	equaling(equal);
	cout << "|\n";
	dashing(dash);
}

//display the content 
void ScreenHeadings::contenting(int dash,string content) {
	int init_pos = 0, fin_pos = 0;
	int len = content.length();
	string str;
	while (init_pos < len) {
		if (dash < 50) {
			str = content;
			init_pos = len;
		}
		else {
			if (fin_pos == 0) {
				fin_pos = 42;
			}
			else if ((len - fin_pos) > 42) {
				fin_pos = 42;
				cout << endl;
			}
			else {
				fin_pos = len - fin_pos;
				cout << endl;
			}
			str = content.substr(init_pos, fin_pos);
			init_pos += fin_pos;
		}
		corner();
		space(3);
		cout << str;
		if (dash == 50 && str.length() < 42) {
			space(42 - str.length());
		}
		else if ((dash - str.length()) > 3) {
			space(dash - str.length() - 8);
		}
		space(3);
		corner();
	}
}

/*
void ScreenHeadings::contenting(string content,int dash){
	int init_pos = 0,fin_pos=0;
	int len = content.length();
	string str;
	while (init_pos < len) {
		if (dash < 50) {
			str = content;
			init_pos = len;
		}
		else {
			if (fin_pos==0) {
				fin_pos = 42;
			}
			else if ((len - fin_pos) > 42) {
				fin_pos = 42;
				cout << endl;
			}
			else {
				fin_pos = len - fin_pos;
				cout << endl;
			}
			str = content.substr(init_pos, fin_pos);
			init_pos += fin_pos;
		}
		corner();
		space(3);
		cout << str;
		if (dash == 50 && str.length() < 42) {
			space(42 - str.length());
		}
		else if ((dash - str.length()) > 3) {
			space(dash - str.length() - 8);
		}
		space(3);
		corner();
	}
}
*/

//display blank row
void ScreenHeadings::blank(int dash) {
	for (int i = 0; i < dash; i++) {
		if (i == 0 || i == (dash - 1))
			cout << "|";
		else cout << " ";
	}
}

//display corner 
void ScreenHeadings::corner() {
	cout << "|";
}

//display space 
void ScreenHeadings::space(int n) {
	for (int i = 0; i < n; i++) {
		cout << " ";
	}
}

//display the dash, dash times
void ScreenHeadings::dashing(int dash) {
	for (int i = 0; i < dash; i++) {
		cout << "-";
	}
}

//display the equal sign 
void ScreenHeadings::equaling(int equal) {
	for (int i = 0; i < equal; i++) {
		cout << "=";
	}
}

