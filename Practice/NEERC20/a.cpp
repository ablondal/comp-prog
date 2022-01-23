#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, n;
    scanf("%d %d", &a, &b);
    n = a + b;
    vector<int> twoRows;
    int row = 0;
    int maxRow = -1;
    while (b > 0)
    {
        if(b & 1){
            twoRows.push_back(row);
            maxRow = row;
        }
        b = b >> 1;
        row++;
    }
    if (maxRow >= 0 && a < (int)(pow(2, maxRow + 1) - 0.5) - (n-a))
    {
        printf("-1\n");
    }
    else
    {
        vector<int> vals(2*n + 7, 0);
        // fill in ones up to the final row
        int placeOnes = 1;
        int row=0;
        while((1<<(row+1)) <= n){
            row++;
            placeOnes = (1<<row);
        }
        for(int i = 1; i < placeOnes; i++){
          vals[i] = 1;
        }

        // overwrite with twos in the correct spots
        for (int i = 0; i < twoRows.size(); i++)
        {
            int val = pow(2, twoRows[i]) + 0.5;
            for (int j = val; j < 2 * val; j++)
            {
                vals[j] = 2;
            }
        }

        int first = (placeOnes);
        // vector<pair<pair<int, int>, int>> positions(1<<row);
                int left = n-placeOnes+1;

        for(int k = 0; k<left; ++k){
            int r = (1<<row);
            int rk = k;
            int ii = 0;
            while(rk){
                if (rk & 1) r |= (1<<(row-ii-1));
                rk >>= 1;
                ii++;
            }
            cout << r << endl;
            vals[r] = 1;
        }

                /* 1011000 == 1101000 */

        // place any remaining ones
        // int first = (placeOnes);
        // queue<int> Q;
        // Q.push(first);
        // Q.push(-1);
        // int layer = row-1;
        // // placeOnes = (1<<row);
        // int left = n-placeOnes+1;
        // while(left){
        //     int c = Q.front();
        //     //printf("c: %d\n", c);
        //     Q.pop();
        //     if (c==-1){
        //         layer--;
        //         Q.push(-1);
        //     }else{
        //         if (vals[c] != 1){
        //             vals[c] = 1;
        //             //printf("%d\n", c);
        //             left--;
        //         }
        //         Q.push(c);
        //         Q.push(c | (1<<layer));
        //     }
        // }
        int index = placeOnes;
        map<int, int> indexMapping;
        for (int i = placeOnes; i < vals.size(); i++){
            if(vals[i] == 1){
                indexMapping[i] = index;
                index++;
            }
        }
            for(int i = 1; i <= 2 * n; i++){
                printf("%d ", vals[i]);
            }
            printf("\n");
        int printed = 0;
        int i = 1;
        while (printed < n)
        {
            if(vals[i] == 0){
                i++;
           



         }else{
                int l = 0, r = 0;
                if (2 * i <= vals.size() && vals[2 * i] != 0)
                {
                    if (indexMapping.find(2 * i) != indexMapping.end())
                    {
                        l = indexMapping[2 * i];
                    }
                    else
                    {
                        l = 2 * i;
                    }
                }
                if (2 * i + 1 <= vals.size() && vals[2 * i + 1] != 0)
                {
                    if (indexMapping.find(2 * i + 1) != indexMapping.end())
                    {
                        r = indexMapping[2 * i + 1];
                    }
                    else
                    {
                        r = 2 * i + 1;
                    }
                }
                printf("%d %d %d\n", vals[i], l, r);
                i++;
                printed++;
            }
        }
    }
}