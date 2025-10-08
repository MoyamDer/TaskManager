#include <iostream>
#include <limits>

void addTask(std::string*& mass, int& size){
    std::string selection;
    std::string task; 
    std::cout << "======ADD MENU======" << "\n" << "\n";
    std::cout << "enter 'exit' to back to menu" << std::endl;

    while(true){
        std::cout << "add a task's: " << std::endl;
        std::getline(std::cin, task);
        if (task == "exit"){
            system("cls");
            break;
        }
        std::string* newMass = new std::string[size+1];
        for (int i{0}; i != size; i++){
            newMass[i] = mass[i];
        }
        newMass[size] = task;

        delete[] mass;
        mass = newMass;
        size++;
    }
    
}

void tasksList(std::string*& mass, int& size){
    std::string selection;
    std::cout << "======TASK LIST======" << std::endl; 
    for (unsigned int i{0}; i != size; i++){
        std::cout << i+1 << ": " << mass[i] << "\n";
    }
    while(true){
        std::cout << "enter 'exit' to back to menu" << std::endl;
        std::cin >> selection;
        if (selection == "exit"){
            system("cls");
            return;
        }
    }

}

void deleteTask(std::string*& mass, int& size){
    std::string selection;
    while (true){
        std::cout << "enter 'exit' to back to menu" << std::endl;
        std::cout << "to delete task type anithing" << std::endl;
        std::cin >> selection;
        if (selection == "exit"){
            system("cls");
            return;
        }
        else{
        system("cls");
        for (unsigned int i{0}; i != size; i++){
            std::cout << i + 1 << ": " << mass[i] << "\n";
        }
        std::cout << "enter tasks which you would like to delete" << std::endl;
        unsigned int numberDel = {};
        std::cin >> numberDel;
         std::string* newMass = new std::string[size-1];
        for (int i{0}, g{0}; i != size; i++){
            if (i != numberDel - 1){
            newMass[g++] = mass[i];
            }
        }
        delete[]mass;
        mass = newMass;
        size--;
        }
    }
}

int main(){
    int size {0};
    std::string selection {};
    std::string* mass {nullptr};
    do{
        std::cout << "====== MENU ======" << "\n" << "\n";
        std::cout << "1. Add task" << std::endl;
        std::cout << "2. Delete task" << std::endl;
        std::cout << "3. Task's list" << std::endl;
        std::cout << "Enter section: " << std::endl;
        std::cout << "Enter 'exit' to exit from programm" << std::endl;
        std::cin >> selection;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (selection == "1"){
            system("cls");
            addTask(mass, size); 
        }
        if (selection == "2"){
            system("cls");
            deleteTask(mass, size);
        }
        if (selection == "3"){
            system("cls");
            tasksList(mass, size);
        }
    } while(selection != "exit");
    delete[] mass;
}