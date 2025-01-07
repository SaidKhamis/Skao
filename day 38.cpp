    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->number == number) {
            tasks.erase(it);
            cout << "Task no(" << number << ") Deleted Successfully!\n";
            return;
        }
    }