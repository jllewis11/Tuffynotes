#ifndef NOTEBOOK_HPP
#define NOTEBOOK_HPP
#include <string>

using namespace std;

//This class defines the notes and its functions of adding note title and note body.
class Note {

  public:

    Note();
    Note(std::string &title, std::string &body);

    void setTitle(std::string title);
    void setBody(std::string body);

    std::string getTitle();
    std::string getBody();

  private:
    //This privatizes the note and only certain accessors can access it.
    string title_;
    string body_;
};

class Notebook {
  public:
    Notebook();
    Notebook(int capacity);

    void set_capacity(int capacity);
    void set_size(int size);

    int get_capacity();
    int get_size();

    void add(Note &note);
    Note get(int index);
    void list();
    void view();
    void save();
    void load();

    ~Notebook();

  private:
    int capacity_;
    int size_;
    Note *notes_;
};

Note createNote();


void list_notes(Notebook notepad);
void view_notes(Notebook notepad);
void save_notes(Notebook notepad);
void load_notes(Notebook notepad);
#endif //NOTEBOOK_HP
