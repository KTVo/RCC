/* 
 * File:   main.cpp
 * Author: Kevin Vo
 * Book: Gaddis 7th Ed.
 * Created on October 2, 2014, 9:24 PM
 * Prob 10.1 -> Count the # of characters in a string w/ pointer
 * Prob 10.2 -> Displays a string backwards with pointer
 * Prob 10.3 -> Counts # of words with pointers
 * Prob 10.4 -> Displays average # of letters *ISSUE:Doesn't display correct avg
 * Prob 10.5 -> Capitalize first letter of a sentence w/ pointer
 * Prob 12.1 -> Shows only the first 10 lines of a .txt
 * Prob 12.2 -> Displays a requested .txt and display 24 lines before pausing
 * Prob 12.3 -> Displays joke.txt then punchline.txt
 * Prob 12.6 -> Searches for string in a .txt
 * Prob 12.11 -> Uses structure to store company data
 */

//Note: There is a problem with Prob. 10.4 where the float does not display
//the correct value for the average.

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cctype>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <map>
#include <sstream>





using namespace std;

//Function prototype for the menu.
void Menu();
int getN();
void def(int);
void problem10_1();
void problem10_2();
void problem10_3();
void problem10_4();
void problem10_5();
void problem12_1();
void problem12_2();
void problem12_3();
int problem12_6();
int problem12_11();

//Prototype prob. 10.1
int stringLengthCounter(char*, int);
//prototype for prob. 10.2
void reverseString(char *);
//prototype for prob. 10.3 & 10.4
int wordCounter(char *);
//Prototype for prob. 10.4
float avgNumLetters(char *, int);
//Prototype for prob. 10.5
void capitalizer(char *);
//Function Prototypes 12.3
void getLineJoke(fstream &);
void getLinePunchLine(fstream &);
//Funct. Prototype for 12.6
bool SearchFileForString( char [], char []);




int main(int argc, char** argv) {
    int inN;
        do{
            Menu();
            inN=getN();
            switch(inN){
                case 1: problem10_1();break;
                case 2: problem10_2();break;
                case 3: problem10_3();break;
                case 4: problem10_4();break;
                case 5: problem10_5();break;
                case 6: problem12_1();break;
                case 7: problem12_2();break;
                case 8: problem12_3();break;
                case 9: problem12_6();break;
                case 10: problem12_11();break;
                default: def(inN);}
            }while(inN<11);
            return 1;
}

void Menu(){
    cout<<endl;
    cout<<"Type 1 for Problem 10.1\n";
    cout<<"Type 2 for Problem 10.2\n";
    cout<<"Type 3 for Problem 10.3\n";
    cout<<"Type 4 for Problem 10.4\n";
    cout<<"Type 5 for Problem 10.5\n";
    cout<<"Type 6 for Problem 12.1\n";
    cout<<"Type 7 for Problem 12.2\n";
    cout<<"Type 8 for Problem 12.3\n";
    cout<<"Type 9 for Problem 12.6\n";
    cout<<"Type 10 for Problem 12.11\n";

}

int getN()
{
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN)
{
   cout<<"You typed "<<inN<<" to exit the program"<<endl;
}


//Starts Problem 10.1
void problem10_1(){
    const int size = 1000;
    char *ptrInput;
    char inputString[size];
    int numChar;
    
    cout<<"Please enter a string of text without spaces and the program will count and "<<
          "return the number of character(s) including punctuations.\n"<<
          "Note: This program will only count up to 1000 characters a session.";
    cin.ignore();
    cout<<"\nUser's Input: ";
    cin.getline(inputString, size);//As for input of string
    
    ptrInput = inputString;//Assigns c-string to pointer

    stringLengthCounter(inputString, size);//calls for funct. that counts char.

    numChar = stringLengthCounter(ptrInput, size);
    
    //Displays # of characters in the string
    if (numChar < 2){
    cout<<numChar<<" character was inputed.\n";
    }
    if (numChar >= 2){
    cout<<numChar<<" characters were inputed.\n"; 
    }
}

//Counts the number of characters in the string
int stringLengthCounter(char *input, int maxSizeOfString){
    int numCharacters = 0;
    for (int countChar = 0; countChar < maxSizeOfString; countChar++){
        if(isalnum(input[numCharacters]) || ispunct(input[numCharacters])){
            numCharacters += 1;
            }
    }
    return numCharacters;}


//Starts Problem 10.2
void problem10_2(){
    const char sizeReverse = 101;
    char inputReverse[sizeReverse];
    char *ptrReverse;

    cout<<"Please enter a string and a reversed format of it will be displayed."
        <<"\nNote: This program will only reverse up to 100 characters."
        <<"\nUser Input: ";
    cin.ignore();
    cin.getline(inputReverse, sizeReverse);//collects
    
    ptrReverse = inputReverse;//assign a pointer to the c-string

    reverseString(ptrReverse);//calls for the funct. that reverses the c-string
}

void reverseString(char *userInput){
    char *ptrInput = userInput;

    //While loop that will keep on going as long as the cstring does has not
    //reach the null character
	while (*ptrInput != '\0'){
		++ptrInput;
                }
        cout<<"Reversed: ";
        //Displays the content backwards as the pointer decreases
	while ( ptrInput != userInput ){

                cout.put ( *--ptrInput );
                }
        cout<<endl;        
}


//Starts problem 10.3
void problem10_3(){
    const int size = 100;
    char inputWord[size];
    char *ptrInput;
    int DisplayNumWords;
    cout<<"Enter in a string so that the number of words can be displayed.\n";
    cout<<"Input: ";
    cin.ignore();
    cin.getline(inputWord, size);
    
    ptrInput = inputWord;//assings c-string to a pointer

    wordCounter(ptrInput);

    DisplayNumWords = wordCounter(ptrInput);
    
    cout<<"Number of Words: "<<DisplayNumWords<<endl;
}

int wordCounter(char *input){
    int numWords = 1;
    
    while(*input != '\0'){
        //Adds 1 to the numWords whenever there's a space
        if(*input == ' '){
            numWords++;
        }
        *input++;
    }
return numWords;}


//Starts Problem 10.4
void problem10_4(){
    const int size = 100;
    char inputWord[size];
    char *ptrInput;
    int DisplayNumWords;
    float DisplayAvgNumLetters;
    cout<<"Enter in a string so that the number of words can be displayed.\n";
    cout<<"Input: ";
    cin.ignore();
    cin.getline(inputWord, size);
    
    ptrInput = inputWord;//Assigns c-string to a pointer

    wordCounter(ptrInput);//calls funct. that counts the num. of words

    DisplayNumWords = wordCounter(ptrInput);//assigns float funct. to variable
    
    cout<<"Number of Words: "<<DisplayNumWords<<endl;//Display # of words
    

    avgNumLetters(ptrInput, DisplayNumWords);

   
    DisplayAvgNumLetters = avgNumLetters(ptrInput, DisplayNumWords);
    //cout the avg. # of letters 
    cout<<"Average Number of Letters: "<<DisplayAvgNumLetters<<endl;

}

//Calculates the average # of letters *ERROR HERE* incorrect display of avg.
float avgNumLetters(char *input, int numWords){
    float avgNumLetters;
    int numLetters = 0;
    while(*input != '\0'){
        if (isalpha(*input)){
            numLetters++;
        }
        *input++;
    }
    avgNumLetters = (numLetters/numWords);
return avgNumLetters;}

void problem10_5(){
    const int size = 1000;
    char *inputSent;
    inputSent = new char[size];

    cout<<"This program will capitalize every letter at the beginning of the "
        <<"sentence.\nPlease type in your sentences then hit the Enter key.\n";
        cin.ignore();
        cin.getline(inputSent, size);
 
        cout<<endl;

        capitalizer(inputSent);
}

//changes all first letter of a sentence to uppercase
void capitalizer(char* inputSent)
{
    int space = 0, punctuation = 0;//set value to space and punct. for string
 
    *inputSent = toupper(*inputSent);//toupper changes *inputSent to uppercase
 
    cout << *inputSent;//displays the pointer
 
    for (int count = 1; count < strlen(inputSent); ++count){
        if (space >= 1 && punctuation >= 1 && *(inputSent + count) != ' '){
            *inputSent = toupper(*(inputSent + count));
            cout << *inputSent;
            punctuation = 0;
            space = 0;
            }
            else
            {
                cout << (*(inputSent + count));
 
                if (punctuation == 1){
                    if (*(inputSent + count) == ' '){
                            space++;
                    }
                    else
                    {
                    space = 0;
                    }
                }
                    else
                    {
                    if (*(inputSent + count) == '.' || *(inputSent + count) ==
                     '?' || *(inputSent + count) == '!'){
                        punctuation++;
                    }
                    else
                    {
                    punctuation = 0;
                    }
                    }
                }
        }
}


//Starts prob. 12.1
void problem12_1(){
    string fileName;
    const int size = 400;
    char word[400];
    //prompts user about program and requests filename
    cout<<"This program will request you to type in a file's name so that it "
        <<"displays the first 10 lines in that file.\n\nNote: Enter 'sample.txt'"
        <<" (has less than 10 lines) or 'example.txt' (has more than 10 lines)" 
        <<"without the apostrophe below to continue.";

    cout<<"\n\nPlease enter the filename: ";       
    cin.ignore();                       
    getline(cin, fileName);    //collects cstring

    ifstream file(fileName.c_str(), ios::in);//opens the file to read
    
    cout<<endl;
        //if file cannot be opened, it displays this
	if (!file.is_open())
	{
		cout<<"File "<<fileName<<" opened unsuccessfully."<<endl;
	}
	
	//if file is opened it will display the first 10 lines
	int counter = 0;
	while (counter < 10 && file.good() ) 
	{
		file.getline(word, 400);
		counter++;
		cout<<word<<endl;
	}

	// if fewer than 10 lines the program show this
	if (counter < 10) 
	{
		cout<<"\nThe entire file has been displayed.\n";
	}
}


//Starts Prob. 12.2
void problem12_2(){
    string line;//will holds each line from the .txt  
    cout<<"Please enter 'example.txt' below without the apostrophe.\n";
    cout << "Enter the filename: "; //display instruction to user
    string fileName;//holds the file name
    cin.ignore();
    getline(cin, fileName);//requests user for file name

    ifstream file(fileName.c_str(), ios::in);//opens the file with inputted name

     // Loop through entire file and print each line to the screen
     for (int count = 1; !file.eof(); ++count) {
          getline(file, line);//get the next line in the file

          cout<<line<<endl;// display the line to the screen
          if (count % 24 == 0) system("Pause");//pauses for every 24 lines
     }
}

//Starts Problem 12.3
void problem12_3(){
    fstream jokeFile, punchLineFile;	

    jokeFile.open("joke.txt", ios::in );//opens joke.txt to read

    //if joke.txt cannot be open, it displays this
    if (jokeFile.fail()){
        cout << "--- File to open file joke.txt ---\n"; }

    getLineJoke(jokeFile);//calls upon funct. to display content
    jokeFile.close();//closes joke.txt

    //Asks user to hit enter to continue
    cout << "Press the Enter key to continue...";
        cin.ignore();
    cin.get();

    cout<<endl;
    
    //opens punchline.txt to read
    punchLineFile.open("punchline.txt", ios::in);

    //if punchline.txt cannot be open, it displays this
    if (punchLineFile.fail()){ 
        cout << "--- File to open file punchline.txt ---\n"; 
    }
        
	getLinePunchLine(punchLineFile);//calls upon funct. to display content
	punchLineFile.close(); //closes punchline	
}

//Displays content on joke.txt
void getLineJoke(fstream &file)
{
	char character;
	
	file.get(character);
	while (!file.fail()){
            cout<<character; 
            file.get(character); 
        }
	cout<<endl;	
}

//Displays content on punchline.txt
void getLinePunchLine(fstream &file)
{
    const int size = 81;
    char input[size];

    file.getline(input, size, '\n');
    while(!file.eof()){
	file.getline(input, size, '\n');
    }
    cout<<input<<endl;	
}


//Starts Problem 12.6
int problem12_6(){

	const int SIZE = 200;// constant for size of character string
	char fileName[SIZE];// to hold the file name
	ifstream inputFile;// input file
	int counter = 0;// counter for the number of strings




	//Requests for the file's name
	cout<<"\n\nNOTE -> Enter: 'example.txt' for filename and 'Aircraft' "
            <<"for search word without the apostrophe to test.\n"
            <<"\n\nEnter the filename that is wished to be searched: ";

	cin>>fileName;	

	// Open user's file.
	inputFile.open(fileName);
	if(!fileName)
	{
		cout<<endl;
		cout<<"Cannot open file." <<fileName<<endl;
		return 0;
	}




	//Reads the file then search for the string 
	multimap<string, int> words;
	map<int, string> lines;
	string strng;
	ifstream input(fileName);
	if(input.fail())//If fileName cannot be it this displays
	{
		cout<<"\nThe file could not be opened.";
		return -1;
	}
	int i=1;
	while(getline(input,strng))
	{
		istringstream in(strng);
		string s;
		while(in>>s)
		{
			words.insert(make_pair(s,i));
		}
		lines.insert(make_pair(i,strng));
		i++;
	}
	string search;
	cout << "\nWhat word would you like to search for?: ";
	cin >> search;//Stores the string that is to be searched for

        //Displays the # of matches (borrowed)
	cout << "\n  Total number of matches = " << words.count(search) << '\n';
	multimap < string,int>::iterator it1=words.lower_bound(search);
	multimap < string,int>::iterator it2=words.upper_bound(search);
	while(it1 != it2)
	{
		int x=it1->second;
		map<int,string>::iterator iter = lines.find(x);
		cout << '\n' << x << " ) " << iter->second << '\n';
		it1++;
		while(true)
		{
			if(it1 != it2 && it1->second == x)
			{
				it1++;

			}
			else
			{
				break;
			}
		}
	}

return 0;}



//Prob. 12.11
//Stores Division name, quarter, quarterly sales and display total
struct SaleInfo {
    float Quarter[4], total = 0.0, average =0.0;
    string Division;
    
	SaleInfo(string st) 
	{
        Division = st;
    }
    
	int setQ(int qtr, float f) 
	{
            if (f > 0) 
			{
                Quarter[qtr] = f;
                return 1;
            }
        return 0;
    }

        //Display all Annual Total and Avg
	void getQ(int qtr) 
	{
		float total=0.0;

		for(int m = 0; m < 4; m++)
		{
			total = total + Quarter[m];
			average = total / 4;
		}
		cout<<"Annual Total: $"<<setprecision(2)<<fixed<<total<<endl;
		cout<<"Annual Average: $"<<setprecision(2)<<fixed<<average<<endl;
        }
        
};

int problem12_11(){
    SaleInfo **Datapoint;
    Datapoint = new SaleInfo *[4];
    float numInput;
    //string sorting all division for display
	string divisionName[4] = {"North","South","East","West"};

    for (int i = 0; i < 4; i++) 
	{
        cout << endl;
       
		Datapoint[i] = new SaleInfo(divisionName[i]);
        
		for (int q = 0; q < 4; q++) 
		{
            do//Asks for quarter sales of each division
			{
                cout << "Division: "<< Datapoint[i]->Division << endl 
                     << "Enter sales for Quarter: "<< q+1 << ": ";
                cin >> numInput;
                //If a neg. # is inputted this display and program ends
                if (numInput < 0){
                    cout<<"Input Validation: Do not accept negative numbers "<<
                            "for any sales figures.\n";
                return 0;}
            } while (!Datapoint[i]->setQ(q,numInput));
        }  
    }cout << endl;

	for (int count = 0; count < 4; count++)
	{
		cout<<Datapoint[count]->Division << endl;
		Datapoint[count]->getQ(count);
	}


	cout << endl;
return 0;}