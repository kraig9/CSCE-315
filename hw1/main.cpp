#include "Header.h"
int main() {
	//global data structures to store books and courses
	vector<course> courses;
	vector<book> books;

	//also had to define this outside of the case statement. it is only used for the "course" case
	string title;

	while (true) {

		string buf;
		getline(cin, buf);
		//temp_char is for the case of the D input tag
		string temp_char;
		if (buf.length() > 16)temp_char = buf.substr(16, 1);
		std::map<int, book>::iterator iter0;


		//to use a case statement, these had to be defined outside of the case statement,
		//even though they are only used for specific cases.
		//this holds the returned vector from the
		//split function
		vector<string> split_input;
		//this holds the index returned by the match function
		int temp_index;
		//rest of the variables used to store into data structures
		string temp_isbn;
		string temp_title;
		book temp_book;
		course temp_course;
		
		//decide what the input is trying to do
		//the first switch is for modifying and creating books and courses
		switch (buf.front()) {
		case 'B':
			//define book
			temp_isbn = buf.substr(2,13);
			temp_title = buf.substr(17);
			temp_book.ISBN = temp_isbn;
			temp_book.title = temp_title;
			books.push_back(temp_book);
			break;
		case 'D':
			//define characteristic of book
			if (temp_char == "A") {
				vector<string> split_input = split(buf);
				temp_index = match(books, split_input[1]);
				if(temp_index>=0) books[temp_index].author = split_input[3];
				for (int i = 0; i < courses.size(); i++) {
					for (iter0 = courses[i].sec_to_book_map.begin(); iter0 != courses[i].sec_to_book_map.end(); iter0++) {
						if (iter0->second.ISBN == split_input[1]) {
							iter0->second.author=split_input[3];
							break;
						}
					}
				}
			}
			else if (temp_char == "E") {
				vector<string> split_buf = split(buf);
				temp_index = match(books, split_buf[1]);
				if (temp_index >= 0) books[temp_index].edition = stoi(split_buf[3]);
				for (int i = 0; i < courses.size(); i++) {
					for (iter0 = courses[i].sec_to_book_map.begin(); iter0 != courses[i].sec_to_book_map.end(); iter0++) {
						if (iter0->second.ISBN == split_input[1]) {
							iter0->second.edition = stoi(split_input[3]);
							break;
						}
					}
				}
			}
			else if (temp_char == "D") {
				vector<string> split_buf = split(buf);
				temp_index = match(books, split_buf[1]);
				if (temp_index >= 0) books[temp_index].date = split_buf[3];
				for (int i = 0; i < courses.size(); i++) {
					for (iter0 = courses[i].sec_to_book_map.begin(); iter0 != courses[i].sec_to_book_map.end(); iter0++) {
						if (iter0->second.ISBN == split_input[1]) {
							iter0->second.author = split_input[3];
							break;
						}
					}
				}
			}
			//if the split function returns -1 for failure, cout this error message.
			else cout << "Current isbn does not exist. Create a new book to modify characteristics." << endl;
			break;
		case 'M':
			//define cost and condition of book
				split_input = split(buf);
				temp_index = match(books, split_input[1]);
				if (temp_index >= 0) {
					books[temp_index].cost = stod(split_input[2]);
					books[temp_index].condition = split_input[3][0];
				}
				for (int i = 0; i < courses.size(); i++) {
					for (iter0 = courses[i].sec_to_book_map.begin(); iter0 != courses[i].sec_to_book_map.end(); iter0++) {
						if (iter0->second.ISBN == split_input[1]) {
							iter0->second.cost = stod(split_input[2]);
							iter0->second.condition = split_input[3][0];
						}
					}
				}
			break;
		case 'C':
			//define a course
			split_input = split(buf);
			for (int i = 2; i < split_input.size(); i++) {
				title = title + split_input[i];
			}
			temp_course.dept_code = split_input[1];
			temp_course.course_num = stoi(split_input[2]);
			temp_course.name = title;
			courses.push_back(temp_course);
			break;
		case 'A':
			//assign book to a course
			split_input = split(buf);
			temp_isbn = split_input[1];
			for (int i = 0; i < books.size(); i++) {
				if (temp_isbn==books[i].ISBN) {
					for (int j = 0; j < courses.size(); j++) {
						if (courses[j].course_num == stoi(split_input[3])) {
							//this line gives the already made course a section number
							courses[j].section_num = stoi(split_input[4]);
							//this line uses a map data structure to "assign" a book to a course
							courses[j].sec_to_book_map.insert(make_pair(courses[j].section_num, books[i]));

						}
					}
				}
			}
			break;
		default:
			break;
		}
		//the section switch checks to see if you want to print

		string buf2 = buf.substr(0, 2);
		int buf3 = 0;
		if (buf2 == "GC") buf3 = 1;
		if (buf2 == "GS") buf3 = 2;
		if (buf2 == "GB") buf3 = 3;
		if (buf2 == "PB") buf3 = 4;
		if (buf2 == "PC") buf3 = 5;
		if (buf2 == "PY") buf3 = 6;
		if (buf2 == "PD") buf3 = 7;
		if (buf2 == "PM") buf3 = 8;

		//iterator to loop through the map
		std::map<int, book>::iterator iter;

		//parsing input again
		split_input = split(buf);

		double min_cost, max_cost, total, n;

		switch (buf3) {
		case 1:
			//print books required and optional for all sections of course
			for (int i = 0; i < courses.size(); i++) {
				if (courses[i].dept_code == split_input[1]) {
					if (courses[i].course_num == stoi(split_input[2])) {
						for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
							iter->second.print_book();
						}
					}
				}
			}
			break;
		case 2:
			//print books required and optional for given section of course
			for (int i = 0; i < courses.size(); i++) {
				if (courses[i].dept_code == split_input[1] && courses[i].section_num == stoi(split_input[2])) {
					for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
						iter->second.print_book();
					}
				}
			}
			break;
		case 3:
			//print all information known about a particular book
			for (int i = 0; i < courses.size(); i++) {
				for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
					if (iter->second.ISBN == split_input[1]) {
						iter->second.print_book();
						break;
					}
				}
			}
			break;
		case 4:
			//print all defined books
			for (int i = 0; i < courses.size(); i++) {
				for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
						iter->second.print_book();
				}
			}
			break;
		case 5:
			//print all defined courses
			for (int i = 0; i < courses.size(); i++) {
				courses[i].print_course();
			}
			break;
		case 6:
			//print all books with known pub dates in given month/year or later
			for (int i = 0; i < courses.size(); i++) {
				for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
					if (iter->second.date==split_input[1])iter->second.print_book();
				}
			}
			break;
		case 7:
			//print lists of all books used in a dept. given by dept. code
			for (int i = 0; i < courses.size(); i++) {
				if (courses[i].dept_code == split_input[1]) {
					for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
						iter->second.print_book();
					}
				}
			}
			break;
		case 8:
			//print average min and max costs of all books in a dept.
			min_cost = 999999999, max_cost = 0, total = 0, n = 0;
			for (int i = 0; i < courses.size(); i++) {
				//temporary variables for the average costs cases
				//cost buffer is to check if the cost is the lowest or highest for the book
				if (courses[i].dept_code == split_input[1]) {
					for (iter = courses[i].sec_to_book_map.begin(); iter != courses[i].sec_to_book_map.end(); iter++) {
						if (iter->second.cost > 0) {
							double temp = iter->second.cost;
							if (temp < min_cost)min_cost = temp;
							else if (temp > max_cost)max_cost = temp;
							total += temp;
							n++;
						}
					}
				}
			}
			cout << "number of books that had a cost: " << n << endl <<
				"average cost: " << (n > 0 ? total / n : total / 1) << endl <<
				"minimum cost: " << min_cost << endl <<
				"maximum cost: " << max_cost << endl;
			break;
		default:
			break;
		}
		//handle bad inputs here
	}
}