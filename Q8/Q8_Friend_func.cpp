#include <iostream>

using namespace std;



class Box{

    private:
       int length, width, height;

    public:
        Box( int l =0 , int w =0 , int h =0) : length(l), width(w), height(h) {}

        friend int Volume( Box& box);

        friend ostream& operator<< (ostream& os, const Box& other) ;

};


ostream& operator<< (ostream& os, const Box& other){
    
    os << "The box dimensions are : " << endl;
    os << " length: " << other.length ;
    os<< " width: " << other.width;
    os << " height: " << other.height << endl ;
    return os;

}

int Volume(Box& box) {
    
    int volume = box.length * box.width * box.height ;
    cout << "Volume is: " << volume << endl;
    return volume;
}




int main(){
    int x, y,z ;
    cout<< "Please entre the box dimension x: ";
    cin>> x;

    cout<< "Please entre the box dimension y: ";
    cin>> y;

    cout<< "Please entre the box dimension z: ";
    cin>> z;

    Box B1(x,y,z);

    cout << B1;
    Volume(B1);





    return 0;
}