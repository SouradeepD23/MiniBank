#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;

int isUsername();
int isPassword();
void gotoxy(int,int);
void wrongInput();
void home();
int selectUser();
int login(int);
void logout();
void SystemAdminFunction();
void ManagerFunction();
void CustomerFunction();
void ExitFunction();
void selectCustomerFunction();
void newAccountFunction();

class Person;

typedef struct Dates
{
    int d;
    int m;
    int y;
    } Date;



class Person
{
    protected:
    char name[100], gender[6], username[100], password[100];
    Date dob;
    //int age;
    public:
        virtual int displayFunctions()=0;
        virtual void setData()=0;
};

class Customer: public Person
{
    int ver;
    public:
    void setData()
    {
        cout<<"-------SET CUSTOMER CREDENTIALS-------"<<endl;
        cout<<"NAME: ";
        char n[100];
        cin.getline(n,100);
        strcpy(name,n);
        cout<<"GENDER: "<<endl<<"\t1.Female"<<endl<<"\t2.Male"<<endl<<"\t3.Other"<<endl;
        int gen;
        cout<<"Enter choice...:";
        cin>>gen;
        if(gen==1)
            strcpy(gender,"Female");
        if(gen==2)
            strcpy(gender,"Male");
        if(gen==3)
            strcpy(gender,"Other");
        cin.ignore();
        cout<<"USERNAME: ";
        cin.getline(n,100);
        strcpy(username,n);
        cout<<"PASSWORD: ";
        cin.getline(n,100);
        strcpy(password,n);
        ver=0;
    }

    char* getusername()
    {
        return username;
    }

    char* getpassword()
    {
        return password;
    }

    int getVer()
    {
        return ver;
    }

    void setVer(int v)
    {
        v=1;
    }

    int displayFunctions()
    {
        system("cls");
        gotoxy(70,10);
        cout<<"-----CHOOSE FUNCTION-----\n\n"<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t    1. VIEW ACCOUNT SUMMARY";
        cout<<"\n\t\t\t\t\t\t\t\t    2. BALANCE INQUIRY";
        cout<<"\n\t\t\t\t\t\t\t\t    3. TRANSFER";
        cout<<"\n\t\t\t\t\t\t\t\t    4. CLOSE ACCOUNT";
        cout<<"\n\t\t\t\t\t\t\t\t    5. LOGOUT";
        cout<<"\n\n\t\t\t\t\t\t\t\t    Choice:";
        int choice;
        cin>>choice;
        cin.ignore();
        return choice;
    }
};



class Manager: public Person
{
    public:
    void setData()
    {
        cout<<"-------SET MANAGER CREDENTIALS-------"<<endl;
        cout<<"NAME: ";
        char n[100];
        cin.getline(n,100);
        strcpy(name,n);
        cout<<"GENDER: "<<endl<<"\t1.Female"<<endl<<"\t2.Male"<<endl<<"\t3.Other"<<endl;
        int gen;
        cout<<"Enter choice...:";
        cin>>gen;
        if(gen==1)
            strcpy(gender,"Female");
        if(gen==2)
            strcpy(gender,"Male");
        if(gen==3)
            strcpy(gender,"Other");
        cin.ignore();
        cout<<"USERNAME: ";
        cin.getline(n,100);
        strcpy(username,n);
        cout<<"PASSWORD: ";
        cin.getline(n,100);
        strcpy(password,n);
    }

    char* getusername()
    {
        return username;
    }
    char* getpassword()
    {
        return password;
    }
    int displayFunctions()
    {
        system("cls");
        gotoxy(70,10);
        cout<<"-----CHOOSE FUNCTION-----\n\n"<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t    1. VIEW AND VERIFY PENDING APPLICTIONS";
        cout<<"\n\t\t\t\t\t\t\t\t    2. VIEW AND VERIFY PENDING TRANSFERS";
        cout<<"\n\t\t\t\t\t\t\t\t    3. VIEW AND VERIFY PENDING A/c CLOSURES";
        cout<<"\n\t\t\t\t\t\t\t\t    4. LOGOUT";
        cout<<"\n\n\t\t\t\t\t\t\t\t    Choice:";
        int choice;
        cin>>choice;
        cin.ignore();
        return choice;
    }
};




class SysAdmin: public Person
{
    public:
    void setData()
    {
        cout<<"-------SET SYSTEM ADMIN CREDENTIALS-------"<<endl;
        cout<<"NAME: ";
        char n[100];
        cin.getline(n,100);
        strcpy(name,n);
        cout<<"GENDER: "<<endl<<"\t1.Female"<<endl<<"\t2.Male"<<endl<<"\t3.Other"<<endl;
        int gen;
        cout<<"Enter choice...:";
        cin>>gen;
        if(gen==1)
            strcpy(gender,"Female");
        if(gen==2)
            strcpy(gender,"Male");
        if(gen==3)
            strcpy(gender,"Other");
        cin.ignore();
        cout<<"USERNAME: ";
        cin.getline(n,100);
        strcpy(username,n);
        cout<<"PASSWORD: ";
        cin.getline(n,100);
        strcpy(password,n);
    }

    char* getusername()
    {
        return username;
    }
    char* getpassword()
    {
        return password;
    }

    int displayFunctions()
    {
        system("cls");
        gotoxy(70,10);
        cout<<"-----CHOOSE FUNCTION-----\n\n"<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t    1. CREATE MANAGER";
        cout<<"\n\t\t\t\t\t\t\t\t    2. REMOVE MANAGER";
        cout<<"\n\t\t\t\t\t\t\t\t    3. VIEW LOG";
        cout<<"\n\t\t\t\t\t\t\t\t    4. LOGOUT";
        cout<<"\n\n\t\t\t\t\t\t\t\t    Choice:";
        int choice;
        cin>>choice;
        cin.ignore();
        return choice;

    }

    void addManager()
    {
        Manager ma;
        ma.setData();
        ofstream ob("Manager.dat");
        ob.write((char *)&ma,sizeof(Manager));
    }
    void removeManager()
    {
        int i=remove("Manager.dat");
        //cout<<endl<<i<<endl;
    }
};

int isUsername(int p){
   char username[100];
   cin.getline(username,100);
   char *str;
   if(p==1)
   {
       SysAdmin ad;
       ifstream ib("SystemAdmin.dat");
       ib.read((char*)&ad,sizeof(SysAdmin));
       str=ad.getusername();
   }
   if(p==2)
   {
       Manager ma;
       ifstream ib("Manager.dat");
       ib.read((char*)&ma,sizeof(Manager));
       str=ma.getusername();
   }
   if(p==3)
   {
       Customer ctm;
       ifstream ib("CustomerAccounts.dat");
       while(ib.read((char*)&ctm,sizeof(Customer)))
       {
           str=ctm.getusername();
           if(strcmp(username,str)==0)
            break;
       }
   }
   if(strcmp(username,str)==0){
      return 1;
   }else{
      return 0;
   }
}

int isPassword(int p){
   string pass ="";
   char ch;
   ch = _getch();
   while(ch != 13){//character 13 is enter
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   char *str;
   if(p==1)
   {
       SysAdmin ad;
       ifstream ib("SystemAdmin.dat");
       ib.read((char*)&ad,sizeof(SysAdmin));
       str=ad.getpassword();
   }
   if(p==2)
   {
       Manager ma;
       ifstream ib("Manager.dat");
       ib.read((char*)&ma,sizeof(Manager));
       str=ma.getpassword();
   }
   if(p==3)
   {
       Customer ctm;
       ifstream ib("CustomerAccounts.dat");
       while(ib.read((char*)&ctm,sizeof(Customer)))
       {
           str=ctm.getpassword();
           if(pass.compare(str)==0)
            break;
       }
   }
   if(pass.compare(str)==0){
      return 1;
   }else{
      return 0;
   }

}



void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }



void selectCustomerFunction()
{
    system("cls");
    gotoxy(70,10);
    cout<<"-----PERSONAL BANKING-----\n\n"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t    1. LOGIN";
    cout<<"\n\t\t\t\t\t\t\t\t    2. CREATE NEW ACCOUNT";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t    Choice:";
    int choice;
    cin>>choice;
    cin.ignore();
    if(choice>2 && choice<1)
    {
        wrongInput();
        home();
    }
    else
        if(choice==1)
            return;
        else
            newAccountFunction();
}

Customer theman;

void home()
{
    int status;
    ifstream iob("Manager.dat");
    system("cls");
    gotoxy(70,10);
    cout<<"-----THE IRON BANK-----"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t\t      Welcome.\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t   ";
    system("pause");
    int user;
    while(1)
        {
        while(1)
        {
            user=selectUser();
            if(user>=1 && user<=4)
                break;
            else
                wrongInput();
        }
        if(user==4)
            break;
        if(user==2)
        {
            if(!iob.is_open())
            {
                cout<<"MANAGER NOT PRESENT";                //manager doesnt exist case in selectUser()
                home();
            }
            else
                iob.close();
        }
        if(user==3)
            selectCustomerFunction();
        status=login(user);
        if(status==1)
            break;
        else
            wrongInput();
        }
    switch(user)
    {
    case 1:
        SystemAdminFunction();
        break;

    case 2:
        ManagerFunction();
        break;

    case 3:
        CustomerFunction();
        break;

    default:
        ExitFunction();
    }
    //Sleep(3000);
}

void SystemAdminFunction()
{
    int job;
    SysAdmin sa;
    ifstream iob("Manager.dat");
    while(1)
    {
        job=sa.displayFunctions();
        if(job>=1 && job<=4)
            break;
        else
        {
            wrongInput();
            system("cls");
            SystemAdminFunction();
        }
    }


        switch(job)
        {
        case 1:
            if(!iob.is_open())
                {
                    sa.addManager();
                    SystemAdminFunction();
                }
            else
                {
                    system("cls");
                    cout<<"MANAGER ALREADY PRESENT... CANNOT ADD NEW MANAGER!!";
                    system("pause");
                    system("cls");
                    SystemAdminFunction();
                }
            break;

        case 2:
            if(iob.is_open())
                {
                    iob.close();
                    sa.removeManager();
                    system("pause");
                    SystemAdminFunction();
                }
            else
            {
                system("cls");
                cout<<"MANAGER NOT PRESENT... ADD NEW MANAGER!!";
                system("pause");
                system("cls");
                SystemAdminFunction();
            }
            break;

        case 3:
            cout<<"Function not ready yet!";
            system("pause");
            SystemAdminFunction();
            break;

        default:
            logout();

        }
}

void ManagerFunction()
{
    int job;
    Manager ma;
    Customer viewctm;
    ifstream ob1("AccountsDraft.dat",ios::binary);
    ofstream ob2("CustomerAccounts.dat",ios::app|ios::binary);
    while(1)
    {
        job=ma.displayFunctions();
        if(job>=1 && job<=4)
            break;
        else
        {
            wrongInput();
            system("cls");
            ManagerFunction();
        }
    }

    switch(job)
        {
        case 1:
           /* while(ob1.read((char*)&viewctm,sizeof(Customer)))
                {
                    viewctm.getData();
                }*/
            while(ob1.read((char*)&viewctm,sizeof(Customer)))
            {
                if(viewctm.getVer()==0)
                {
                    cout<<"Enter 1 to verify";
                    int v;
                    cin>>v;
                    if(v!=1)
                    {
                        wrongInput();
                        system("cls");
                        ob1.close();
                        ManagerFunction();
                    }
                    viewctm.setVer(1);
                    ob2.write((char*)&viewctm,sizeof(Customer));
                    ob2.close();
                }
                else
                    system("pause");
            }
            break;

        case 2:
            cout<<"Function not ready yet!";
            system("pause");
            ManagerFunction();
            break;

        case 3:
            cout<<"Function not ready yet!";
            system("pause");
            ManagerFunction();
            break;

        default:
            logout();
        }
        ManagerFunction();
}

void CustomerFunction()
{
    int job;
    Customer cu;
    //ofstream customacc("CustomerAccounts.dat");
    while(1)
        {
        job=cu.displayFunctions();
        if(job>=1 && job<=5)
            break;
        else
            {
            wrongInput();
            system("cls");
            CustomerFunction();
            }
        }

    switch(job)
        {
        case 1:
            cout<<"Function not ready yet!";
            system("pause");
            CustomerFunction();
            break;

        case 2:
            cout<<"Function not ready yet!";
            system("pause");
            CustomerFunction();
            break;

        case 3:
            cout<<"Function not ready yet!";
            system("pause");
            CustomerFunction();
            break;

        case 4:
            cout<<"Function not ready yet!";
            system("pause");
            CustomerFunction();
            break;

        default:
            logout();
        }

}

void newAccountFunction()
{
    Customer newctm;
    newctm.setData();              //add username validation
    ofstream wob;
    wob.open("AccountsDraft.dat",ios::app|ios::binary);
    wob.write((char*)&newctm,sizeof(Customer));
    wob.close();
    selectCustomerFunction();
}

void wrongInput()
{
    system("cls");
    gotoxy(70,10);
    cout<<"INVALID INPUT... TRY AGAIN!!!";
    Sleep(2000);
}


int selectUser()
{
    system("cls");
    gotoxy(70,10);
    cout<<"-----CHOOSE USER-----\n\n"<<endl;
    cout<<"\n\t\t\t\t\t\t\t\t    1. SYSTEM ADMINISTRATOR";
    cout<<"\n\t\t\t\t\t\t\t\t    2. MANAGER";
    cout<<"\n\t\t\t\t\t\t\t\t    3. PERSONAL BANKING";
    cout<<"\n\t\t\t\t\t\t\t\t    4. Exit";
    cout<<"\n\n\n\n\t\t\t\t\t\t\t\t    Choice:";
    int choice;
    cin>>choice;
    cin.ignore();
    return choice;
}

int login(int p)
    {
        system("cls");
        gotoxy(70,10);
        cout<<"-----LOGIN-----"<<endl;
        cout<<"\n\t\t\t\t\t\t\t\t\tUSERNAME: ";
        int un=isUsername(p);
        cout<<"\n\t\t\t\t\t\t\t\t\tPASSWORD: ";
        int pw=isPassword(p);

        if(un==1 && pw==1)
            return 1;
        else
            return 0;
    }

void logout()
{
    system("cls");
    gotoxy(70,10);
    cout<<"LOGGING OUT";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    system("cls");
    home();
}


void ExitFunction()
{
    system("cls");
    gotoxy(70,10);
    cout<<"EXITING";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    cout<<".";
    Sleep(500);
    system("cls");
    exit(0);
}


int main()
{
    system("MODE CON COLS=1024 LINES=768");
    home();
    system("cls");
    /*
    SysAdmin sa;
    sa.setData();
    ofstream ob("SystemAdmin.dat");
    ob.write((char*)&sa,sizeof(SysAdmin));
    */
    return 0;
}
