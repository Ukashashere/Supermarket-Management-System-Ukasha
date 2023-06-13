#include <iostream>
#include <fstream>
using namespace std;
class shopping
{
  private:
    int pcode;
    float price;
    string pname;
    float dis;

  public:
    void menu();
    void administrator();
    void buyer();
    void rem();
    void list();
    void add();
    void edit();
    void reception();

};

void shopping:: menu()
{
  m:
  int choice;
  string email;
  string password;

  cout<<"\t\t\t\t____________________________\n";
  cout<<"\t\t\t\t                            \n";
  cout<<"\t\t\t\t   Supermarket main menu    \n";
  cout<<"\t\t\t\t                            \n";
  cout<<"\t\t\t\t____________________________\n";
  cout<<"\t\t\t\t|| 1)   Administrator      |\n";
  cout<<"\t\t\t\t||                         |\n";
  cout<<"\t\t\t\t|| 2)   Buyer              |\n";
  cout<<"\t\t\t\t||                         |\n";
  cout<<"\t\t\t\t|| 3)   Exit               |\n";
  cout<<"\t\t\t\t||                         |\n";
  cout<<"\t\t\t\t||      Please select      |\n";
  cin>>choice;
  switch(choice)
  {
    case 1:
      cout<<"\t\t\t  please login  \n";
      cout<<"\t\t\t                \n";
      cout<<"\t\t\t  Enter Email   \n";
      cin>>email;
      cout<<"\t\t\t  Enter password\n";
      cin>>password;
      if(email=="ukasha@email.com" && password=="ukasha@123")
      {
        administrator();
      }
      else
      {       
        cout<<"Invalid Email/password";
      }
      break;
     
    case 2:
      {
        buyer();
      }
    case 3:
      {
        exit(0);
      }
    default:  
      {
        cout<<"Please select from the given options";
      } 
}
goto m;
}

void shopping:: administrator()
{
  m:
  int choice;
  cout<<"\n\t\t\t   Administrator menu        ";
  cout<<"\n\t\t\t___1)Add the product        |";
  cout<<"\n\t\t\t                            |";
  cout<<"\n\t\t\t___2)Modify the product     |";
  cout<<"\n\t\t\t                            |";
  cout<<"\n\t\t\t___3)Delete the product     |";
  cout<<"\n\t\t\t                            |";
  cout<<"\n\t\t\t___4)Back to main menu      |";
  cout<<"\n\t\t\t                            |";
  cout<<"\n\t\t\t___Please enter your choice |\n";
  cin>>choice;
  switch(choice)
  {
    case 1:
      {
        add();
        break;
      }
    case 2:
      {
        edit();
        break;
      }
    case 3:
      {
        rem();
        break;
      }
    case 4:
      {
        menu();
        break;
      }
    default:
      {
        cout<<"invalid choice!";
      }
  }
  goto m;
}

void shopping:: buyer()
{
  m:                 //put m: here apmi marzi se
  int choice;
  cout<<"\t\t\t__________Buyer__________\n";
  cout<<"\t\t\t                         \n";
  cout<<"\t\t\t1) Buy product           \n";
  cout<<"\t\t\t                         \n";
  cout<<"\t\t\t2) Go back               \n";
  cout<<"\t\t\t    Enter your choice:   \n";
  cin>>choice;
  switch(choice)
  {
    case 1:
      reception();
      break;
    case 2:
      menu();
    default:
      cout<<"Invalid choice!";    
  }
  goto m;
}  

void shopping:: add()
{
  m:
  fstream data;
  int c;
  int token=0;
  float p;
  float d;
  string n;
  cout<<"\n\n\t\t\t Add new product     ";
  cout<<"\n\n\t\t\t Product code of the product:";
  cin>>pcode;
  cout<<"\n\n\t\t\t Name of the product: ";
  cin>>pname;
  cout<<"\n\n\t\t\t price of the product:";
  cin>>price;
  cout<<"\n\n\t\t\tdiscount on product:\n";
  cin>>dis;

  data.open("database.txt",ios::in);
  if(!data)
  {
    data.open("database.txt",ios::app|ios::out);
    data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
    data.close();
  
  }
  else
  {
    data>>c>>n>>p>>d;
    while (!data.eof())
    {
      if(c==pcode)
      {
        token++;
      }
      data>>c>>n>>p>>d;
    }
    data.close();
  }
  if(token==1)
    goto m;
  else
  {
    data.open("database.txt",ios::app|ios::out);
    data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
    data.close();
    cout<<"\n\n\t\t record inserted!";
  }
}
void shopping::edit()
{
  fstream data,data1;
  int pkey;
  int token=0;
  int c;
  float p;
  float d;
  string n;

  cout<<"\n\t\t\t Modify the record";
  cout<<"\n\t\t\t Product code:    ";
  cin>>pkey;
  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"\n\nfile dosen't exist!\n";
  }
  else{
    data.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
      if(pkey==pcode)
      {
        cout<<"\n\t\t Product  new code: ";
        cin>>c;
        cout<<"\n\t\t name of the product:";
        cin>>n;
        cout<<"\n\t\t Discount :        \n";
        cin>>d;
        data1<<"  "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"\n";
        cout<<"\n\n\t\t record edited\n";
        token++;
      }
      else
      {
        data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
      }
      data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();

    remove("database.txt");
    rename("database1.txt","database.txt");
    if(token==0)
    {
      cout<<"\n\n Record not found sorry!";
    }

  }
}
void shopping::rem()
{
  fstream data,data1;
  int pkey;
  int token=0;
  cout<<"\n\n\t Delete product";
  cout<<"\n\n\t Product code:";
  cin>>pkey;
  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"File dosen't exist";
  }
  else{
    data.open("database1.txt",ios::app|ios::out);
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
      if(pcode==pkey)
      {
        cout<<"\n\n\t Product deleted successfully";
        token++;
      }
      else
      {
        data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
      }
      data>>pcode>>pname>>price>>dis;
    }
    data.close();
    data1.close();
    remove("database.txt");
    rename("database1.txt","database.txt");

    if(token==0)
    {
      cout<<"\n\n Record not found";
    }
  }
}
void shopping::list()
{
  fstream data;
  data.open("database.txt",ios::in);
  cout<<"\n\n|_______________________________\n";
  cout<<"proNo\t\tName\t\tPrice\n";
  cout<<"\n\n|_______________________________\n";
  data>>pcode>>pname>>price>>dis;
  while(!data.eof())
  {
    cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
    data>>pcode>>pname>>price>>dis;
  }
  data.close();
}

void shopping::reception()
{
  fstream data;
  int arrc[100];
  int arrq[100];
  string choice;
  int c=0;
  float amount=0;
  float dis=0;
  float total=0;
  cout<<"\n\n\t\t\t  RECEIPT ";
  data.open("database.txt",ios::in);
  if(!data)
  {
    cout<<"\n\n Empty database ";
  }
  else{
    data.close();
    list();
    cout<<"\n_______________________\n";
    cout<<"\n***********************\n";
    cout<<"\n Please place the order\n";
    cout<<"\n***********************\n";
    cout<<"\n_______________________\n";
    do
    {
      m:
      cout<<"\n\n Enter product code     ";
      cin>>arrc[c];
      cout<<"\n\n Enter product quantity:";
      cin>>arrq[c];
      for(int i=0;i<c;i++)
      {
        if(arrc[c]==arrc[i])
        {
          cout<<"\n\n Dublicate product code. Please try again!\n";
          goto m;
        }
      }  
      c++;
      cout<<"\n\n Do you want to buy another product? if yes then press y else no\n";
      cin>>choice;
    }
    while(choice=="y");
    cout<<"\n\n\t\t\t_______________________RECEIPT_____________________\n";
    cout<<"\n Product No\t Product Name\t Product quantity\t price\t amount with discount\n";
    for(int i=0; i<c; i++)
    { 
      data.open("database.txt",ios::in);
      data>>pcode>>pname>>price>>dis;
      while(!data.eof())
      {
        if(pcode==arrc[i])
        {
          amount=price*arrq[i];
          dis=amount-(amount*dis/100);
          total=total+dis;
          cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
        }
        data>>pcode>>pname>>price>>dis;
      }
    }
    data.close();
  }
  cout<<"\n\n____________________________________________________________________________________";
  cout<<"\n\n total Amount : \n"<<total;
}
int main()
{
  shopping s;
  s.menu();
}
