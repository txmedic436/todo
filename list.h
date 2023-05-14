#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <sstream>


class List {
public:
	void openFile(std::string);
	int SetFilePath(std::string);
	void AddItem();
	void RemoveItem(int);
	void EditItem(int);

private:
	std::fstream file;
	std::string m_filepath = ".todo.dat"	//Default file path
	struct Task {
		std::string title;
		std::string detail;
	};
}


#endif
