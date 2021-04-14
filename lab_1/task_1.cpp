#include <iostream>
#include <vector>
#include <string>
#include <sstream>

std::vector<int> arr(std::vector<int> vec) {
    using namespace std;

    int idx(0);
    for (size_t i = 0, size = vec.size(); i < size; i++)
        if (!(vec[i] & 1)) idx++;
        else vec[i - idx] = vec[i];

    vec.erase(vec.begin() + vec.size() - idx, vec.end());

    return vec;
}

std::string dec2hex(const std::string &input) {

    std::stringstream sstr(input);
    int dec; sstr >> dec;
    std::string hex(input.size() + 2, '0');
    hex[1] = 'x';

    int idx(hex.size() - 1), tmp;
    while (dec > 0) {
         hex[idx] = (tmp = dec % 16) > 9
                ? 'A' + tmp - 10
                : '0' + tmp;
        dec /= 16;
        idx--;
    }

    return hex;
}

std::string std_dec2hex(const std::string &input) {

    std::stringstream in(input);
    std::stringstream out;

    int dec; in >> dec;

    out << "0x"
        << std::setfill('0') << std::setw(input.size())
        << std::hex << dec;

    return out.str();
}