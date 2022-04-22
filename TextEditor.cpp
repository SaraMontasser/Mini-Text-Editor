#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include "TextEditor.h"


using namespace std;

template <class t>
Line<t>::Line()
{
}
template <class t>
void Line<t>::insert()
{
	const int max = 30; //maximum number of words per line
	string insertarr[max];
	string word;
	for (int i = 0; i < max; i++) //gets input line from user and separates it into array of strings then adds it to the line
	{
		cin >> word;
		insertarr[i] = word;
		line.push_back(insertarr[i]);
		if (cin.get() == '\n')
			break;
	}
}
template <class t>
bool Line<t>::Find(t word)
{
	bool found = false;

	for (int i = 0; i < line.size(); i++)
	{
		if (word == line.at(i))
		{
			found = true;
			break;
		}

	}
	return found;

}
template <class t>
void Line<t>::Find_and_replace(t word, t other)
{
	for (int i = 0; i < line.size(); i++)
	{
		if (word == line.at(i)) //finds a word and replaces it with other
		{
			line.at(i) = other;
		}
	}
}
template <class t>
void Line<t>::display()
{
	for (int i = 0; i < line.size(); i++)
	{
		cout << line.at(i) << " ";
	}
	cout << endl;

};


template <class t>
Text<t>::Text()
{

}
template <class t>
void Text<t>::add_line(Line<t> line)
{
	cout << "please enter line text : ";
	line.insert(); //uses insert function
	lines.push_back(line); //puts line in text file
	cout << "\n\nLine added successfully!";
}
template <class t>
void Text<t>::Find_all(t word)
{
	if (lines.empty() != true) //checks that textfile is not empty
	{
		bool exist = false;
		cout << "The word " << word << " is at lines : ";
		for (int i = 0; i < lines.size(); i++)
		{
			if (lines.at(i).Find(word) == true) //checks if word is found at certain line and returns its number
			{
				cout << i + 1 << " ";
				exist = true;
			}
			else if (lines.at(i).Find(word) == false && exist == false)
			{
				if (i == lines.size() - 1) //checks if it is end of file
				{
					cout << "The word " << word << " is not found in text file!";
				}

			}
		}
	}
	else
		cout << "Text file is empty!";
	cout << endl;
}
template <class t>
void Text<t>::Find_and_replace_all(t word, t other)
{
	if (lines.empty() != true) //checks that textfile is not empty
	{
		cout << "The word " << word << " will be replaced with " << other;
		for (int i = 0; i < lines.size(); i++) //uses find and replace function at each line
		{
			lines.at(i).Find_and_replace(word, other);
		}
	}
	else
		cout << "Text file is empty!";
	cout << endl;
}
template <class t>
void Text<t>::show()
{
	if (lines.empty() == true)
		cout << "Text file is empty!\n";
	else {
		for (int i = 0; i < lines.size(); i++)
		{
			lines.at(i).display();
		}
	}

}
template <class t>
void Text<t>::get_line_text(int number)
{
	if (number<1 || number>lines.capacity())
		cout << "line number out of bound!\n";
	else
	{
		cout << endl;
		Line<t> line = lines.at(number - 1);
		line.display();
	}

}
template <class t>
void Text<t>::insert_line(Line<t> line, int number)
{
	if (lines.empty() == false) //makes sure file is not empty
	{
		cout << "please enter line text : ";
		line.insert();
		cout << "please enter number : ";
		cin >> number;
		if (number > lines.capacity()) //if number is bigger than file it just adds it to the end
		{
			lines.push_back(line);
		}
		else
			lines.insert(lines.begin() + number - 1, line);
		cout << "\nLine inserted successfully!\n";
	}
	else //if empty then uses normal add_line
		add_line(line);

}
template <class t>
void Text<t>::update(Line<t> line, int number)
{
	if (lines.empty() == false) //checks if file is empty
	{
		cout << "please enter line text : ";
		line.insert();
		cout << "please enter number : ";
		cin >> number;

		if (number>=1 && number<=lines.capacity())
		{
			lines.at(number - 1) = line;
			cout << "Line updated successfully!\n";
			
		}
		else
		{
			cout << "line number out of bound!\n";
		}
	}
	else
		cout << "Text File is empty!\n";
	
	
}
template <class t>
void Text<t>::delete_line(int number)
{
	if (lines.empty() == false) //checks if line is empty
	{
		cout << "please enter number : ";
		cin >> number;

		if (number>=1 && number<=lines.capacity())
		{
			lines.erase(lines.begin() + number - 1);
			cout << "Line deleted successfully";
			
		}
		else
		{
			cout << "line number out of bound!\n";
		}
	}
	else
		cout << "Text File is empty!\n";
	
}

