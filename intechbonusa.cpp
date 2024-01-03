#include <iostream>
#include <string>

string compress_string(const string& str) {
    string compressed;
    int count = 1;
    char prev = str[0];

    for (int i = 1; i < str.length(); ++i) {
        char curr = str[i];
        if (curr == prev) {
            count++;
        } else {
            compressed += prev + to_string(count);
            count = 1;
            prev = curr;
        }
    }

    // Handle the last character
    compressed += prev + to_string(count);

    return compressed.length() < str.length() ? compressed : str; // Return shorter version
}

string second_compressor(const string& compressed) {
    string further_compressed;
    int count = 1;
    string prev_group = compressed.substr(0, 2); // Handle character and count as a group

    for (int i = 2; i < compressed.length(); i += 2) {
        string group = compressed.substr(i, 2);
        if (group == prev_group) {
            count++;
        } else {
            // Add the previous group only once, even if its count is 1
            if (count > 1) {
                further_compressed += prev_group.substr(0, 1) + to_string(count);
            } else {
                further_compressed += prev_group.substr(0, 1); // Add single character if count is 1
            }
            count = 1;
            prev_group = group;
        }
    }

    // Handle the last group (and add it even if its count is 1)
    if (count > 1) {
        further_compressed += prev_group.substr(0, 1) + to_string(count);
    } else {
        further_compressed += prev_group.substr(0, 1);
    }

    return further_compressed.length() < compressed.length() ? further_compressed : compressed;
}

int main() {
    string original_string = "aabbcccaa";

    string compressed_string = compress_string(original_string);
    cout << "First compression: " << compressed_string << endl; // Output: a2b2c3a2

    string further_compressed = second_compressor(compressed_string);
    cout << "Second compression: " << further_compressed << endl; // Output: aba2c3

    return 0;
}
