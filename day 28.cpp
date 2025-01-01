    bool found = false;
    for (auto& task : tasks) {
        if (task.number == number){
            if (!task.isCompleted){
                task.isCompleted = true;
                cout << "Task no. " << number << ", Marked as Completed!\n";
            } else {
                cout << "Task no. " << number << ", has Already Marked.\n";
            }
            found = true;
            break;
        }
    }