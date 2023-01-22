#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <list>
#include <locale>
#include <map>
#include <stdlib.h>
#include <string>
#include <vector>
#include <ctime>
#include <unistd.h>


using namespace std;

//global variables
struct hotelSelection;
list <string> hotelsList;
bool x = false;
bool z = false;
string searchedHotel;
list <string> names;
list <string> address;
list <string> phoneNumber;
list<string>availableRooms;
string customerNumber;


//universal//
void Welcome();
void booking();
void response();
void CheckingSystem();
void hotelTxtList();
void checkingIn();
void search();
void getTime();
void List();
void Reciept();
void availability();
void recieptMaker();
void availabilityChecker();
//checking for availability of rooms in hotels
/*void availability(){
  z = true;
  
  
}*/

//STRUCTURES HOLDING VARIABLES
struct hotelSelection{
  public:
  string hotelSelected;
  string Availability;
  string answer;
  string searchAnswer;
};


//function for holding hotel names
void hotelTxtList(){
  //using variables from the structure
  hotelSelection hotelsSelection;

  //openeing the hotels file and adding it to a list
  fstream file;
  file.open("hotels.txt", ios::in);
  if (file.is_open()) {
    string hotelsAvailable;
    while (getline(file, hotelsAvailable)) {
      hotelsList.push_back(hotelsAvailable);
    }
    file.close();
  }
  
}

//function for holding checked in customer list
void checkInList(){  
  fstream checkIn;
  
  checkIn.open("hotels.txt", ios::app);
  if (checkIn.is_open()) {
    checkIn << searchedHotel<< " :" << "check-in date: ";
    checkIn.close();
  }
}

//intro 
void Welcome(){
   system("Color 0B");
    cout<< " ----------------------------------"<<endl;
    cout<< "|    Welcome to Student Lodging    |"<<endl;
    cout<< " ----------------------------------"<<endl<<endl<<endl;
    booking();
}

//getting check-in and check-out date
void getTime(){
   time_t t = time(0);   // get time now
    tm* now = localtime(&t);
    cout << (now->tm_year + 1900) << '-' 
         << (now->tm_mon + 1) << '-'
         <<  now->tm_mday-1
         <<"\n";
  
}
void addingTime(){
  int returnDate;
  int returnMon;
   time_t t = time(0);   // get time now
  tm* now = localtime(&t);
  int currDate =now->tm_mday-1;
 int currMonth = now->tm_mon +1;
  if(currDate > 21 && currMonth ==2 ){
     returnDate =  1;
     returnMon =  3;
    cout<< (now->tm_year + 1900) << '-' 
         << returnMon << '-'
         <<  returnDate 
         <<"\n";
  }
  else if(currDate >23 && currMonth <12){
    returnDate = 1;
    returnMon = now->tm_mon + 1;
    cout<< (now->tm_year + 1900) << '-' 
         << returnMon << '-'
         <<  returnDate
         <<"\n";
    
  }
  else if(currDate >23 && currMonth >11 ){
    returnDate = 3;
    returnMon = 1;
    cout<< (now->tm_year + 1900) +1<< '-' 
         << returnMon << '-'
         <<  returnDate
         <<"\n";
  }
  else{
    cout<< (now->tm_year + 1900)<< '-' 
        <<  currMonth <<'-'
         << currDate +7
         <<"\n";
  }
  
}
void booking(){
hotelSelection hotelSelecting;
cout << "Would you like to check in, search for a hotel or get list of hotels (enter list)? " << endl;

  cin>> hotelSelecting.answer;
  if(hotelSelecting.answer == "check in"|| hotelSelecting.answer == "checkin"|| hotelSelecting.answer == "Check in"){
    checkingIn();
  }
  else if(hotelSelecting.answer == "search"|| hotelSelecting.answer == "Search"){
    search();
  }
  else if(hotelSelecting.answer== "list"|| hotelSelecting.answer == "LIST"|| hotelSelecting.answer == "List"){
    
    List();
  }
}

//paste hotel names//
void List(){
  ifstream Hotels("hotels.txt");
  string lists;
  while(getline(Hotels, lists)){
    cout<<lists<<endl;
  }
   Hotels.close(); 

  sleep(5);
  system("clear");
checkingIn();
  
  
}
void loop(){
  if(z==true){
    system("clear");
    Welcome();
  }
}

//response to lodging//
void checkingIn(){
  cout<< "What hotel would you like to check in to? \n";
  cin.ignore();
  getline(cin, searchedHotel);
  

 for (string j : hotelsList) {
  
    //checks if search matches on of the elements in the list
    if (j.compare(searchedHotel) == 1) {
      x = true;
      }
  }

  //if book matches elements in the list, it asks the user if they want to proceed with the searched book
  if (x == false) {   

    sleep(5);
    system("clear");
      response();
    }
      
      //the searched book is also added to signed out time file along with date of issue and date of return
     
    //if the book does not match the elements of the list, it tells the user to try again as the book was not found
  else {
    cout << "HOTEL NOT FOUND";
    cout << endl << "Please try again!";
    z=true;
    loop();
  }

  
}

void search(){
  hotelSelection hotelSelecting;
string search;
  
  //opens files and lists
  hotelTxtList();
    
  cout << "Enter a hotel name: ";
  //asks for a search
  cin.ignore();
  getline(cin, searchedHotel);
 

  //iterates thru content of the book list
  for (string i : hotelsList) {
    //checks if search matches on of the elements in the list
    if (i.compare(searchedHotel) == 0) {
      x = true;
      
      }
  }

  //if hotel name matches elements in the list, it asks the user if they want to proceed with the searched hotel
  if (x == true) {
    sleep(1);
    cout << "HOTEL FOUND: " << searchedHotel << endl;
    sleep(1);
    cout << "Do you want to proceed with this hotel? ";
    cin >> hotelSelecting.searchAnswer;

    //if they say yes, the system will take them to the booking system page where the user will enter their name, amount of people checking in and their phone number.
    if (hotelSelecting.searchAnswer == "Yes" || hotelSelecting.searchAnswer == "yes") {

      sleep(3);
      system("clear");
      response();
      /*
      getTime();
      booked.open("booked.txt",ios::app);
      if(booked.is_open()){
        booked<< searchedHotel<<endl;
      }
      booked.close();
      response();
*/
    }
    else{
      cout<<"Try again!";
      sleep(2);
      system("clear");
      Welcome();
    }
    }
  else {
    cout << "HOTEL NOT FOUND\nPlease try again!";
    sleep(2);
      system("clear");
    z=true;
      loop();
    }
  
}



/*void response(){
  hotelSelection Lodges;
  fstream booked;
  int numOfRooms;
  string customerName;
  string customerAddress;
  int customerNumber;
   
    cout<< " ----------------------------------"<<endl;
    cout<< "|    Welcome to Booking system     |"<<endl;
    cout<< " ----------------------------------"<<endl<<endl;
    
    cout<< "Lodging Name: "<<searchedHotel<<endl;
    cout<< "Ammount of people checking in: ";
    cin>> Lodges.ammount;
    cout<<"Numbers of room required: ";
    cin>> numOfRooms;
  

  if(z = true){
    cout<< "Please enter your full name: ";
    cin.ignore();
  getline(cin, customerName);
  //names.push_back(customerName);
    cout<<customerName;
  
  cout<< "Please enter your address: ";
  getline(cin, customerAddress);

 // address.push_back(customerAddress);

  cout<< "Please enter your number: ";
  cin>>customerNumber;
  ///phoneNumber.push_back(customerNumber);

    cout<<"Check-in date: ";
    getTime();
    cout<< "Check-out date: ";
    addingTime();
    booked.open("booked.txt",ios::app);
      if(booked.is_open()){
        booked<< "Hotel: "<<searchedHotel<<endl;
        booked<< "Name of the costumer: "<< customerName<< endl;
        booked<< "Number of people checked in: "<< Lodges.ammount<<endl;
        booked<<"Number of rooms checked into: "<<numOfRooms<<endl; 
        booked<< "Address: "<<customerAddress<<endl;
        booked<< "Phone Number: "<<customerNumber<<"\n\n";
      }
      booked.close();
    
  }
  else{
    cout<< "Please check in to another hotel because no rooms are currently available!";
    sleep(3);
    system("clear");
    booking();
      
}
  

  

}*/

struct recieptItems{
    public:
    string name;
    string address;
    string HotelN;
    string Room;
    int ammount;

};

class cost{
public:
  int costOfStay=1500;
};
//Admin Booking system///
void response(){
    cout<< " ----------------------------------"<<endl;
    cout<< "|    Welcome to Booking system     |"<<endl;
    cout<< " ----------------------------------"<<endl<<endl;
    Reciept();
}
//gathers information for reciept and booking//
void Reciept(){ 
  cost pay;
recieptItems reciept; 
  string room;
  fstream booked;
  string c;
    cout<< "Hotels name: "<<searchedHotel<<endl;
  
    cout<< "Name of recipient: ";
  cin.ignore();
    getline(cin, reciept.name);
  
    cout<< "Address: ";
    getline(cin,reciept.address);
  
    cout<<"Please enter your number: ";
    cin>>customerNumber;
  
    cout<< "Number of people checking in: ";
    cin>>reciept.ammount;  
  
    cout<<"Rooms Numbers availiable: "<<endl;
    availability(); 
    cin>> reciept.Room;

  
    sleep(2);

  
    cout<<"Check-in date: ";
    getTime();
    cout<< "Check-out date: ";
    addingTime();
  cout<<"Cost for 1 day = $1500 \n";
  cout<<"Cost of stay for "<<reciept.ammount<<" people for 7 days = $"<<pay.costOfStay * reciept.ammount * 7;
  cout<<"Hope you have a great stay";
    
    booked.open("booked.txt",ios::app);
      if(booked.is_open()){
        booked<< "Hotel: "<<searchedHotel<<endl;
        booked<< "Name of the costumer: "<< reciept.name<< endl;
        booked<< "Address: "<<reciept.address<<endl;
        booked<< "Phone Number: "<<customerNumber<<endl;
        booked<< "Number of people checked in: "<< reciept.ammount<<endl;
         booked<<"Room "<<": "<<reciept.Room<<endl;
           booked<<"Cost of stay= $"<<pay.costOfStay * reciept.ammount * 7<<endl;
        
        booked.close();
      }
    
    
    
    
}
//creats and shows availabiltiy//
void availability(){
   recieptItems reciept; 
  ifstream couts ("availability.txt");
      string paste;
    while (getline(couts, paste)){
    cout<<paste<<endl;
    
  } 
  couts.close();
}

void availabilityChecker(){
  recieptItems reciept; 
 //openeing the hotels file and adding it to a list
  fstream file;
  file.open("availability.txt", ios::in);
  if (file.is_open()) {
    string RoomsAvailable;
    while (getline(file, RoomsAvailable)) {
      availableRooms.push_back(RoomsAvailable);
    }
    file.close();
  }
 
 
  

   for (string i : availableRooms) {
    //checks if search matches on of the elements in the list
    if (i.compare(reciept.Room )== 0) {
      x = true;
      }
     }
     if (x == true) {
    ifstream Removing("availabiltiy.txt");
       
    ofstream write("tempt.txt"); 
    if (Removing.is_open()) {
       string line;
       while (getline(Removing, line)) {
          if (line.find(reciept.Room) != std::string::npos){
            write << line;
          }
       }
      Removing.close();
    write.close();
      }
    
  }if (x == false) {
    cout<<"please choose a different room.";
    
  }
}


void recieptMaker(){
  recieptItems reciept;
  ofstream Final("reciept.txt");
}



int main(){
    Welcome();
}