//Windows header guard
#pragma once

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
	unsigned int edition;
	string date;
	double cost;
	char condition;
	unsigned int section_num;

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
	void define_edition(string ISBN, unsigned int edition);
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
};

struct course {
	//variables that make up a course
	string dept_code;
	unsigned int course_num;
	string name;

	//constructor
	course() {};
	course(string dept_code, unsigned int course_num, string name) {
		dept_code = dept_code;
		course_num = course_num;
		name = name;
	}
};