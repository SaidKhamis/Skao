#include<iostream>
#include<string>
#include<vector>

using namespace std;

//Defining class Task
struct Task {
	int number;
	string description;
	string deadline;
	bool isCompleted;
	
	void display() const {
		cout << number << ". " << description << ",  Deadline:(" << deadline << ")"; 
	}
};

//function prototypes
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markcompletedTask(vector<Task>& task);
void deleteTask(vector<Task>& task);

//Main function
int main() {
	vector<Task> tasks;      //variable to store the tasks
	int choice;              //temporary variable to store user choice.
	
	do {
		//Choices to choose for running the to-do list manager
		cout << "\n <==== To-Do List Manager ====> \n";
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

//Function to view Tasks
void viewTasks(const vector<Task>& tasks) {
	if (tasks.empty()) {
		//Program search for any task added if not it will display message below.
		cout << "\nNo Task Added Yet.\n";
		return;
		
	} else {
		//Othherwise if the program find any task it will do this.
		
		cout << "\n <==== To-Do List ====> \n";

		for(const auto& task : tasks) {
			task.display();
						
			if(task.isCompleted) {
				cout << " [Completed].\n";
			}
			cout << endl;
		}
	}
}

// Function to Mark Completed Tasks
void markcompletedTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo Task Available to Mark.\n";
        return;
    }

    cout << "\n  Available Tasks:\n";
    for (const auto& task : tasks) {
        cout << task.number << ". " << task.description;
        if (task.isCompleted) {
            cout << " [Completed]";
        }
        cout << "\n";
    }
	
	//update here
	string cont;
	do {
		int number;
       	cout << "\nEnter Number of the Task to Mark as Completed: ";
    	cin >> number;

    	bool found = false;
    	for (auto& task : tasks) {
	        if (task.number == number){
	            if (!task.isCompleted){
	                task.isCompleted = true;
	                cout << "Task no. " << number << ", Marked as Completed!\n";
	            } else {
	                cout << "Task no. " << number << ", has Already Been Marked.\n";
	            }
	            found = true;
	            break;
	       	}
	    } 
	
	    if (!found) {
	        cout << "Invalid Task Number.\n";
	    }	
	    
	    cout << "Click 'y' to Mark More, or 'n' to Stop Marking: "; 
	    cin >> cont;
	} 
	while(cont == "y");
	return;
}


// Function to Delete a Task
void deleteTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo Task Available to Delete.\n";
        return;
    } 

    cout << "\n  Available Tasks:\n";
    for (const auto& task : tasks) {
        cout << task.number << ". " << task.description;
        if (task.isCompleted) {
            cout << " [Completed]";
        }
        cout << "\n";
    }

    int number;
    cout << "\nEnter Number of the Task to Delete: ";
    cin >> number;

    // Find and erase the task
    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->number == number) {
            tasks.erase(it);
            cout << "Task no(" << number << ") Deleted Successfully!\n";
            return;
        }
    }

    cout << "Task no.(" << number << ") not Found.\n";
}

//The end of the program