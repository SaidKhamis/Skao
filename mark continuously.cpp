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