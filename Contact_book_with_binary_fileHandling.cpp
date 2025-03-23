#include<iostream>   // Standard input and output stream
#include<iomanip>    // For output formatting
#include<fstream>    // For file handling (reading/writing files)
#include<conio.h>    // For console input/output (getch, etc.) - non-standard, works in Turbo C++/Windows
#include<cstring>    // For string manipulation functions
#include<stdio.h>    // Standard I/O operations (printf, scanf, etc.)
#include<cstdlib>    // For general utilities like memory allocation, random numbers, and system commands
#include<windows.h>  // For Windows-specific functions (like sleep, console manipulation)

using namespace std;


// Defining a structure to store contact information
struct contacts {
    char name[80];     // Contact name (max 80 characters)
    char number[20];   // Phone number (max 20 characters)
    char email[80];    // Email address (max 80 characters)
    char address[50]; // Physical address (max 50 characters)
    char note[20];    // Additional notes (max 20 characters)
    char category[20]; // Category of the contact (e.g., friend, family, work)
};

// Array to store multiple contacts (up to 100 contacts)
contacts c[100];

// Variable to keep track of the number of contacts
int n = 0;
void gotoxy(short, short);          // Moves the cursor to a specified position on the console
void display(contacts[], int&);     // 	1. Displays all contacts
void add(contacts[], int&);         // Adds a new contact
void search(contacts[], int&);      // Searches for a contact
void sort(contacts[], int&);        // Sorts contacts (by name, number, etc.)
void del(contacts[], int&);         // Prototype for a delete function 
void modify(contacts[], int&);      // Modifies an existing contact
//////////////////////////////////////
/////////////////// Main /////////////
//////////////////////////////////////

int main() {
    char ch1;  // Variable to store the user's choice
    fstream file;  // Declare file stream object

    // Open file in binary read mode to load existing contacts
    file.open("contacts.dat", ios::in | ios::binary);
    if (!file) {
    	n = 0;  // If file doesn't exist, start with 0 contacts
    	
		}

     else {
        // Read the number of contacts first
        file.read((char*)&n, sizeof(n));
        // Read the contacts array
        file.read((char*)c, sizeof(contacts) * n);
        file.close();
    }
    
    
    while (1) {
        system("cls");  // Clear the screen (Windows-specific)

        // Display the main menu
        cout << setw(50) << "|---------------------------------|" << endl
             << setw(50) << "|MY CONTACT BOOK                  |" << endl
             << setw(50) << "|                Project BY ehhsen|" << endl
             << setw(50) << "|---------------------------------|" << endl << endl
             << setw(52) << "Please choose one of the options below: " << endl
             << setw(71) << "--------------------------------------------------------------" << endl << endl
             << setw(25) << left << "-( A ) ADD A CONTACT" << endl << endl
             << setw(25) << left << "-( O ) SORT ALL CONTACTS" << endl << endl
             << setw(25) << left << "-( S ) SEARCH A CONTACT" << endl << endl
             << setw(25) << left << "-( D ) DISPLAY A CONTACT" << endl << endl
             <<setw(25) << left << "-( X ) DELETE A CONTACT" << endl << endl  
             << setw(25) << left << "-( M ) UPDATE A CONTACT" << endl << endl
             << setw(25) << left << "-( Q ) Quit" << endl << endl
             << setw(25) << left << "Enter Option       [ ]" << endl << endl;

        gotoxy(20, 20);  // Move the cursor to position (20,20)

        // Capture user's choice
        switch (getche()) {
            case 'a':
            case 'A': add(c, n); break;  // Add a contact

            case 'd':
            case 'D': display(c, n); break;  // Display contacts

            case 's':
            case 'S': search(c, n); break;  // Search for a contact

          case 'x':
          case 'X': del(c, n); break;  // Delete a contact 

            case 'o':
            case 'O': sort(c, n); break;  // Sort contacts

            case 'm':
            case 'M': modify(c, n); break;  // Modify a contact

            case 'q':
            case 'Q':
			// Save contacts to file before quitting
                file.open("contacts.dat", ios::out | ios::binary);
                if(!file){
                	cout<<"\nFile can't be opened ";
				}
				else{
                    file.write((char*)&n, sizeof(n));  // Write number of contacts
                    file.write((char*)c, sizeof(contacts) * n);  // Write contacts array
                    file.close();					
				}
                exit(0); break;  // Quit the program

            default:
                puts("\n Enter only from selections listed");
        } // end switch
    } // end while

    getch();  // Wait for user input before closing (Windows-specific)
} // end main
//////////////////////////////////////
///////////////////Display///////////////
/////////////////////////////////////

void display(contacts cont[], int &n)
{
    system("cls"); // Clears the console screen

    cout << "in display function\n"; // Debugging message (can be removed later)

    // Display header for the contact list
    cout << setw(20) << " Name" << setw(20) << "Number" << setw(20) << "Email" << setw(20) << "City" << setw(20) << "Category" << setw(20) << "Relevant information" << endl;
    cout << setw(20) << "-----" << setw(20) << "------" << setw(20) << "-----" << setw(20) << "----" << setw(20) << "--------" << "--------------------" << endl;

    // Iterate through the contacts array and display each contact's information
    for (int i = 0; i < n; i++)
    {
        cout << setw(20) << cont[i].name         // Display name with formatting
             << setw(20) << cont[i].number       // Display number with formatting
             << setw(20) << cont[i].email        // Display email with formatting
             << setw(20) << cont[i].address      // Display address/city with formatting (assuming 'address' holds city)
             << setw(20) << cont[i].category     // Display category with formatting
             << cont[i].note << endl;           // Display relevant information/note without fixed width
    }

    cout << "Press enter to goto main manu....."; // Prompt user to continue
    getch();                                     // Wait for a key press (typically Enter) before returning
}
//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////

void add(contacts cont[], int &n)
{
    char ch; // Stores user's choice to add more contacts
    //char pnumber[20];  // Not used, can be removed

    do
    {
        system("cls"); // Clears the console screen

        cout << "Enter Name : ";
        cin.getline(cont[n].name, 80); // Reads name (up to 79 characters + null terminator)

        cout << "Enter City of the person: ";
        cin.getline(cont[n].address, 50); // Reads city (up to 49 characters + null terminator)

        cout << "Enter email address: ";
        cin.getline(cont[n].email, 80); // Reads email (up to 79 characters + null terminator)

        cout << "Enter phone number: ";
        cin.getline(cont[n].number, 20); // Reads phone number (up to 19 characters + null terminator)

        cout << "Enter any relevent information: ";
        cin.ignore(); // Consume the newline character left by previous cin.getline
        cin.getline(cont[n].note, 20); // Reads relevant information (up to 19 characters + null terminator)

        cout << "Enter Contact category [Family, Friends, Office, etc]: ";
        //cin.ignore(); // No need to ignore here as previous input was also cin.getline
        cin.getline(cont[n].category, 20); // Reads contact category (up to 19 characters + null terminator)
		if (n >= 100) {
   		 cout << "Contact limit reached!" << endl;
   		 return;
		}
        n++; // Increment the contact count
        
        // Save to file immediately after adding
        fstream file;
        file.open("contacts.dat", ios::out | ios::binary);
        if(!file){
            cout<<"\nFile can't be opened ";
		}
		else{
            file.write((char*)&n, sizeof(n));  // Write number of contacts
            file.write((char*)c, sizeof(contacts) * n);  // Write contacts array
            file.close();					
		}        
 
        cout << "\n============================" << endl;

        cout << "do you want to add more records [y/n]";
        ch = getch(); // Reads a character without echoing it to the console
    } // end of Do
    while (ch != 'n' && ch != 'N'); // Continue loop if user enters 'y' or 'Y'
} // end of add function


//////////Search////////////////////
void search(contacts cont[], int &n)
{
    char name[50]; // Stores the name to search for
    bool found = false; // Flag to indicate if a contact was found

    system("cls"); // Clears the console screen
    cout << "\nIn SEARCH function\n"; // Debugging message (can be removed later)

    cout << "Enter a name Please: ";
    cin.getline(name, 50); // Reads the name to search (up to 49 characters + null terminator)

    for (int i = 0; i < n; i++)
    {
        // Comparison using strcmp. Returns 0 if strings are equal.
        if (strcmp(cont[i].name, name) == 0) 
        {
            cout << "\nContact Found" << endl;

            cout << "\nName: " << setw(20) << cont[i].name << endl
                 << "Number: " << setw(20) << cont[i].number << endl
                 << "Email: " << setw(20) << cont[i].email << endl
                 << "Adress: " << setw(20) << cont[i].address << endl // Typo: "Adress" should be "Address"
                 << "Category: " << setw(20) << cont[i].category << endl
                 << "Note: " << setw(20) << cont[i].note << endl;

            found = true; // Set the flag to true since a contact was found
            break; // Exit the loop since the contact is found
        }
    }

    if (!found) // Check the flag after the loop
    {
        cout << "\nName does not exist";
    }

    cout << "\nPress enter to goto main manu.....";
    getch(); // Waits for a key press before returning
}
//////////sort///////////////////////
void sort(contacts cont[], int &n)
{
    system("cls"); // Clears the console screen
    cout << "\nin SORT function\n"; // Debugging message (can be removed later)

    contacts temp; // Local variable used to swap records

    // Outer loop iterates through the array (n-1) times
    for (int i = 0; i < n - 1; i++) // Corrected loop condition
    {
        // Inner loop iterates from 0 to n-i-1. It does comparisons and swaps adjacent elements.
        for (int j = 0; j < n - i - 1; j++) // Corrected loop condition and loop variable name
        {
            // Case-insensitive comparison of names using strcasecmp
            if (strcasecmp(cont[j].name, cont[j + 1].name) > 0) // Corrected index to j and j+1
            {
                // Swap the records if they are in the wrong order
                temp = cont[j];
                cont[j] = cont[j + 1];
                cont[j + 1] = temp;
            }
        }
    }

    cout << "\nContacts Sorted:)";
    cout << "\nPress enter to goto main manu.....";
    getch(); // Waits for a key press before returning
}
////////////Delete//////////////////////
void del(contacts cont[], int &n){
	char name[50];
    fstream file;
    system("cls");
    cout << "\nin DELETE function\n";
    cout << "Enter name of contact to delete: ";
    cin.getline(name, 50);

    for (int i = 0; i < n; i++) {
        if (strcmp(cont[i].name, name) == 0) {
            // Shift all contacts after this one left
            for (int j = i; j < n - 1; j++) {
                cont[j] = cont[j + 1];
            }
            n--;  // Decrease contact count
            cout << "\nContact Deleted";
// Save updated contacts to file
        file.open("contacts.dat", ios::out | ios::binary);
        if(!file){
            cout<<"\nFile can't be opened ";
		}
		else{
            file.write((char*)&n, sizeof(n));  // Write number of contacts
            file.write((char*)c, sizeof(contacts) * n);  // Write contacts array
            file.close();					
		} 
            break;
        }// end of if
    }// end of for

    cout << "\nPress enter to goto main manu.....";
    getch();
} // end of delete           



///////////Modify//////////////////////
void modify(contacts cont[], int &n)
	{
		char name[50];	
		system("cls");
		cout<< "\nin MODIFY function\n";
		cout<<"Enter name of contact you want to modify: ";
		cin.getline(name, 50);
		for (int i = 0; i < n; i ++)
		{
		if( !(  strcmp  (cont[i].name, name)))
		{
			cout<<"\nContact found";
		cout<<"\nUpdating Contact"<<endl;
		cout<<"Enter Name : ";
    	cin.getline( cont[i].name,80);
		cout<<"Enter City of the person: ";
 		cin.getline(cont[i].address, 100);
    	cout<<"Enter email address: ";
  		cin.getline( cont[i].email, 80);  
    	cout<<"Enter phone number: ";
 		cin.getline( cont[i].number, 20); 
     
//    cin.ignore(); 
  		cout<<"Enter any relevent information: ";    
 	    cin.ignore(); 
 		cin.getline(cont[i].note, 120);
    
//	cin.ignore(); 
   		cout<<"Enter Contact category [Family, Friends, Office, etc]: ";
   		cin.getline(cont[i].category, 20);	
		       
    }//end of iff
}// end of for 
		fstream file;
        file.open("contacts.dat", ios::out | ios::binary);
        if(!file){
            cout<<"\nFile can't be opened ";
		}
		else{
            file.write((char*)&n, sizeof(n));  // Write number of contacts
            file.write((char*)c, sizeof(contacts) * n);  // Write contacts array
            file.close();					
		} 
			
		cout<<"\nContact Updated";

		cout<<"\nPress enter to goto main manu.....";
		getch();
	}// end of modify


////////////////////////////////////////
/////////////////gotoxy //////////////////////////
// Sets the console cursor position to the specified coordinates.
void gotoxy(short x, short y)
{
    COORD pos = {x, y}; // Create a COORD structure to hold the coordinates.
    // Set the cursor position using the Windows API function SetConsoleCursorPosition.
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//////////////////////////////////////////
