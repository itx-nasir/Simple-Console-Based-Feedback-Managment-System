#include<iostream>
#include<fstream>
#include<cstring>
#include<iomanip>
using namespace std;
void ASK_PASSWORD();
int CALCULATION(string);
void admin();
void menu(int);
void students();
void MODIFY(int );
void EDIT();
void VIEW(int );
void SEARCH_WORD();
void LOG_OUT();
bool CHECK_PASSWORD(string,string,int);
void REMOVE(int);
void ADD(int);
int Give_Feedback(string);
int main()

     { 
     
	 cout<<"\n\t\t\t\t| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
	  cout<<"\t\t\t\t| WELCOME TO ICAST INSTITUTE OF MODERN EDUCATION |\n";
	  cout<<"\t\t\t\t|            FEEDBAK MANAGEMENT SYSTEM           |\n";
	  cout<<"\t\t\t\t| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
	   menu(1);
      
       return 0;
      }

void menu(int flag)              //Every menu is control by this  function....
  { if(flag==1)
  {
    char ch;
     bool a;
     cout<<"\n| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
     cout<<"|Enter A/a if you are admin.                     |";
	 cout<<"\n|Enter S/s If you are student.                   |";
	 cout<<"\n| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
     cin>>ch;
      while(ch!='A' && ch!='a' && ch!='S' && ch!='s' )
             {cout<<"Invalid Input....Please enter S or A.\n";
               cin>>ch;
		     }
		     
 if(ch=='A'||ch=='a')
      { admin();
	  }
 if(ch=='S'|| ch=='s')
        {
		students();
		}
}

if(flag==2)
    {
    int choice;
   cout<<"\n\n| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
   cout<<"|The available menu are:               |\n";
   cout<<"|enter 1 for adding students.          |\n";
   cout<<"|Enter 2 for removing student.         |\n";
   cout<<"|Enter 3 for Editing feedback.         |\n";
   cout<<"|Enter 4 for viewing feedback.         |\n";
   cout<<"|Enter 5 for Modifying student details.|\n";
   cout<<"|Enter 6 for word to seacrch.          |\n";
   cout<<"|Enter 7 for log out.                  |\n"; 
   cout<<"| *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*|\n";
   cin>>choice;
   	 switch(choice)
   {
	case 1:
	     ADD(1);
	     break;
	case 2:
	     REMOVE(1);
	     break;
    case 3:
    	EDIT();
        break;
    case 4:
    	VIEW(2);
    	break;
    case 5:
    	MODIFY(1);
    	break;
    //case 6:                                    //UNDER COSTRUCTION    
    //	SEARCH_WORD();
    //	break;
    case 7:
    	LOG_OUT();
    	break;
    }
  }
}
void admin()                               //this function will ask password and user ID of admin it control all the..
                                          //task..
	{ 
	 string ID,pass;
     cout<<"Please enter your admin ID\n";
     cin>>ID;
     cout<<"Enter your password.\n";
     cin>>pass;
     bool a;
         a=CHECK_PASSWORD(ID,pass,1);
         while(a!=1)
             {cout<<"Invalid password or user name:\nPlease enter your userID again:\n";
             
               cin>>ID;
               cout<<"Enter your password again:\n";
                cin>>pass;
                a=CHECK_PASSWORD(ID,pass,1);
			 }
	cout<<"YOu have succefully loged in:\n";
	 menu(2);
    

  
    
   }


void ADD(int flag)   //THis Function can add the students as far as admin want..and the questions to the feedback.....

{ 
   fstream outfile,outfile1;
   if (flag==1)
   { outfile.open("Students_data.txt",ios::in);
     if(outfile.fail())
         {outfile.open("Students_data.txt",ios::out);
          outfile<<"Name"<<setw(40)<<"Password"<<setw(40)<<"Name"<<endl;
          outfile.close();
		 }
		 outfile.close();
   	
		  VIEW(1);
  
       outfile.open("Students_data.txt",ios::out|ios::app);
      int n;
      cout<<"Enter how many students do you want to add.\n";
      cin>>n;
      string name;
      string roll,password;
      for(int i=0;i<n;i++)
        {   
        	cout<<"Enter roll number of that student: ";
        
        	cin>>roll;
           outfile<<roll<<setw(40);
           cout<<"SEt the password for that student :";
            cin>>password;
            outfile<<password<<setw(40);
	        cout<<"Enter the  name of  student that you want to add to the file: ";
	        cin.ignore();
            getline(cin,name);
           outfile<<name<<endl;
           
         }
    outfile.close();
     VIEW(1);
    }
    
 else if(flag==2)
      { outfile1.open("Feedback.txt",ios::in);
         if(outfile1.fail())
              {outfile1.open("Feedback.txt",ios::out|ios::app);
               outfile1<<" A  B  C  D  E     A)strongly agree   B)agree   C)uncertain   D)Dissatisfied E)Strongly Disagree";
               outfile1<<endl;
			  }
	    outfile1.close();
       VIEW(2);
       outfile1.open("Feedback.txt",ios::out|ios::app);
      int n;
      cout<<"Enter how many questions do you want to add to the feedback.\n";
      cin>>n;
      string name;
      for(int i=0;i<n;i++)
        {
	      cout<<"Enter the  Question "<<i+1<<" you want to add to the feedback "; 
		  cout<<"start at like Q.1),Q.2) etc end at with ?.\n";
		  cin.ignore();
           getline(cin,name);
           outfile1<<name<<endl;
         }
    outfile1.close();
    VIEW(2);
    }
  
int choice;
  cout<<"Added succesfully.\n Enter 1 for going to the main menu.\n";
  cout<<"Enter 2 for log out.\n";
  cin>>choice;
  if(choice==1)
       menu(2);
 else if(choice==2)
       LOG_OUT(); 
}

void REMOVE(int flag)    //this function can remove the student and feedback question.
{ fstream outfile,outfile1;
if(flag==1)
     { VIEW(1);
	   int n;
      cout<<"Enter number of students you want to delete.";
       cin>>n;
        for(int i=0;i<n;i++)
           {
              outfile1.open("temp.txt",ios::out);
              outfile.open("Students_data.txt",ios::in);
               string roll,temp;
  
                cout<<"Enter the roll number of the  student  that you want to Remove.\n";
                cin>>roll;
                while(outfile>>temp)
                   {if (temp==roll)
                       {getline(outfile,temp);
		               }
	                 else
	                   { 
		                outfile1<<temp;
		                 getline(outfile,temp);
		                 outfile1<<temp<<endl;
	                   }
	               }
                 outfile.close();
                 outfile1.close();
				  remove("Students_data.txt");
                 rename("temp.txt","Students_data.txt");
            }
        VIEW(1);
      }
  else if(flag==2)
     { VIEW(2);
	   int n;
      cout<<"Enter number of questions you want to delete.\n";
       cin>>n;
        for(int i=0;i<n;i++)
           {
              outfile1.open("temp.txt",ios::out);
              outfile.open("Feedback.txt",ios::in);
               string roll,temp;
  
                cout<<"Enter the  name of question  that you want to Remove in a specific format e.g Q.1).\n";
                cin>>roll;
                while(outfile>>temp)
                   {if (temp==roll)
                       {getline(outfile,temp);
           
		               }
	                 else
	                   { 
		                outfile1<<temp;
		                 getline(outfile,temp);
		                 outfile1<<temp<<endl;
	                   }
	               }
                 outfile.close();
                 outfile1.close();
				  remove("Feedback.txt");
                 rename("temp.txt","Feedback.txt");
            }
        VIEW(2);
      }
  int choice;
  cout<<"Removed  Succefully.\n Enter 1 for going to the main menu.\n";
  cout<<"Enter 2 for log out.\n";
  cin>>choice;
  if(choice==1)
       menu(2);
 else if(choice==2)
       LOG_OUT();
	   
}   

void VIEW(int flag)        //THis function will control all  display i-e feedback display....
{ string Q;
   fstream outfile;
  if(flag==1)
     {	
	    outfile.open("Students_data.txt",ios::in);
		cout<<"The students in your files are.\n";
        while(getline(outfile,Q))
            cout<<Q<<endl;
	  } 
  else if(flag==2)
         {
	     outfile.open("feedback.txt",ios::in);
		
        while(getline(outfile,Q))
            cout<<Q<<endl<<endl;
         }
}
	
void EDIT()   //this functio is for admin to edit feedback and students data.....
{int choice;
 cout<<"NOw you can Edit feedback....\n";
 cout<<"Enter 1 for Adding the question.\nEnter 2 for Removing the quiestion.\nEnter 3 for Modifying the Question.";
 cout<<"enter 4 for MOving back to the main menu:\n";
 cin>>choice;
 switch(choice)
      {case 1:
      	 ADD(2);
      	 break;
      	case 2:
      	  REMOVE(2);
      	case 3:
      		MODIFY(2);
      	case 4:
      		menu(2);
	  }
}


void MODIFY(int flag)    //will modify the question and student data if admin want
{ 
  fstream outfile,outfile1;
  string temp,temp1;
  if(flag==1)
      { VIEW(1);
	   int n;
      cout<<"Enter number of students that you want to modify their ID or password or name.\n";
       cin>>n;
        for(int i=0;i<n;i++)
           {
              outfile1.open("temp.txt",ios::out);
              outfile.open("Students_data.txt",ios::in);
  
                cout<<"Enter the roll number of the  student  that you want to edit.\n";
                cin>>temp;
                while(outfile>>temp1)
                   {
				     if(temp==temp1)
                     {     cout<<"The detail of the student are.\n"<<temp1<<"   ";
                           getline(outfile,temp1);
                           cout<<temp1;
                           cout<<"\nEnter the new ID for the student.\n";
                           cin>>temp1;
                           outfile1<<temp1<<setw(40);
                           cout<<"\nEnter new password for that student.\n";
                           cin>>temp1;
                           outfile1<<temp1<<setw(40);
                           cout<<"Enter new name for that student.\n";
                           cin.ignore();
                           getline(cin,temp1);
                           outfile1<<temp1<<endl;
				   }
                   	
                   	
	                 else
	                   { 
		                outfile1<<temp1;
		                 getline(outfile,temp1);
		                 outfile1<<temp1<<endl;
	                   }
	               }
                 outfile.close();
                 outfile1.close();
				  remove("Students_data.txt");
                 rename("temp.txt","Students_data.txt");
            }
        cout<<"Modified successfully..\n\nNow the students in your file is.";
        VIEW(1);
      }
      
      
  if(flag==2)
      { VIEW(2);
	   int n;
      cout<<"Enter number of questions that you want to modify.\n";
       cin>>n;
        for(int i=0;i<n;i++)
           {
              outfile1.open("temp.txt",ios::out);
              outfile.open("Feedback.txt",ios::in);
  
                cout<<"Enter the question number as Q.1),Q.2),Q.3) that you want to modify.\n";
                cin>>temp;
                string kh;
                while(outfile>>temp1)
                   {
				     if(temp==temp1)
                     {   kh=temp1;
                           cout<<"\n the  Question you want to edit is "<<temp1;
                           getline(outfile,temp1);
                           cout<<temp1<<endl;
                           cout<<"\nEnter the new Question and end it with ?.\n"<<kh<<" ";
                           cin.ignore();
                           getline(cin,temp1);
                           outfile1<<kh<<" "<<temp1<<endl;
				   }
                   	
                   	
	                 else
	                   { 
		                outfile1<<temp1;
		                 getline(outfile,temp1);
		                 outfile1<<temp1<<endl;
	                   }
	               }
                 outfile.close();
                 outfile1.close();
				  remove("Feedback.txt");
                 rename("temp.txt","Feedback.txt");
            }
        cout<<"Modified successfully..\n\nNow the Questions in your feedback file is\n\n.";
        VIEW(2);
      }     
menu(2);
	 
}
void students()    //will ask student password and id....
     { bool a;
	 string UserID,password; 
	
	  cout<<"please enter your user ID:\n";
         cin>>UserID;
         cout<<"\nEnter your password:\n";
         cin>>password;
         a=CHECK_PASSWORD(UserID,password,2);
         while(a!=1)
             {cout<<"Invalid password or user name:\nPlease enter your userID again:\n";
             
               cin>>UserID;
               cout<<"Enter your password again:\n";
                cin>>password;
                a=CHECK_PASSWORD(UserID,password,2);
			 }
	cout<<"YOu have succefully loged in:\n";
	cout<<" Enter 1  for giving feedback.\nEnter 2 for logout.\n";
	int choice;
	cin>>choice;
	if(choice==1)
	    {
		int m=Give_Feedback(UserID);
	      if(m==0)
	         cout<<"Sorry you cant give feedback again.";
	     }
	else if(choice==2)
	     LOG_OUT();
	}

int Give_Feedback(string UserID)   //student will give feedback only once....
{
int count4=0;
 fstream khattak,khattak1;
  string nasii;
  nasii=UserID;
  khattak.open("given_feedback.txt",ios::in);
           string ch;
           while(khattak>>ch)
                {
	              if(ch==nasii)
                  {  return 0;
		          }
                }
           khattak.close();	
  UserID+=".txt";
lable1:
	  {
	  if(count4<5)
	     { 
		   	   
           int i;
           int choice,count=0;
           string arr[5]={"ITC","English","History","calculus 1","Linear Algebra"};
           for(i=0;i<5;i++)
           {cout<<"Enter "<<i+1<<" for "<<arr[i]<<endl;
	       }
           cin>>choice;
          switch(choice)
           { 
	        case 1:
      	       cout<<arr[0];
      	       break;
      	    case 2:
      		   cout<<arr[1];
      		   break;
      	    case 3:
      		   cout<<arr[2];
      		   break;
      	    case 4:
      		   cout<<arr[3];
      		    break;
      	    case 5:
      		    cout<<arr[4];
      		    break;
	       }
	  cout<<"   Feedback\n\n\n";
	  VIEW(2);
	  char temp;
	  cout<<"\n\nSElect any one option in all the question\n.Select it as A,B etc.\n\n";
	  fstream outfile;
	  outfile.open(UserID.c_str(),ios::out|ios::app);
	   fstream   outfile2;
	     outfile2.open("Feedback.txt",ios::in);
	    outfile<<setw(40)<<"Answers   sheet of  "<<arr[choice-1]<<endl<<endl;
	    i=0;
	    string temp2,comment;
	          getline(outfile2,temp2);
	      while(getline(outfile2,temp2,'?'))
	          {cout<<" Enter the option of question No."<<i+1<<endl;
	           cin>>temp;
	           outfile<<"Ans."<<i+1<<")"<<setw(10)<<temp<<endl<<endl;
	           i++;
		      }
	    double per;
		per=CALCULATION(UserID);
		per=per/i;
		outfile<<"percentage="<<per<<"%"<<endl;
     cout<<"Comment if any:\n";
     cin.ignore();
     getline(cin,comment);
     outfile<<"comment: "<<comment;
  count4++; 
   goto lable1;
   }
 khattak1.open("given_feedback.txt",ios::out|ios::app);
     khattak1<<nasii<<endl;
    khattak1.close();  
   
 } 
 
 
     
}
int CALCULATION(string userID)   //it will calculate percentage and return....
      { double percentage=0;
	  fstream outfile;
	   outfile.open(userID.c_str(),ios::in);
	   char temp;
	   while(outfile>>temp)
	         { if(temp=='A'|| temp=='a')
	              percentage+=100;
	          else if(temp=='B'||temp=='b')
	             percentage+=70;
			  else if(temp=='C'||temp=='c')
			      percentage+=40;
			  else if(temp=='D'||temp=='d')
			      percentage+=10;
			  else if(temp=='E'||temp=='e')
			      percentage+=0;   
			 }
			
		return percentage;
		
	  }

bool CHECK_PASSWORD(string UserID,string password,int flag)  //check password and id of both user and admin....
{ string UserID1,password1;
fstream outfile;
if(flag==2)
{
 outfile.open("Students_data.txt",ios::in);
 
 while(outfile>>UserID1 && outfile>>password1)
        { 
		if(UserID==UserID1 && password==password1)
                return 1;
        else
             {cin.ignore();
             getline(outfile,UserID1);
			 }
		}
	return 0;
 
}

else if(flag==1)
     {outfile.open("Admin.txt",ios::in);
      while(outfile>>UserID1 && outfile>>password1)
          
        {  
		if(UserID==UserID1 && password==password1)
                return 1;
		}
	return 0;
	 }
}
void LOG_OUT()
{cout<<"\nLog out successfully..\n";
}
