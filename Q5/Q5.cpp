#include <iostream>
#include <string>
#include <array> 
#include <limits>
#include <vector>

using std::cout ;
using std::cin ;
using std::endl;
using std::string;
using std::vector;




class User {

    private:

        // define the static varibale
        static int nextId ;
        string name = "";
        int id;
        
        public:
           User() : id(0), name("Unknown") {}   
           
           void setup(string n){
                name = n;
                id = nextId ++ ; 
                // note here we assigned first and then we increament
           }

           void print() const {
                cout << "Name: " << name << " | ID : " << id <<endl;
           }

};

// WE HAVE TO INITIALIZE THE STATIC VARIABLE OUTSIDE THE CLASS

int User::nextId = 1000;



int main(){

    int n;
    string Name;
    int count = 0;

    // Take from user how many user he needs to create
    cout << "please entre how many users? " << endl;
    while(!(cin >> n) || n < 0 ){
        cout << "Invalid input, please integer number higher than [0] " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // now we need to make an array [we use vector becouse it is a size changable array] of objects user, and assign the array size to n
    vector <User> myUsers(n) ;

    // now we need to assigne objects inside out vector using for loop
    for(auto& user: myUsers){
        cout << "please entre the name of user " << ++count << ":"<< endl ;
        while(!(cin >> Name)){
            cout << "Invalid input, please entre string " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        user.setup(Name);
    }

    cout << "\n--- USER LIST ---" << endl;

    for (const auto& user: myUsers){ user.print();}
    
    return 0;
}