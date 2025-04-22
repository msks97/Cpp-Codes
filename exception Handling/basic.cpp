#include <iostream>
using namespace std;

/*class exception2
{
    protected:
        string msg;

    public:
        exception2(string msg)
        {
            this->msg = msg;
        }

        string what()
        {
            return msg;
        }
};

class runtime_error2 : public exception2
{
    public:
    runtime_error2(const string &msg): exception2(msg);

};*/

class invalidAmountError : public runtime_error
{
    public:
        invalidAmountError(const string &msg) : runtime_error(msg)
        {};
};

class insufficientBalanceError : public runtime_error
{
    public:
        insufficientBalanceError(const string &msg) : runtime_error(msg)
        {};
};

class Customer
{
    string name;
    int balance, account_number;

    public:
        Customer(string name, int balance, int account_number)
        {
            this->name =name;
            this->balance = balance;
            this->account_number = account_number;
        }

        //other way of writing
        void deposit(int amount)
        {
            if(amount <=0)
            throw invalidAmountError("Amount should be greater than 0");

            balance+=amount;
            cout<<amount<<" is credited successfully"<<endl;
         
        }
        
        /*void deposit(int amount)
        {
            if(amount >0)
            {
                balance+=amount;
                cout<<amount<<" is credited successfully"<<endl;
            }
            else
            {
                throw "Amount should be greater than 0";
            }

        }*/

        void withdraw(int amount)
        {
            if(amount >0 && amount <= balance)
            {
                balance-=amount;
                cout<<amount<<" is debited successfully"<<endl;
            }
            else if(amount<0)
            {
                throw invalidAmountError("Amount should be greater than 0");
            }
            else
            {
                throw insufficientBalanceError("Low balance");
            }
        }

};

int main()
{
    Customer c1("shaswat", 5000, 10);

    try
    {
        c1.deposit(100);
        c1.withdraw(6000);
        c1.deposit(200); // if exception in withdraw ths line will now run as it will move to catch block
    }
    catch(const invalidAmountError &e)
    {
        cout<<"Exception runtime occured :"<<e.what()<<endl;
    }
    catch(const insufficientBalanceError &e)
    {
        cout<<"Exception occured :"<<e.what()<<endl;;
    }
    catch(...)
    {
        cout<<"Exception occured"<<endl;;
    }
    
}