# todo
A command line tool for tracking your todo items.
This tool was orginally developed as a project for me to practice with.

usage: todo [options] required_input required_input2
  options:
    -a,                      Add a task to the todo list
    -f,                      Load task list from file
    -r required_input        removes the specified task number

#UPDATES
5/25/23 - Added a timestamp to the creating of each task. time_t, accessable at Task.created_on . 

BUGS:

5/24/23 - Edit task function changes the task but seems to be deleting the previous task.
5/4/23 - Fixed bug which did not allow the creation of a data file. Program now ask user if they want to create a new file.
