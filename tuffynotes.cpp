//Program will ask for a user input to create a note or exit
#include <iostream>
#include <string>
#include "notebook.hpp"
#include <fstream>

int main() {
  Notebook start;
  Notebook notepad(100);
  Note note;
  char choice;
  unsigned int size = 0;
  std::cout << "Welcome to Tuffynotes.\n";
//Do while allows for the program to loop until the user exits the program
    do
    {
      std::cout << "[C] Create a note\n";
      std::cout << "[L] List note\n";
      std::cout << "[V] View notes\n";
      std::cout << "[S] Save note\n";
      std::cout << "[O] Load note\n";
      std::cout << "[E] Exit\n";
      std::cout << "Choice: ";
      std::cin >> choice;
      std::cin.ignore();

      switch (choice) {
        case 'C':
        case 'c':
            note = createNote();
            notepad.add(note);
            break;
        case 'L':
        case 'l':
            notepad.list();
            break;
        case 'E':
        case 'e':
            std::cout << "\nThank you for using Tuffynotes!\n";
            break;
        case 'V':
        case 'v':
            notepad.view();
            break;
        case 'S':
        case 's':
            notepad.save();
            break;
        case 'O':
        case 'o':
            notepad.load();
            break;
        default:
            std::cout << "\n Invalid choice. Please try again\n\n";
      }
    } while (choice != 'e' && choice != 'E');

    return 0;
}
