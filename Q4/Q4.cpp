#include <iostream>
#include <algorithm>
#include <limits>


using std::cout;
using std::cin;
using std::endl;
using std::copy;





class IntArray {

    public:

    // Parameterized Constructor = The "Factory" (creates something from raw materials).
    // we created an paramatrized constructor, which takes 1 value as attribute;
    // and inside it, we made the pointer to point to a new bulk of memeory in the heap
    // and then we initialized its intial values to be 0, to ignore the garbage values problem
        explicit IntArray(int s) : size(s) {
            data = new int[size];
            // we should put initial values inside the array
            for (int i =0; i < size; i++ ) data[i] =0;
            cout << "Object created at heap address: " << data << endl;
        }

        // we should make a copy deep constructor
        // Copy Constructor = The "Xerox Machine" (creates something from an existing item).
        /*
            four golden rules to follow to write a bug-free Deep Copy Constructor:
            1) use constant refrence
            2) new memory allocation
            3) data transfer [we must physically copy the data by std::copy() or for loop]
            4) use memeber initialization list
        */

        IntArray(const IntArray& other): size(other.size){
            data = new int[other.size]; // i assigned a seprate new bulk of memory in the heap
            std::copy(other.data, other.data + size , data);
            cout << " Deep copy created at heap address: " << data <<  endl;
        }

        void setElement (int index, int value){
            if (index >= 0 && index < size) data[index] = value;
        }

        void getElement () const { for (int i =0; i < size; i++ ) cout << "the array elements are : " << data[i] << endl;}

        ~IntArray (){ delete [] data;}




    private:
        int* data;
        int size;
};

int main(){

    int userSize;
    cout << "please entre thehsize of the array you want to copy" << endl;

    while(!(cin >> userSize) || userSize <= 0) {
        cout << "Invalid input, please integer number" << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    IntArray myArr(userSize);

    cout << "please entre the array elements: " << endl;
    for (int i =0; i < userSize ; i ++){
        int input;
        while(!(cin >> input)){
            cout << "Invalid input, please integer number" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // assign input to the object i created
        myArr.setElement(i,input);
    }

    // test the copy constructor

    IntArray copyArr = myArr;
    copyArr.getElement();

    cout<< " ############ changine the secound obejct and lets see the effect on both:  ####################" << endl;

    copyArr.setElement(0, 90000);
    copyArr.getElement();
    myArr.getElement();

    return 0;
}