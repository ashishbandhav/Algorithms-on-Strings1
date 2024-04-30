/*
 * Coursera/Algorithms on Strings/Week 1/Problem 1:
 * Construct a Trie from a Collection of Patterns
 * Grading: 'Good job! (Max time used: 0.04/0.50, max memory used: 67588096/536870912.)'
 * Respect Coursera Honor Code
 * Copyright © 2018. All rights reserved
 *
 */

#include <iostream>
#include <vector>
#include <map>

using std::map;
using std::string;
using std::vector;

using edges = map<char, int>;
using trie = vector<edges>;

trie build_trie(vector<string> &patterns)
{

  if (patterns.empty())
  {
    return trie{};
  }

  trie t{edges{}};

  int root{0}, cnt{0};

  for (auto &p : patterns)
  {
    int current = root;

    for (auto s : p)
    {
      if (t[current].find(s) != t[current].end())
      {
        current = t[current][s];
      }
      else
      {
        t.emplace_back(edges{});
        t[current][s] = ++cnt;
        current = cnt;
      }
    }
  }
  return t;
}

int main()
{
  size_t n;
  std::cin >> n;
  vector<string> patterns;
  for (size_t i = 0; i < n; i++)
  {
    string s;
    std::cin >> s;
    patterns.push_back(s);
  }

  trie t = build_trie(patterns);
  for (size_t i = 0; i < t.size(); ++i)
  {
    for (const auto &j : t[i])
    {
      std::cout << i << "->" << j.second << ":" << j.first << "\n";
    }
  }

  return 0;
}
