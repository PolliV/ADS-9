// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <string>
#include <algorithm>
template<typename T>
  class BST {
   private:
      struct Node {
        T value;
        int count;
        Node* r;
        Node* l;
      };
      Node* root;
      Node* addNode(Node* root, T value) {
        if (root == nullptr) {
          root = new Node;
          root->value = value;
          root->l = root->r = nullptr;
          root->count = 1;
        } else if (value < root->value) {
          root->l = addNode(root->l, value);
        } else if (value > root->value) {
          root->r = addNode(root->r, value);
        } else {
          root->count += 1;
        }
        return root;
      }
      int searchT(Node* root, T value) {
        if (root == nullptr) {
          return 0;
        }
        while (true) {
          if (value > root->value) {
            root = root->r;
          } else if (value < root->value) {
            root = root->l;
          } else {
            return root->count;
          }
        }
      }
      int depth(Node* root) {
        if (!root) {
            return 0;
        }
        return 1 + std::max(depth(root->l), depth(root->r));
      }

   public:
      BST(): root(nullptr) {}
      void add(T value) {
        root = addNode(root, value);
      }
      int depth() {
        return depth(root) - 1;
      }
      int search(T value) {
        return searchT(root, value);
      }
      BST<std::string> createTree(const char* filename);
  };
#endif  // INCLUDE_BST_H_
