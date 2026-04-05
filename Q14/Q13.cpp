#include <iostream>
#include <string>
#include <vector>
#include <limits>


using namespace std;

class CallCounter{

    public:
        // make initial value for count
        CallCounter(int x =0): count(x){}

        // make the call function
        void call (string msg) const{
            count +=1;
            cout << "[" << count << "] "<<  msg <<endl;
        }

        // make getter for count

        int getCount(){return count;}


    private:
        mutable int count;
};




int main(){

    //vector <string> vec;
    int n;
    CallCounter callObj;

    cout << "Please enter how many calls you want to make: " ; cin >>n;

    for (int i =0 ; i < n; i++){
        string message;
        cout << "Please enter the string values: " ;
        cin>>message;
        callObj.call(message);
    }

    cout<< "Total calls: " << callObj.getCount() <<endl;






    return 0;
}