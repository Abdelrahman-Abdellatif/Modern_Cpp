#include <iostream>
#include <vector>
#include <limits>
// this way is safer in large projects other than using namespace std;
using std::cout;
using std::cin;
using std::endl;



class Account{

    private:
        int balance;
        int counter =0;
    public:
    // solve the problem of: How do you make sure the balance starts at exactly 0 , 'explicit' prevents accidental conversions
    explicit Account (int start =0) : balance(start), counter(0){}

    void deposit(int amount) {
        if (amount <= 0) {
                cout << "Error: Deposit must be positive.\n";
                return;
            }
            balance += amount;
            counter++;
        }

        void withdraw(int amount) {
            // Check for negative withdrawals AND insufficient funds
            if (amount <= 0) {
                cout << "Error: Withdrawal must be positive.\n";
                return;
            }
            if (amount > balance) {
                cout << "Error: Insufficient funds.\n";
                return;
            }
            balance -= amount;
            counter++;
        }    
    int getBalance() const {return balance;}
    int getCounter() const {return counter;}


};

int main(){
    // entering the initial balance
    int initialBalance; 
    cout << "Please enter the balance: ";
    
    // better way to take input from user so we dont run into a cin infinate errors
    while(!(cin >> initialBalance )){
        cout << "Invalid input, please enter an integer" << endl;
        cin.clear(); //  Clear the error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // if we used "" it will give us error, that we need to enter a constant char. so we must use '' that measn constant char
        ///  Throw away the "bad" characters in the buffer
    } 
    
    Account myAcc(initialBalance);

    // asking for how many operation user need to make
    int opCount;
    cout << "Please specifiy how many operations you need: "; 
    while(!(cin >> opCount)){
        cout << "Invalid input, please enter an integer" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        //This tells C++ to ignore everything until the next line, no matter how long it is.

    }
    
    while (myAcc.getCounter() < opCount)
    {
        
            int choice;
            cout << "please choose operation option: 1 --> deposit , 2 --> withdraw , 3 --> Current balance " <<endl; 
            
            while((!(cin >> choice)) || choice > 3 || choice < 1 ){
                cout << "Invalid input, please entre 1 or 2 or 3" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            
            if (choice ==1){
                int dep;
                cout << "How much you need to deposit?: "; cin >> dep;
                myAcc.deposit(dep);
            }
            else if (choice == 2)
            {
                int wid;
                cout << "How much you want to withdraw?: "; cin >> wid;
                myAcc.withdraw(wid);
            }
            else if (choice ==3)
            {
                cout << "Current Balance is: " << myAcc.getBalance() << endl;
            }          
        
    }
    cout << "Final amout:  " <<  myAcc.getBalance()<< endl;
    
    return 0;
}