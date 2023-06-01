#include<iostream>
#include<fstream>
#include<conio.h>

using namespace std;


void intro();
void login();
void reg();
void home(string);
void ticketing(string);
void showcity(string );
void flights(string ,string ,string );
void billing(int, string );
void create_userhistory( double ,string ,string , string );
void show_history(string );

int main(){
	intro();	
}

void intro(){
	system("cls");
	int choice;
	system("Color 0C");

cout<<"\t---------------- Welcome To Airline tikcting Software ----------------"<<endl<<endl;

cout<<"\tPress 1 for Login"<<endl;
cout<<"\tpress 2 for Registraion"<<endl;
cout<<"\tPress 4 to Quit App"<<endl;
cout<<endl;

cout<<"Enter Number of Your choice : ";
	cin>>choice;
if(choice == 1){
	login();
}else if(choice == 2){
	reg();
}else if(choice == 3){
	cout<<"Thankyou Visit us again";
}else{
	cout<<endl<<"\t Invalid Input";
	main();
}
}

void login(){
    string username,password,un,pw;
    int ch;
    bool isfound = false;
     system("cls");
    cout<<"\t---------------- Welcome To User Login Page ----------------"<<endl<<endl;
    cout<<"\tEnter Your username : ";
    cin>>username;
    cout<<"\tEnter Your Password : ";
    
	ch = getch();
   while (ch != 13) {
        if (ch == 8) {
            if (!password.empty()) {
                cout << "\b \b"; // Erase the character from the screen
                password.erase(password.size() - 1); 
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
    ifstream file("registered.txt");
    while(file>>un>>pw){ 
        if(un == username && pw == password){
            isfound = true;
            break;
        }
    }
    file.close();

    if(isfound){
        
		home(username);        
        
    }else{
       int c;
        cout<<endl<<"\tWrong Username Or Password try Again"<<endl;
       
		cout<<endl<<"\tWant to Redirect Welcome Screen press 1"<<endl;
		cout<<"\tWant to Redirect User Registertation Screen press 2"<<endl;
	
		cout<<endl<<"Enter Number of Your choice : ";
		cin>>c;	
		if(c==1){
			main();
		}else if(c==2){
			reg();
		}else{
			cout<<"\tInvalid Input";
			
			system("cls");
			main();
		}
}
}

void reg() {
    string username, password, un, pw;
    bool isfound = false;
    int c, ch;
    system("cls");
    cout << "\t---------------- Welcome To User Registration Page ----------------" << endl
         << endl;

    cout << "\tEnter Your username : ";
    cin >> username;
    cout << "\tEnter Your Password : ";
    ch = _getch();
    while (ch != 13) {
        if (ch == 8) {
            if (!password.empty()) {
                cout << "\b \b"; // Erase the character from the screen
                password.erase(password.size() - 1);
            }
        } else {
            password.push_back(ch);
            cout << '*';
        }
        ch = _getch();
    }
     ifstream file("registered.txt");
    while (file >> un >> pw) {
        if (un == username && pw == password) {
            isfound = true;
            break;
        } else {
            isfound = false;
        }
    }
    file.close();

    if (isfound) {
        cout << endl << "You are already registered." << endl;
        cout << endl << "Press 1 for Login Screen: ";
        cin >> c;
        if (c == 1) {
            login();
        }
    } else {
        ofstream files("registered.txt", ios::app);
        files << username << " " << password<<endl;
        files.close();
        cout << endl;
        cout << "\tRegistration Successful! Now you can login and enjoy our services." << endl;
        cout << endl << "Press 1 for Login Screen: ";
        cin >> c;
        if (c == 1) {
            login();
        }
    }
}

void home(string username){
	system("cls");
	int c;
	cout<<"\t---------------- Welcome To User Home Screen ----------------"<<endl<<endl;

    cout<<"\t Press 1 to Book Ticket"<<endl;
	cout<<"\t press 2 to view Tickiting History"<<endl;
	cout<<"\t Press 3 to Logout"<<endl;
 
	 cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
 	if(c==1){
 		ticketing(username);
	 }else if(c==2){
	    show_history( username);
	 }else if(c==3){
	 	intro();
	 }
}

void ticketing(string username){
	system("cls");
	int c,count;
	cout<<"\t---------------- Welcome To User Home Screen ----------------"<<endl<<endl;

	showcity(username);

cout<<endl<<endl<<"\t Press 0 to Go back"<<endl;
	 cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
if(c==0){
	home(username);
}
}



void showcity(string username) {
    string airline, cname, to, from;
    bool isfound = false;
    bool isfound2 = false;
    int count = 0;

    ifstream file("cities.txt");
    while (file >> cname ) {
        cout << count+1 << " " << cname << endl;
        count++;
    }

    file.close(); 

    while (true) {
        int item_index;
        int item_index2;

        cout << endl << "\tEnter the index of the city you want to travel from (1-" << count << "): ";
        cin >> item_index;
        cout << endl << "\tEnter the index of the city you want to travel to (1-" << count << "): ";
        cin >> item_index2;

        if (item_index == 0) {
            cout << "Exiting the program. Goodbye!" << endl;
            break;
        } else if ((item_index < 1 || item_index > count) || (item_index2 < 1 || item_index2 > count)) {
            cout << "Invalid item index. Please try again." << endl;
            continue;
        }

        item_index--;
        item_index2--;

        ifstream infile("cities.txt");
        int current_index = 0;

        while (infile >> cname) {
            if (current_index == item_index) {
                isfound = true;
            from= cname;
                break;
            }
            current_index++;
        }


        infile.clear();
        infile.seekg(0, ios::beg); // Reset the file pointer to the beginning of the file
        
        current_index = 0; // Reset the current_index for the next loop

        while (infile >> cname) {
            if (current_index == item_index2) {
                isfound2 = true;
                to = cname;
                break;
            }
            current_index++;
        }

        infile.close(); 

        if (isfound && isfound2) {
               flights( username, to, from);
            break;
        } else {
            cout << "Invalid item index. Please try again." << endl;
        }
    }
}

void flights(string username,string to,string from){
	string user,From,To,airline;
	int fare,count;
	bool founded = false;
	ifstream file("flights.txt");
	while(file>>From>>To>>airline>>fare){
	   if (to == To && from == From) {
            founded = true;
            cout << count + 1 << " " << airline << " " << fare << endl;
            count++;
      }
	}
	if(!founded){
		cout<<endl<<"No Flight Schdule";
	}else{
	int item_index;
	int total_price=0;
        cout << "Enter the index of the flight you want to book (1-" << count << "): ";
        cin >> item_index;
        if (item_index >= 1 && item_index <= count) {
            int quantity;
            cout << "Enter the quantity of the flight you want to book: ";
            cin >> quantity;
            // Retrieve the fare of the selected flight
            ifstream file("flights.txt");
            int current_index = 0;
            while (file >> From >> To >> airline >> fare) {
                if (to == To && from == From) {
                    current_index++;
                    if (current_index == item_index) {
                        // Calculate total price
                         total_price = fare * quantity;
                        cout << "Total amount: " << total_price << endl;
                        break;
                    }
                }
               
            }
             int c;
                cout<<"To check out Press 1 : ";
                cin>>c;
                if(c==1){
                	billing(total_price,username);
                	 create_userhistory( total_price, username,to,  from);
				}
            file.close();
        } else {
            cout << "Invalid item index. Please try again." << endl;
        }   
	}
}

void billing(int price, string username) {
    system("cls");
    cout << "\t---------------- Billing Page ----------------" << endl << endl;
    cout << "Total Payable Amount is " << price << endl;

        int cvv;
        string wa;
        cout << "\tEnter the Card number : ";
        cin >> cvv;
        cout << "\tEnter the Whatsapp number : ";
        cin >> wa;
       
        cout << "Thanks for purchase!Your tickets will be sended to user phone number" << endl;
    
    }
    
void create_userhistory(double price, string username, string to, string from) {
    ofstream outfile("history.txt", ios::app);
   
        outfile << username << " " << from << " " << to << " " << price << endl;
        outfile.close();
        cout << "History added." << endl;
}
void show_history(string username) {
	system("cls");
    string search_string = username;
    ifstream file("history.txt");
    string line;
    bool isfound = false;
    cout<<"\t---------------- Purchase History ----------------"<<endl<<endl;
    while (getline(file, line)) {
        if (line.find(search_string) != string::npos) {
            cout <<"\t"<< line << endl;
         isfound = true; 
		}
    }    
    if(isfound != true){
    	cout<<"No Purcahase History found "<<endl;
	}
    file.close();
 int c;
 cout<<"Press 0 to go back : ";
 cin>>c;
 if(c==0){
 	home(username);
 }
}


