#include <iostream>
#include <limits>
#include <vector>


using namespace std;

class Adder{

    private:
        int base;
    public:
        // give the base initial value everytime we create an object
        Adder(int b =0) : base(b) {}

        // lets us create setter for the base
        void setBase(int value) {base = value;}

        //getter for base
        int getBase(){return base;}
        
        // function call operator [overloading the operator ()] [it must be a memeber function not friend]
        int operator()(int x) const {return base + x;}



};


int main(){

    vector <int> vec ;
    int Base_Value;
    int n;
    Adder add;

    cout << "Please enter the base value [The default is 0] : " ;
    
        while(!(cin >> Base_Value )){
        cout << "Invalid input, please enter an integer" << endl;
        cin.clear(); //  Clear the error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }
    
    // set the base value the user made
    add.setBase(Base_Value);
    
    cout << "Please enter how many operations you want to make: " ;
    
        while(!(cin >> n)){
        cout << "Invalid input, please enter an integer" << endl;
        cin.clear(); //  Clear the error state
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    for (int i =0; i<n ; i++){
        int index;
        cout<<"Please enter value you want to add  " << i+1 << " : " ; cin>>index;

        // store the values we will added it on our base
        int result = add(index);

        // store the values inside the vector
        vec.push_back(result);
    }

    cout << "########## RESULTS: ##############" <<endl;

    for (auto x: vec){
        cout << x <<endl;
    }




    

  






    return 0;
}