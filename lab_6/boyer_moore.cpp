#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>


namespace search_by_str {
    using namespace std;

    int boyer_moore_search(const string &substr, const string &path) {

        unordered_map<char, int> mp;
        for (int i = 2; i <= substr.size(); i++)
            mp[substr[substr.size() - i]] =
                    (mp.contains(substr[substr.size() - i]) ? mp[substr[substr.size() - i]] : i - 1);

        ifstream file(path);
        if (!file.is_open())
            throw exception();

        uint64_t total_counter = 0;
        string txt;
        while (getline(file, txt)) {
            int txt_it = 0, pat_it = substr.size() - 1;

            while (pat_it > -1 and txt_it + substr.size() - 1 < txt.size()) {
                if (substr[pat_it] != txt[txt_it + pat_it]) {
                    txt_it += mp[txt[txt_it]] or substr.size();
                    pat_it = substr.size() - 1;
                } else
                    pat_it--;
            }
            if (pat_it == -1)
                return total_counter + txt_it;

            total_counter += txt.size();
        }

        return -1;
    }
}