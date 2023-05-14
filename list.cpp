#include <iostream>
#include <fstream>
#include <sstream>
#include "list.h"

List::List(){
	if(!OpenFile(m_filepath, std::ios::in)){
		exit(EXIT_FAILURE);
	}
}

List::List(std::string filepath){
	m_filepath = filepath;
	if(!OpenFile(m_filepath, std::ios::in)){
		exit(EXIT_FAILURE);
	}
}

bool File:: OpenFile(std::ios::fmtflags flag){
	file.open(m_filepath, flag);
	if(!file.is_open()){
		std::cerr << "Unable to open " << m_filepath << std::endl;
		if(flag == std::ios::in){
			char option;
			std::cout << "Would you like to create it(y/n)? ";
			std::cin.get(option);
			if(option == 'y' || option == 'Y'){
				OpenFile(m_filepath, std::ios::out);
				file.close();
				file.open(m_filepath, std::ios::in);
				return true;
			}
			else return false;
		}
	else return true;
}


List::~List(){
	if(file.open()){
		file.close();
	}
}


