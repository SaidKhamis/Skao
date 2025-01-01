    cout << "\n  Available Tasks:\n";
    for (const auto& task : tasks) {
        cout << task.number << ". " << task.description;
        if (task.isCompleted) {
            cout << " [Completed]";
        }
        cout << "\n";
    }