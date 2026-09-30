#include <iostream>
using namespace std;
#include "Image_Class.h"
int main(){
    cout << "please choose from (1 , 2)\n1 is rotating your image\n2 is making your image white and black\nplease choose: ";
int choice;
cin >> choice;
if (choice == 1) {
string imageName;
int degree;
cout << "please enter image name: ";
cin >> imageName;
cout << "enter how much you want to rotate (90 , 180 , 270) degree: ";
cin >> degree;
Image image(imageName);
if (degree == 90)
{
    Image image90d(image.height,image.width);
    for (int i = 0; i < image.width; i++)
    {
       for (int j = 0; j < image.height; j++)
       {
        for (int k = 0; k < image.channels; k++)
        {
            image90d(image90d.width-1-j , image90d.height-1-i ,k)=image(i,j,k);
        }
        
       }}
    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imageName;
    image90d.saveImage(imageName);
}

else if (degree == 180)
{    Image image180d(image.width , image.height);
    for (int i = 0; i < image.width; i++)
{
    for (int j = 0; j < image.height; j++)
    {
       for (int k = 0; k < 3; k++)
       {
        image180d(i , image180d.height-1-j , k)=image(i,j,k);
       }
       
    }  }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imageName;
    image180d.saveImage(imageName);
}
else if (degree == 270)
{
     Image image270d(image.height , image.width);
for (int i = 0; i < image.width; i++)
{
    for (int j = 0; j < image.height; j++)
    {
      for (int k = 0; k < 3; k++)
      {
       image270d(j,image270d.height-1-i,k) = image(i,j,k);
      }
      
    }
}

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";
    cin >> imageName;
    image270d.saveImage(imageName);
}
}
else if (choice == 2) {
    string filename;
    cout << "Please enter your image name: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; 

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k); 
            }

            avg /= 3; 
            if (avg>127){
                avg = 255;
            }
            else {
                avg = 0;
            }
            image(i,j,0) = avg;
            image(i,j,1) = avg;
            image(i,j,2) = avg;

        }
    }

    cout << "Pls enter image name to store new image\n";
    cout << "and specify extension .jpg, .bmp, .png, .tga: ";

    cin >> filename;
    image.saveImage(filename);
}

}