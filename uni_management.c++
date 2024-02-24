#include <iostream>
#include <string>
#include <fstream> // Include the file handling library

using namespace std;

class university {
private:
    int password;
    int pass, a;
    string id;

public:
    void getstudentdata() {
        string s_name;
        int rollnum;
        float cgpa;
        int mob_num;
        char section;
        cout << "ENTER NAME OF THE STUDENT: ";
        cin >> s_name;
        cout << "ENTER ROLL NUMBER: ";
        cin >> rollnum;
        cout << "ENTER YOUR CGPA: ";
        cin >> cgpa;
        cout << "ENTER MOBILE NUMBER: ";
        cin >> mob_num;
        cout << "ENTER SECTION: ";
        cin >> section;

        // Open a file in append mode
        ofstream outfile;
        outfile.open("student_records.txt", ios::app);

        // Write the student data to the file
        outfile << "Name: " << s_name << "\nRoll Number: " << rollnum << "\nCGPA: " << cgpa
                << "\nMobile Number: " << mob_num << "\nSection: " << section << endl;

        // Close the file
        outfile.close();
    }

    void loadstudentdata() {
        // Open the file in read mode
        ifstream infile("student_records.txt");
        if (infile.is_open()) {
            string line;
            while (getline(infile, line)) {
                cout << line << endl;
            }
            infile.close();
        } else {
            cout << "Unable to open the file." << endl;
        }
    }
    
    void getteacherdata() {
        string t_name;
        int teacher_id;
        int mob_num;
        string qualification;
        cout << "ENTER NAME OF THE TEACHER: ";
        cin >> t_name;
        cout << "ENTER ID: ";
        cin >> teacher_id;
        cout << "ENTER MOBILE NUMBER: ";
        cin >> mob_num;
        cout << "ENTER QUALIFICATION: ";
        cin >> qualification;

        // Open a file in append mode
        ofstream outfile;
        outfile.open("teacher_records.txt", ios::app);

        // Write the teacher data to the file
        outfile << "Name: " << t_name << "\nID: " << teacher_id << "\nMobile Number: " << mob_num
                << "\nQualification: " << qualification << endl;

        // Close the file
        outfile.close();
    }

    void loadteacherdata() {
        // Open the file in read mode
        ifstream infile("teacher_records.txt");
        if (infile.is_open()) {
            string line;
            while (getline(infile, line)) {
                cout << line << endl;
            }
            infile.close();
        } else {
            cout << "Unable to open the file." << endl;
        }
    }
    
    void course() {
        cout << " LIST OF ASSIGNED COURSES ARE " << endl;
        cout << "1) OOP : OBJECT ORIENTED PROGRAMMING " << endl;
        cout << "2) LA  : LINEAR ALGEBRA " << endl;
        cout << "3) SNS : SIGNALS AND SYSTEM " << endl;
        cout << "4) CAO : COMPUTER ARCHITECHTURE AND ORGANIZATION " << endl;
        cout << "5) ED  : ENGINEERING DRAWING " << endl;
        cout << "6) PME : PROBABILITY METHOD IN ENGINEERING" << endl;
    }
    
    void details()
    {
    	cout<<" \t\t\t\t\t*SEMESTER DETAILS* "<<endl;
    	cout<<"\n FROM "<<"\t\t\t TO"<<"\t\t STUDY WEEK"<<"\t\t DECRIPTION OF ACTIVITIES"<<endl;
    	cout<<"\n 13-MARCH-2023 "<<"\t\t18-MARCH-2023"<<"\t\t1"<<"\t\tCLASSES/REGISTRATION"<<endl;
    	cout<<"\n 20-MARCH-2023 "<<"\t\t25-MARCH-2023"<<"\t\t2"<<"\t\tCLASSES/QUIZES"<<endl;
    	cout<<"\n 27-MARCH-2023 "<<"\t\t01-APRIL-2023"<<"\t\t3"<<"\t\tCLASSES/QUIZES/ASSIGNMENTS"<<endl;
    	cout<<"\n 03-APRIL-2023 "<<"\t\t08-APRIL-2023"<<"\t\t4"<<"\t\tCLASSES/MIDS"<<endl;
    	cout<<"\n 10-APRIL-2023 "<<"\t\t15-APRIL-2023"<<"\t\t5"<<"\t\tCLASSES/QUIZES"<<endl;
    	cout<<"\n 17-APRIL-2023 "<<"\t\t22-APRIL-2023"<<"\t\t6"<<"\t\tCLASSES/ACTIVITY/PROJECTS"<<endl;
    	cout<<"\n 25-APRIL-2023 "<<"\t\t29-APRIL-2023"<<"\t\t7"<<"\t\tFINALS/RESULTS"<<endl;
	}
};


int main() {
    university u;
    string id;
    int pass;

    cout << "                UNIVERSITY MANAGEMENT SYSTEM          " << endl;

    while (true) {
        cout << "\nPlease select an option:" << endl;
        cout << "1) Admin Mode" << endl;
        cout << "2) Student Mode" << endl;
        cout << "3) Teacher Mode" << endl;
        cout << "4) Exit the system" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nWELCOME TO ADMIN MODE" << endl;
            cout << "Please enter the admin ID to proceed: ";
            cin >> id;

            if (id == "HAJRA" || id == "hajra" || id == "Hajra" ) {
                cout << "Enter the password to proceed: ";
                cin >> pass;

                if (pass == 1234) {
                    cout << "\n*ADMIN MODE*" << endl;
                    cout << "1) Add a student to the system" << endl;
                    cout << "2) View all student records" << endl;
                    cout << "3) Add a teacher to the system" << endl;
                    cout << "4) View all teacher records" << endl;

                    int adminOption;
                    cout << "Enter your option: ";
                    cin >> adminOption;

                    if (adminOption == 1) {
                        u.getstudentdata();
                    } else if (adminOption == 2) {
                        u.loadstudentdata();
                    } else if (adminOption == 3) {
                        u.getteacherdata();
                    } else if (adminOption == 4) {
                        u.loadteacherdata();
                    }
                } else {
                    cout << "Incorrect password. Access denied." << endl;
                }
            } else {
                cout << "Incorrect admin ID. Access denied." << endl;
            }
        } else if (choice == 2) {
            cout << "\nWELCOME TO STUDENT MODE" << endl;
            cout << "1) See assigned courses" << endl;
            cout << "2) See semester details" << endl;

            int studentOption;
            cout << "Enter your option: ";
            cin >> studentOption;

            if (studentOption == 1) {
                u.course();
            } else if (studentOption == 2) {
                u.details();
            }
        } else if (choice == 3) {
            cout << "\nWELCOME TO TEACHER MODE" << endl;
            cout << "1) View student records" << endl;
            cout << "2) See semester details" << endl;

            int teacherOption;
            cout << "Enter your option: ";
            cin >> teacherOption;

            if (teacherOption == 1) {
                u.loadstudentdata();
            } else if (teacherOption == 2) {
                u.details();
            }
        } else if (choice == 4) {
            cout << "SYSTEM CLOSED" << endl;
            break;
        } else {
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
