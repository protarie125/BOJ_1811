#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string target, guess;
    cin >> target;
    while ("#" != target) {
        cin >> guess;

        auto n = static_cast<int>(guess.length());
        vector<bool> guessChecked(n, false);
        vector<bool> posUsed(n, false);

        int cblack{ 0 };
        for (int i = 0; i < n; ++i)
        {
            auto c = guess[i];
            if (c == target[i]) {
                guessChecked[i] = true;
                posUsed[i] = true;
                cblack += 1;
            }
        }

        int cgrey{ 0 };
        for (int i = 0; i < n; ++i)
        {
            if (!guessChecked[i]) {
                auto c = guess[i];
                if (0 <= i - 1 &&
                    c == target[i - 1] &&
                    !posUsed[i - 1]) {
                    guessChecked[i] = true;
                    posUsed[i - 1] = true;
                    cgrey += 1;
                }
                else if (i + 1 < n &&
                    c == target[i + 1] &&
                    !posUsed[i + 1]) {
                    guessChecked[i] = true;
                    posUsed[i + 1] = true;
                    cgrey += 1;
                }
            }
        }

        int cwhite{ 0 };
        for (int i = 0; i < n; ++i)
        {
            if (!guessChecked[i]) {
                auto c = guess[i];
                for (int j = 0; j < n; ++j)
                {
                    if (c == target[j] && !posUsed[j]) {
                        guessChecked[i] = true;
                        posUsed[j] = true;
                        cwhite += 1;
                    }
                }
            }
        }

        // result
        cout << guess << ": " <<
            cblack << " black, " <<
            cgrey << " grey, " <<
            cwhite << " white\n";

        // next
        cin >> target;
    }

    return 0;
}