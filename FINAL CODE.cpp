#include <iostream>
#include <limits>
using namespace std;

class Student
{
private:
    int rollNo;
    char name[30];
    int attendance;

public:

    // Add student details
    void addStudent()
    {
        while (true)
        {
            cout << "\nEnter Roll Number: ";

            if (cin >> rollNo)
            {
                break;
            }
            else
            {
                cout << "Invalid Roll Number! Please enter numbers only.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        cout << "Enter Student Name: ";
        cin >> name;

        attendance = 0;
    }

    // Get roll number
    int getRollNo()
    {
        return rollNo;
    }

    // Mark attendance
    void markAttendance()
    {
        attendance++;
        cout << "Attendance Marked Successfully!\n";
    }

    // Calculate attendance percentage
    float getAttendancePercentage(int totalDays)
    {
        if (totalDays == 0)
            return 0;

        return (attendance * 100.0) / totalDays;
    }

    // Display student details
    void displayStudent()
    {
        cout << "\nRoll Number : " << rollNo;
        cout << "\nName        : " << name;
        cout << "\nPresent Days: " << attendance << endl;
    }

    // Display students having attendance below 75%
    void displayIfBelow75(int totalDays)
    {
        float percentage = getAttendancePercentage(totalDays);

        if (percentage < 75)
        {
            displayStudent();

            cout << "Attendance Percentage: "
                 << percentage << "%" << endl;
        }
    }
};

int main()
{
    Student s[10];

    int n, choice, roll, i, totalDays;
    char present;

    // Enter number of students
    while (true)
    {
        cout << "Enter Number of Students: ";

        if (cin >> n && n > 0 && n <= 10)
        {
            break;
        }
        else
        {
            cout << "Invalid input! Enter a number between 1 and 10.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

    // Add student details
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter Details of Student " << i + 1 << endl;
        s[i].addStudent();
    }

    // Menu
    do
    {
        cout << "\n==============================";
        cout << "\n   STUDENT ATTENDANCE SYSTEM";
        cout << "\n==============================";
        cout << "\n1. Display Students";
        cout << "\n2. Mark Attendance";
        cout << "\n3. Search Student";
        cout << "\n4. Exit";
        cout << "\n5. Calculate Attendance Percentage";
        cout << "\n6. Students Below 75%";
        cout << "\nEnter Your Choice: ";

        // Validate menu choice
        if (!(cin >> choice))
        {
            cout << "\nInvalid Choice! Please enter a number.\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch (choice)
        {
            // Display all students
            case 1:

                for (i = 0; i < n; i++)
                {
                    s[i].displayStudent();
                    cout << "----------------------";
                }

                break;


            // Mark attendance for ALL students
            case 2:

                cout << "\n===== MARK ATTENDANCE =====\n";

                for (i = 0; i < n; i++)
                {
                    s[i].displayStudent();

                    while (true)
                    {
                        cout << "Is the student present? (Y/N): ";
                        cin >> present;

                        if (present == 'Y' || present == 'y')
                        {
                            s[i].markAttendance();
                            break;
                        }
                        else if (present == 'N' || present == 'n')
                        {
                            cout << "Student marked Absent.\n";
                            break;
                        }
                        else
                        {
                            cout << "Invalid input! Please enter Y or N.\n";
                        }
                    }

                    cout << "----------------------\n";
                }

                cout << "\nAttendance completed for all students!\n";

                break;


            // Search student
            case 3:

                while (true)
                {
                    cout << "\nEnter Roll Number: ";

                    if (cin >> roll)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid Roll Number! Please enter numbers only.\n";

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                for (i = 0; i < n; i++)
                {
                    if (s[i].getRollNo() == roll)
                    {
                        s[i].displayStudent();
                        break;
                    }
                }

                if (i == n)
                {
                    cout << "Student Not Found!\n";
                }

                break;


            // Exit
            case 4:

                cout << "\nThank You!\n";
                break;


            // Calculate attendance percentage
            case 5:

                while (true)
                {
                    cout << "\nEnter Total Working Days: ";

                    if (cin >> totalDays && totalDays > 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid input! Enter a positive number.\n";

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                for (i = 0; i < n; i++)
                {
                    s[i].displayStudent();

                    cout << "Attendance Percentage: "
                         << s[i].getAttendancePercentage(totalDays)
                         << "%";

                    cout << "\n----------------------";
                }

                break;


            // Display students below 75%
            case 6:

                while (true)
                {
                    cout << "\nEnter Total Working Days: ";

                    if (cin >> totalDays && totalDays > 0)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid input! Enter a positive number.\n";

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }
                }

                cout << "\nStudents Having Attendance Below 75%:\n";

                for (i = 0; i < n; i++)
                {
                    s[i].displayIfBelow75(totalDays);

                    cout << "\n----------------------";
                }

                break;


            // Invalid choice
            default:

                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 4);

    return 0;
}
