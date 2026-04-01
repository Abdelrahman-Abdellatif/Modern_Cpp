#include <iostream>
#include <limits>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
// Operator overloading

class Complex{

    private:
        int real;
        struct Imaginary
        {
            int imgnum =0;
            char imagchar ='i';
        } y;
        
        public: 
            // this is a constructor that takes a copy from the struct
            Complex (int n, Imaginary x) : real(n), y(x) {}

            // this is a constructor that takes 2 integers
            Complex (int r, int i): real(r), y{i , 'i'} {}
            
            // We will create operator +
            // I promise not to change the object I am adding to myself.
            // the secound const says This function is 'Read-Only'. It won't change the variables of the object that called it.
            Complex operator+(const Complex& other) const {
                return Complex(this->real + other.real, this->y.imgnum + other.y.imgnum) ;
            }

            // we will make operator -
            Complex operator-(const Complex& other) const {
                return Complex (this->real - other.real, this->y.imgnum - other.y.imgnum ) ;
            }

            // we will make operator =

            Complex& operator=(const Complex& other) {
                if(this != &other){
                    this->real = other.real;
                    this->y.imgnum = other.y.imgnum;
                }
                return *this ;
            }

            // we will make operator << 
            // if you are asking why we use friend keyword [firend allows this function to see the class private data] ? 
            // we use it becouse cout is not a function inside our class it is in the std libarary, so we need it to see our private data so we use friendn
            friend std::ostream& operator<<(std::ostream& os, const Complex& other){
                os << other.real << " + " << other.y.imgnum << other.y.imagchar << endl;
                return os; // return the stream for chaning
            }

            //void print() const { cout << real << " + " << y.imgnum << y.imagchar<< endl; ; }

};


int main(){


    int inputReal;
    int inputImg;
    vector <Complex> vec;

    for (int count =0; count < 2; count++){

        cout << "--- User " << count + 1 << " ---" << endl;

        cout << "Please entre the real number: " ;
        while(!(cin >> inputReal)){
            cout << "Invalid input, please entre integer " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        cout << "Please entre the imaginary number without the character 'i': " ;
        while(!(cin >> inputImg)){
            cout << "Invalid input, please entre integer " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        vec.emplace_back(inputReal,inputImg );        
    }

    Complex sum = vec[0] + vec[1];
    Complex diff = vec[0] - vec [1];

    cout << "\nResults:" << endl;
    cout << "Number 1: " << vec[0] << endl;
    cout << "Number 2: " << vec[1] << endl;
    cout << "--------------------" << endl;
    cout << "Addition:       " << sum << endl;
    cout << "Subtraction:    " << diff << endl;
    return 0;
}


