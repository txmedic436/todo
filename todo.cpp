//NAME:TODO
//VERSION: 1.0
//AUTHOR: TxMedic436
//DESCRIPTION: A command line tool to help organize your todo lists.


#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <unistd.h>

struct Task {
	std::string title;
	std::string detail;
};

//Function Prototypes
void add_tasks(std::vector<Task>* pTasks);
void remove_task(std::vector<Task>* pTasks, int i = 0);

int main(int argc, char* argv[]){
	int option, param;
	bool flag_add = false;
	bool flag_delete = false;

	while((option = getopt(argc, argv, "ar:")) != -1){
		switch(option){
			case 'a':
				flag_add = true;
				break;
			case 'r':
				flag_delete = true;
				param = atoi(optarg);
				break;
			default:
				std::cout << "Usage: " << std::endl;
		}
	}


	std::vector<Task> tasks;

	std::ifstream in_file(".todo.dat");
	if(!in_file.is_open()){
		std::cout << "Unable to open data file.\n";
		exit(EXIT_FAILURE);
		//Condsider providing option to create data file or enter file path.
	}

	//Read File
	std::string line;
	while(getline(in_file, line)){
        Task buffer = {};
        std::stringstream linestream(line);
        std::string value;
	
        getline(linestream, value, ',');
        buffer.title = value;
        getline(linestream, value);
        buffer.detail = value;
        tasks.push_back(buffer);
	}

	in_file.close();

	if(flag_add){
		add_tasks(&tasks);
	}

	if(flag_delete){
        	remove_task(&tasks, param);
	}


	if(tasks.size() == 0){
		std::cout << "No tasks to display\n";
		exit(EXIT_SUCCESS);
	}

	//Display the tasks on the screen
	for(int i = 0; i < tasks.size(); i++){
		std::cout << i+1 << ": " << tasks[i].title << "\n";
	       	if(!tasks[i].detail.empty()){
			std::cout << "\t" << tasks[i].detail << std::endl;
		}
	}

	//Rewrite the tasks to the data file
	std::ofstream out_file(".todo.dat", std::ios::trunc);
	for(int i = 0; i < tasks.size(); i++){
        	out_file << tasks[i].title << "," << tasks[i].detail << std::endl;
	}
	out_file.close();

	return 0;
}

void add_tasks(std::vector<Task> *pTasks){
	std::string title;
	std::string detail;

	std::cout << "Enter Title: ";
	getline(std::cin, title);
	std::cout << "Enter Detail: ";
	getline(std::cin, detail);

	if(title.empty()){
        std::cerr << "Task requries a title\n";
        exit(EXIT_FAILURE);
	}
	
    	pTasks->push_back(Task{title, detail});
}

void remove_task(std::vector<Task> *pTasks, int i){
    if(i > pTasks->size()){
        std::cerr << "Invalid task\n";
        exit(EXIT_FAILURE);
    }

    else {
        pTasks->erase(pTasks->begin() + (i-1));
    }
}