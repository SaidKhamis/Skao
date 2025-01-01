void markcompletedTask(vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo Task Available to Mark.\n";
        return;
    }