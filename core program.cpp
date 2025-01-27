int main() {
	vector<Task> tasks;      //variable to store the tasks
	int choice;              //temporary variable to store user choice.
	
	do {
		//Choices to choose for running the to-do list manager
		cout << "\n <==== To Do List Manager ====> \n";
		cout << "1. Add Task.\n";
		cout << "2. View Tasks.\n";
		cout << "3. Mark Task as Completed.\n";
		cout << "4. Delete Task.\n";
		cout << "5. Exit.\n";
		cout << " <=============================>\n";
		cout << "Enter your choice: ";
		cin >> choice;
		
		switch(choice) {
			case 1:
				addTask(tasks);
				break;
				
			case 2:
				viewTasks(tasks);
				break;
				
			case 3:
				 markcompletedTask(tasks);
				 break;
				
			case 4:
				deleteTask(tasks);
				break;
				
			case 5:
				cout << "Exiting the program.\n";
				
			default:
				cout << "Invalid choice,Please Try Again.\n";
		}
	} while(choice != 5);   //Loop up to when user choose 5 will terminate.
	
	return 0;
}