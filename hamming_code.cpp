#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int calculate_parity(int n, const vector<char>& data) {

    int parity = 0;
    int start_index = n - 1;

    while (start_index < (int)data.size()) {

        for (int j = start_index;
             j < min((int)data.size(), start_index + n);
             ++j) {

            if (data[j] == '1')
                parity++;
        }

        start_index += 2 * n;
    }

    return parity % 2;
}

void hamming_code(string data_str) {

    vector<char> data(data_str.begin(), data_str.end());

    int m = data.size();
    int r = 0;

    int power = 1;
    while (power < m + r + 1) {
        power *= 2;
        r++;
    }

    vector<char> encoded_data;

    for (int i = 0; i < m + r; i++) {
        encoded_data.push_back('0');
    }

    int data_index = 0;

    for (int i = 1; i <= m + r; i++) {

        bool isParityPosition = false;

        int p = 1;
        while (p <= m + r) {

            if (i == p) {
                isParityPosition = true;
                break;
            }
            p *= 2;
        }
        if (!isParityPosition) {
            encoded_data[i - 1] = data[data_index];
            data_index++;
        }
    }

    for (int i = 0; i < r; ++i) {

        int parity_pos = (1 << i) - 1;

        int p = calculate_parity(parity_pos + 1, encoded_data);

        if (p == 1)
            encoded_data[parity_pos] = '1';
        else
            encoded_data[parity_pos] = '0';
    }

    cout << "Encoded data: ";
    for (char c : encoded_data)
        cout << c;
    cout << endl;

}

void verify(string received_data_str) {

    vector<char> data(received_data_str.begin(), received_data_str.end());

    int n = data.size();

    int r = 0;

    int power = 1;

    while (power <= n) {
        r++;
        power *= 2;
    }

    vector<char> old_parities;

    vector<char> temp_data = data;

    for (int i = 0; i < r; ++i) {

        int parity_position = (1 << i) - 1;

        old_parities.push_back(temp_data[parity_position]);

        temp_data[parity_position] = '0';
    }

    int flag = 0;

    for (int i = 0; i < r; ++i) {

        int parity_position = (1 << i);

        int calculated_parity = calculate_parity(parity_position, temp_data);

        char calculated_parity_char;

        if (calculated_parity == 1)
            calculated_parity_char = '1';
        else
            calculated_parity_char = '0';

        if (calculated_parity_char != old_parities[i]) {
            flag = 1;
        }
    }

    if (flag == 1) {
        cout << "The message is corrupted!" << endl;
    }
    else {
        cout << "The message received correctly." << endl;
    }
}

int main() {

    string data = "1010101000011010";

    cout << "Original data: " << data << endl;

    hamming_code(data);

    return 0;
}
