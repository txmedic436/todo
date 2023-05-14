#include <iostream>
#include <fstream>
#include <sstream>
#include "list.h"

List::List(){
	if(OpenFile() == 1){
		exit(EXIT_FAILURE);
	}
	else LoadFile();
}

List::List(std::string filepath){
	m_filepath = filepath;
	if(OpenFile() == 1){
		exit(EXIT_FAILURE);
	}
	else LoadFile();
}

void List::Add(Task task){
	m_list.push_back(task);
}

void List::PrintTask(Task* task){
	std::cout << task->title << std::endl << "\t" << task->detail << std::endl;
}

void List::PrintList(){
	for(int i = 0; i < m_list.size(); i++){
		std::cout << i + 1 << ": ";
		PrintTask(&m_list[i]);
	}
}

void List::RemoveTask(size_t taskID){
	if(taskID > m_list.size()){
		std::cerr << "Invalid task ID\n";
		exit(EXIT_FAILURE);
	}
	m_list.erase(m_list.begin() + (taskID - 1));
}


//This function keeps deleting the element after the change is made
void List::EditTask(size_t taskID){
	std::string buffer;
	
	std::cout << "Current Title: " << m_list.at(taskID - 1).title << std::endl;
	std::cout << "New Title: ";
	getline(std::cin, buffer);
	if(!buffer.empty()){
		m_list.at(taskID - 1).title = buffer;
	}
	std::cout << "Current Description: " << m_list.at(taskID - 1).detail << std::endl;
	std::cout << "New Descritpion: ";
	getline(std::cin, buffer);
	if(!buffer.empty()){
		m_list.at(taskID - 1).detail = buffer;
	}
}

int List::OpenFile(){
	m_file.open(m_filepath, std::ios::in);
	if(m_file.fail()){
		std::cerr << "Unable to open " << m_filepath << std::endl;
		char option;
		std::cout << "Would you like to create it(y/n)? ";
		std::cin.get(option);
		if(option == 'y' || option == 'Y'){
			m_file.open(m_filepath, std::ios::out);
			m_file.close();
			m_file.open(m_filepath, std::ios::in);
			return 0;
		}
		else return 1;
	}
	else return 0;
}

void List::LoadFile(){
	std::string line;
	while(getline(m_file, line)){
		Task buffer_task = {};
		std::stringstream linestream(line);
		std::string value;

		getline(linestream, value, ',');
		buffer_task.title = value;
		getline(linestream, value);
		buffer_task.detail = value;
		m_list.push_back(buffer_task);
	}

	m_file.close();
}

void List::WriteFile(){
	m_file.open(m_filepath, std::ios::trunc | std::ios::out);
	for(int i = 0; i < m_list.size(); i++){
		m_file << m_list[i].title << "," << m_list[i].detail << std::endl;
	}
	m_file.close();
}

List::~List(){
	if(m_file.is_open()){
		m_file.close();
	}
}


