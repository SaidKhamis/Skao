void viewTasks(const vector<Task>& tasks) {
	if (tasks.empty()) {
		//Program search for any task added if not it will display message below.
		cout << "\nNo Task Added Yet.\n";
		return;
	}