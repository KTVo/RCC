#include "Prob5.h"

//Constructor 
//sets the name, job title and hourly rate
Employee::Employee(char name[], char jTitle[], float hrlyRate)
{
    strcpy(MyName, name);
    strcpy(JobTitle, jTitle);
    setHourlyRate(hrlyRate);
    HoursWorked = 0;
    GrossPay = 0.0;
    NetPay = 0.0;
}


//Decides the tax rate based on the gross pay
//I used double becuase the example has a double.
double Employee::Tax(float grossP) //Utility Procedure
{
    if(grossP <= 500){
        return 0.1;
    }
    else if(grossP>500 && grossP<=1000){
        return 0.2;
    }
    else{
        return 0.3;
    }
}

//Set hours worked to private member and input validation check
int Employee::setHoursWorked(int hrWorked){
    //Extra credit, used exceptions
    try{
        if(hrWorked > 0 && hrWorked < 84){
            HoursWorked = hrWorked;
        }    
        else{
            throw 1111;
        }
    }catch (int y){
        cout<<"Error: "<<y<<" Unacceptable Hours Worked\n";
        HoursWorked = 0;
    }
return HoursWorked;}

//Checks for input validation then set the hourly rate to private 
float Employee::setHourlyRate(float hrRate)
{
    try{

        if(hrRate > 0 && hrRate < 200){
            HourlyRate = hrRate;
        }
        else{ throw 9951; }
    }
    catch (int x){
        HourlyRate = 0;
        cout <<"Error: "<<x<<" Unacceptable Hourly Rate\n";
    }


return HourlyRate;}

//Displays the result
void Employee::toString(){
    cout<<"Name = "<<MyName<<" Job Title = "<<JobTitle<<endl;
    cout<<"Hourly Rate = "<<HourlyRate<<" Hours Worked = "<<HoursWorked
        <<" Gross Pay = "<<GrossPay <<" Net Pay = "<<NetPay<<endl;
}

//Sets and return gross pay based on hours worked
float Employee::getGrossPay(float hrRate, int hrWorked){
    GrossPay = 0.0;
    if(hrWorked < 40){
        GrossPay = hrWorked * hrRate;
    }
    else if(hrWorked >= 40 && hrWorked<=50){
        GrossPay = (40*hrRate) + ((hrWorked - 40)*1.5*hrRate);
    }
    else if(hrWorked > 50){
        GrossPay = ((hrWorked-50)*2*hrRate)+(40*hrRate)+
                (1.5*hrRate*(hrWorked-50));
    }
return GrossPay;}

//Returns the net pay = gross pay after deductions
float Employee::getNetPay(float grossPay){
    if (grossPay > 1000){
        NetPay = (grossPay - (grossPay * Tax(grossPay)))+150;
    }
    else if(grossPay <= 1000 && grossPay > 500){
        NetPay = (grossPay - (grossPay * Tax(grossPay)))+50;
    }
    else
    {
        NetPay = grossPay - (grossPay * Tax(grossPay));
    }
return NetPay;}

float Employee::CalculatePay(float x, int y){
    return getNetPay(getGrossPay(setHourlyRate(x),setHoursWorked(y)));
}
