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
    if(!seqfile.is_open())
    {
        cout<<"Failed to open the file."<<endl;
        return;
    }
    do
    {
        cout<<"Enter Name: ";
        cin>>Records.name;
        cout<<"Enter Rollno.: ";
        cin>>Records.rollno;
        cout<<"Enter Division: ";
        cin>>Records.div;
        cout<<"Enter Address: ";
        cin>>Records.address;

        seqfile.write((char*)&Records, sizeof(Records));
        cout<<"Do you want to add more Records(y/n): ";
        cin>>ch;
        cin.ignore(); // To ignore the newline character left by cin
    } while (ch == 'y');
}

void Stud_class::display(string f)
{
    fstream seqfile;
    int n, m, i;
    seqfile.open(f, ios::in | ios::out | ios::binary);
    seqfile.seekg(0, ios::beg);
    cout<<"The Contents of the file are as follows: ";
    while (seqfile.read((char*)&Records, sizeof(Records)))
    {
        if (Records.rollno != -1)
        {
            cout<<"\nName: "<<Records.name;
            cout<<"\nRoll No.: "<<Records.rollno;
            cout<<"\nDivision: "<<Records.div;
            cout<<"\nAddress: "<<Records.address;
            cout<<endl;
        }
        
    }
    seqfile.close();
}

int Stud_class::search(string f)
{
    fstream seqfile;
    int id, pos;
    cout<<"Enter the Roll Number for searching the record: ";
    cin>>id;
    seqfile.open(f, ios::in | ios::out | ios::binary);
    seqfile.seekg(0, ios::beg);
    pos = -1;
    int i = 0;
    while (seqfile.read((char*)&Records, sizeof(Records)))
    {
        if(id == Records.rollno)
        {
            pos = i;
            break;
        }
        i++;
    }
    return pos;
}

void Stud_class::update(string f)
{
    int number;
    cout<<"Updation"<<endl;
    fstream seqfile;
    seqfile.open(f, ios::in | ios::out | ios::binary);
    seqfile.seekg(0, ios::beg);
    int pos = search(f);
    if(pos == -1)
    {
        cout<<"The Record is Not Present in the file";
        return;
    }
    int offset = pos*sizeof(Rec);
    seqfile.seekp(offset);
    cout<<"Enter the Values for updation: ";
    cout<<"Enter Name: ";
    cin>>Records.name;
    cout<<"Enter Roll No.: ";
    cin>>Records.rollno;
    cout<<"Enter Division: ";
    cin>>Records.div;
    cout<<"Enter Address: ";
    cin>>Records.address;
    seqfile.write((char*)&Records, sizeof(Records));
    seqfile.seekg(0);
    seqfile.close();
    cout<<"The Record is Updated!!!"<<endl;
}

void Stud_class::deletef(string f)
{
    int id, pos;
    cout<<"Deletion"<<endl;
    pos = search(f);
    fstream seqfile;
    seqfile.open(f, ios::in | ios::out | ios::binary);
    seqfile.seekg(0, ios::beg);
    int offset = pos*sizeof(Rec);
    if(pos == -1)
    {
        cout<<"The Record is not present in the file"<<endl;
        return;
    }
    seqfile.seekp(offset);
    Records.name =  " ";
    Records.rollno = -1;
    Records.div = ' ';
    Records.address = " ";
    seqfile.write((char*)&Records, sizeof(Records))<<flush;
    seqfile.seekg(0);
    seqfile.close();
    cout<<"The Record is Deleted"<<endl;

}

void Stud_class::append(string f)
{
    fstream seqfile;
    seqfile.open(f, ios::ate | ios::in | ios::out | ios::binary);
    // seqfile.seekg(0, ios::beg);
    // int i = 0;
    seqfile.clear();
    cout<<"Enter the record for appending"<<endl;
    cout<<"Name: ";
    cin>>Records.name;
    cout<<"Enter Roll No.: ";
    cin>>Records.rollno;
    cout<<"Division: ";
    cin>>Records.div;
    cout<<"Address: ";
    cin>>Records.address;
    seqfile.write((char*)&Records, sizeof(Records));
    seqfile.seekg(0);
    seqfile.close();
    cout<<"The record has Appended"<<endl;

}

int main()
{
    Stud_class list;
    char ans = 'y';
    int choice, key;
    string filename;
    cout<<"Please enter the filename: ";
    cin>>filename;
    do
    {
        cout<<"--------------------Main Menu--------------------"<<endl;
        cout<<"1. Create"<<endl;
        cout<<"2. Display"<<endl;
        cout<<"3. Update"<<endl;
        cout<<"4. Delete"<<endl;
        cout<<"5. Append"<<endl;
        cout<<"6. Search"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            list.create(filename);
            break;
        case 2:
            list.display(filename);
            break;
        case 3:
            list.update(filename);
            break;
        case 4:
            list.deletef(filename);
            break;
        case 5:
            list.append(filename);
            break;
        case 6:
            key = list.search(filename);
            if(key < 0)
            {
                cout<<"Record is not present in the file"<<endl;
            }
            else
            {
                cout<<"Record is Present in the file"<<endl;
            }
            break;
        case 7:
            cout<<"Exiting..."<<endl;
            exit(0);
        default:
            break;
        }
        cout<<"Do you want to go back to Main Menu(y/n): ";
        cin>>ans;
    }while(ans == 'y');
    return 0;
}