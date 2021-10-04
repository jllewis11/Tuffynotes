#include "notebook.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

//This contains functions within class 'note' the notebook.hpp

Note::Note() {
  title_ = "Untitled";
  body_ = "";
}

Note::Note(std::string &title, std::string &body) {
  title_ = title;
  body_ = body;
}
//setTitle function ask for the user input of note's title
void Note::setTitle(std::string title) {
  title_ = title;
}


//setBody function ask for the user input of the note's body
void Note::setBody(std::string body) {
  body_ = body;
}

std::string Note::getTitle() {
  return title_;
}

std::string Note::getBody() {
  return body_;
}

Notebook::Notebook() {
  capacity_ = 100;
  size_ = 0;
  notes_ = new Note[100];
}

Notebook::Notebook(int capacity) {
  capacity_ = capacity;
  size_ = 0;
  notes_ = new Note[capacity_];

}

void Notebook::set_capacity(int capacity) {
  capacity_ = capacity;
}
void Notebook::set_size(int size) {
  size_ = size;
}


int Notebook::get_capacity() {
  return capacity_;
}

int Notebook::get_size() {
  return size_;
}

void Notebook::add(Note &note) {
  notes_[size_++] = note;
}

Note Notebook::get(int index) {
  return notes_[index];
}

void Notebook::list() {
  if (size_==0) {
    std::cout << "\nNo notes have been added.\n\n";
  }
  else {
    std::cout << "\nNotes\n";
    for (unsigned int i = 0; i < size_; i++){
      std::cout << i + 1 << ". " << notes_[i].getTitle() << "\n";
    }
    std::cout << "\n";
  }
}

void Notebook::view() {
  list();
  if (size_ > 0) {
    unsigned int index = 0;

    std::cout << "Please input note index: ";
    std::cin >> index;
    std::cin.ignore();
    if (index - 1 >= size_) {
      std::cout << "\nInvalid note index\n\n";
    }
    else {
      std::cout << "\n" << notes_[index - 1].getTitle() << "\n";
      std::cout << notes_[index - 1].getBody() << "\n\n";
    }
  }
}

void Notebook::save() {
  std::string fileName;
  std::cout << "Please enter the file name: ";
  std::getline(std::cin, fileName);

  ofstream file;
  file.open(fileName);
  file << size_ << "\n";

  if (file.is_open()){
    for (int x = 0; x < size_; x++){
      file << "[Notes]\n";
      file << notes_[x].getTitle();
      file << "\n";
      file << notes_[x].getBody();
      file << "\n";
    }
  }
  else {
    std::cout << "Unable to open file";
  }
  file.close();
  std::cout << "Note saved!\n";
}

void Notebook::load() {
  int order = 1;
  int size = 0;
  std::string test;
  std::string fileName;
  std::string example = "[Notes]";
  std::cout << "Please enter the file name: ";
  std::getline(std::cin, fileName);

  ifstream file;
  file.open(fileName);

  std::getline(file, test);

  while (file) {
    std::getline(file, test);
    if (test.compare(example) != 0 && order%3) {
      notes_[size].setTitle(test);
    }
    else if (test.compare(example) != 0){
      notes_[size].setBody(test);
      size++;
    }
    order ++;
}

capacity_ = size;
size_ = size;

std::cout << "Note loaded\n";
file.close();
}

Notebook::~Notebook(){
  delete [] notes_;
  notes_ = NULL;
}

//Create Note functions


Note createNote() {
  std::string title;
  std::string body;
  std::cout << "\nPlease enter the note's title: ";
  getline (std::cin, title);
  std::cout << "Please enter the note: ";
  getline(std::cin, body);
  std::cout << "\n";
  Note note_default;
  Note newNote(title, body);
  std::cout << "Note added!\n\n";
  return newNote;
}
