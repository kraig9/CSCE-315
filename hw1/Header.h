//header guard
#ifndef Header_h
#define Header_h

//standard includes
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

//figure out the hash map implementation later.
//sort books into respective courses.

struct book {
	//member variables
	string ISBN;
	string title;
	string author;
	int edition = -1;
	string date;
	double cost = 0;
	char condition = '-';
	int section_num = -1;

	//function declarations
public:
	//constructors
	book() {};
	book(string ISBN, string title) {
		ISBN = ISBN;
		title = title;
	}

	//functions that modify or create
	void define_book(string ISBN, string title);
	void define_author(string ISBN, string author);
	void define_edition(string ISBN, int edition);
	void define_date(string ISBN, string date);
	void define_cost(string ISBN, double cost, char condition);
	//TODO: figure out how to assign books to hash map
	void assign_book();

	//functions that print
	//TODO: implement the map to complete print functions
	vector<string> print_all();
	vector<string> print_section();
	vector<string> print_info();
	vector<string> print_def_books();
	vector<string> print_def_courses();
	vector<string> print_dept_books();
	double print_avg_cost();

	void print_book();
};

struct course {
	//variables that make up a course
	string dept_code;
	int course_num = -1;
	string name;
	int section_num = -1;

	//this vector will be used to store books that are assigned to the section.
	map<int, book> sec_to_book_map;

	//constructor
	course() {};
	course(string dept_code, int course_num, string name) {
		dept_code = dept_code;
		course_num = course_num;
		name = name;
	}
	//member function
	void print_course();
};

//helper functions that don't belong in a class
vector<string> split(string raw);

int match(vector<book> books, string temp_isbn);

#endif