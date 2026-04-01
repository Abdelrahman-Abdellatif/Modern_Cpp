#include <iostream>
#include <string>

using std::string;
using std::cout ;
using std::cin;
using std::endl;

class Tracer{

    private:
        string name ="";  // GIVE THEM INITIAL VALUES TO PREVENT GARBAGE VALUES
        string name1 ="";
        string name2= "";
    public:
// best practice to solve this is to make a master constructor and then make a constructors delegation
        Tracer(string N, string N1, string N2) : name(N), name1(N1), name2(N2) {
            if(!name.empty()) cout<< "[ctor]" << name << endl;
            if(!name1.empty()) cout << "[ctor]" << name1 << endl;
            if (!name2.empty()) cout << "[ctor]" << name2 <<endl;
        }

        // delegations
        Tracer(string N, string N1) : Tracer(N, N1, ""){}
        Tracer(string N) : Tracer(N, "", "") {}

        // create destructor
        ~Tracer(){
            if(!name.empty()) cout << "[dtor]" << name << endl;
            if(!name1.empty()) cout << "[dtor]" << name1 << endl;
            if (!name2.empty()) cout << "[dtor]" << name2 << endl;

        }

};


int main(){

    Tracer Obj("Alpha", "Beta", "Gamma");
    Tracer Obj1("Alpha", "Beta");
    Tracer Obj2("Alpha");

    return 0;
}