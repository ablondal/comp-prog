#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    //num test cases
    int m;
    cin >> m; 

    //prepare array for light output 
    bool arr[m];
    for(int k = 0; k < m; k++) {
        arr[k] = false;
    }

    //ask user for each test case
    for(int j = 0; j < m; j++) {

        //book location
        int xBook,yBook;
        cin >> xBook >> yBook; 

        //num candles
        int n;
        cin >> n;

        //ask for location of each candle
        for(int i = 0; i < n; i++) {
            int xCandle, yCandle;
            cin >> xCandle;
            cin >> yCandle;
            cout << xCandle << " " << yCandle << endl;

            //true when candle lights book
            //within 8m radius
            if((abs(xBook - xCandle) < 8) 
            && (abs(yBook - yCandle) < 8)) {
                arr[j] = true;
            }
        }
    }
    for(bool light: arr) {
        if(light) {
            cout << "light a candle" << endl;
        } else {
            cout << "curse the darkness" << endl;
        }
    }
}