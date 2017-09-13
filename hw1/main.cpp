#include "Header.h"

//This function splits up the inputted line by spaces and returns each part of the line
//in a vector of strings.
vector<string> split(string raw) {
	vector<string> fill_this;
	string token;
	for (int i = 0; i == raw.length();i++) {
		char thing = raw[i];
		if (thing == ' ') {
			fill_this.push_back(token);
			token = "";
		}
		else token += thing;
	}
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

int main() {
	vector<course> courses;
	vector<book> books;
	map<string, vector<book>> library;
	string temp_isbn;
	string temp_title;
	book temp_book;
	course temp_course;

	while (true) {
		string buf;
		getline(cin, buf);
		//temp_char is for the case of the D input tag
		string temp_char = buf.substr(16,1);
		
		//decide what the input is trying to do
		//the first switch is for modifying and creating books and courses
		switch (buf.front()) {
		case 'B':
			//define book
			temp_isbn = buf.substr(2,13);
			temp_title = buf.substr(17);
			temp_book.define_book(temp_isbn, temp_title);
			books.push_back(temp_book);
			break;
		case 'D':
			//define characteristic of book
			if (temp_char == "A") {
				vector<string> split_buf = split(buf);
				int temp_index = match(books, split_buf[1]);
				if(temp_index>=0) books[temp_index].author = split_buf[3];
			}
			else if (temp_char == "E") {
				vector<string> split_buf = split(buf);
				int temp_index = match(books, split_buf[1]);
				if (temp_index >= 0) books[temp_index].author = split_buf[3];
			}
			else if (temp_char == "D") {
				vector<string> split_buf = split(buf);
				int temp_index = match(books, split_buf[1]);
				if (temp_index >= 0) books[temp_index].author = split_buf[3];
			}
			//if the split function returns -1 for failure, cout this error message.
			else ("Current isbn does not exist. Create a new book to modify characteristics.");
			break;
		case 'M':
			//define cost of book
			if (buf.end == 'N') {
				vector<string> split_input;
				split_input = split(buf);
				temp_book.define_cost(temp_isbn, stod(split_input[2]), split_input[3][0]);
			}
			else if (buf.end == 'U') {
				vector<string> split_input;
				split_input = split(buf);
				temp_book.define_cost(temp_isbn, stod(split_input[2]), split_input[3][0]);
			}
			else if (buf.end == 'R') {
				vector<string> split_input;
				split_input = split(buf);
				temp_book.define_cost(temp_isbn, stod(split_input[2]), split_input[3][0]);
			}
			else if (buf.end == 'E') {
				vector<string> split_input;
				split_input = split(buf);
				temp_book.define_cost(temp_isbn, stod(split_input[2]), split_input[3][0]);
			}
			else "ISBN does not exist, or entered an invalid condition.";
			break;
		case 'C':
			//define a course
			vector<string> split_input;
			split_input = split(buf);
			string title;
			for (int i = 2; i < split_input.size(); i++) {
				title = title + split_input[i];
			}
			temp_course.dept_code = split_input[1];
			temp_course.course_num = stoi(split_input[2]);
			temp_course.name = title;
			courses.push_back(temp_course);
			break;
		case 'A':
			//assign book to class

			break;
		default:
			break;
		}
		//the section switch checks to see if you want to print

		string buf2 = buf.substr(0, 1);
		int buf3;
		if (buf2 == "GC") buf3 = 1;
		if (buf2 == "GS") buf3 = 2;
		if (buf2 == "GB") buf3 = 3;
		if (buf2 == "PB") buf3 = 4;
		if (buf2 == "PC") buf3 = 5;
		if (buf2 == "PY") buf3 = 6;
		if (buf2 == "PD") buf3 = 7;
		if (buf2 == "PM") buf3 = 8;
		switch (buf3) {
		case 1:
			//print books required and optional for all sections of course
			break;
		case 2:
			//print books required and optional for given section of course
			break;
		case 3:
			//print all information known about a particular book
			break;
		case 4:
			//print all defined books
			break;
		case 5:
			//print all defined courses
			break;
		case 6:
			//print all books with known pub dates in given month/year or later
			break;
		case 7:
			//print lists of all books used in a dept. given by dept. code
			break;
		case 8:
			//print averge min and max costs of all books in a dept.
			break;
		default:
			break;
		}
		//handle bad inputs here
	}
}