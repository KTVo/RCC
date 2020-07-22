/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Book: Gaddis 7th Edition
 * Chapter 11
 * Prob 11.1 -> Uses structures to store & display data on movies
 * Prob 11.2 -> Modded version of prob 11.1 that displays 1st year profit/lost
 * Prob 11.3 -> Uses structures to store & display corp. data
 * Prob 11.4 -> Uses structure to store weather data
 * Prob 11.6 -> *ERROR: table doesn't display correctly* Stores & display soccer player's stats !ERROR: table doesn't display correctly*
 * Prob 11.7 -> Uses structure to store customer's data
 * Prob 11.9 -> Keeps track of a speakers' burea
 * Created on October 19, 2014, 4:43 PM
 */


#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void Menu();
int getN();
void def(int);
void problem1();
void problem2();
int problem3();
void problem4();
int problem5();
void problem6();
void problem7();

//Struct for 11.1 & 11.2
//Struct of the movie's data
struct MovieData{
    string movieTitle; //stores the name of the movie
    string movieDirector; //stores string of director's name
    int yearReleased; //stores value of the year
    int runningTime; //stores the running time
    int firstYrProfit; //stores the first year profit of movie
};

//Prototype for 11.1
void assignData(MovieData *object,string title, string director, int year, int running);
void displayData(MovieData *object);

//Prototype for 11.2
void assignData2(MovieData *object,string title, string director, int year, int running, int firstYr);
void displayData2(MovieData *object);

//Struct for 11.3
//Structure -> Cal. and display ann. total and average
struct CorpData{
    float Quarter[4], total, avg;
    string Division;
    
	CorpData(string st){
        Division = st;
        }

	int setQ(int qtr, float f) {
            if (f > 0) 
			{
                Quarter[qtr] = f;
                return 1;
            }
        return 0;}

	void getQ(int qtr){
		float total=0.0;

		for(int m = 0; m < 4; m++)
		{
			total = total + Quarter[m];
			avg = total / 4;
		}
		cout<<"Annual Total: $"<<setprecision(2)<<fixed<<total<<endl;
		cout<<"Annual Average: $"<<setprecision(2)<<fixed<<avg<<endl;
        }
        
};

int main(int argv,char *argc[]){
	int inN;
        do{
         Menu();
         inN=getN();
         switch(inN){
          case 1:    problem1();break;
          case 2:    problem2();break;
          case 3:    problem3();break;
          case 4:    problem4();break;
          case 5:    problem5();break;
          case 6:    problem6();break;
          case 7:    problem7();break;
          default:   def(inN);}
        }while(inN<8);
        return 1;
    }
    void Menu()
    {
           cout<<"\nType 1 for problem 11.1"<<endl;
           cout<<"Type 2 for problem 11.2"<<endl;
           cout<<"Type 3 for problem 11.3"<<endl;
           cout<<"Type 4 for problem 11.4"<<endl;
           cout<<"Type 5 for problem 11.6"<<endl;
           cout<<"Type 6 for problem 11.7"<<endl;
           cout<<"Type 7 for problem 11.9"<<endl;
           cout<<"Type 8 to exit \n"<<endl;
    }
    int getN()
    {
           int inN;
           cin>>inN;
           return inN;
    }

//----Problem# 11.1---- 
void problem1(){
MovieData first, second;
    //Stores the data that will be displayed.
    assignData(&first,"The Mummy", "Stephen Sommers", 1999, 125);	
    assignData(&second,"Splash", "Ron Howard", 1984, 111);

    //Calls for function to display data
    cout<<"\nFirst Movie:";
    cout<<"\n--------------------\n";
    displayData(&first);
    cout<<endl;

    cout<<"\nSecond Movie:";
    cout<<"\n--------------------\n";
    displayData(&second);
    cout<<endl;
}


//Assign data to object for display
void assignData(MovieData *object,string title, string director, int year, int running){
    object->movieTitle=title;
    object->movieDirector=director;
    object->yearReleased=year;
    ((*object).runningTime)=running;    
}

//Displays data of both movies
void displayData(MovieData *object){
    cout<<"Title: "<<object->movieTitle<<endl;	
    cout<<"Director: "<<object->movieDirector<<endl;	
    cout<<"Year Released: "<<object->yearReleased<<endl;	
    cout<<"Running Time (in minutes): "<< object->runningTime<<endl;
}


//----Problem# 11.2---- 
void problem2(){
    MovieData first, second;
    //Stores the data that will be displayed.
    assignData2(&first,"The Mummy", "Stephen Sommers", 1999, 125, 415933406);	
    assignData2(&second,"Splash", "Ron Howard", 1984, 111, 69821334);

    //Calls for function to display data
    cout<<"\nFirst Movie:";
    cout<<"\n--------------------\n";
    displayData2(&first);
    cout<<endl;

    cout<<"\nSecond Movie:";
    cout<<"\n--------------------\n";
    displayData2(&second);
    cout<<endl;
}

//Assign data to object for display
void assignData2(MovieData *object,string title, string director, int year, int running, int firstYr){
    object->movieTitle=title;
    object->movieDirector=director;
    object->yearReleased=year;
    ((*object).runningTime)=running;
    object->firstYrProfit=firstYr;
}

//Displays data of both movies
void displayData2(MovieData *object){
    cout<<"Title: "<<object->movieTitle<<endl;	
    cout<<"Director: "<<object->movieDirector<<endl;	
    cout<<"Year Released: "<<object->yearReleased<<endl;	
    cout<<"Running Time (in minutes): "<<object->runningTime<<endl;
    cout<<"First Year's Profit: $"<<object->firstYrProfit<<endl;
}



//Problem 11.3
int problem3(){
    CorpData **Datapoint;
    Datapoint = new CorpData *[4];
    float num;
    string Division_name[4] = {"North","South","East","West"};

    cout<<"This program will store data of a company's division.\n";

    for (int i = 0; i < 4; i++){
        cout<<endl;
		Datapoint[i] = new CorpData(Division_name[i]);
		for (int q = 0; q < 4; q++){
            do{
                cout<<"Division: "<< Datapoint[i]->Division <<endl
                    <<"Enter sales for quarter "<< q+1 << ": ";
                cin >> num;
                
                if (num<0){
                    cout<<"Input Validation: Do not accept negative numbers for any sales figures.";
                    return 0;
                }
            } while (!Datapoint[i]->setQ(q,num));
        }  
    }
    cout<<endl;
	for (int count = 0; count<4; count++){
		cout<<Datapoint[count]->Division << endl;
		Datapoint[count]->getQ(count);
	}
	cout<<endl;
        delete[] Datapoint;
}

//const int for problem 11.4
const int months = 12;
//stores months of the year
const char nameMonths[months][10] = { "January", "February", "March", "April", "May",
"June", "July", "August", "September", "October",
"November", "December" } ; //months of the year

//Prototype 11.4
struct Weather{
    float rainfall;//stores the rainfall
    float highestTemp;//stores the highest temperature
    float lowestTemp;//stores the lowest temperature
    float avgTemp; //stores the average temperature
};
 
//Prototypes 11.4
void findAVG(Weather [], int);
float arrayOfAvg(Weather [], char[]);
void temperatureFinder(Weather[], int&, int&);
void calculateInfo(Weather []);
void displayResults(Weather[]);

void problem4(){
    Weather array[months];
    calculateInfo(array); //stores and shows the data to the user 
    displayResults(array);//Displays results
}

 
//Find avg temp
void findAVG(Weather array[], int i){
    array[i].avgTemp = (array[i].highestTemp + array[i].lowestTemp) / 2;
}
 
//Finds avg of weather
float arrayOfAvg(Weather array [], char choice[]){
    float average = 0; //stores the average
 
    if(choice == "temp"){
        for (int i = 0; i < months; i++)
        average += array[i].avgTemp;
    //finds the average
    return (average / months);
}
 
    if(choice == "rain"){
        //Adds up array
        for(int i = 0; i < months; i++)
        average += array[i].rainfall;
        return (average/months);}
}
 
    //Finds lowest and highest temp
    void temperatureFinder(Weather array [], int & tempHighest, int & tempLowest){
    float min = array[0].lowestTemp, max = array[0].highestTemp;
    
    tempLowest = 0;
    tempHighest = 0;
    //find max. and min. temp
    for(int i = 1; i < months; i++){
        //changes the min to a smaller value and updates the position
        if(min > array[i].lowestTemp){
        min = array[i].lowestTemp;
        tempLowest = i;
        }

        //updates highest value for temp
        if(max < array[i].highestTemp){
            max = array[i].highestTemp;
            tempHighest= i;
        }
    }
}
 
//Displays prompt and askes for highest and lowest temperature of each month
void calculateInfo(Weather array[]){
    cout<<"This progam will calculate the average rainfall and temperature.\n"
        <<"Please enter the data for each month.\n\n";
 
    //loops user input
    for(int i = 0; i < months; i++){
        cout<<"Data for month "<<nameMonths[i]<<":"<<endl;
        cout<<"Enter Total Rainfall: ";
        cin>>array[i].rainfall;
        cout<<"Highest Temperature: ";
        cin>>array[i].highestTemp;

        //Checks input and/or asks for re-input
        while((array[i].highestTemp < -100) or (array[i].highestTemp > 140)){
            cout<<"\nInput Validation: Only accept temperatures within the range " 
                <<"between 100 and +140 degrees Fahrenheit.\n";
 
            cout<<"Highest Temperature: ";
            cin>>array[i].highestTemp;
        }

        cout<<"Lowest Temperature: ";
        cin>>array[i].lowestTemp;
 
        //Validates input and has user re-input
        while((array[i].lowestTemp < -100) || (array[i].lowestTemp > 140)
        || (array[i].lowestTemp > array[i].highestTemp)){
        cout<<"\nInput Validation: Only accept temperatures within the range between "
            <<"100 and +140 degrees Fahrenheit or\nthe lowest temp > highest temp.\n";

            cout<<"Lowest temperature: ";
            cin>>array[i].lowestTemp;
        }
        //Find the average temperature
        findAVG(array, i);
        cout<<endl;
    }
}
 
//Function displaying the results
void displayResults(Weather array[]){
    int tempHighest, tempLowest;
    //Gets for lowest & highest temp.
    temperatureFinder(array, tempHighest, tempLowest);
 
    //Displayed results
    cout<<"\n---Results---\n";
    cout<<"Average rainfall: "<<arrayOfAvg(array, "rain")<<endl
        <<"Highest Temperature: "<<array[tempHighest].highestTemp
        <<" ("<<nameMonths[tempHighest]<<")\n"<<"Lowest Temperature: " 
        <<array[tempLowest].lowestTemp<<" ("<<nameMonths[tempLowest]<<")\n"
        <<"Average Temperature: "<<arrayOfAvg(array, "temp")<<endl;
}

//Problem 11.6
struct Player {
    char name[16];
    int jersey;
    int score;
};
//Prototype 11.6
void displayPlayer( Player* );

int problem5()
    {
    struct Player playerList[13];

    cout<<"Program will ask you to input the 12 players' name, jersey#, & score"
        <<" to find and display the MVP along with a table.\n\n";

    for(int i = 0; i < 13; i++){
        cout<<"Player "<<i+1<<" Name: ";
        cin.ignore();
        cin.getline(playerList[i].name, 16);

        cout<<"Jersey Number: ";
        cin>>playerList[i].jersey;
    
        while(playerList[i].jersey < 0){
        cout<<"Input Validation: Do not accept negative values for players "
            <<"numbers or points scored.";
    
        cout<<"Jersey Number: ";
        cin>>playerList[i].jersey;
        }

        cout<<"Players Score: ";
        cin>>playerList[i].score;

        while(playerList[i].score < 0){
            cout<<"Input Validation: Do not accept negative values for players "
                <<"numbers or points scored.";
            cout<<"Player's Score: ";
            cin>>playerList[i].score;
        }
        
       cout<<endl;
    }

    cout<<"Player Name ";
    cout<<"Jersey Number ";
    cout<<"Player Score";
    cout<<"----------------------------------------";
    cout<<endl;

    for(int i = 0; i < 13; i++){
        displayPlayer(playerList);
    }

    int total = 0;

    for(int i = 0; i < 13; i++){
        total += playerList[i].score;
    }

    cout<<"Team's Total Points: "<<total<<endl;

return 0;}

//Can't get this to display correctly
void displayPlayer( Player* list){
    for(int count = 0; count < 13; count++){
        cout<<setw(15)<<list[count].name;
        cout<<setw(12)<<list[count].jersey;
        cout<<setw(15)<<list[count].score;
    }
}

//Problem 11.7*****
//Struct 11.7
struct customer{ 
	string name, address, city, state, zip, telephone, date;
	int balance;
};
//Prototype 11.7
void editCustomer(customer&); //Edits customers' data to be stored
void DisplayCustomer(customer); //Displays the customers' data



    void problem6()
    {
	int numCust, input = 1;

	cout<<"This program will store and display customers' information.\n\n"
            <<"How many customers?: ";

	cin>>numCust;
	customer*database=new customer[numCust];

	while(input!=3){//selection menu
		cout<<"-------Menu-------\n"; 
                cout<<"Type 1 to input customer(s) information\n";
                cout<<"Type 2 to display customer(s) information\n";
                cout<<"Type 3 to exit\n";
                cout<<"User Input: ";
		cin>>input;
		cout<<endl;
		switch(input){
			case 1:{//edit customer info
				int cnum;
				cout<<"customers:\n";
				for(int x=0; x < numCust; x++)
					cout<<x+1<<" : "<<database[x].name<<endl;
				cout<<"\nEnter the customer # to edit info: ";
				cin>>cnum;
				if(cnum<=numCust && cnum>0)
					editCustomer(database[cnum-1]);
				else
					cout<<"\ninvalid customer number!\n\n";
				 }
			break;
			case 2:{//displays customers' info
				int cnum;
				cout<<"customers:\n";
				for(int x=0;x<numCust;x++)
					cout<<x+1<<" : "<<database[x].name<<endl;
				cout<<"\nEnter the customer # to display info: ";
				cin>>cnum;
				if(cnum<=numCust && cnum>0)
					DisplayCustomer(database[cnum-1]);
				else
					cout<<"\nInput Validation: When the data for a new account is entered, be sure the user enters"
                                            <<" data for all the elds. No negative account balances should be entered.\n";
				   }
			break;
			default: break;
		}
	}
	delete[] database;
    }

//edits customer's data
void editCustomer(customer&set){
	cout<<"Enter Customer's Info\n";
        cout<<"Name: ";
	cin>>set.name;
	cout<<"Address: ";
	cin.ignore(256,'\n');
	getline(cin, set.address);
	cout<<"City: ";
	cin>>set.city;
	cout<<"State: ";
	cin>>set.state;
	cout<<"Zip Code: ";
	cin>>set.zip;
	cout<<"Telephone Number: ";
	cin>>set.telephone;
	cout<<"Date of Last Payment: ";
	cin>>set.date;
	do{
		cout<<"Account Balance: ";
		cin>>set.balance;
		if(set.balance<0)
			cout<<"Input Validation: When the data for a new account is entered, be sure the user enters"
                            <<" data for all the elds. No negative account balances should be entered.\n";
	}while(set.balance<0);
}

//shows customers data
void DisplayCustomer(customer get)
{
	cout<<"\n --- Data for "<<get.name<<" ---\n";
	cout<<"\nAddress: "<<get.address<<", "<<get.city<<", "<<get.state<<", "<<get.zip;
	cout<<"\nTelephone: "<<get.telephone;
	cout<<"\nLast Payment: "<<get.date;
	cout<<"\nAccount balance: "<<get.balance<<endl<<endl;
}

//***Problem 11.9***
// Structure lists
    struct speakerInfo
    {
           string name;
           string phone;    //Japanese for phone
           string topic;  
           int feeReq;
           };

//Function prototypes
void inputSpeaker(speakerInfo *);
void displaySpeaker(speakerInfo *);
void editSpeaker(speakerInfo *);

    void problem7()
    {
        int NUM_SPEAKERS = 10; //The number of speakers
        int index;             //Loop counter...        
        speakerInfo infos[10];    //Array to hold the stats for each speaker...
        
        //Choice for menu
        int submenu;
        const int enter = 1,
                  change = 2,
                  print = 3,
                  leave = 4;
    
        //Displays menu
        do{
        cout << "1) Enter 1 for speaker's information.\n"
             << "2) Enter 2 to change speaker's information.\n"
             << "3) Enter 3 to print speaker information.\n"
             << "4) Enter 4 to exit.\n"
             << "Selection: ";
        cin >> submenu;
        
        switch (submenu){
               case enter:{
                    //stores speaker information
                    inputSpeaker(infos);
                    }
                    break;
               case change:{
                    //edit speaker information
                    editSpeaker(infos);
                    }
                    break;
               case print:{
                    //display speaker information
                    displaySpeaker(infos);
                    }
                    break;
                    }}
                    while (submenu != leave);
    }

void inputSpeaker(speakerInfo *array){                 
     int index=0;
     int size=10;

     for (index=0; index < size; index++){
     cout <<"\nSpeaker #"<<index+1<< ": \n";
     cout<<"-----------------------------------------\n";
     cout <<"Name: ";
     cin.ignore();
     getline (cin, array[index].name);
     cout<<"\nTelephone Number: ";
     getline (cin, array[index].phone);
     cout<<"\nTopic: ";
     getline (cin, array[index].topic);
     cout<<"\nFee Required: ";
     cin>>array[index].feeReq;
     }
}

//Displays the speakers info
void displaySpeaker(speakerInfo *p){
     int index=0;
     int size=10;

     for (index=0; index < size; index++){
     cout<<"The information entered for each speaker is: \n";
     cout<<"Seaker #"<<index<<endl;
     cout<<"Name: "<<p[index].name<<endl;
     cout<<"Telephone Number: "<<p[index].phone<<endl;
     cout<<"Topic: "<<p[index].topic<<endl;
     cout<<"Fee Required: "<<p[index].feeReq<<endl<<endl;
     }
}

//edits speaker's info
void editSpeaker(speakerInfo *p){
     int i;
     cout<<"Please enter the number speaker(s) that you'd like to be to edit.\n";
     cout<<"User Input: ";
     cin>>i;
     if (i <=9)
          {
     cout << endl;
     cout <<"Please enter the updated information of the speaker: \n";
     cout <<"Name: ";
     cin.ignore();  //To skip remaining '\n' character
     getline (cin, p[i].name);
     cout<<"\nTelephone Number: ";
     getline (cin, p[i].phone);
     cout<<"\nTopic: ";
     getline (cin, p[i].topic);
     cout<<"\nFee Required: ";
     cin>>p[i].feeReq;}

     else
     {
         cout<<"Input Validation: When the data for a new speaker is entered, be sure the user enters"
             <<" data for all the elds. No negative amounts should be entered for a speaker s fee.\n";
     }
}

    void def(int inN)
    {
           cout<<"You typed "<<inN<<" to exit the program"<<endl;
    }