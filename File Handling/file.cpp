#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;
 
class Stud_class
{
    typedef struct student
    {
        string name;
        int rollno;
        char div;
        string address;
    }Rec;
    Rec Records;
    public:
        void create(string f);
        void display(string f);
        void update(string f);
        void deletef(string f);
        void append(string f);
        int search(string f);       
    
};

void Stud_class::create(string f)
{
    char ch = 'y';
    fstream seqfile;
    seqfile.open(f, ios::out | ios::binary);
    seqfile.close();
    seqfile.open(f, ios::in | ios::out | ios::binary);
    do
    {
        cout<<"Enter: ";

        // //
        //
        //
        //

        seqfile.write((char*)&Records, sizeof(Records));
        
    } while (ch == 'y');
    
}