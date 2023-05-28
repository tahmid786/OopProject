#include <bits/stdc++.h>
#include <string>
#include<conio.h>
//username:Tahmid
//password:Tahmidrefat

using namespace std;
class entry{
    public:
        string memories[100];  // Array to store memories
    string dates[100];     // Array to store dates
    int numRecords;
     entry() {
        numRecords = 0;  // Initialize the number of records to 0
    }
 void addrecord(){
  string newMemory;
        string newDate;

        cout << "Enter the memory: ";
        cin.ignore();
        getline(cin, newMemory);

        cout << "Enter the date: ";
        getline(cin, newDate);

        // Save the memory and date to your data structure
        memories[numRecords] = newMemory;
        dates[numRecords] = newDate;
        numRecords++;

        cout << "Record added successfully." << endl;
        getch();
        }
  void viewrecord(){
      cout << "========== Memories ==========" << endl;
        for (int i = 0; i < numRecords; i++) {
            cout << "Memory " << (i + 1) << ":" << endl;
            cout << "Date: " << dates[i] << endl;
            cout << "Memory: " << memories[i] << endl;
            cout << endl;
        }
        cout << "========== End of Memories ==========" << endl;

        getch(); // Wait for user input};
}
   void editrecord(){
    if (numRecords == 0) {
            cout << "No records to edit." << endl;
            getch(); // Wait for user input
            return;
        }

        cout << "Enter the index of the record to edit (1-" << numRecords << "): ";
        int index;
        cin >> index;

        // Validate the index
        if (index < 1 || index > numRecords) {
            cout << "Invalid index. Please try again." << endl;
            getch(); // Wait for user input
            return;
        }

        string newMemory;
        string newDate;

        cout << "Enter the new memory: ";
        cin.ignore();
        getline(cin, newMemory);

        cout << "Enter the new date: ";
        getline(cin, newDate);

        // Update the memory and date at the specified index
        memories[index - 1] = newMemory;
        dates[index - 1] = newDate;

        cout << "Record updated successfully." << endl;
        getch(); // Wait for user input


   }
  void  deleterecord(){
    if (numRecords == 0) {
            cout << "No records to delete." << endl;
            getch(); // Wait for user input
            return;
        }

        cout << "Enter the index of the record to delete (1-" << numRecords << "): ";
        int index;
        cin >> index;

        // Validate the index
        if (index < 1 || index > numRecords) {
            cout << "Invalid index. Please try again." << endl;
            getch(); // Wait for user input
            return;
        }

        // Shift the records to remove the selected record
        for (int i = index - 1; i < numRecords - 1; i++) {
            memories[i] = memories[i + 1];
            dates[i] = dates[i + 1];
        }

        numRecords--;

        cout << "Record deleted successfully." << endl;
        getch(); // Wait for user input
    }
    };




class diary:public entry{
    public:

void first_page(){
 int ch;
    cout<<"\n\n\t***********************************\n";
    cout<<"\t  *PERSONAL DIARY MANAGEMENT SYSTEM*\n";
    cout<<"\t***********************************";
    while(1)
    {
        cout<<"\n\n\t\tMAIN MENU:";
        cout<<"\n\n\tADD DIARY\t[1]";
        cout<<"\n\tVIEW DIARY\t[2]";
        cout<<"\n\tEDIT DIARY\t[3]";
        cout<<"\n\tDELETE DIARY\t[4]";

        cout<<"\n\tEXIT\t\t[5]";
        cout<<"\n\n\tENTER YOUR CHOICE:";
        cin>>ch;

        switch(ch)
        {
        case 1:
            addrecord();
            break;
        case 2:
            viewrecord();
            break;
        case 3:
            editrecord();
            break;
        case 4:
            deleterecord();
            break;
        case 5:
            cout<<"\n\n\t\tTHANK YOU! ";
            getch();
            exit(0);
        default:
            cout<<"\nYOU ENTERED WRONG CHOICE..";
            cout<<"\nPRESS ANY KEY TO TRY AGAIN";
            getch();
            break;
        }
        system("cls");
    }
}



};

bool login(const string& username, const string& password) {
    // Perform authentication logic here
    // You can use a database or hard-coded values for simplicity in this example
    string storedUsername = "Tahmid";
    string storedPassword = "Tahmidrefat";

    if (username == storedUsername && password == storedPassword) {
        return true;
    } else {
        return false;
    }
}

int main() {
    string username, password;
    diary d;

    cout << "Login Page" << endl;
    cout << "Username: ";
    cin >> username;

    cout << "Password: ";
    cin >> password;


    if (login(username, password)) {
        cout << "Login successful. Welcome, " << username << "!" << endl;
        d.first_page();


        // Continue with your program logic or display the main menu
    } else {
        cout << "Invalid username or password. Login failed." << endl;
        // Handle unsuccessful login, such as displaying an error message or exiting the program
    }

    return 0;
}
