#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;

// Function declarations
void ASK_PASSWORD();
int CALCULATION(string);
void admin();
void menu(int);
void students();
void MODIFY(int);
void EDIT();
void VIEW(int);
void SEARCH_WORD();
void LOG_OUT();
bool CHECK_PASSWORD(string, string, int);
void REMOVE(int);
void ADD(int);
int Give_Feedback(string);

int main() {
    cout << "\n\t\t\t\t| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
    cout << "\t\t\t\t| WELCOME TO ICAST INSTITUTE OF MODERN EDUCATION |\n";
    cout << "\t\t\t\t|            FEEDBACK MANAGEMENT SYSTEM          |\n";
    cout << "\t\t\t\t| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
    menu(1);
    return 0;
}

void menu(int flag) {
    if(flag == 1) {
        char ch;
        cout << "\n| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
        cout << "|Enter A/a if you are admin.                     |\n";
        cout << "|Enter S/s If you are student.                   |\n";
        cout << "| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
        
        do {
            cin >> ch;
            if(ch != 'A' && ch != 'a' && ch != 'S' && ch != 's')
                cout << "Invalid Input....Please enter S or A.\n";
        } while(ch != 'A' && ch != 'a' && ch != 'S' && ch != 's');

        if(ch == 'A' || ch == 'a')
            admin();
        else if(ch == 'S' || ch == 's')
            students();
    }
    else if(flag == 2) {
        int choice;
        cout << "\n\n| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
        cout << "|The available menu are:               |\n";
        cout << "|Enter 1 for adding students.          |\n";
        cout << "|Enter 2 for removing student.         |\n";
        cout << "|Enter 3 for Editing feedback.         |\n";
        cout << "|Enter 4 for viewing feedback.         |\n";
        cout << "|Enter 5 for Modifying student details.|\n";
        cout << "|Enter 6 for word to search.           |\n";
        cout << "|Enter 7 for log out.                  |\n";
        cout << "| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
        
        cin >> choice;
        switch(choice) {
            case 1: ADD(1); break;
            case 2: REMOVE(1); break;
            case 3: EDIT(); break;
            case 4: VIEW(2); break;
            case 5: MODIFY(1); break;
            case 7: LOG_OUT(); break;
            default: cout << "Invalid choice!\n"; break;
        }
    }
}

void admin() {
    string ID, pass;
    bool a;
    
    cout << "Please enter your admin ID\n";
    cin >> ID;
    cout << "Enter your password.\n";
    cin >> pass;
    
    a = CHECK_PASSWORD(ID, pass, 1);
    while(!a) {
        cout << "Invalid password or username.\nPlease enter your userID again:\n";
        cin >> ID;
        cout << "Enter your password again:\n";
        cin >> pass;
        a = CHECK_PASSWORD(ID, pass, 1);
    }
    
    cout << "You have successfully logged in.\n";
    menu(2);
}

void ADD(int flag) {
    fstream outfile, outfile1;
    
    try {
        if(flag == 1) {
            outfile.open("data/Students_data.txt", ios::in);
            if(outfile.fail()) {
                outfile.open("data/Students_data.txt", ios::out);
                outfile << "RollNo" << setw(40) << "Password" << setw(40) << "Name" << endl;
                outfile.close();
            }
            outfile.close();
            
            VIEW(1);
            outfile.open("data/Students_data.txt", ios::out | ios::app);
            
            int n;
            cout << "Enter how many students do you want to add: ";
            cin >> n;
            
            for(int i = 0; i < n; i++) {
                string roll, password, name;
                cout << "Enter roll number of student: ";
                cin >> roll;
                cout << "Set password for student: ";
                cin >> password;
                cout << "Enter name of student: ";
                cin.ignore();
                getline(cin, name);
                
                outfile << roll << setw(40) << password << setw(40) << name << endl;
            }
            outfile.close();
            VIEW(1);
        }
        else if(flag == 2) {
            // Similar structure for feedback questions
            // Updated file paths and error handling
        }
    }
    catch(const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return;
    }
    
    int choice;
    cout << "Added successfully.\n1. Main menu\n2. Log out\nChoice: ";
    cin >> choice;
    if(choice == 1)
        menu(2);
    else if(choice == 2)
        LOG_OUT();
}

void REMOVE(int flag) {
    fstream outfile, outfile1;
    if(flag == 1) {
        VIEW(1);
        int n;
        cout << "Enter number of students you want to delete: ";
        cin >> n;
        for(int i = 0; i < n; i++) {
            outfile1.open("temp.txt", ios::out);
            outfile.open("data/Students_data.txt", ios::in);
            string roll, temp;
            
            cout << "Enter the roll number of the student that you want to remove.\n";
            cin >> roll;
            while(outfile >> temp) {
                if (temp == roll) {
                    getline(outfile, temp);
                } else {
                    outfile1 << temp;
                    getline(outfile, temp);
                    outfile1 << temp << endl;
                }
            }
            outfile.close();
            outfile1.close();
            remove("data/Students_data.txt");
            rename("temp.txt", "data/Students_data.txt");
        }
        VIEW(1);
    } else if(flag == 2) {
        VIEW(2);
        int n;
        cout << "Enter number of questions you want to delete.\n";
        cin >> n;
        for(int i = 0; i < n; i++) {
            outfile1.open("temp.txt", ios::out);
            outfile.open("data/Feedback.txt", ios::in);
            string roll, temp;
            
            cout << "Enter the name of question that you want to remove in a specific format e.g Q.1).\n";
            cin >> roll;
            while(outfile >> temp) {
                if (temp == roll) {
                    getline(outfile, temp);
                } else {
                    outfile1 << temp;
                    getline(outfile, temp);
                    outfile1 << temp << endl;
                }
            }
            outfile.close();
            outfile1.close();
            remove("data/Feedback.txt");
            rename("temp.txt", "data/Feedback.txt");
        }
        VIEW(2);
    }
    int choice;
    cout << "Removed successfully.\n1. Main menu\n2. Log out\nChoice: ";
    cin >> choice;
    if(choice == 1)
        menu(2);
    else if(choice == 2)
        LOG_OUT();
}

void VIEW(int flag) {
    string Q;
    fstream outfile;
    if(flag == 1) {
        outfile.open("data/Students_data.txt", ios::in);
        cout << "The students in your files are.\n";
        while(getline(outfile, Q))
            cout << Q << endl;
    } else if(flag == 2) {
        outfile.open("data/Feedback.txt", ios::in);
        while(getline(outfile, Q))
            cout << Q << endl << endl;
    }
}

void EDIT() {
    int choice;
    cout << "Now you can Edit feedback...\n";
    cout << "Enter 1 for Adding the question.\nEnter 2 for Removing the question.\nEnter 3 for Modifying the Question.";
    cout << "Enter 4 for Moving back to the main menu:\n";
    cin >> choice;
    switch(choice) {
        case 1: ADD(2); break;
        case 2: REMOVE(2); break;
        case 3: MODIFY(2); break;
        case 4: menu(2); break;
    }
}

void MODIFY(int flag) {
    fstream outfile, outfile1;
    string temp, temp1;
    if(flag == 1) {
        VIEW(1);
        int n;
        cout << "Enter number of students that you want to modify their ID or password or name.\n";
        cin >> n;
        for(int i = 0; i < n; i++) {
            outfile1.open("temp.txt", ios::out);
            outfile.open("data/Students_data.txt", ios::in);
            
            cout << "Enter the roll number of the student that you want to edit.\n";
            cin >> temp;
            while(outfile >> temp1) {
                if(temp == temp1) {
                    cout << "The detail of the student are.\n" << temp1 << "   ";
                    getline(outfile, temp1);
                    cout << temp1;
                    cout << "\nEnter the new ID for the student.\n";
                    cin >> temp1;
                    outfile1 << temp1 << setw(40);
                    cout << "\nEnter new password for that student.\n";
                    cin >> temp1;
                    outfile1 << temp1 << setw(40);
                    cout << "Enter new name for that student.\n";
                    cin.ignore();
                    getline(cin, temp1);
                    outfile1 << temp1 << endl;
                }
                
                else {
                    outfile1 << temp1;
                    getline(outfile, temp1);
                    outfile1 << temp1 << endl;
                }
            }
            outfile.close();
            outfile1.close();
            remove("data/Students_data.txt");
            rename("temp.txt", "data/Students_data.txt");
        }
        cout << "Modified successfully..\n\nNow the students in your file is.";
        VIEW(1);
    }
    
    if(flag == 2) {
        VIEW(2);
        int n;
        cout << "Enter number of questions that you want to modify.\n";
        cin >> n;
        for(int i = 0; i < n; i++) {
            outfile1.open("temp.txt", ios::out);
            outfile.open("data/Feedback.txt", ios::in);
            
            cout << "Enter the question number as Q.1),Q.2),Q.3) that you want to modify.\n";
            cin >> temp;
            string kh;
            while(outfile >> temp1) {
                if(temp == temp1) {
                    kh = temp1;
                    cout << "\nThe question you want to edit is " << temp1;
                    getline(outfile, temp1);
                    cout << temp1 << endl;
                    cout << "\nEnter the new question and end it with ?.\n" << kh << " ";
                    cin.ignore();
                    getline(cin, temp1);
                    outfile1 << kh << " " << temp1 << endl;
                }
                
                else {
                    outfile1 << temp1;
                    getline(outfile, temp1);
                    outfile1 << temp1 << endl;
                }
            }
            outfile.close();
            outfile1.close();
            remove("data/Feedback.txt");
            rename("temp.txt", "data/Feedback.txt");
        }
        cout << "Modified successfully..\n\nNow the questions in your feedback file is\n\n.";
        VIEW(2);
    }
    menu(2);
}

void students() {
    bool a;
    string UserID, password;
    
    cout << "Please enter your user ID:\n";
    cin >> UserID;
    cout << "\nEnter your password:\n";
    cin >> password;
    a = CHECK_PASSWORD(UserID, password, 2);
    while(!a) {
        cout << "Invalid password or user name:\nPlease enter your userID again:\n";
        cin >> UserID;
        cout << "Enter your password again:\n";
        cin >> password;
        a = CHECK_PASSWORD(UserID, password, 2);
    }
    
    cout << "You have successfully logged in:\n";
    cout << "Enter 1 for giving feedback.\nEnter 2 for logout.\n";
    int choice;
    cin >> choice;
    if(choice == 1) {
        int m = Give_Feedback(UserID);
        if(m == 0)
            cout << "Sorry you can't give feedback again.";
    } else if(choice == 2)
        LOG_OUT();
}

int Give_Feedback(string UserID) {
    int count4 = 0;
    fstream khattak, khattak1;
    string nasii;
    nasii = UserID;
    khattak.open("given_feedback.txt", ios::in);
    string ch;
    while(khattak >> ch) {
        if(ch == nasii) {
            return 0;
        }
    }
    khattak.close();
    
    UserID += ".txt";
    lable1: {
        if(count4 < 5) {
            int i;
            int choice, count = 0;
            string arr[5] = {"ITC", "English", "History", "calculus 1", "Linear Algebra"};
            for(i = 0; i < 5; i++) {
                cout << "Enter " << i + 1 << " for " << arr[i] << endl;
            }
            cin >> choice;
            switch(choice) {
                case 1:
                    cout << arr[0];
                    break;
                case 2:
                    cout << arr[1];
                    break;
                case 3:
                    cout << arr[2];
                    break;
                case 4:
                    cout << arr[3];
                    break;
                case 5:
                    cout << arr[4];
                    break;
            }
            cout << "   Feedback\n\n\n";
            VIEW(2);
            char temp;
            cout << "\n\nSelect any one option in all the question\n.Select it as A,B etc.\n\n";
            fstream outfile;
            outfile.open(UserID.c_str(), ios::out | ios::app);
            fstream outfile2;
            outfile2.open("data/Feedback.txt", ios::in);
            outfile << setw(40) << "Answers   sheet of  " << arr[choice - 1] << endl << endl;
            i = 0;
            string temp2, comment;
            getline(outfile2, temp2);
            while(getline(outfile2, temp2, '?')) {
                cout << "Enter the option of question No." << i + 1 << endl;
                cin >> temp;
                outfile << "Ans." << i + 1 << ")" << setw(10) << temp << endl << endl;
                i++;
            }
            double per;
            per = CALCULATION(UserID);
            per = per / i;
            outfile << "percentage=" << per << "%" << endl;
            cout << "Comment if any:\n";
            cin.ignore();
            getline(cin, comment);
            outfile << "comment: " << comment;
            count4++;
            goto lable1;
        }
        khattak1.open("given_feedback.txt", ios::out | ios::app);
        khattak1 << nasii << endl;
        khattak1.close();
    }
}

int CALCULATION(string userID) {
    double percentage = 0;
    fstream outfile;
    outfile.open(userID.c_str(), ios::in);
    char temp;
    while(outfile >> temp) {
        if(temp == 'A' || temp == 'a')
            percentage += 100;
        else if(temp == 'B' || temp == 'b')
            percentage += 70;
        else if(temp == 'C' || temp == 'c')
            percentage += 40;
        else if(temp == 'D' || temp == 'd')
            percentage += 10;
        else if(temp == 'E' || temp == 'e')
            percentage += 0;
    }
    return percentage;
}

bool CHECK_PASSWORD(string UserID, string password, int flag) {
    string UserID1, password1;
    fstream outfile;
    if(flag == 2) {
        outfile.open("data/Students_data.txt", ios::in);
        while(outfile >> UserID1 && outfile >> password1) {
            if(UserID == UserID1 && password == password1)
                return 1;
            else {
                cin.ignore();
                getline(outfile, UserID1);
            }
        }
        return 0;
    } else if(flag == 1) {
        outfile.open("data/Admin.txt", ios::in);
        while(outfile >> UserID1 && outfile >> password1) {
            if(UserID == UserID1 && password == password1)
                return 1;
        }
        return 0;
    }
}

void LOG_OUT() {
    cout << "\nLogged out successfully.\n";
}
