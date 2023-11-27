#include <iostream>
using namespace std;

int main() {
    int N, L, total_scores = 0, passes_count = 0;

    cin >> N >> L; // Number of students

    for(int i = 1; i <= N; ++i){
        int score;
        cin >> score; // Students scores (Ai)
        if(score >= L){
            total_scores += score; // Sum of the passing scores
            passes_count++; // Count the number of students who passed
        }
    }
    cout << passes_count << endl;
}
