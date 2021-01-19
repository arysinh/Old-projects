/*                   	 COMPUTER SCIENCE PROJECT          [Made by: ARYAN]
				     ON                    [                           &  ]
				BANK MANAGEMENT            [                         ZUBER]            */




#include<iostream>
// #include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iomanip>

using namespace std;


class man_ac
	{

			 public:
			 char name[50];
			 char res_address[50];
			 char contact_no[11];
			 char off_address[50];
			 char type[10];
			 char password[8];

			 int id;
			 double balance;
			 void enter();
			 void display();
			 void withdrawl();
			 void deposit();
			 void bal();

			 friend void view_acc(fstream &);

			 };

//input
	void man_ac::enter()
	{     char a;
	 char password1[8];
	 system("clear");
		cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
	 cout<<endl;

	 cout<<"\nEnter the details of the  account : ";
	 cout<<"\n********************************\n";
	 cout<<"\nName : ";
	 cin>>name;
	 cout<<"Residential address : ";
// 	 gets(res_address);
	 cout<<"Office address : ";
// 	 gets(off_address);
	 cout<<"Contact number : ";
	 cin>>contact_no;

	s0:	 cout<<"Type of account : \n1.Savings  2.Current ";
		 cin>>a;
		if(a=='1')  strcpy(type ,"Savings");
		else if(a=='2')  strcpy(type ,"Current");
		else {cout<<"\n\nInvalid input\n\n";goto s0 ;}
		cout<<endl;
	s1:   cout<<"Enter your password : ";
	 cin >>password;
	 cout<<"Confirm your password : ";
	 cin>>password1;
	 if(strcmp(password,password1))
		 {cout<<"\nPassword unmatched.\nKindly re-enter your password\n\n";
		  goto s1;
		 }
	  cout<<"*****************************\n";
	  cout<<"Your ID NUMBER is "<<id;
	  cout<<"\n*****************************\n";
	  //getch();

	}



	void man_ac::display()
	{
	 system("clear");
		cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
	 cout<<endl;

	 cout<<"\nThe details of the  account : ";
	 cout<<"\n********************************\n";
	 cout<<"\nId Number : "<<id;
	 cout<<"\nName :";
	 cout<<name;
	 cout<<"\nResidential address :";
	 cout<<res_address;
	 cout<<"\nOffice address : ";
	 cout<<off_address;
	 cout<<"\nContact number : ";
	 cout<<contact_no;
	 cout<<"\nType of account : "  ;
	 cout<<type;
	 cout<<"\nBalance : Rs ";
	 cout<<balance;
	}


 void man_ac::withdrawl()           //withdrawl of amount from the existing account
	{
			 system("clear");
			 double w;
			 cout<<" \n\t\t\t     WITHDRAWL AREA \n";
			 cout<<"\t\t\t  ********************\n";
			 cout<<"\nEnter the amount to be withdrawn  : Rs ";
			 cin>>w;
			 if((balance>=w)&& (w<25000.00))
			{ balance-=w;
			  cout<<"\n\nYour amount has been succesfully withdrawn";
			  cout<<" \nYour balance amount is : Rs "<<balance;
			}
			 else
			{ cout<<"\n\nSorry, you cannot withdraw  \n";}
			  cout<<" \n***************************************** ";
			 cout<<" \n\nType the any one of the menus : ";
			 cout<<"\n1: Next-menu"<<endl<<"2 :Exit "<<endl;
			 char opt;
			 switch(opt)
			 { case '1':deposit();break;}

	  }


void man_ac::deposit()
	   {
			 system("clear");
			 double d;
			 char opt;
			 cout<<" \n\t\t\t     DEPOSIT AREA \n";
			 cout<<"\t\t\t  ****************** \n";
			 cout<<"\nEnter the amount to be deposited : Rs ";
			 cin>>d;

			 { balance+=d; }
			 cout<<"\n\nYour amount has been succesfully deposited ";
			 cout<<" \nYour balance amount is : Rs "<<balance;
			 cout<<"\n****************************************";
			 cout<<"\n\nType the any one of the menus \n";
			 cout<<"1: Previous-menu"<<endl<<"2: Next-menu"<<endl<<"3 :Exit "<<endl;
			 cin>>opt;
			 switch(opt)
			 { case '1':withdrawl();break;
				case '2':bal();break;
			 }
	   }



void man_ac::bal()
	    {
		system("clear");

		cout<<" \n\t\t\t     BALANCE AREA \n";
		cout<<"\t\t\t  ****************** \n";
		cout<<" \nYour balance amount is : Rs "<<balance;
		cout<<"\n****************************************";
		cout<<"\n\nType the any one of the menus \n";
		cout<<"1: Previous-menu"<<endl<<"2: Exit "<<endl;
		char opt;
		cin>>opt;
		switch(opt)
			 { case'1':withdrawl();break;
			 }
	    }

//add account
void  add_acc(fstream & f1)
	 {

	 char opt='1';
	 man_ac ob1,ob2;
	 long n1,n2;
	 long int n=0,l=0;
	 f1.seekg(0,ios::end);
	 n=f1.tellg()/sizeof(ob1);

	 ofstream f2;
	 f2.open("temp",ios::binary|ios::out|ios::app);

	 f2.seekp(0);
	 n2=0;

	 f1.seekg(0);
	 n1=0;

	 ob2.id=0;

	 //adding
	 while (opt=='1')
			{ system("clear");
			cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
		cout<<endl;

		cout<<"\nKindly enter the option no";
		cout<<"\n********************************\n";
		cout<<"\n1. Add account"<<"\n2. Quit"<<endl ;
		cin>>opt;
		if (opt=='1'){

			  f1.seekg(n1);
			  while(l<n)
			{ f1.seekg(n1);
			  f1.read((char*) &ob1,sizeof(ob1));
			  n1=f1.tellg();
			  l++;
			  if ((ob1.id - ob2.id)==1)
				  { ob2=ob1;
					 f2.seekp(n2);
					 f2.write((char*) &ob1,sizeof(ob1));
					 n2=f2.tellp();
				  }
			  else
				  {  n1=n1-sizeof(ob1);
				f1.seekg(n1);
				n1=f1.tellg();
				l--;
				break;
				  }
			}


			  ob2.id++;

			  //ui
			  ob2.enter();
			  ob2.balance=0;

			  f2.seekp(n2);
			  f2.write((char*) &ob2,sizeof(ob2));
			  n2=f2.tellp();
			  system("clear");

			  }
		}



	 f1.seekg(n1);
	 f2.seekp(n2);
	 while (l<n)  {
			  f1.read((char*) &ob1,sizeof(ob1));
			  f2.write((char*) &ob1,sizeof(ob1));
			  l++;
			  }
	 f1.clear();
	 f1.close();
	 f2.close();
	 remove("Managerial_acc");
	 rename("temp","Managerial_acc");
	 f1.open("Managerial_acc",ios::binary|ios::in|ios::out);

		 }


//search
int search(fstream &f1,int id)
  {      man_ac ma1;
	 long int l,m,f,flag=-1;

	 f=0;
	 f1.seekg(0,ios::end);

	 l=(f1.tellg()/sizeof(ma1)) -1;
	 while (l>=f)
			{
			m=(l+f)/2;
			f1.seekg(m*sizeof(ma1),ios::beg);
			f1.read((char*) &ma1,sizeof(ma1));
			if (ma1.id==id)
			{f1.seekg(-1*sizeof(ma1),ios::cur);
			 flag=f1.tellg();
			 break;
			}
			else if (ma1.id>id){l=m-1;}
			else {f=m+1;}

			}
	 return(flag);
  }

//delete account
void del_acc(fstream & f1)
  { man_ac ob1;
	 char a,b;
    char flag='1';
    int id;
	 long int n;
    while (flag=='1')
		 {

start: system("clear");
	cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
       cout<<endl;

       cout<<"\nKindly enter the option no";
		 cout<<"\n********************************\n";
       cout<<"\n1. Delete account"<<"\n2. Quit"<<endl ;
	   cin>>b;
	   if(b=='2')
	   break;
	   while(b=='1')  {
		 if (flag=='1')
	    {
	     cout<<"\nKindly enter the ID no. you wish to delete : ";
		  cin>>id;

	     n=search(f1,id);
	     if (n==-1){ cout <<"\nId no. not found.";

			 //getch();
			 goto start;
			}
		  f1.seekg(n);
	     f1.read((char*) &ob1,sizeof(ob1));


	     ob1.display();
	     cout<<"\n\nDo you wish to delete the account ?\nEnter y to delete else n : ";
	     cin>>a;

	     if(a=='y'||a=='Y'){
				 ob1.id=0;
				 f1.seekg(n);
				 f1.write((char*) &ob1,sizeof(ob1));

				 //write rest of the records

				 fstream f2;
				 long int n=0,l=0;
				 f1.seekg(0,ios::end);
				 n=f1.tellg()/sizeof(ob1);
				 f1.seekg(0);
				 f2.open("temp",ios::binary|ios::in|ios::out);
				 while(l<n){
					   f1.read((char*) &ob1,sizeof(ob1));
					   l++;
					   if (ob1.id!=0)  f2.write((char*) &ob1,sizeof(ob1));
						}

				 f1.close();
				 f2.close();
				 remove("Managerial_acc");
				 rename("temp","Managerial_acc");
				 f1.open("Managerial_acc",ios::binary|ios::in|ios::out);
			       }
				}

	 }
       }

}


//modify
void mod_acc(fstream & f1)
{   man_ac ob1;

    system("clear");
	 char opt='1';
    int id;
    long int n;
    char a;
    while (opt=='1')
      {
  start: system("clear");
		cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
	 cout<<endl;

	 cout<<"\nKindly enter the option no";
	 cout<<"\n********************************\n";
	 cout<<"\n1. Search and modify account"<<endl<<"2. Quit"<<endl;
	 cin>>opt;

	 if (opt=='1'){
	      cout<<"\nKindly enter the ID no. : ";
	      cin>>id;

	      n=search(f1,id);
	      if (n==-1){ cout <<"\nId no. not found.";
			  //getch();
			  goto start;
			}
	      f1.seekp(n);
	      f1.read((char*) &ob1,sizeof(ob1));

	      ob1.display();
	      cout<<"\n\nDo you wish to modify the account ?\nEnter y to modify else n : ";
	      cin>>a;

	      if(a=='y'||a=='Y'){  ob1.enter();
				   f1.seekg(n);
				   f1.write((char*) &ob1,sizeof(ob1));
				}
	       }
    }


 }


//display
void view_acc(fstream &f1)
 { man_ac ob1;
   int i=0;
   system("clear");
   long int n=0,l=0;
   f1.seekg(0,ios::end);
	n=f1.tellg()/sizeof(ob1);
   f1.seekg(0);

	cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
   cout<<endl;

   cout<<setw(8)<<"Id No";
	cout<<setw(25)<<"Name";
   cout<<setw(20)<<"Type";
   cout<<setw(20)<<"Balance";
   cout<<endl;
   while(l<n)
	      {  if(i<=15)
		 {  f1.clear();
			 f1.read((char*)&ob1,sizeof(ob1));
		    cout<<endl;
		    cout<<setw(8)<<ob1.id;
		    cout<<setw(25)<<ob1.name;
		    cout<<setw(20)<<ob1.type;
		    cout<<setw(20)<<ob1.balance;
		    i++;
		    l++;
		 }
	       else
		 {  cout<<"\n Press any key to continue";
		    //getch();
		    system("clear");
		    i=0;
				cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
		    cout<<endl;

		    cout<<setw(8)<<"Id No";
			 cout<<setw(25)<<"Name";
			 cout<<setw(20)<<"Type";
			 cout<<setw(20)<<"Balance";
			 cout<<endl;
		 }
			}
		  //getch();

	}

//account as a customer

void cust_menu(fstream &f1)
{

  char password[8];

  int id;
  long pos;
  man_ac ma1;

  int flag=1;
  while(flag){

  char c;
  //Menu
  start:  system("clear");
	cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
  cout<<"\ndo you want to continue?(y/n) : ";
  cin>>c;
  if(c=='N'||c=='n'){ flag=0;
  break;}

  cout<<"\n\n Enter your ID no. :  ";
  cin>>id;

  cout<<" Enter your Password :  ";
  cin>>password;


  pos=search(f1,id);
  if (pos==-1){ cout <<"\n Id no. not found ";
			//getch();
			goto start;
		 }

  f1.seekg(pos);
  f1.read((char*) &ma1,sizeof(ma1));
  if(strcmp(password,ma1.password))
		{cout <<"\n Password unmatched ";
		 //getch();
		 goto start;
		}


  char opti='1';
  while(opti!='4')
		 { system("clear");
		cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
	 cout<<endl<<endl;
	 cout<<"Id no : "<<id<<" \nName :  "<<ma1.name<<endl;
	 cout<<"\n*******************************************************************************";
	 cout<<"\n\n\t\t\t\t    Menu\n";
	 cout<<"\t\t\t\t  ********";
	 cout<<"\n\nSelect your choice :-  ";
	 cout<<"\n1: WITHDRAWL  ";
	 cout<<"\n2: DEPOSIT    ";
	 cout<<"\n3: BALANCE   ";
	 cout<<"\n4: EXIT    ";
	 cout<<"\n*******************";
	 cout<<"\nEnter your choice  :    ";
	 cin>>opti;

  switch(opti)
	{case '1':ma1.withdrawl();break;
	 case '2':ma1.deposit();break;
	 case '3':ma1.bal();break;
	 case '4':
		  flag=0;
		  system("clear");
			cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
		  cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		  cout<<"\n\t\t\t THANK YOU FOR YOUR VISIT ";
		  cout<<"\n\t\t\t *************************";

		  //getch();
	}
	 }

  f1.seekg(pos);
  f1.write((char*) &ma1,sizeof(ma1));
  }


  }

int main()
{
	system("clear");
	int flag=1;
	fstream f1("temp",ios::in|ios::out|ios::app|ios::binary);
	while(flag==1)
	{
		char choice;
		system("clear");
			cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
		cout<<"\n\n    --------------------MAIN MENU----------------------";

		cout<<"\n\n\t1.ACCESS AS A CUSTOMER";
		cout<<"\n\t2.CREATE ACCOUNT";
		cout<<"\n\t3.DELETE ACCOUNT";
		cout<<"\n\t4.MODIFY ACCOUNT";
		cout<<"\n\t5.DISPLAY ACCOUNT" ;
		cout<<"\n\t6.EXIT";
		cout<<"\nPlease enter your choice : ";
		cin>>choice;
		switch(choice)
	{
		case '1':  system("clear");
		cust_menu(f1);
		break;


		case '2':system("clear");
		add_acc(f1);
		 break;

		case '3':system("clear");
		del_acc(f1);
		break;

		case '4':system("clear");
		mod_acc(f1);
		break;

		case '5': system("clear");
		view_acc(f1);
		break;

		case '6':system("clear");
			cout<<"________________________________________________________________________________";
			cout<<"\t\t\t\t A & Z BANK";
			cout<<"\n________________________________________________________________________________";
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;

			cout<<"\n\t\t\t THANK YOU FOR YOUR VISIT ";flag=0;
			cout<<"\t\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t Made by: ARYAN";
			cout<<"\n\t\t\t\t\t\t\t\t\t    &";
			cout<<"\n\t\t\t\t\t\t\t\t\t  ZUBER";
			//getch();
			flag=0;
			f1.close();
			break;

	}
}

};

