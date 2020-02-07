#include <iostream>
#include <cmath>
using namespace std;

const int N = 30;
const int M = 70;

void updateImage(bool [][M],int,int,int);

void showImage(const bool [][M]);

int main()
{
    bool image[N][M] = {};
    int s,x,y;
    do{
        showImage(image);
        cout << "\nInput your brush size and location:";
        cin >> s >> x >> y;
        updateImage(image,s,x,y);
    }while(s != 0 && x != 0 && y != 0 );
    return 0;
}

void updateImage(bool image[][M],int s,int x,int y){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            if(image[i][j]==1) continue;
            if(sqrt(pow((i-x),2)+pow((j-y),2))<=s-1)  image[i][j]=1;
            else  image[i][j]=0;
        }
    }
}

void showImage(const bool image[][M]){
    int i,j;
    for(i=0;i<M+2;i++) cout << "-"; 
    for(i=0;i<N;i++){
        cout <<"\n"  << "|";
        for(j=0;j<M;j++){
            if(image[i][j]==true) cout << "*";
            else cout << " ";
        }
        cout << "|";
    }
    cout << "\n";
    for(i=0;i<M+2;i++) cout  << "-";
}
