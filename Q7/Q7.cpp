#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <string>

using std::cout;
using std::cin;
using std::vector;
using std::endl;
using std::sort ;
using std::reverse ;
using std::string;


class Student {

    private:
        string name;
        float gpa;
    
        public: 
            Student (string n="", float g = 0.0) : name(n) , gpa(g) {} 

            // lets make operator overloading for taking input >>  [it is much easier and keep main clean]
            friend std::istream& operator>> (std::istream& is, Student& other) {
                cout << "Entre Student Name: " ;
                is >> other.name;
                cout << "Entre student GPA : " ;
                is >> other.gpa ;
                return is; // Return the stream so we can do: cin >> s1 >> s2 ;
            }

            friend std::ostream& operator<< (std::ostream& os, const Student& other) {
                os << "Student Name: " <<other.name << " GPA : " << other.gpa << endl;
                return os ; // return the stream for chaning
            }

             // lets make operator greater than >  
            bool operator> (const Student& other ) const {
                return this->gpa > other.gpa ;
            }

            // lets make operator < less than [just for fun and practice]

            bool operator< (const Student& other) const {
                return this->gpa < other.gpa ;
            }
};


int main() {
    
    int count ;
    cout << "please entre how many students you want to entre: " ;
    while(!(cin >> count)){
        cout << "Invalid input, please entre integer " << endl;
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    vector <Student> vec; 
    
    // Data collection loop
    for (int i =0 ; i < count; i++){
        Student temp;
        cout << "Please enter student" << i+1 << "  Data : " ;  
        cin >> temp;
        vec.push_back(temp);
    }

    sort(vec.begin(), vec.end()); // this will use my overloading operator to sort low -> high

    reverse(vec.begin(), vec.end());

    cout << "\n--- Students Ranked by GPA (High -> Low) ---" << endl;
    for(const auto& s : vec){
        cout << s << endl;
    }





    return 0;
}