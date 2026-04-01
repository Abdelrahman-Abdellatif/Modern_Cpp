#include <iostream>

using namespace std;

class Sensor{

    private:
        double reading;
    public: 
        Sensor(double x =0) : reading(x){}
        
        double setReading(double value){return reading = value;}    
        
        void getReading () const {cout <<"sensor reading: " << reading << endl;}
};







int main(){

    Sensor s1;
    s1.setReading(25.7);
    s1.getReading();

    const Sensor constSensor(10.7);
    constSensor.getReading();

    // constSensor.setReading(30.0);        ERROR

    return 0;
}