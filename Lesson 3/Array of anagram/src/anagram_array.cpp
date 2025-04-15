#include "anagram_array.hpp"
#include <unordered_map>
#include <algorithm>

std::vector<std::set<std::string>> make_array_angram (const std::vector<std::string>& data) {

    std::unordered_map<std::string, std::set<std::string>> hash;
    auto cmp = [](char x, char y) {return x < y;};
    for (const std::string& s : data) {
        std::string copy_s = s;
        std::sort(copy_s.begin(), copy_s.end(), cmp);
        if (hash.find(copy_s) == hash.end())
            hash.emplace(copy_s, std::set<std::string>({s}));
        else
            hash[copy_s].emplace(s);
    }

   std::vector<std::set<std::string>> ans;
   ans.reserve(hash.size());

   for (auto& i : hash) {
        ans.push_back(std::move(i.second));
   }

   return ans;
}
