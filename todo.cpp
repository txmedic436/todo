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
    std::string filepath = ".todo.dat";

	while((option = getopt(argc, argv, "af:r:")) != -1){
		switch(option){
			case 'a':
				flag_add = true;
				break;
			case 'r':
				flag_delete = true;
				param = atoi(optarg);
				break;
			case 'f':
				filepath = optarg;
				break;
			default:
				std::cout << "Usage: " << std::endl;
		}
	}


	std::vector<Task> tasks;

	std::ifstream in_file(filepath);
	if(in_file.fail()){
		char selection;
        std::cout << "Unable to open " << filepath << std::endl;
        std::cout << "Would you like to create a new data file?(y/n)";
		std::cin >> selection;
        if(selection == 'y' || selection == 'Y'){
            std::ofstream file(filepath);
            if(!file.is_open()){
                std::cerr << "Unable to create " << filepath << std::endl;
                exit(EXIT_FAILURE);
            }
            else {
                std::cout << "Created " << filepath << std::endl;
                file.close();
            }
           in_file.close();	
	}
       else exit(EXIT_FAILURE);
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
	std::ofstream out_file(filepath, std::ios::trunc);
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
