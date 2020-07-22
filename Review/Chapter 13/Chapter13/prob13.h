/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   prob13.h
 * Author: dangerouspirate
 *
 * Created on June 17, 2018, 1:43 PM
 */

#ifndef PROB13_H
#define PROB13_H

class Mortgage{
    private:
        double payment;
        double loan;
        double rate;
        int years;

    public:
        void calPayment();
        void setLoan(double);
        void setRate(double);
        void setYear(int);

        double getMonthlyPay() const { return payment; }
        double getPayAmount() const { return payment * years; }
};


#endif /* PROB13_H */

