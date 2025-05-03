#include<iostream>
using namespace std;

class Shape{
    public:
    int length,breadth,height,area;
       Shape(int a, int b,int c)
       {
          length=a;
          breadth=b;
          height=c;
       }
       void Square(){
        area=length*length;
        cout<<"Area of a Square: "<<area<<endl;
       }

       void Cube()
       {
          area=6*length*length;
          cout<<"Area of a Cube: "<<area<<endl;
       }
       void Rectangle()
       {
        area=length*breadth;
        cout<<"Area of a Rectangle: "<<area<<endl;
       }
       void Cuboid()
       {
        area=2*(length*breadth+breadth*height+length*height);
        cout<<"Area of a Cuboid: "<<area<<endl;
       }

};

int main()
{
    int len,bre,hei;
    cout<<"Enter all the Dimensions for square,rectangle,cube,cuboid....."<<endl;
    cout<<"Enter length value: \n";
    cin>>len;
    cout<<"Enter breadth value: \n";
    cin>>bre;
    cout<<"Enter height value: \n";
    cin>>hei;
    Shape shape(len,bre,hei);
    while(1)
    {
        cout<<"1.Square\n2.Rectangle\n3.Cube\n4.Cuboid\n5.Exit\n";
        int choice;
        cout<<"Enter a choice:"<<endl;
        cin>>choice;
        switch (choice)
        {
        case 1:
            shape.Square();
            break;
        
        case 2:
             shape.Rectangle();
             break;
        case 3:
             shape.Cube();
             break;
        case 4:
             shape.Cuboid();
             break;
        case 5:
            cout<<"Thank you for visiting my program"<<endl;
            exit(1);
            break;
        }
    }

    return 0;

}