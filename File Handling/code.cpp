#include<iostream>
#include<iomanip>
#include<fstream>
#include<string.h>
//#include<conio.h>
#include<stdlib.h>
using namespace std;
class STUD_CLASS
{
    typedef struct student
    {
        char name[10];
        int rollno;
        char div;
        char Address[20];
    }Rec;
    Rec Records;
    public:
    void Create(char f[]);
    void Display(char f[]);
    void Update(char f[]);
    void Delete(char f[]);
    void Append(char f[]);
    int Search(char f[]);
};
void STUD_CLASS::Create(char f[])
{
    char ch='y';
    fstream seqfile;
    seqfile.open(f,ios::in|ios::out|ios::binary);
    do
    {
        cout<<"\n Enter Name: ";
        cin>>Records.name;
        cout<<"\n Enter roll no: ";
        cin>>Records.rollno;
        cout<<"\n Enter div: ";
        cin>>Records.div;
        cout<<"\n Enter Address ";
        cin>>Records.Address;

        //then write the record containing this data in the file
        seqfile.write((char*)&Records,sizeof(Records));
        cout<<"\nDo you want to add more records?";
        cin>>ch;
    }while(ch=='y');
    seqfile.close();
}
void STUD_CLASS::Display(char f[])
 {
    fstream seqfile;
    int n,m,i;
    seqfile.open(f,ios::in|ios::out|ios::binary);
    //positioning the pointer in the file at the beginning
    seqfile.seekg(0,ios::beg);
    cout<<"\n The Contents of file are ..."<<endl;
    //read the records sequentially
    while(seqfile.read((char *)&Records,sizeof(Records)))
    {
        if(Records.rollno!=-1)
        {
            cout<<"\nName: "<<Records.name;
            cout<<"\nRollNO: "<<Records.rollno;
            cout<<"\nDivision: "<<Records.div;
            cout<<"\nAddress: "<<Records.Address;   
            cout<<"\n";
        }
     }
     //int last_rec=seqfile.tellg();//last record position
     seqfile.close();
}
void STUD_CLASS::Update(char f[])
{
    int pos;
    cout<<"\n For updation,";
    fstream seqfile;
    seqfile.open(f,ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    //obtaining the position of desired record in the file
    pos=Search(f);
    if(pos==-1)
    {
        cout<<"\n The record is not present in the file";
        return;
    }
    //calculate the actual offset of the desired record in the file
    int offset=pos*sizeof(Rec);
    seqfile.seekp(offset);//seeking the desired record for modification
    cout<<"\n Enter the values for updation...";
    cout<<"\n Name: ";cin>>Records.name;
    cout<<"\n Rollno: ";cin>>Records.rollno;
    cout<<"\n Div: ";cin>>Records.div;
    cout<<"\n Address: ";cin>>Records.Address;
    seqfile.write((char*)&Records,sizeof(Records))<<flush;
    seqfile.seekg(0);
    seqfile.close();
    cout<<"\n The record is updated!!!";
}
    
void STUD_CLASS::Delete(char f[])
{
    int id,pos;
    cout<<"\n For deletion,";
    fstream seqfile;
    seqfile.open(f,ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);//seeking for reading purpose
    pos=Search(f);//finding pos. for the record to be deleted
    if(pos==-1)
    {
        cout<<"\n The record is not present in the file";
        return;
    }
    //calculate offset to locate the desired record in the file
    int offset=pos*sizeof(Rec);
    seqfile.seekp(offset);//seeking the desired record for deletion
    strcpy(Records.name,"");
    Records.rollno=-1;
    Records.div=' ';
    strcpy(Records.Address,"");
    seqfile.write((char*)&Records,sizeof(Records))<<flush;
    seqfile.seekg(0);
    seqfile.close();
    cout<<"\n The record is Deleted!!!";
}
void STUD_CLASS::Append(char f[])
{
    fstream seqfile;
    seqfile.open(f,ios::ate|ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    int i=0;
    while(seqfile.read((char *)&Records,sizeof(Records)))
    {
        i++;//going through all the records
        // for reaching at the end of the file
    }
    //instead of above while loop
    //we can also use seqfile.seekg(0,ios::end)
    //for reaching at the end of the file
    seqfile.clear();//turning off EOF flag
    cout<<"\n Enter the record for appending";
    cout<<"\nName: ";cin>>Records.name;
    cout<<"\nRoll NO ";cin>>Records.rollno;
    cout<<"\nDiv: ";cin>>Records.div;
    cout<<"\nAddress: ";cin>>Records.Address;
    seqfile.write((char*)&Records,sizeof(Records));
    seqfile.seekg(0);//reposition to start(optional)
    seqfile.close();
    cout<<"\n The record is Appended!!!";
}
int STUD_CLASS::Search(char f[])
{
    fstream seqfile;
    int id,pos;
    cout<<"\n Enter the Roll no for searching the record ";
    cin>>id;
    seqfile.open(f,ios::ate|ios::in|ios::out|ios::binary);
    seqfile.seekg(0,ios::beg);
    pos=-1;
    int i=0;
    while(seqfile.read((char *)&Records,sizeof(Records)))
    {
        if(id==Records.rollno)
        {
            pos=i;
            break;
        }
        i++;
    }
    return pos;
}
int main()
{
    STUD_CLASS List;
    char ans='y';
    int choice,key;
    char filename[20];
    cout<<endl<<"please enter filename(make sure file is created in same folder)";
    cin>>filename;
    //clrscr();
    do
    {
        cout<<"\n             Main Menu             "<<endl;
        cout<<"\n 1.Create";
        cout<<"\n 2.Display";
        cout<<"\n 3.Update";
        cout<<"\n 4.Delete";
        cout<<"\n 5.Append";
        cout<<"\n 6.Search";
        cout<<"\n 7.Exit";
        cout<<"\n Enter your choice ";
        cin>>choice;
        switch(choice)
        {
            case 1:List.Create(filename);
            break;
            case 2:List.Display(filename);
            break;
            case 3:List.Update(filename);
            break;
            case 4:List.Delete(filename);
            break;
            case 5:List.Append(filename);
            break;
            case 6:key=List.Search(filename);
            if(key<0)
                cout<<"\n Record is not present in the file";
            else
                cout<<"\n Record is present in the file";
            break;
            case 7:exit(0);
        }
        cout<<"\n\t Do you want to go back to Main Menu?";
cin>>ans;
}while(ans=='y');
}
