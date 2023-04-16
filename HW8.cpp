#include<iostream>
#include<string.h>

using namespace std;
static int saCount = 0; // Global static Integer to count Transactions in the Savings Account
class Account
{
    protected:
        string firstName, lastName;
        double currentBalance;
    public:
        Account(string firstName, string lastName, double currentBalance)
        {
            this->firstName = firstName;
            this->lastName = lastName;
            this->currentBalance = currentBalance;
        }

        virtual string getAccType() const
        {
            return "Account";
        }

        virtual double debitTransaction(double debitamount)
        {
             currentBalance -= debitamount;
             return currentBalance;
        }

        virtual double creditTransaction(double creditamount)
        {
             currentBalance += creditamount;
             return currentBalance;
        }

        void print()
        {
            cout << firstName << " " << lastName << "\t" << getAccType() << "\t \t" << currentBalance << endl;
        }
};

class CheckingAccount : public Account
{
    public:
        CheckingAccount(string firstName, string lastName, double currentBalance) : Account(firstName, lastName, currentBalance) { };

        virtual string getAccType() const
        {
            return "CheckingAccount";
        }

        virtual double debitTransaction(double debitamount)
        {
            if(currentBalance < 100)
            {
                chargeFee();
            }
            Account::debitTransaction(debitamount);
            return currentBalance;
        }

         virtual double creditTransaction(double creditamount)
        {
            Account::creditTransaction(creditamount);
            if(currentBalance < 100)
            {
                chargeFee();
            }
            return currentBalance;
        }

        private:
            void chargeFee()
            {
                currentBalance = currentBalance - 10;
            }
};

class SavingsAccount : public Account
{
    public:
    SavingsAccount(string firstName, string lastName, double currentBalance) : Account(firstName, lastName, currentBalance) { };

    virtual string getAccType() const
    {
        return "SavingsAccount";
    }

    virtual double debitTransaction(double debitamount)
        {
            if(saCount < 2 )
            {
                Account::debitTransaction(debitamount);
                payIntrest();
                saCount++;
            }
            else
            {
                return EXIT_FAILURE;
            }
            return currentBalance;
        }

        virtual double creditTransaction(double creditamount)
        {
            if(saCount < 2 )
            {
                Account::creditTransaction(creditamount);
                payIntrest();
                saCount++;
            }
            else
            {
                return EXIT_FAILURE;
            }
            return currentBalance;
        }

    void payIntrest()
    {
         currentBalance = currentBalance + (currentBalance * 0.02); 
    }
};

int main()
{
    Account* ac1 = new SavingsAccount("Hunain", "Shahid", 1000.0);
    Account* ac2 = new CheckingAccount("Saud", "Yaseen", 200.0);

    cout << endl << "*** Two accounts ***" << endl;
    ac1->print();
    ac2->print();
    cout << endl;

    ac1->debitTransaction(150.00);
    ac1->print();
    ac1->creditTransaction(200.00);
    ac1->print();
    ac1->debitTransaction(5.00);
    ac1->print();
    cout << endl;
    cout << "Final Information" << endl;
    ac1->print();
    cout << endl;

    ac2->debitTransaction(150.00);
    ac2->print();
    ac2->debitTransaction(5.00);
    ac2->print();
    ac2->creditTransaction(200.00);
    ac2->print();
    cout << endl;
    cout << "Final Information" << endl;
    ac2->print();
    cout << endl;

    return EXIT_SUCCESS;
}