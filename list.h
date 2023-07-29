#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <ctime>
#include <chrono>

struct Task {
	std::string title;
	std::string detail;
	size_t priority;
	time_t created_on;
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
	std::string DateToString(time_t);
private:
	std::fstream m_file;
	std::string m_filepath;
};


#endif
