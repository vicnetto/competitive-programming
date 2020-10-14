#include <bits/stdc++.h>

using namespace std;

int main () {
    int length, events;
    char newline;

    while(cin >> length && cin >> events) {
        scanf("%c", &newline);

        int gain = 0;
        vector<pair<string, pair<int, int>>> parking;
        parking.push_back(make_pair("-", make_pair(0, 0)));
        parking.push_back(make_pair("-", make_pair(length, length)));

        for (int i = 0; i < events; i++) {
            string description, plate;
            getline(cin, description);

            int begin = 0, end = 0, size = 0;
            char letter = 'A';

            end = description.find_first_of(" ", begin);
            if (begin == 0) {
                letter = description.substr(begin, end - begin)[0];
            }
            begin = end + 1;

            end = description.find_first_of(" ", begin);
            plate = description.substr(begin, end - begin);
            begin = end + 1;

            end = description.find_first_of(" ", begin);
            if (letter == 'C') {
                size = stoi(description.substr(begin, end - begin));

                for (int j = 0; j < parking.size(); j++) {
                    if (parking.at(j).second.second != length) {
                        if (parking.at(j).second.second + size <= parking.at(j + 1).second.first) {
                            parking.insert(parking.begin() + j + 1, make_pair(plate, make_pair(parking.at(j).second.second, parking.at(j).second.second + size)));
                            gain += 10;
                            break;
                        }
                    }
                }
            }

            if (letter == 'S') {
                for (int j = 0; j < parking.size(); j++) {
                    if (parking.at(j).first == plate) {
                        parking.erase(parking.begin() + j);
                    }
                }
            }

        }

        cout << gain << endl;
    }

    return 0;
}