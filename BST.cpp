#include "BST.h"
#include <iostream>

using std::cout;
using std::endl;

template <typename T>
BST<T>::BST() {
  root = 0;
}

template <typename T>
BST<T>::~BST() {
  
}


template <typename T>
bool BST<T>::find(T v) {
  Node<T>* temp = new Node<T>(v);
  root = temp;  
  return true;
}

template <typename T>
void BST<T>::insert(T v) {
  Node<T>* temp = new Node<T>(v);
  Node<T>** curr = &root;

  while (*curr != 0) {
    if (v < (*curr)->getValue()) {
      curr = &((*curr)->getLeftChild());
    } else if (v > (*curr)->getValue()) {
      curr = &((*curr)->getRightChild());
    }
  }
  *curr = temp;
}

template <typename T>
void BST<T>::remove(T v) {
  Node<T>** curr = &root;
  while(*curr != 0 && (*curr)->getValue() != v){
    if(v < (*curr)->getValue()){
      curr = &(*curr)->getLeftChild();
    }
    else if(v > (*curr)->getValue()){
      curr = &(*curr)->getRightChild();
    }
  }
  if(*curr != 0){
    Node<T>* ntr = *curr;
    if(ntr->getRightChild() == 0 && ntr->getLeftChild() == 0){
      *curr = 0;
    }
    else if(ntr->getRightChild() == 0){
      *curr = (*curr)->getLeftChild();
    }
    else if(ntr->getLeftChild() == 0){
      *curr = (*curr)->getRightChild();
    }
    else{
      Node<T>* ios = ntr->getRightChild();
      while(ios->getLeftChild() != 0){
	ios = ios->getLeftChild();
      }
      ios->setLeftChild(*(ntr->getLeftChild()));
      *curr = (*curr)->getRightChild();
    }
    delete ntr;
  }
}

template <typename T>
void BST<T>::print() {
  traversalPrint(root);
}

template <typename T>
void BST<T>::traversalPrint(Node<T>* root) {
  if(root != 0) {
    traversalPrint(root->getLeftChild());
    std::cout << root->getValue() << std::endl;
    traversalPrint(root->getRightChild());
  }
}

template class BST<int>;
template class BST<double>;
template class BST<std::string>;
