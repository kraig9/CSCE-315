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

void book::define_edition(string ISBN, unsigned int edition) {
	if (ISBN == ISBN) {
		edition = edition;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}

void define_date(string ISBN, string date) {
	if (ISBN == ISBN) {
		date = date;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}
void define_cost(string ISBN, double cost, char condition) {
	if (ISBN == ISBN) {
		cost = cost;
		condition = condition;
	}
	else {
		cout << "No book with the specified ISBN was found.";
	}
}

//TODO: figure out how to assign books to hash map
void assign_book() {

}

//functions that print
//std::vector<std::string> print_all();
//std::vector<std::string> print_section();
//std::vector<std::string> print_info();
//std::vector<std::string> print_def_books();
//std::vector<std::string> print_def_courses();
//std::vector<std::string> print_dept_books();
//double print_avg_cost();