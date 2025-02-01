#include <bits/stdc++.h>
using namespace std;

void getOutput();

int main() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        int n;
        cin >> n;
        cin.ignore();

        for (int q = 0; q < n; q++) {
            int width, length, start;
            cin >> width >> length >> start;
            string path[length+4][width+2];

            //starting line
            for (int i = 0; i < width+2; i++){
                path[0][i] = "=";
            }
            for (int i = 0; i < width; i++){
                path[1][i+1] = " ";
            }
            path[1][0] = "|";
            path[1][width+1] = "|";
            path[1][start] = "v";
            for (int i = 0; i < width+2; i++){
                path[2][i] = "-";
            }


            //sidelines
            for (int i = 0; i < length; i++){
                for (int k = 0; k < width; k++){
                    path[i+3][k+1] = " ";
                }
                path[i+3][0] = "|";
                path[i+3][width+1] = "|";
            }
            //finish line
            for (int i = 0; i < width+2; i++){
                path[length+3][i] = "=";
            }
            

            //add obstacles
            int g;
            cin >> g;
            for (int k = 0; k < g; k++){
                int r, e;
                cin >> r >> e;
                for (int i = 0; i < length; i++){
                    if ((i+1) % r == 0){
                        path[i+3][e] = "o";
                    }
                }
            }

            
            //add player movement and set lastline to index if spot broken
            string directions;
            int lastline = length+4;
            cin >> directions;
            int place = start;
            path[3][place] = "v";
            for (int i = 0; i < directions.length(); i++){
                if (directions[i] == 'L'){
                    place--;
                }
                else {
                    place++;
                }

                //dont got through walls
                if (place < 1){
                    place = 1;
                }
                if (place > width){
                    place = width;
                }

                //if crash
                if (path[i+4][place] == "o"){
                    path[i+4][place] = "X";
                    lastline = i+5;
                    break; 
                }
                else {
                    path[i+4][place] = "v";
                }
            }


            //print it
            for (int i = 0; i < lastline; i++){
                for (int k = 0; k < width + 2; k++){
                    cout << path[i][k];
                }
                cout << "\n";
            }


            if (lastline != length+4){
                cout << "You Crashed - GAME OVER" << "\n";
            }
            else {
                cout <<"Course Complete!" << "\n";
            }
            
        }

        return 0;
}