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
	    cout<<"history";
	 }else if(c==3){
	 	intro();
	 }
}

void ticketing(string username){
	system("cls");
	int c,count;
	cout<<"\t---------------- Welcome To User Home Screen ----------------"<<endl<<endl;

	showcity(username);

cout<<endl<<endl<<"\t Press 1 to Select city"<<endl;
cout<<endl<<endl<<"\t Press 0 to Go back"<<endl;
	 cout<<endl<<"Enter The Number of Your choice : ";
 	cin>>c;
if(c==0){
	home(username);
}else if(c==1){
	
}
}

void showcity(string username){
	string airline;
	int count=0;
	ifstream file("cities.txt");
	while(file>>airline){
		cout<<count+1<<" "<<airline<<endl;
		count++;
	}
}
