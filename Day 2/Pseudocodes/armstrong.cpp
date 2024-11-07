#include <iostream>
#include <cmath>

using namespace std;

bool isArmstrong(int number){
    int copy = number;
    int counter = 0;
    while(copy > 0){
        copy /= 10;
        counter++;
    }
    copy = number;
    int sum = 0;
    while(copy > 0){
        int temp = copy % 10;
        sum = sum + (int)pow(temp,counter);
        copy /= 10;
    }
    if(sum == number)
        return true;
    return false;
}

void isArmstrongTest(){
    int number;
    cout << "Input a number: ";
    cin >> number;
    bool result = isArmstrong(number);
    if(result)
        cout << "It's Armstrong";
    else
        cout << "Not Armstrong";
}

int main()
{
    isArmstrongTest();

    return 0;
}
