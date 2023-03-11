#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
// there are 3 shells, 1, 2, 3
// n times swap 2 shells and the other guess
// find the most correct guess
// 1 <= n <= 100
// Time complexity: O(n)
void swapShell(int a, int b, int start1[3], int start2[3], int start3[3]){
    int temp = start1[a - 1];
    if((a == 1 && b == 2) || (a == 2 && b == 1)){ // swap 1 and 2
        // case start 1
        temp = start1[1];
        start1[1] = start1[0];
        start1[0] = temp;
        // case start 2
        temp = start2[1];
        start2[1] = start2[0];
        start2[0] = temp;
        // case start 3
        temp = start3[1];
        start3[1] = start3[0];
        start3[0] = temp;

    }else if((a == 1 && b == 3) || (a == 3 && b == 1)){ // swap 1 and 3
        // case start 1
        temp = start1[2];
        start1[2] = start1[0];
        start1[0] = temp;
        // case start 2
        temp = start2[2];
        start2[2] = start2[0];
        start2[0] = temp;
        // case start 3
        temp = start3[2];
        start3[2] = start3[0];
        start3[0] = temp;
    }else if ((a == 2 && b == 3) || (a == 3 && b == 2)){ // swap 2 and 3
        // case start 1
        temp = start1[2];
        start1[2] = start1[1];
        start1[1] = temp;
        // case start 2
        temp = start2[2];
        start2[2] = start2[1];
        start2[1] = temp;
        // case start 3
        temp = start3[2];
        start3[2] = start3[1];
        start3[1] = temp;
    }
}
int solve(){
    // get input from file shell.in
    // read input
    int n;
    int ans = 0;
    ifstream fin("shell.in");
    fin >> n;
    vector<int> a(n), b(n), g(n);
    for (int i = 0; i < n; i++){
        fin >> a[i] >> b[i] >> g[i];
    }
    fin.close();
    int start1[4] = {1, 0, 0, 0};
    int start2[4] = {0, 1, 0, 0};
    int start3[4] = {0, 0, 1, 0};
    for(int i = 0; i < n; i++){
        // swap 2 shells
        swapShell(a[i], b[i], start1, start2, start3);
        // guess
        if(start1[g[i] - 1] == 1){
            start1[3] ++;
        }else if(start2[g[i] - 1] == 1){
            start2[3] ++;
        }else if(start3[g[i] - 1] == 1){
            start3[3] ++;
        }
    }
    // find the max
    int max = 0;
    for(int i = 0; i < 4; i++){
        if(start1[i] > max){
            max = start1[i];
        }
        if(start2[i] > max){
            max = start2[i];
        }
        if(start3[i] > max){
            max = start3[i];
        }
    }

    // output to file shell.out
    fclose(stdin);
    return max;

}
int main(){
    int ans = solve();
    freopen("shell.out", "w", stdout);
    // write output to file shell.out
    ofstream fout("shell.out");
    fout << ans << endl;
    fout.close();
    fclose(stdout);

    return 0;

}