#include "Header.h"

//function definitions
//kk
//functions that modify or create
void book::define_book(string ISBN, string title) {
	ISBN = ISBN;
	title = title;
}

void book::define_author(string ISBN, string author) {
	if (ISBN == ISBN) {
		author = author;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}

void book::define_edition(string ISBN, int edition) {
	if (ISBN == ISBN) {
		edition = edition;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}

void book::define_date(string ISBN, string date) {
	if (ISBN == ISBN) {
		date = date;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}
void book::define_cost(string ISBN, double cost, char condition) {
	if (ISBN == ISBN) {
		cost = cost;
		condition = condition;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}

//TODO: figure out how to assign books to hash map
void assign_book();

//functions that print
//std::vector<std::string> print_all();
//std::vector<std::string> print_section();
//std::vector<std::string> print_info();
//std::vector<std::string> print_def_books();
//std::vector<std::string> print_def_courses();
//std::vector<std::string> print_dept_books();
//double print_avg_cost();
void book::print_book() {
	string output;
	output = "ISBN: " + ISBN + "\ntitle: " + title + "\n";
	if (author.size() != 0) output = output + "author: " + author + "\n";
	if (edition > 0)output = output + "edition: " + to_string(edition) + "\n";
	if (date.size() != 0)output = output + "date of publication:" + date + "\n";
	if (cost > 0)output = output + " cost: " + to_string(cost) + "\n";
	if (condition != '-')output = output + "condition: " + condition + "\n";
	if (section_num > 0)output = output + "section number: " + to_string(section_num) + "\n";
	cout << output;
}

void course::print_course() {
	string output;
	output = "department code: " + dept_code + "\n" +
		"course number: " + to_string(course_num) + "\n" +
		"name: " + name + "\n";
	if (section_num >= 0)output = output + "section number: " + to_string(section_num) + "\n";
	cout << output;
}

//helper functions that don't belong in a class
//This function splits up the inputted line by spaces and returns each part of the line
//in a vector of strings.
vector<string> split(string raw) {
	vector<string> fill_this;
	string token;
	for (int i = 0; i < raw.length(); i++) {
		char thing = raw[i];
		if (thing == ' ') {
			fill_this.push_back(token);
			token = "";
		}
		else token += thing;
	}
	if (token != "")fill_this.push_back(token);
	return fill_this;
}

//this function tries to find a matching isbn in the vector of books
int match(vector<book> books, string temp_isbn) {
	for (int i = 0; i < books.size(); i++) {
		if (books[i].ISBN == temp_isbn) {
			return i;
		}
	}
	//if ISBN is not found, return a -1
	return -1;
}