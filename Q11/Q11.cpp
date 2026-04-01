#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::endl;


class SafeVector{

    private:
        vector <int> vec;
    
    public:

    // lets create a function to add the data to our vector
    void add(int value){ vec.push_back(value);}

    // lets crrate the operator [] function

    int operator[](int index) {
        if (index >= (int)vec.size() || index < 0){
            cout << "Error: index " << index << " out of range" << endl;
            return -1; // Return a dummy value because the function must return an int
        }

        return vec[index];
    }
    
    
    void peintElement(int index){
        int results = (*this)[index];
        if (results != -1){
            cout << "v[" << index << "] = " << results << endl;
        }
    }



};



int main () {

    SafeVector sv;
    int n, q;

    // 1. Read the number of elements
    if (!(cin >> n)) return 0;

    // 2. Fill the SafeVector
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        sv.add(val);
    }

    // 3. Read the number of queries
    if (!(cin >> q)) return 0;

    // 4. Process the queries
    for (int i = 0; i < q; i++) {
        int index;
        cin >> index;
        
        // We use the overloaded [] here
        // If the index is 7 and size is 5, it triggers the Error inside the class
        sv.peintElement(index);
    }


    return 0;
}