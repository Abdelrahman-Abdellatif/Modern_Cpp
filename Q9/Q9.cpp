#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;




class QueryBuilder{

    private:
        string columns, table, condition;

    public:

    QueryBuilder& select (string col){
        this->columns =col;
        return *this;
    }

    QueryBuilder& from(string tbl){
        this->table = tbl;
        return *this;
    }

    QueryBuilder& where(string cond){
        this->condition = cond;
        return *this;
    }

    string build(){
        return  " SELECT " + columns + " FROM " + table + " WHERE " + condition + " ; " ;
    }




};





int main() {

    string sel;
    string fr;
    string whr;
    QueryBuilder Q1;
    
    
    cout << "please enter the column: "; cin>> sel;
    cout << "Plese enter the table: " ; cin>> fr;
    cout << "Please enter the condition: " ; cin>> whr;

    
    
    string myQ = Q1.select(sel).from(fr).where(whr).build();

    cout << "GENERATED QUERY IS : " << myQ << endl;
    return 0;
}