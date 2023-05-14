#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>


struct Task {
	std::string title;
	std::string detail;
};

class List {
public:
	List();
	List(std::string);
	~List();
	void Add(Task);
	void EditTask(size_t);
	void RemoveTask(size_t);
	void PrintTask(Task*);
	void PrintList();
	void WriteFile();
public:
	std::vector<Task> m_list;

private:
	int OpenFile();
	void LoadFile();
private:
	std::fstream m_file;
	std::string m_filepath;
};


#endif
