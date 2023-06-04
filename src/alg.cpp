// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string fail;
  while (!file.eof()) {
    int mac = file.get();
    if (mac >= 65 && mac <= 90) {
      mac += 32;
      fail += mac;
    } else if (mac >= 97 && mac <= 122) {
      fail += mac;
    } else {
      tree.add(fail);
      fail = "";
    }
  }
  file.close();
  return tree;
  // поместите сюда свой код
}
