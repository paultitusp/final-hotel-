 #include<iostream> 
 #include<fstream>
 #include<conio.h>
 #include<stdio.h>
 #include<string.h>
 #include<process.h>
 #include<windows.h>   // Used for creating gotoxy in Dev C++
 //TODO: Admin Access requires password. USE goto for redirecting functions back to home screen.
 //TODO: Case of exiting from admin to home screen not done.
 
 using namespace std;

 void gotoxy(short x, short y) {  // Used since Dev C++ doesn't support gotoxy present in conio.h
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
 }	
 void clearInputBuffer(){
 	cin.clear();	
	fflush(stdin); //An error occured due to presence of data in the input buffer. Clears the input buffer.
 }
	
class Hotel
    {
    	float star;
		int maxSeat,bookedSeats,hotelid;
    	char name[20],review[300],cuisine[20];
    	//To Paul: Let Abdulla design this part.
    	//TODO: Break Review down into food, Service, look and feel.
    	/*TODO: create a procedure to input each review individually 
		        and specifically ask user to input.
		        Add location.
            Remove all code comments.
		*/
    	public:
    	Hotel(){						//Initialises a hotel object
    		strcpy(name,"   ");
    		strcpy(review,"   ");
    		strcpy(cuisine,"   ");
    		star=0;
    		maxSeat=0;
    		bookedSeats=0;					
    		hotelid=0;
		}
    	void display(){
    		cout<<"HotelID: "<<hotelid<<endl;
			cout<<"Number of seats: "<<maxSeat<<endl;
			cout<<"Available Seat: "<<maxSeat-bookedSeats<<endl;
			cout<<"Name: "<<name<<endl;
			cout<<"Stars: "<<star<<endl;
			cout<<"Cuisine: "<<cuisine<<endl;
			cout<<"Review: "<<endl<<review<<endl;
		}
    	void modifyName(){
        	cout<<"Enter Name"<<endl;
        	clearInputBuffer(); //Used to clear input buffer. Temporarily solved the problem
        	cin.getline(name,20);
        }
        void modifySeats(){
        	cout<<"Enter number of seats"<<endl;
        	cin>>maxSeat;
        }
    	void modifyHotelID(){
        	cout<<"Enter HotelID"<<endl;
        	cin>>hotelid;
        }
    	void modifyStars(){
        	cout<<"Enter Stars"<<endl;
        	cin>>star;
        }
		void modifyReview(){
        	cout<<"Enter Review"<<endl;
        	clearInputBuffer();
        	cin.getline(review,300);
    	}
        void modifyBookedSeats(){
        	int tempSeats;
        	cout<<endl<<endl<<"Welcome to the reservation counter of "<<name<<endl<<endl;
        	cout<<"Available Seats: "<<(maxSeat-bookedSeats)<<endl;
			cout<<"How many seats would you like to book?"<<endl;
        	cin>>tempSeats;
        	if(tempSeats<=(maxSeat-bookedSeats)){
        		bookedSeats+=tempSeats;
			}
			else{
				cout<<"We are booked full. Please try again on a later day."<<endl;
			}
        	
		}
		void modifyCuisine(){
			int d;
			cout<<"\t\t\t\t\t\t"<< "Availble Cuisines";
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t"<< "1) Chinese"<<endl;
			cout<<"\t\t\t\t\t"<< "2) Continental"<<endl;	
			cout<<"\t\t\t\t\t"<< "3) North Indian"<<endl;
			cout<<"\t\t\t\t\t"<< "4) South Indian"<<endl;	
			cout<<"\t\t\t\t\t"<< "5) Cafe"<<endl;
			cout<<"\t\t\t\t\t"<< "6) Dessert"<<endl;
			cout<<"\t\t\t\t\t"<< "7) Exit"<<endl<<endl;
			cout<<"What cuisine does your hotel serve?"<<endl<<"\t";
			cin>>d;
			switch(d)
			{	
				case 1:strcpy(cuisine,"chinese"); 
					   break;
				case 2:strcpy(cuisine,"continental"); 
					   break;
				case 3:strcpy(cuisine,"northIndian"); 
					   break;
				case 4:strcpy(cuisine,"southIndian"); 
					   break;
				case 5:strcpy(cuisine,"cafe"); 
					   break;
				case 6:strcpy(cuisine,"dessert"); 
					   break;
	   			default:break;
			}
		}
		void createHotel(){
			modifyHotelID();
			modifyName();
			modifyCuisine();
			modifyStars();
			modifySeats();
			modifyReview();
		}
		void modifyHotel(){
			system("cls");
			cout<<"What would you like to modify?"<<endl;
			cout<<"1. Name"<<endl;
			cout<<"2. Hotel ID"<<endl;
			cout<<"3. Cuisine"<<endl;
			cout<<"4. Review"<<endl;
			cout<<"5. Number of seats"<<endl;
			cout<<"6. Stars"<<endl;
			cout<<"7. To exit."<<endl;
			int choice;
			cin>>choice;
			switch (choice){
				case 1:
					modifyName();
					break;
				case 2:
					modifyHotelID();
					break;
				case 3:
					modifyCuisine();
					break;
				case 4:
					modifyReview();
					break;
				case 5:
					modifySeats();
					break;
				case 6:
					modifyStars();
					break;
				case 7:
					break;
				default:cout<<"Enter a proper number";
			}			
		}
		int getAvailableSeats(){
			return (maxSeat - bookedSeats);
		}
		char* getCuisine(){
			return cuisine;
		}
		int getHotelId(){
			return hotelid;
		}
		int getMaxseats(){
			return maxSeat;
		}
		char* getHotelName(){
			return name;
		}
		char* getReview(){
			return review;
		}
		float getStars(){
			return star;
		}
	};
char* cuisine()
{
	int d;
	char* c;
	bool invalidNumber=false;
	for(;;){
		cout<<"\t\t\t\t\t\t"<< "Availble Cuisines";
		cout<<endl<<endl;
		cout<<"\t\t\t\t\t"<< "1) Chinese"<<endl;
		cout<<"\t\t\t\t\t"<< "2) Continental"<<endl;	
		cout<<"\t\t\t\t\t"<< "3) North Indian"<<endl;
		cout<<"\t\t\t\t\t"<< "4) South Indian"<<endl;	
		cout<<"\t\t\t\t\t"<< "5) Cafe"<<endl;
		cout<<"\t\t\t\t\t"<< "6) Dessert";
		cout<<"\t\t\t\t\t"<< "7) Exit"<<endl<<endl;
		cout<<"What do you prefer?"<<endl;
		cin>>d;
		switch(d)
		{	
			case 1:strcpy(c,"chinese"); 
				   break;
			case 2:strcpy(c,"continental"); 
				   break;
			case 3:strcpy(c,"northIndian"); 
				   break;
			case 4:strcpy(c,"southIndian"); 
				   break;
			case 5:strcpy(c,"cafe"); 
				   break;
			case 6:strcpy(c,"dessert"); 
				   break;
			case 7:exit(0);
			default: cout<<"Enter a valid choice";
					 invalidNumber=true;		   
		}
		system("cls");
		if(invalidNumber==false){
			break;
		}
	}
	return c;
		
} 
int SearchHotelAdmin(){
	system("cls");
	Hotel placerHotel;
	cout<<"What do you want to search with?"<<endl;
	int choice;
	bool match=false;
	int returnId;
	cout<<"1. Hotel Name"<<endl;
	cout<<"2. Hotel ID"<<endl;
	cin>>choice;
	ifstream fileRead ("Hotel.dat");
	switch(choice){
		case 1:{
			system("cls");
			char searchVariable[20];
			cout<<"Enter name of Hotel Name"<<endl;
			clearInputBuffer();
			cin.getline(searchVariable,20);
			while(fileRead.read((char*)&placerHotel,sizeof(placerHotel))){
				if(!strcmpi(placerHotel.getHotelName(),searchVariable)){
					returnId=placerHotel.getHotelId();
					match=true;
					break;
				}
			}
			break;
		} 
		case 2:{
			system("cls");
			int searchVariable;
			cout<<"Enter name of Hotel Id"<<endl;
			cin>>searchVariable;
			while(fileRead.read((char*)&placerHotel,sizeof(placerHotel))){
				if(searchVariable==placerHotel.getHotelId()){
					returnId=placerHotel.getHotelId();
					match=true;
					break;
				}
			}
			break;
		}
		default:cout<<"Enter a valid number for your choice."<<endl;
	}
	if(match==true){
		return returnId;
	}
	else{
		return 0;
	}
}
int SearchHotelUser(){
	system("cls");
	Hotel placerHotel;
	cout<<"Hit F for Filters."<<endl;
	int choice;
	int returnID=0;
	char characterChoice;
	bool match=false,Stars=false,Cuisine=false;
	int returnId;
	cin>>characterChoice;
	if(characterChoice=='F'){
		for(int i=0;i!=10;){
			system("cls");
			cout<<"1. Stars"<<endl;
			cout<<"2. Cuisine"<<endl;	
			cout<<"3. Exit Filters"<<endl;
			cin>>choice;
			switch(choice){
				case 1: Stars=!Stars;
						cout<<"Star Filter Toggled"<<endl;
						system("pause");
						break;
				case 2: Cuisine=!Cuisine;
						cout<<"Cuisine Filter Toggled"<<endl;
						system("pause");
						break;
				case 3: cout<<"filters exited."<<endl;
						i=10;
			}
		}
	}
	system("cls");
	ifstream fileRead ("Hotel.dat");
	if(Stars==false && Cuisine==false){
		while(fileRead.read((char*)&placerHotel,sizeof(placerHotel))){
			system("cls");
			placerHotel.display();
			cout<<"Is this the hotel you were looking for? \n To book, press y. ";
			cout<<"\n To choose a new hotel, press n."<<endl;
			cin>>characterChoice;
			if(characterChoice=='y'){
				returnID=placerHotel.getHotelId();
				match=true;
				break;
			}
		}
		
	}
	else if(Stars==true && Cuisine==false){
		cout<<"Enter the number of stars of the hotel"<<endl;
		float Starsnumber;
		cin>>Starsnumber;
		while(fileRead.read((char*)&placerHotel,sizeof(placerHotel))){
			if(placerHotel.getStars()==Starsnumber){
				system("cls");
				placerHotel.display();
				cout<<"Is this the hotel you were looking for? \n To book, press y. ";
				cout<<"\n To choose a new hotel, press n."<<endl;
				cin>>characterChoice;
				if(characterChoice=='y'){
					returnID=placerHotel.getHotelId();
					match=true;
					break;
				}
			}
		}
	}
	else if(Stars==false && Cuisine==true){
		char* cuisineChoice;
		strcpy(cuisineChoice,cuisine());
		while(fileRead.read((char*)&placerHotel,sizeof(placerHotel))){
			if(!strcmpi(cuisineChoice,placerHotel.getCuisine())){
				system("cls");
				placerHotel.display();
				cout<<"Is this the hotel you were looking for? \n To book, press y. ";
				cout<<"\n To choose a new hotel, press n."<<endl;
				cin>>characterChoice;
				if(characterChoice=='y'){
					returnID=placerHotel.getHotelId();
					match=true;
					break;
				}
			}
		}
	}
	else{
		cout<<"Enter the number of stars of the hotel"<<endl;
		float Starsnumber;
		cin>>Starsnumber;
		char* cuisineChoice;
		strcpy(cuisineChoice,cuisine());
		while(fileRead.read((char*)&placerHotel,sizeof(placerHotel))){
			if((strcmpi(cuisineChoice,placerHotel.getCuisine()))&&(Starsnumber==placerHotel.getStars())){
				system("cls");
				placerHotel.display();
				cout<<"Is this the hotel you were looking for? \n To book, press y. ";
				cout<<"\n To choose a new hotel, press n."<<endl;
				cin>>characterChoice;
				if(characterChoice=='y'){
					returnID=placerHotel.getHotelId();
					match=true;
					break;
				}
			}
		}
	}
	cout<<returnID;
	if(match==true){
		return returnID;
	}
	else{
		return 0;
	}
}



	bool userlogin()
 {
 	system("cls");
 	char n[30];
	b:
	gotoxy(30,7);
	cout<<"------------------";
	gotoxy(30,6);
	cout<<"|";
	gotoxy(30,5);
	cout<<"------------------";
	gotoxy(10,6);
	cout<<"username";
	gotoxy(32,6);
	cin>>n; //USERNAME
	double p;
	gotoxy(30,9);
	
	gotoxy(30,10);
	cout<<"------------------";
	gotoxy(30,9);
	cout<<"|";
	gotoxy(30,8);
	cout<<"------------------";
	gotoxy(10,9);
	cout<<"password";
	getch();
	gotoxy(32,9);
	char pass[50];
	int i=0;
	for(;;)
	{
		char c = getch();
		if(c=='\r')
		break;
		else
		cout<<"*";
		pass[i]=c;
		i++;
	}
	pass[i]='\0';
	cout<<endl;	
 	//cout<<pass<<endl; // To remove later.
 	getch();
 	char x[30],x1[30],tempUser[25],tempPass[20];
 	bool Login;
 	ifstream iff("user.txt");
 	iff.seekg(ios::beg);
 	for(;;){
 		if(iff.fail()){
 			cout<<"No user has been created. Please sign up."<<endl;
 			break;
		} 
	 	iff>>x;
	 	iff>>tempUser;
	 	//cout<<tempUser; //to remove
// 		getch();
	 	if(!strcmpi(tempUser,n)){
	 		iff>>tempPass;
	 	//	cout<<tempPass; //to remove
	 		if(!strcmp(tempPass,pass))
 				{
				 	cout<<"Login Successfull"<<endl;
				 	Login=true;
			 		getch();
			 		system("cls");
				 	break;
			 	}
		 	else{
				cout<<"Wrong Password"<<endl;
				getch();
				system("cls");
				goto b;		
	 		}
		 }
		 else{	
			iff>>x;
			iff>>x1;
			
			cout<<endl;
			if(iff.eof()){
				cout<<"No user exists"<<endl;
				getch();
				system("cls");
				goto b;
			}
			 		
		 }
	 }
 	iff.close();
 	getch();
 	system("cls");
 	return Login;
 }

class usersignup
{
	char name[25], username[30], password[20];
	double phno;
	public:
		void enter()
		{	
		char temporaryPassword[20],confirmPassword[20];
		clearInputBuffer();
		cout<<"Enter your Name-"<<endl<<endl;
		cin.getline(name,  30);
		cout<<endl;
		cout<<"Enter your username "<<endl<<endl;
		cin.getline(username,  30);
		cout<<endl;
		for(;;){
			cout<<"Enter your password (More than 6 characters) "<<endl<<endl;	
			cin.getline(temporaryPassword,  30);
			cout<<endl;
			cout<<"Renter your password  "<<endl<<endl;
			cin.getline(confirmPassword,  30);
			cout<<endl;
			if(strcmp(confirmPassword,temporaryPassword)!=0)
			  {
			  cout<<"Passwords not matching"<<endl;
			  }
			else
			  {
			  	cout<<"You have succesfully created a new account"<<endl;
			  strcpy(password,temporaryPassword);
			  break;
			  }
		}
	}
	char* getname(){
		return name;
	}
	char* getusername(){
		return username;
	}
	char* getpassword(){
		return password;
	}
 };
 void usersign()
 {
	system("cls");
	usersignup s;
	s.enter();
    ofstream off1("user.txt",ios::app);
	off1<<s.getname()<<endl;
	off1<<s.getusername()<<endl;
	off1<<s.getpassword()<<endl;
	off1<<'#'<<endl;
	off1.close();
 }




 void user()
 {
	system("cls");
	cout<<"  Hello User";
	int p;
	bool check;
	cout<<"        1)Login      2)Sign Up"<<endl<<endl<<endl<<endl;
	c : cin>>p;
	switch (p)
		{
			case 1:check = userlogin();
			break;
			case 2:  usersign();
			break;
			default: cout<<"Choose again";
					 goto c;

		}
	if(check==true){
		int HotelID;
		for(;;){
			system("cls");
			HotelID = SearchHotelUser();
			if(HotelID==0){
				break;
			}
			Hotel tempHotel,dummyHotel;
			ifstream binaryHotel("Hotel.dat");
			while(binaryHotel.read((char*)&dummyHotel,sizeof(dummyHotel))){
				if(HotelID==dummyHotel.getHotelId()){
					tempHotel=dummyHotel;
					break;
				}
			}
	//		tempHotel.display();
	//		getch();
			tempHotel.modifyBookedSeats();
			binaryHotel.seekg(0,ios::beg);
			ofstream replaceHotel("temp.dat");
			replaceHotel.write((char*)&tempHotel,sizeof(tempHotel));
			while(binaryHotel.read((char*)&dummyHotel,sizeof(dummyHotel))){
				if(HotelID!=dummyHotel.getHotelId()){
					replaceHotel.write((char*)&dummyHotel,sizeof(dummyHotel));
				}
			}
			replaceHotel.close();
			binaryHotel.close();
			remove("Hotel.dat");
			rename("temp.dat","Hotel.dat");	
			getch();
		}
	}
 }



bool adminlogin()
 {
 	system("cls");
 	char n[30];
	b:
	gotoxy(30,7);
	cout<<"------------------";
	gotoxy(30,6);
	cout<<"|";
	gotoxy(30,5);
	cout<<"------------------";
	gotoxy(10,6);
	cout<<"Admin name";
	gotoxy(32,6);
	cin>>n; //ADMIN NAME
	double p;
	gotoxy(30,9);
	
	gotoxy(30,10);
	cout<<"------------------";
	gotoxy(30,9);
	cout<<"|";
	gotoxy(30,8);
	cout<<"------------------";
	gotoxy(10,9);
	cout<<"password";
	getch();
	gotoxy(32,9);
	char pass[50];
	int i=0;
	for(;;)
	{
		char c = getch();
		if(c=='\r')
		break;
		else
		cout<<"*";
		pass[i]=c;
		i++;
	}
	pass[i]='\0';
	cout<<endl;	
 	//cout<<pass<<endl; // To remove later.
 	getch();
	char x[30],x1[30],tempadmin[25],tempPass[20];
 	bool Login;
 	ifstream iff("admin.txt" );
 	iff.seekg(ios::beg);
 	for(;;){
 		if(iff.fail()){
 			cout<<"No admin has been created. Please sign up."<<endl;
 			break;
		} 
	 	iff>>x;
	 	iff>>tempadmin;
	 	//cout<<tempadmin; //to remove
// 		getch();
	 	if(!strcmpi(tempadmin,n)){
	 		iff>>tempPass;
	 		//cout<<tempPass; //to remove
	 		if(!strcmp(tempPass,pass))
 				{
				 	cout<<"Login Successfull"<<endl;
				 	Login=true;
			 		getch();
			 		system("cls");
				 	break;
			 	}
		 	else{
				cout<<"Wrong Password"<<endl;
				getch();
				system("cls");
				goto b;		
	 		}
		 }
		 else{	
			iff>>x;
			iff>>x1;
			
			cout<<endl;
			if(iff.eof()){
				cout<<"No Admin exists"<<endl;
				getch();
				system("cls");
				goto b;
			}
			 		
		 }
	 }
 	iff.close();
 	getch();
 	system("cls");
 	return Login;
 }



class adminsignup
{
	char name[25], adminname[30], password[20];
	double phno;
	public:
		void enter()
		{	
		char temporaryPassword[20],confirmPassword[20];
		clearInputBuffer();
		cout<<"Enter your Name-"<<endl<<endl;
		cin.getline(name,30);
		cout<<endl;
		cout<<"Enter your Admin name "<<endl<<endl;
		cin.getline(adminname,30);
		cout<<endl;
		for(;;){
			cout<<"Enter your password (More than 6 characters) "<<endl<<endl;	
			cin.getline(temporaryPassword,  30);
			cout<<endl;
			cout<<"Renter your password  "<<endl<<endl;
			cin.getline(confirmPassword,  30);
			cout<<endl;
			if(strcmp(confirmPassword,temporaryPassword)!=0)
			  {
			  cout<<"Passwords not matching"<<endl;
			  }
			else
			  {
			  	cout<<"You have succesfully created a new Adiministrative Account"<<endl;
			  strcpy(password,temporaryPassword);
			  break;
			  }
		}
	}
	char* getname(){
		return name;
	}
	char* getusername(){
		return adminname;
	}
	char* getpassword(){
		return password;
	}
 }; 



void adminsign()
 {
	system("cls");
	adminsignup s;
	s.enter();
    ofstream off1("admin.txt",ios::app);
	off1<<s.getname()<<endl;
	off1<<s.getusername()<<endl;
	off1<<s.getpassword()<<endl;
	off1<<'#'<<endl;
	off1.close();
 }


void admin()
	{
	system("cls");
	cout<<"  Welcome Admin";
	int p;
	bool check;
	cout<<"        1)Login      2)Sign Up"<<endl<<endl<<endl<<endl;
	c : cin>>p;
	switch (p)
		{
			case 1:check = adminlogin();
			break;
			case 2:  adminsign();
			break;
			default: cout<<"Choose again";
					 goto c;

		}
	if(check==true)
	{
	int choice;
	Hotel dummyHotel;
	cout<<"  Hello Admin";
	getch();
	for(;;){
		system("cls");
		cout<<"What would you like to do?"<<endl;
		cout<<"1.Add a new hotel"<<endl;
		cout<<"2.Modify hotel details"<<endl;
		cout<<"3.Remove a hotel from the database."<<endl;
		cout<<"4.Display all hotels in database"<<endl;
		cout<<"5.Exit ."<<endl;
		cin>>choice;
		system("cls");
		switch(choice){
			case 1: 
					{
					
					dummyHotel.createHotel();
						ofstream binaryHotel("Hotel.dat",ios::app);
						binaryHotel.write((char*)&dummyHotel,sizeof(dummyHotel));
						binaryHotel.close();
					}
					break;
			case 2:
					{
						Hotel tempHotel;
						int HotelID=SearchHotelAdmin();
						ifstream binaryHotel("Hotel.dat");
						if(HotelID==0){
							break;
						}
						while(binaryHotel.read((char*)&dummyHotel,sizeof(dummyHotel))){
							if(HotelID==dummyHotel.getHotelId()){
								tempHotel=dummyHotel;
								break;
							}
						}
						
						tempHotel.display();
						getch();
						tempHotel.modifyHotel();
						binaryHotel.seekg(0,ios::beg);
						ofstream replaceHotel("temp.dat");
						replaceHotel.write((char*)&tempHotel,sizeof(tempHotel));
						while(binaryHotel.read((char*)&dummyHotel,sizeof(dummyHotel))){
							if(HotelID!=dummyHotel.getHotelId()){
								replaceHotel.write((char*)&dummyHotel,sizeof(dummyHotel));
							}
						}
						replaceHotel.close();
						binaryHotel.close();
						remove("Hotel.dat");
						rename("temp.dat","Hotel.dat");
					}
					break;
			case 3:
				{
						Hotel tempHotel;
						int HotelID=SearchHotelAdmin();
						if(HotelID==0){
							break;
						}
						ifstream binaryHotel("Hotel.dat");
						ofstream replaceHotel("temp.dat");
						while(binaryHotel.read((char*)&dummyHotel,sizeof(dummyHotel))){
							if(HotelID!=dummyHotel.getHotelId()){
								replaceHotel.write((char*)&dummyHotel,sizeof(dummyHotel));
							}
						}
						replaceHotel.close();
						binaryHotel.close();
						remove("Hotel.dat");
						rename("temp.dat","Hotel.dat");
					}
					break;
				
			case 4: 
					{
						ifstream binaryHotel("Hotel.dat");
						while(binaryHotel.read((char*)&dummyHotel,sizeof(dummyHotel))){
							system("cls");
							dummyHotel.display();
							getch();
						}
						binaryHotel.close();
					}
					break;
					
					
			case 5: exit(0)	;	
		}
	}
}

}

 int main()
 {
	int n;
	cout<<"                          WELCOME TO HUNGRY HELPERS";
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"      Are you :-"<<endl<<endl;
	cout<<"                   1)USER       2)HOTEL MANAGEMENT        0)Exit"<<endl;
	a:cin>>n;
	cout<<endl<<endl<<endl<<endl;
	switch(n)
		{
			case 1: user();
			break;
			case 2: admin();
			break;
			case 0: exit(0);

			default:cout<< "Choose again"<<endl;
			goto a;
		}
		return 0;
 }



