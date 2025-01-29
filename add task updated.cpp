//Function to add Task
void addTask(vector<Task>& task){
	int stop;
	do{
		Task newTask;         //Creating object newTask for the class Task and as variable to store tasks added at the moment.
		cout << "\nEnter Task number: ";
		cin >> newTask.number;
		cin.ignore();		//Clearing the input buffer to avoid incorect code behaving in executioning.
		
		cout << "Enter Task descriptions: ";
		getline(cin, newTask.description);
		
		cout << "Enter Task Deadline (eg. DD/MM/YYYY or 'No deadline'): ";
		getline(cin, newTask.deadline);
		newTask.isCompleted = false;		//Assigning newTask equal to false as it is not completed.
		
		task.push_back(newTask);			//Storing the added task and provide feedbak below.
		cout << "    Task Added Successfully! \n";
		cout << "\n  NB: Press 0 to continue Task addition," << endl << "  Otherwise Press 1" << endl;
		cin >> stop;	
	}
    while(stop==0);
    return;
}