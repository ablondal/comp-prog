#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct pt{
    double x;
    double y;
    pt(double xx, double yy):x(xx), y(yy){}
    pt():x(0), y(0){}
} pt;

pt operator-( pt a, pt b )
{
    return pt( a.x-b.x, a.y-b.y );
}

pt operator+( pt a, pt b )
{
    return pt( a.x+b.x, a.y+b.y );
}

pt operator*( double c, pt a )
{
    return pt( a.x*c, a.y*c);
}




int cross(pt a, pt b)
{
    float cross = a.x*b.y - b.x*a.y;
    if(cross<0) return -1;
    else if (cross>0) return 1;
    else return 0;
}

int main() {
    int N;
    vector <pt> pts;
    vector <pt> cents;
    vector <double> weights;
    int tmp1, tmp2;
    while(cin>>N)
    {
        pts.clear();
        cents.clear();
        weights.clear();
        if(N<3) break;

        // Insert the points in a counterclockwise manner
        for(int i=0; i<N; ++i){
            cin >> tmp1 >> tmp2;
            pt ne = pt(tmp1, tmp2);
            if(i>1){
                int j = 0;
                while(j+1 < i && ( cross(pts[j+1]-pts[j], ne - pts[j+1]) == 1 ) )
                {
                    j++;
                }
                pts.insert(pts.begin()+j+1, ne);
            }
            else pts.push_back(pt(tmp1, tmp2));
        }
        
        // Triangulate simply, calculate center of mass and mass of each triangle
        cents.resize(N-2);
        weights.resize(N-2);
        double totmass = 0;
        /*for(int i=1; i<N-1; ++i){
            // Triangle w pts 0, i, i+1
            cents[i-1].x = (pts[0].x + pts[i].x + pts[i+1].x)/3.0;
            cents[i-1].y = (pts[0].y + pts[i].y + pts[i+1].y)/3.0;
            weights[i-1] = pts[0].x*pts[i].y +
                pts[i].x*pts[i+1].y +
                pts[i+1].x*pts[0].y -
                pts[0].x*pts[i+1].y -
                pts[i].x*pts[0].y -
                pts[i+1].x*pts[i].y;
            weights[i-1] *= 0.5;
            totmass += weights[i-1];
        }
        pt center(0,0);
        for(int i=0; i<N-2; ++i){
            center = center + (weights[i]/totmass)*cents[i];
        }*/
        pt a, b;
        pt center(0,0);
        pt off = pts[0];
        double crossmass;
        for(int i=0; i<N; ++i){
            int j=(i+1)%N;
            a = pts[i]; b = pts[j];
            crossmass = (a.x - off.x) * (b.y - off.y) - (a.y - off.y) * (b.x - off.x);
            totmass += crossmass;
            center = center + crossmass * (a + b - 2*off);
        }
        totmass *= 3;

        printf("%.3f %.3f\n", center.x/totmass + off.x, center.y/totmass + off.y);
        //cout << center.x << " " << center.y << endl;
    }
    
    return 0;
}