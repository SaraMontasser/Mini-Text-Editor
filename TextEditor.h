#pragma once
#include <vector>
template <class t>
class Line //an Arraylist of strings representing a single line
{
public:
	std::vector<t> line;
	Line();
	void insert();
	bool Find(t word);
	void Find_and_replace(t word, t other);
	void display();
};
template <class t>
class Text //an Arraylist of Lines representing the text file
{
	std::vector<Line<t>> lines;
public:
	Text();
	void add_line(Line<t> line);
	void Find_all(t word);
	void Find_and_replace_all(t word, t other);
	void show();
	void get_line_text(int number);
	void insert_line(Line<t> line, int number);
	void update(Line<t> line, int number);
	void delete_line(int number);
	
	
};

