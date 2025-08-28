/******************************************************************************

             C++ PROJECT ON "BILLING SYSTEM IN SUPERMARKET"
                     SCHOOL OF ENGINEERING
                     FAR-WESTERN UNIVERSITY
                        Kanchanpur Nepal
                        SECOND SEMESTER
    MEMBERS: 
            BIJAYA SINGH SAUD
            JANAK SINGH DHAMI
            MAMATA PANT
            PUSKAR BHATT
*******************************************************************************
****************************CODE***********************************************/
#include<iostream>
#include<conio.h>
#include<fstream>
using namespace std;
class bill
{
    private: //Variables
    int code;
    float price,discount;
    string name;
    public:  //Functions
    void menu();
    void admin();
    void customer();
    void add();
    void search();
    void edit();
    void del();
    void show();
    void list();
    void invoice();
};
void bill:: menu() //Menu Function(of Bill class) Definition
{
    p:
    system("cls");
    int choice;
    char ch;
    string email,pass;
    cout<<"\n\n\t\t Control Panel";
    cout<<"\n\n 1. Admin";
    cout<<"\n\n 2. Customer";
    cout<<"\n\n 3. Exit";
    cout<<"\n\n Enter Your Choice :";
    cin>>choice;
    switch(choice)
    {
        case 1:
        system("cls");
        cout<<"\n\n\t\t Login System";
        cout<<"\n\nE-mail:";
        cin>>email;
        cout<<"\n\nPasssword : ";
        for(int i=1;i<=6;i++)
        {
            ch=getch();
            pass +=ch;
            cout<<"*";
        }
        if(email=="billingsystem@gmail.com" && pass=="direct")
        {
            admin();
        }
        else
        {
            cout<<"\n\nInvalid E-mail or Password...";
        }
        break;
        case 2:
        customer();
        case 3:
        exit(0);
        default:
        cout<<"\n\n Invalid Value...Please Try again...";
    }
    getch();
    goto p;
}
void bill::admin() //Definition of admin function of class bill
{
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\tAdmin Panel";
    cout<<"\n\n1. Add Product";
    cout<<"\n2. Search Product";
    cout<<"\n3. Edit Product";
    cout<<"\n4. Delete Product";
    cout<<"\n5. Show Product";
    cout<<"\n6. Go Back";
    cout<<"\n Enter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        add();
        break;
        case 2:
        search();
        break;
        case 3:
        edit();
        break;
        case 4:
        del();
        break;
        case 5:
        show();
        break;
        case 6:
        menu();
        default:
        cout<<"\n\nInvalid value...PLease Try Again";
    }
    getch();
    goto p;
}
void bill::customer() //customer function definition
{
    p:
    system("cls");
    int choice;
    cout<<"\n\n\t\t\tCustomer Panel";
    cout<<"\n\n1. Buy Product";
    cout<<"\n2. Back To Main-menu";
    cout<<"\n\nEnter Your Choice : ";
    cin>>choice;
    switch(choice)
    {
        case 1:
        invoice();
        break;
        case 2:
        menu();
        default:
        cout<<"\n\nInvalid Value...Please Try Again...";
    }
    getch();
    goto p;
}
void bill::add() //Add function definition
{
    p:
    system("cls");
  fstream file;
  int c,found=0;
  float p,d;
  string n;
  cout<<"\n\n\t\tAdd New Product";
  cout<<"\n\nProduct Code :";
  cin>>code;
  cout<<"\n\nName : ";
  cin>>name;
  cout<<"\n\n Price : ";
  cin>>price;
  cout<<"\n\nDiscount in % : ";
  cin>>discount;
  file.open("product.txt",ios::in);
  if(!file)
  {
    file.open("product.txt",ios::app|ios::out);
    file<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
    file.close();
  }
  else
  {
    file>>c>>n>>p>>d;
    while(!file.eof())
    {
        if(c==code)
        {
            found++;
        }
        file>>c>>n>>p>>d;
    }
    file.close();
    if(found==1)
    goto p;
    else
    {
        file.open("product.txt",ios::app|ios::out);
       file<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
       file.close();
    }
  }
  cout<<"\n\n\t\tRecord Inserted Successfully...";
}
void bill::search() //Search function definition
{
    system("cls");
    fstream file;
    int p_c, found=0;
    cout<<"\n\n\t\tSearch Record";
    cout<<"\n\n Product Code : ";
    cin>>p_c;
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"\n\nFile Opening Error...";
    }
    else
    {
        file>>code>>name>>price>>discount;
        while(!file.eof())
        {
            if(p_c==code)
            {
                system("cls");
                cout<<"\n\n\t\t Search Record";
                cout<<"\n\n Product Code : "<<code;
                cout<<"\n\nName : "<<name;
                cout<<"\n\n Price : "<<price;
                cout<<"\n\n Discount : "<<discount<<"%";
                found++;
            }
            file>>code>>name>>price>>discount;
        }
        file.close();
        if(found==0)
        cout<<"\n\n Record Can Not Found...";
    }
}
void bill::edit() //edit function definition
{
   
    system("cls");
    fstream file,file1;
    int p_c, found=0,c;
    float p,d;
    string n;
    cout<<"\n\n\t\t Edit Record";
    cout<<"\n\n Product Code : ";
    cin>>p_c;
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error...";
    }
    else
    {
        file1.open("product1.txt",ios::app|ios::out);
        file>>code>>name>>price>>discount;
        while(!file.eof())
        {
            if(p_c==code)
            {
                cout<<"\n\n Product New Code : ";
                cin>>c;
                cout<<"\n\n Name : ";
                cin>>n;
                cout<<"\n\nPrice : ";
                cin>>p;
                cout<<"\n\nDiscount in % : ";
                cin>>d;
                file1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\n\t\t Record Edit Successfully...";
                found++;
            }
            else
            {
                file1<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            file>>code>>name>>price>>discount;
        }
        file.close();
        file1.close();
        remove("product.txt");
        rename("product1.txt","product.txt");
        if(found==0)
        cout<<"\n\nRecord Can not Found...";
    }
    getch();
}
void bill::del() //delete function definition
{
    system("cls");
    fstream file,file1;
    int p_c, found=0;
    cout<<"\n\n\t\t Delete Product";
    cout<<"\n\nProduct Code : ";
    cin>>p_c;
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n File Opening Error...";
    }
    else
    {
        file1.open("product1.txt",ios::app|ios::out);
        file>>code>>name>>price>>discount;
        while(!file.eof())
        {
            if(code==p_c)
            {
                cout<<"\n\n Product Deleted Successfully...";
                found++;
            }
            else
            {
                file1<<" "<<code<<" "<<name<<" "<<price<<" "<<discount<<"\n";
            }
            file>>code>>name>>price>>discount;
        }
        file.close();
        file1.close();
        remove("product.txt");
        rename("product1.txt","product.txt");
        if(found==0)
        cout<<"\n\n Record Cannot Found...";
    }
}
void bill::show()  //show function definition
{
    system("cls");
    fstream file;
    cout<<"\n\n\t\t\tShow Products";
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\t\t\tFile Opening Error...";
    }
    else
    {
        cout<<"\n\nCode\t\tName\t\tPrice\t\tDiscount";
        file>>code>>name>>price>>discount;
        while(!file.eof())
        {
            cout<<"\n"<<code<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<discount<<" %"<<"\n";
            file>>code>>name>>price>>discount;
        }
        file.close();
    }
}
void bill::list() //list function definition
{
    fstream file;
    file.open("product.txt",ios::in);
    cout<<"\n\n\t\t\t\t====================================================================\n";
    cout<<"\t\t\t\t"<<"P.NO.\t\tNAME\t\tPRICE\t\tDISCOUNT\n\n";
     cout<<"\t\t\t\t====================================================================\n";
     file>>code>>name>>price>>discount;
     while(!file.eof())
     {
        cout<<"\t\t\t\t"<<code<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<discount<<"\n";
        file>>code>>name>>price>>discount;
     }
     file.close();
}
void bill::invoice() //invoice function definition
{
    system("cls");
    fstream file;
    char choice;
    int o_c[50],o_q[50],c=0;
    float amt=0, dis=0,total=0, r_amo=0;
    cout<<"\n\n\t\t\t\t\t\tInvoice Generate";
    file.open("product.txt",ios::in);
    if(!file)
    {
        cout<<"\n\n\t\t\t\tData Base Is Empty...";
    }
    else
    {
        file.close();
        list();
        cout<<"\n\t\t\t\t==========================";
        cout<<"\n   \t\t\t\t PLACE YOUR ORDER";
        cout<<"\n\t\t\t\t==========================";
        do
        {
          p:
          cout<<"\n\n\t\t\t\t Product Code : ";
          cin>>o_c[c];
          cout<<"\n\t\t\t\tProduct Quantity : ";
          cin>>o_q[c];
          for(int i=0;i<c;i++)
          {
            if(o_c[c]==o_c[i])
            {
                cout<<"\n\n\t\t\t\tDuplicate Product Code...";
                goto p;
            }
          }
          c++;
          cout<<"\n\n\t\t\t\tDO You want to add Anothr Product (Y,N) : ";
          cin>>choice;
        } while (choice=='Y'||choice=='y');
        for(int i=0;i<c;i++)
        {
            file.open("product.txt",ios::in);
            file>>code>>name>>price>>discount;
            while(!file.eof())
            {
                if(code==o_c[i])
                {
                    amt=price*o_q[i];
                    dis = amt-(amt/100*discount);
                    total +=dis;
                }
                file>>code>>name>>price>>discount;
            }
            file.close();
        }
        cout<<"\n\n\t\t\t\tTotal Amount : "<<total;
        cout<<"\n\n\t\t\t\tRecive Amount : ";
        cin>>r_amo;
        system("cls");
        cout<<"\n\n*****************************INVOICE**************************************************\n";
        cout<<"\nPr No."<<"\tPr. Name"<<"\tQuantity"<<"\tPrice"<<"\tAmount"<<"  \tAmount after discount";
        for(int i=0;i<c;i++)
        {
            file.open("product.txt",ios::in);
            file>>code>>name>>price>>discount;
            while(!file.eof())
            {
                if(code==o_c[i])
                {
                    amt=price*o_q[i];
                    dis=amt-(amt/100*discount);
                    cout<<"\n"<<code<<" \t"<<name<<"\t\t"<<o_q[i]<<"\t\t"<<price<<"\t"<<amt<<"\t\t"<<dis;
                }
                file>>code>>name>>price>>discount;
            }
            file.close();
        }
        cout<<"\n\n======================================================================================";
        cout<<"\n\t\t\t\tTotal Amount            : "<<total;
        cout<<"\n\t\t\t\tTotal Amount to be paid : "<<total;
        cout<<"\n\t\t\t\tTotal items             : "<<c;
        amt=0;
        for (int i=0;i<c;i++)
        {
            amt+= o_q[i];
        }
        cout<<"\n\t\t\t\tTotal Quantity Sold     : "<<amt;
        cout<<"\n\t\t\t\tAmount Received          : "<<r_amo;
        cout<<"\n\t\t\t\tChange Given            : "<<r_amo-total;
        cout<<"\n\n\t\t\t\t\tTHANK YOU...";
        cout<<"\n_______________________________________________________________________________________\n\n"; 
    }
}
int main()
{
    bill b;b.menu();
}