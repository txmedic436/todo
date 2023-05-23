//NAME:TODO
//VERSION: 1.0
//AUTHOR: TxMedic436
//DESCRIPTION: A command line tool to help organize your todo lists.
//LICENSE: GPL GNU 3.0

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>

#include "list.h"


int main(int argc, char* argv[]){
	int option, delete_param, edit_param;
	std::string filepath = ".todo.dat";
	bool flag_add = false;
	bool flag_delete = false;
	bool flag_edit = false;

	while((option = getopt(argc, argv, "a:f:r:")) != -1){
		switch(option){
			case 'a':
				flag_add = true;
				break;
			case 'e':
				flag_edit = true;
				edit_param = atoi(optarg) - 1;
			case 'r':
				flag_delete = true;
				delete_param = atoi(optarg);
				break;
			case 'f':
				filepath = optarg;
				break;
			default:
				std::cout << "Usage: " << std::endl;
				exit(EXIT_FAILURE);
		}
	}
	
	List tasklist(filepath);
	
	//Start to actions on task list, order of the functions is important
	if(flag_add){
		std::string title, detail;
		unsigned priority;
		std::cout << "Add task\nTitle: ";
		getline(std::cin, title);
		std::cout << "Add detail: ";
		getline(std::cin, detail);
		std::cout << "Priority: ";
		std::cin >> priority;
		tasklist.Add({title, detail, priority});
	}

	if(flag_delete){
		tasklist.RemoveTask(delete_param);
	}

	if(flag_edit){
		tasklist.EditTask(edit_param);	
	}

	//Display tasklist and save to file
	tasklist.PrintList();
	tasklist.WriteFile();

	return 0;

}
