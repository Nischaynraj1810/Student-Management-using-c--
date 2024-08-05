#include <iostream>
#include <vector>
#include <string>

using namespace std;


class User {
protected:
    string name;
    string id; 
    )
public:
    User(string name, string id) : name(name), id(id) {}
    void changeInformation(string newName, string newId) {
        name = newName;
        id = newId;
    }
    string getName() const { return name; }
    string getId() const { return id; }
};


class Student : public User {
private:
    vector<string> assignments;
    char grade;  
public:
    Student(string name, string id) : User(name, id), grade('N') {}
    void submitAssignment(const string& assignment) {
        assignments.push_back(assignment);
    }
    void setGrade(char newGrade) { 
        grade = newGrade;
    }
    void displayInfo() const {
        cout << "Name: " << name << "\nID: " << id << "\nAssignments: ";
        if (assignments.empty()) {
            cout << "None";
        } else {
            for (const auto& assignment : assignments) {
                cout << assignment << "; ";
            }
        }
        cout << "\nGrade: " << grade << endl; 
    }
};

class Teacher : public User {
public:
    Teacher(string name, string id) : User(name, id) {}
    void gradeStudent(Student &student, char grade) {
        student.setGrade(grade); 
        cout << "Graded " << student.getName() << " with grade " << grade << endl;
    }
    void displayInfo() const {
        cout << "Name: " << name << "\nTeacher ID: " << id << endl; 
    }
};

int main() {
    string name, id, task;
    char grade;
    int choice;

    cout << "Create Student\n";
    cout << "Enter student name: ";
    getline(cin, name);
    cout << "Enter student ID: "; 
    getline(cin, id);
    Student student(name, id);

    cout << "Create Teacher\n";
    cout << "Enter teacher name: ";
    getline(cin, name);
    cout << "Enter teacher ID: ";
    getline(cin, id);
    Teacher teacher(name, id);

    do {
        cout << "\nMenu:\n";
        cout << "1. Change Student Information\n";
        cout << "2. Submit Assignment\n";
        cout << "3. Grade Student\n";
        cout << "4. Display Student Info\n";
        cout << "5. Display Teacher Info\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                cout << "Enter new student name: ";
                getline(cin, name);
                cout << "Enter new student ID: ";  to ID
                getline(cin, id);
                student.changeInformation(name, id);
                cout << "Student information updated.\n";
                break;
            case 2:
                cout << "Enter assignment: ";
                getline(cin, task);
                student.submitAssignment(task);
                cout << "Assignment submitted.\n";
                break;
            case 3:
                cout << "Enter grade (e.g., A, B, C): ";
                cin >> grade;
                teacher.gradeStudent(student, grade);
                break;
            case 4:
                student.displayInfo();
                break;
            case 5:
                teacher.displayInfo(); 
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice, please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
