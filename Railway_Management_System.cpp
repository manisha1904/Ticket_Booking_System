#include<fstream>
#include<iomanip>
#include<iostream>
#include<process.h>
#include<string.h>
#include<stdio.h>
using namespace std;

/*Methods and Attributes related to train class*/
class train
{
	int tno;
	char tname[20];
	char tstart[30];
	char ttermi[30];
	char ttime[15];
	int tcoach;
	char tstations[100];
	public:
		void tgetdata();
		void tshowdata();
		void tmodify(int n);
		char* rettname(){
			return tname;
		}
		int rettno(){
			return tno;
		}
};

/*Methods and Attributes related to passenger class*/
class passanger
{
	int pid;
	char pname[20];
	char pno[11];
	char pdest[40];
	char ptrain[20];
	int pfare;
	public:
		void pgetdata(int id);
		void pshowdata();
		void pmodifiy(int id);
		int retpid()
		{
			return pid;
		}
		char* retptrain(){
			return ptrain;
		}
		char* retpno(){
			return pno;
		}
};

/*Function to input the details of new train*/
void train::tgetdata()
   {
   	string s;
   	cout<<"Enter password for authentication \n";
   	cin>>s;
   	if(s=="DSA_Project"){
   cout<<"\nEnter train number";
   cin>>tno;
   cout<<"\nEnter the name of train";
   cin.ignore(256,'\n');
   gets(tname);
   cout<<"\nEnter starting station";
   gets(tstart);
   cout<<"\nEnter terminating station";
   gets(ttermi);
   cout<<"\nEnter the time of train";
   gets(ttime);
   cout<<"\nEnter all the stations";
   gets(tstations);
   cout<<"\nEnter number of coaches";
   cin>>tcoach;
}
else
cout<<"Wrong Password\n";
cout<<"You don't have permission to make changes here\n";
}

/*Entering details of new train*/
void newtrain()
 { 
 ofstream tt;
   if(!tt) {
      cout << "Cannot open file!" << endl;
    
   }
   
    train tp;
   	tt.open("Train.txt",ios::binary);
   tp.tgetdata();
   tt.write((char*)&tp,sizeof(tp));
   tt.close();
}

/*Printing the details of train*/
void traindetails(){
	train t;
	ifstream if1;
	int x;
	char start='y';
	do{
		cout<<"\n 1. Maroon Line (Palam - IIT Delhi)";
		cout<<"\n 2. White Line (Green Park - Chandni Chowk)";
		cout<<"\n 3. Black Line (Pitampura - Shahdara)";
		cout<<"\n 4. Quit";
		cout<<"\nWhich Train ? (1-4)";
		cin>>x;
		switch(x){
			case 1: if1.open("Train.txt",ios::binary);
			while(if1.read((char*)&t, sizeof(t))){
				if(strcmpi(t.rettname(),"Maroon Line")==0){
					cout<<"Find\n";
					t.tshowdata();
				}
			}
			if1.close();
			break;
			case 2: if1.open("Train.txt",ios::binary);
			while(if1.read((char*)&t, sizeof(t))){
				if(strcmpi(t.rettname(),"White Line")==0)
						t.tshowdata();
			}
			if1.close();
			break;
			case 3: if1.open("Train.txt",ios::binary);
			while(if1.read((char*)&t, sizeof(t))){
				if(strcmpi(t.rettname(),"Black Line")==0)
					t.tshowdata();
			}
			if1.close();
			break;
			case 4: exit(0);
		}
	}while(x<=4);
}

/*Printing details of passengers*/
void passangerdetails()
{
    passanger p;
    ifstream if1;
    int ch;
    cout<<"1. Maroon Line (Palam- IIT Delhi)\n";
    cout<<"2. White Line (Green Park - Chandni Chowk)\n";
    cout<<"3. Black Line (Pitampura - Shahdara)\n";
    cout<<"4. Quit\n";
    cout<<"Enter your Train ? (1-4)\n";
    cin>>ch;
    switch(ch)
    {
        case 1 : if1.open("Passanger.txt",ios::binary);
                 while(if1.read((char*)&p, sizeof(p)))
                 {
                    if(strcmp(p.retptrain(),"Maroon Line")==0)
                    {
                        p.pshowdata();
                    }
                 }
                 if1.close();
                 break;
        case 2 : if1.open("Passanger.txt",ios::binary);
                 while(if1.read((char*)&p, sizeof(p)))
                 {
                    if(strcmp(p.retptrain(),"White Line")==0)
                    {
                        p.pshowdata();
                    }
                 }
                 if1.close();
                 break;
        case 3 : if1.open("Passanger.txt",ios::binary);
                 while(if1.read((char*)&p, sizeof(p)))
                 {
                    if(strcmp(p.retptrain(),"Black Line")==0)
                    {
                        p.pshowdata();
                    }
                 }
                 if1.close();
                 break;
        case 4 : exit(0);
    }
}

/*Details of particular passenger*/
void passanger::pshowdata()
{
    cout<<"\nPassanger Id : "<<pid<<endl;
    cout<<"\nPassanger No : ";
    puts(pno);
    cout<<"\nPassanger Name : ";
    puts(pname);
    cout<<"\nDestination : ";
    puts(pdest);
    cout<<"\nTrain : ";
    puts(ptrain);
    cout<<"\nFare : "<<pfare;
    cout<<endl;
}

/*Details of particular train*/
void train::tshowdata(){
	cout<<"\nTrain number : "<<tno;
	cout<<"\nTrain name : "<<tname;
	cout<<"\nStarting point : "<<tstart;
	cout<<"\nTerminating point : "<<ttermi;
	cout<<"\nTime : "<<ttime;
	cout<<"\nNumber of coaches : "<<tcoach;
	cout<<"\nStations are : "<<tstations;
	cout<<endl;
}

/*Entering the details of passenger related to train and fair*/
void passanger::pgetdata(int id)
{
	pid=id;
	cout<<"Name : ";
	cin.ignore(256,'\n');
	gets(pname);
	cout<<"Phone number : ";
	fgets(pno,sizeof(pno),stdin);
	int x=0,y=0;
	cout<<"\n 1. Maroon Line (Palam - IIT Delhi)";
	cout<<"\n 2. White Line (Green Park - Chandni Chowk)";
	cout<<"\n 3. Black Line (Pitampura - Shahdara)";
	cout<<"\nWhich Train ? (1-3)";
	cin.ignore(256,'\n');
	cin>>x;
	switch(x)
	{
		case 1: strcpy(ptrain,"Maroon Line");
		        cout<<"\n Stations                    fare(1-7)  fare(7-1)";
		        cout<<"\n 1. Palam                       10         70";
		        cout<<"\n 2. Sadar Bazaar Cantonment     20         60";
		        cout<<"\n 3. T1 - IGI Airport            30         50";
		        cout<<"\n 4. Shankar Vihar               40         40";
		        cout<<"\n 5. Munirka                     50         30";
		        cout<<"\n 6. R.K. Puram                  60         20";
		        cout<<"\n 7. IIT Delhi                   70         10";
		        cout<<"\n Enter your Destination ? (1-7)";
		        cin.ignore(256,'\n');
		        cin>>y;
		        switch(y)
		        {
		        	case 1: strcpy(pdest,"Palam");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
		        	        break;
		        	case 2: strcpy(pdest,"Sadar Bazaar Cantonment");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 3: strcpy(pdest,"T1 - IGI Airport");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 4: strcpy(pdest,"Shankar Vihar");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 5: strcpy(pdest,"Munirka");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 6: strcpy(pdest,"R.K. Puram");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 7: strcpy(pdest,"IIT Delhi");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
				}
				break;
		case 2: strcpy(ptrain,"White Line");
		        cout<<"\n Stations              fare(1-6)  fare(6-1)";
		        cout<<"\n 1. Green Park            10         60";
		        cout<<"\n 2. INA                   20         50";
		        cout<<"\n 3. Udyog Bhawan          30         40";
		        cout<<"\n 4. Patel Chowk           40         30";
		        cout<<"\n 5. New Delhi             50         20";
		        cout<<"\n 6. Chandni Chowk         60         10";
		        cout<<"\n Enter your Destination ? (1-6)";
		        cin>>y;
		        switch(y)
		        {
		        	case 1: strcpy(pdest,"Green Park");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 2: strcpy(pdest,"INA");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 3: strcpy(pdest,"Udyog Bhawan");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 4: strcpy(pdest,"Patel Chowk");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 5: strcpy(pdest,"New Delhi");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 6: strcpy(pdest,"Chandni Chowk");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
				}
		        break;
		case 3: strcpy(ptrain,"Black Line");
		        cout<<"\n Stations                    fare(1-6)  fare(6-1)";
				cout<<"\n 1. Pitampura                   10         60";
		        cout<<"\n 2. Netaji Subhash Place        20         50";
		        cout<<"\n 3. Shastri Nagar               30         40";
		        cout<<"\n 4. Tis Hazari                  40         30";
		        cout<<"\n 5. Welcome                     50         20";
		        cout<<"\n 6. Shahdara                    60         10";
		        cout<<"\n Enter your Destination ? (1-6)";
		        cin>>y;
		        switch(y)
		        {
		        	case 1: strcpy(pdest,"Pitampura");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 2: strcpy(pdest,"Netaji Subhash Place");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 3: strcpy(pdest,"Shastri Nagar");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 4: strcpy(pdest,"Tis Hazari");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 5: strcpy(pdest,"Welcome");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
		        	case 6: strcpy(pdest,"Shahdara");
		        	        cout<<"Enter Your Fare : ";
		        	        cin>>pfare;
							break;
				}
		        break;
	}
}

/*Funciton to book ticket*/
void bookticket()
{
	passanger p;
	int pid;
	ifstream if1;
	ofstream of1;
	if1.open("Passanger.txt",ios::binary);
	if1.seekg(0,ios::end);
	long sz=if1.tellg();
	if(sz==-1)
	{
		pid=0;
	}
	else
	{
		if1.seekg(0,ios::beg);
		while(if1.read((char*)&p,sizeof(p)))
		    pid=p.retpid();
	}
	pid++;
	if1.close();
	of1.open("Passanger.txt",ios::binary|ios::app);
	p.pgetdata(pid);
	of1.write((char*)&p,sizeof(p));
	of1.close();
}

/*Modify the details of train*/
void train::tmodify(int n)
{
    tno=n;
    char time[15];
    cout<<"Enter the new time :\n";
    cin.ignore(256,'\n');
    gets(time);
    strcpy(ttime,time);
}

void modifytrain()
{
    train t;
    int n;
    ifstream if1;
    ofstream of1;
    cout<<"Enter the train number to modify :\n";
    cin>>n;
    if1.open("Train.txt",ios::binary);
    of1.open("Temp.txt",ios::binary|ios::out);
    while(if1.read((char*)&t,sizeof(t)))
    {
        if(t.rettno()==n)
        t.tmodify(n);
        of1.write((char*)&t,sizeof(t));
    }
    if1.close();
    of1.close();
    remove("Train.txt");
    rename("Temp.txt","Train.txt");
}


/*Modify details of passenger*/
void passanger::pmodifiy(int id)
{
	pid=id;
	int x;
		cout<<"\n1. Modify Name";
		cout<<"\n2. Modify Phone Number";
		cout<<"\n3. Back to Main";
		cout<<"\nEnter Choice";
		cin>>x;
		switch(x)
		{
			case 1: char name[20];
			        cout<<"Enter new name : ";
			        cin.ignore(256,'\n');
			        gets(name);
			        strcpy(pname,name);
			        break;
			case 2: char phone[10];
			        cout<<"Enter new phone number : ";
			        cin.ignore(256,'\n');
			        gets(phone);
			        strcpy(pno,phone);
			        break;  
			case 3: return;           		  
		}
}

/*Modify the details of booked ticket*/
void modifyticket()
{
	passanger p;
	int id;
	cout<<"Enter the passanger ID to modify ";
	cin>>id;
	ifstream if1;
	ofstream of1;
	if1.open("Passanger.txt",ios::binary);
	of1.open("Temp.txt",ios::binary|ios::out);
	while(if1.read((char*)&p,sizeof(p)))
	{
		if(p.retpid()==id)
		    p.pmodifiy(id);
		of1.write((char*)&p,sizeof(p));    
	}
	if1.close();
	of1.close();
	remove("Passanger.txt");
	rename("Temp.txt","Passanger.txt");
}


/*Function to print ticket*/
void printticket(){
	passanger p;
	ifstream if1;
	char phone[11];
	cout<<"Enter your unique phone number\n";
	cin>>phone;
	if1.open("Passanger.txt",ios::binary);
	while(if1.read((char*)&p,sizeof(p))){
		if(strcmp(p.retpno(),phone)==0){
			cout<<"Here is your ticket\n";
			p.pshowdata();
		}
	}
	if1.close();
}

/*Function to cancel a ticket*/
void cancelticket(){
	int flag=0;
	passanger p;
	ifstream if1;
	ofstream of1;
	char phone[11];
	cout<<"Enter your unique phone number\n";
	cin>>phone;
	if1.open("Passanger.txt",ios::binary);
	of1.open("Temp.txt",ios::binary);
	while(if1.read((char*)&p,sizeof(p))){
		if(strcmp(phone,p.retpno())==0){
			flag=1;
			cout<<"Details of cancelled ticket\n";
			p.pshowdata();
		}
		else{
			of1.write((char*)&p,sizeof(p));
		}
	}
	if1.close();
	of1.close();
	if(flag==0)
		cout<<"Ticket not found\n";
	remove("Passanger.txt");
	rename("Temp.txt","Passanger.txt");
}

/*Main Funciton*/
int main()
{
	cout<<endl<<endl<<endl;
	cout<<setw(100)<<"INDIRA GANDHI DELHI TECHNICAL UNIVERSITY FOR WOMEN \n";
	cout<<endl<<endl<<endl;
	cout<<setw(82)<<"DATA STRUCTURES \n";
	cout<<setw(78)<<"PROJECT \n";
	cout<<endl<<endl<<endl;
	cout<<setw(83)<<"RAILWAY MANAGEMENT \n";
	cout<<setw(77)<<"SYSTEM \n";
	cout<<endl<<endl<<endl;
	cout<<setw(120)<<"MADE BY : \n";
	cout<<setw(138)<<"B.TECH CSE 1 (3RD SEMESTER) \n";
	cout<<setw(135)<<"02801012019 BHAWNA YADAV \n";
	cout<<setw(136)<<"05601012019 SIMRAN ATTREE \n";
	cout<<setw(128)<<"07501012019 NIDHI \n";
	cout<<setw(141)<<"07801012019 MANISHA CHATURVEDI \n";
	cout<<endl<<endl<<endl;
	cout<<"******************************************************************** MAIN MENU ***************************************************************************";
	cout<<endl<<endl;
	int ch,id;
	train t;
	passanger p;
	do
	{
		cout<<"\n1. New Train \n";
		cout<<"2. Book Ticket \n";
		cout<<"3. Print Ticket \n";
		cout<<"4. Cancel Ticket \n";
		cout<<"5. Modify Details of Ticket \n";
		cout<<"6. Modify Details of Train \n";
		cout<<"7. Details of Trains \n";
		cout<<"8. Details of Passangers \n";
		cout<<"9. Quit \n";
		cin>>ch;
		switch(ch)
		{
			case 1: newtrain();
			        break;
			case 2: bookticket();
			        break;
			case 3: printticket();
			        break;
			case 4: cancelticket();
			        break;
			case 5: modifyticket();
			        break;
			case 6: modifytrain();
			        break;
			case 7: traindetails();
			        break;
			case 8: passangerdetails();
			        break;
			case 9: exit(0);        
		}
	}while(ch<=9);
	return 0;
}
