# todo
A command line tool for tracking your todo items.
This tool was orginally developed as a project for me to practice with.

usage: todo [options] required_input required_input2
  options:
    -a,                      Add a task to the todo list
    -f,                      Load task list from file
    -r required_input        removes the specified task number

#UPDATES
11/30/23 - Fixed the parser which would throw std::invalid_argument if the user had a comma (',') in their title or description. Changed delimter to ';'.
9/22/23 - Fixed bug which resulted in deletion of unrelated task, added early error handling into main function to filter out majority of modification OUT_OF_BOUNDS errors.
5/25/23 - Added a timestamp to the creating of each task. time_t, accessable at Task.created_on . 

#BUGS
5/27/23 - When no output file exists and the user adds the -a flag, the program ask the user if they want to create a new file. If they select 'y' it skips the title input and goes straight to detail. Easy fix is to terminate the program and have them renter the command but the ideal fix is to eliminate that issue.

