#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> quotes = {
        "Keep going, you're doing great!",
        "Dream big, work hard, stay humble.",
        "Every moment is a fresh beginning.",
        "Believe you can and you're halfway there.",
        "Mistakes are proof that you are trying."
    };

    srand(time(0));  
    int idx = rand() % quotes.size();

    cout << "Random Quote: " << quotes[idx] << endl;
    return 0;
}
