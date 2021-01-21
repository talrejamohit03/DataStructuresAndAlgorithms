#include <iostream>
using namespace std;

struct point{
    int x,y;
};
point thirdpt(point p1,point p2){
    point temp;
    temp.x=p1.x*p2.x;
    temp.y=p1.y*p2.y;
    return temp;
}
void getpoint(point &pt){
    cout<<"Enter x coordinate: ";
    cin>>pt.x;
    cout<<"Enter y coordinate: ";
    cin>>pt.y;
}
int main(){
    point pt1,pt2,pt3;
    cout<<"For point 1: \n";
    getpoint(pt1);
    cout<<"For point 2: \n";
    getpoint(pt2);
    pt3=thirdpt(pt1,pt2);
    cout<<"Coordinates for the 3rd point are: ("<<pt3.x<<","<<pt3.y<<") "<<endl;
    return 0;
}
