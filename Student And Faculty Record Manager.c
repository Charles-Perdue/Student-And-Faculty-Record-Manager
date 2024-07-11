// Student And Faculty Record Manager
// Charles Perdue
// July, 11, 2024
// COP 3223

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for storing student information
typedef struct {
    char sname[100];
    char sid[100];
    float gpa;
    int credit;
} student;

// Structure for storing faculty information
typedef struct {
    char fname[100];
    char fid[100];
    char rank[100];
    char department[100];
} faculty;

// Function Prototypes
int Menu();
int AddFaculty(faculty *faculties, int fcount);
int AddStudent(student *students, int scount);
void Invoice(student *students, int scount);
void Info(faculty *faculties, int fcount);
void Exit(student *students, int scount, faculty *faculties, int fcount);

int main() {
    // Welcome message
    printf("\n\n\t\t\tWelcome to PerPro\n\n");

    // Variable declarations
    int selection = 0;     // Menu selection
    student students[100]; // Array to store students
    int scount = 0;        // Student count
    faculty faculties[30]; // Array to store faculties
    int fcount = 0;        // Faculty count

    // Main loop for menu selection
    while (1) {
        selection = Menu();

        // Menu selection handling
        switch (selection) {
            case 1:
                fcount = AddFaculty(faculties, fcount);
                break;
            case 2:
                scount = AddStudent(students, scount);
                break;
            case 3:
                Invoice(students, scount);
                break;
            case 4:
                Info(faculties, fcount);
                break;
            case 5:
                Exit(students, scount, faculties, fcount);
                return 0;
            default:
                printf("Invalid selection. Please try again.\n");
        }
    }

    return 0;
}

// Function to display the menu and get the user's selection
int Menu() {
    int selection;
    int attempts = 0;

    while (attempts < 3) {
        printf("Choose one of the options\n\n");
        printf("1- Add a new faculty member\n");
        printf("2- Add a new student\n");
        printf("3- Print tuition invoice for a student\n");
        printf("4- Print information of a faculty\n");
        printf("5- Exit Program\n");
        printf("\n\tEnter your selection: ");
        scanf("%d", &selection);
        printf("\n\n");

        if (selection >= 1 && selection <= 5) {
            return selection;
        } else {
            attempts++;
            printf("Invalid selection.\n");
        }
    }

    printf("Too many invalid attempts. Exiting the program.\n");
    exit(EXIT_FAILURE);
}

// Function to add a new faculty member
int AddFaculty(faculty *faculties, int fcount) {
    int valid_id = 0;
    int valid_department = 0;
    int valid_rank = 0;

    // Get faculty name
    printf("Name of the faculty: ");
    char fname[50], lname[50];
    scanf("%s %s", fname, lname);
    snprintf(faculties[fcount].fname, 100, "%s %s", fname, lname); // Combine first and last name

    // Get and validate faculty ID
    for (int i = 0; i < 3; i++) {
        printf("ID: ");
        scanf("%s", faculties[fcount].fid);

        if (strlen(faculties[fcount].fid) == 8 &&
            isalpha(faculties[fcount].fid[0]) &&
            isalpha(faculties[fcount].fid[1]) &&
            isdigit(faculties[fcount].fid[2]) &&
            isdigit(faculties[fcount].fid[3]) &&
            isdigit(faculties[fcount].fid[4]) &&
            isdigit(faculties[fcount].fid[5]) &&
            isdigit(faculties[fcount].fid[6]) &&
            isdigit(faculties[fcount].fid[7])) {
            valid_id = 1;
            break;
        } else {
            printf("Invalid ID. Please try again.\n");
        }
    }

    if (!valid_id) {
        printf("Failed to enter a valid ID after 3 attempts. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    // Get and validate faculty rank
    for (int i = 0; i < 3; i++) {
        printf("Rank: ");
        scanf("%s", faculties[fcount].rank);
        if (strcasecmp(faculties[fcount].rank, "Professor") == 0 ||
            strcasecmp(faculties[fcount].rank, "Adjunct") == 0) {
            valid_rank = 1;
            break;
        } else {
            printf("Invalid Rank. Please try again.\n");
        }
    }

    if (!valid_rank) {
        printf("Failed to enter a valid rank after 3 attempts. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    // Get and validate faculty department
    for (int i = 0; i < 3; i++) {
        printf("Department: ");
        scanf("%s", faculties[fcount].department);
        if (strcasecmp(faculties[fcount].department, "Math") == 0 ||
            strcasecmp(faculties[fcount].department, "CS") == 0 ||
            strcasecmp(faculties[fcount].department, "Science") == 0) {
            // Convert department to uppercase
            for (int j = 0; j < strlen(faculties[fcount].department); j++) {
                faculties[fcount].department[j] = toupper(faculties[fcount].department[j]);
            }
            valid_department = 1;
            break;
        } else {
            printf("Invalid Department. Please try again.\n");
        }
    }

    if (!valid_department) {
        printf("Failed to enter a valid department after 3 attempts. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    fcount++;
    return fcount;
}

// Function to add a new student
int AddStudent(student *students, int scount) {
    int valid_id = 0;

    printf("\nEnter student's info: \n");

    // Get student name
    printf("Name of student: ");
    char fname[50], lname[50];
    scanf("%s %s", fname, lname);
    snprintf(students[scount].sname, 100, "%s %s", fname, lname); // Combine first and last name

    // Get and validate student ID
    for (int i = 0; i < 3; i++) {
        printf("ID: ");
        scanf("%s", students[scount].sid);

        if (strlen(students[scount].sid) == 8 &&
            isalpha(students[scount].sid[0]) &&
            isalpha(students[scount].sid[1]) &&
            isdigit(students[scount].sid[2]) &&
            isdigit(students[scount].sid[3]) &&
            isdigit(students[scount].sid[4]) &&
            isdigit(students[scount].sid[5]) &&
            isdigit(students[scount].sid[6]) &&
            isdigit(students[scount].sid[7])) {
            valid_id = 1;
            break;
        } else {
            printf("Invalid ID. Please try again.\n");
        }
    }

    if (!valid_id) {
        printf("Failed to enter a valid ID after 3 attempts. Exiting the program.\n");
        exit(EXIT_FAILURE);
    }

    // Get student GPA
    printf("GPA: ");
    scanf("%f", &students[scount].gpa);

    // Get student credit hours
    printf("Credit Hours: ");
    scanf("%d", &students[scount].credit);

    scount++;
    return scount;
}

// Function to print a student's tuition invoice
void Invoice(student *students, int scount) {
    // Declare id and ask for id
    char id[100];
    printf("Enter student ID: ");
    scanf("%s", id);

    // Compare id to sid to find match
    int found = 0;
    for (int i = 0; i < scount; i++) {
        if (strcasecmp(students[i].sid, id) == 0) {
            found = 1;
            printf("Here is the tuition invoice for %s\n", students[i].sname);
            printf("---------------------------------------------------------------------------\n");
            printf("%s", students[i].sname);
            printf("\t\t\t%s\n", students[i].sid);
            printf("Credit Hours: %d", students[i].credit);
            printf("\t($236.45/credit hour)\n");
            printf("Fees: $52\n\n");
            float total_payment = students[i].credit * 236.45 + 52;
            float discount = 0;
            if (students[i].gpa >= 3.85) {
                discount = total_payment * 0.25;
                total_payment *= 0.75;
                printf("Total payment: %.2f", total_payment);
                printf("\t\t($%.2f discount applied)\n", discount);
            } else {
                printf("Total payment: %.2f", total_payment);
                printf("\t\t($0 discount applied)\n");
            }
            printf("---------------------------------------------------------------------------\n");
            break;
        }
    }
    if (!found) {
        printf("Student ID not found.\n");
    }
}

// Function to print information of a faculty
void Info(faculty *faculties, int fcount) {
    // Declare id and ask for id
    char id[100];
    printf("Enter faculty ID: ");
    scanf("%s", id);

    // Compare id to fid to find match
    int found = 0;
    for (int i = 0; i < fcount; i++) {
        if (strcasecmp(faculties[i].fid, id) == 0) {
            found = 1;
            printf("Faculty found\n");
            printf("---------------------------------------------------------------------------\n");
            printf("%s\n", faculties[i].fname);
            printf("%s Department,", faculties[i].department);
            printf("  %s\n", faculties[i].rank);
            printf("---------------------------------------------------------------------------\n");
            break;
        }
    }
    if (!found) {
        printf("Faculty ID not found.\n");
    }
}

// Function to handle program exit and final report printing
void Exit(student *students, int scount, faculty *faculties, int fcount) {
    char choice;
    char sort_choice;

    // Ask if they want to print the final report
    printf("Would you like to print the final report (Y/N): ");
    scanf(" %c", &choice);

    if (toupper(choice) == 'Y') {
        // Ask if they want to sort by name
        printf("Sorted by name? (Y/N): ");
        scanf(" %c", &sort_choice);

        if (toupper(sort_choice) == 'Y') {
            // Sort faculties by name
            for (int i = 0; i < fcount - 1; i++) {
                for (int j = i + 1; j < fcount; j++) {
                    if (strcmp(faculties[i].fname, faculties[j].fname) > 0) {
                        faculty temp = faculties[i];
                        faculties[i] = faculties[j];
                        faculties[j] = temp;
                    }
                }
            }

            // Sort students by name
            for (int i = 0; i < scount - 1; i++) {
                for (int j = i + 1; j < scount; j++) {
                    if (strcmp(students[i].sname, students[j].sname) > 0) {
                        student temp = students[i];
                        students[i] = students[j];
                        students[j] = temp;
                    }
                }
            }
        }

        // Print report
        printf("\nHere is your report….\n");
        printf("\n\t------    L I S T   O F   F A C U L T Y  -----\n");
        for (int i = 0; i < fcount; i++) {
            printf("\t\t%s  %s\n", faculties[i].fname, faculties[i].department);
        }

        printf("\n\t------    L I S T   O F   S T U D E N T S  -----\n");
        for (int i = 0; i < scount; i++) {
            printf("\t\t%s\n", students[i].sname);
        }
    }

    // Goodbye message
    printf("\nThank you for using PerPro. Goodbye!\n");
}
