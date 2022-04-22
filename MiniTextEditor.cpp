#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "TextEditor.cpp"


using namespace std;

int main()
{
	Text<string> textEditor; //textfile
	Line<string> newLine; //for line manipulation 
	int choice = 0;  //menu choice
	string word, other; //"word" to be passed to functions and "other" is replacement for "word" in find and replace
	int lineNum = 0; //to get line number
	int clear; //clear and refresh menu
	do
	{
		cout << "----------Mini Text Editor----------\n";
		cout << "  To insert line press 1\n";
		cout << "  To find a word press 2\n";
		cout << "  To replace a word press 3\n";
		cout << "  To get line text press 4\n";
		cout << "  To show all press 5\n";
		cout << "  To insert at specific index press 6\n";
		cout << "  To update line press 7\n";
		cout << "  To delete line press 8\n";
		cout << "  To exit press 0\n";
		cout << "------------------------------------\n";

		cin >> choice;
		system("CLS");
		switch (choice)
		{
		case 1: //insert
			textEditor.add_line(newLine);
			break;
		case 2: //find
			cout << "Enter the word : ";
			cin >> word;
			textEditor.Find_all(word);
			break;
		case 3: //replace
			cout << "Enter original word : ";
			cin >> word;
			cout << "Enter new word : ";
			cin >> other;
			textEditor.Find_and_replace_all(word, other);
			break;
		case 4: //get line
			cout << "Enter line number: ";
			cin >> lineNum;
			textEditor.get_line_text(lineNum);
			break;
		case 5: //show
			textEditor.show();
			break;
		case 6: //insert at
			textEditor.insert_line(newLine, lineNum);
			break;
		case 7: //update
			textEditor.update(newLine, lineNum);
			break;
		case 8: //delete
			textEditor.delete_line(lineNum);
			break;
		case 0: //end
			return 0;

		}
		cout << "\n\npress 0 to return\n";
		do
		{
			cin >> clear;
		} while (clear != 0);
		system("CLS");

	} while (choice > 0);
}

