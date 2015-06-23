////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// skip_list_for_account.cpp                                                  //
// The class SkipList                                                         //
//                                                                            //
// Author: daivdzan<davidzan830@gmail.com>                                    //
////////////////////////////////////////////////////////////////////////////////

#include "dsa.hpp"
#include "skip_list_for_account.hpp"
#include "account.hpp"
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of SkipList                                                //
////////////////////////////////////////////////////////////////////////////////
SkipList::SkipList() {
  max_node = 1;
  num_node = 0;
  max_height = 1;
  
  ninf = new Node;
  inf = new Node;

  ninf->height = 1;
  ninf->left[0] = nullptr;
  ninf->right[0] = pinf;
  ninf->data_id = new ID;
  strcpy(ninf.IDptr, "!");

  pinf->height = 1;
  pinf->left[0] = ninf;
  pinf->right[0] = nullptr;
  pinf->data_id = new ID;
  strcpy(ninf.IDptr, "{");
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of SkipList                                                 //
////////////////////////////////////////////////////////////////////////////////
SkipList::~SkipList() {
  Node* temp;
  while (temp!=nullptr) {
    delete temp->data_accout;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Get Node* for correspond id                                                //
//                                                                            //
// Input Parameters:                                                          //
// id: the ID                                                                 //
//                                                                            //
// Output Parameters:                                                         //
// node: the pointer of target if exit, otherwise the previous one that       //
//       assume id exits in this skip list.                                   //
//                                                                            //
// Return Value:                                                              //
// true if exist, false if not                                                //
////////////////////////////////////////////////////////////////////////////////
bool SkipList::Find( const IDptr id, Node* node ) {
  node = ninf;
  Node* next;
  int level = (int)max_height - 1;
  
  while (strcmp(id, node->data_id) != 0) {
    next = node->right[level];
    if (strcmp(id, next->data_id) > 0) {
      if (level == 0) {
        return false;
      } else {
        level -= 1;
      }
    } else {
      node = next;
    }
  }

  return true;
}

////////////////////////////////////////////////////////////////////////////////
// Remove target node in skip list (without the content of account)           //
//                                                                            //
// Parameters:                                                                //
// node: the pointer of the target node                                       //
//                                                                            //
// Ensure:                                                                    //
// Remove the target node in the skip list                                    //
////////////////////////////////////////////////////////////////////////////////
void SkipList::Remove( const Node* node ) {
  for (int i = 0; i < node->height; ++i) {
    node->left[i]->right[i] = node->right[i];
    node->right[i]->left[i] = node->left[i];
  }

  delete node;
}

////////////////////////////////////////////////////////////////////////////////
// Insert target account into a new node with the key id                      //
//                                                                            //
// Parameters:                                                                //
// id: the ID used as key(usually equal to the ID of target account)          //
// account: the pointer of the target account                                 //
//                                                                            //
// Retrun Value:                                                              //
// true if successfully add node, false if id already exits                   //
////////////////////////////////////////////////////////////////////////////////
bool SkipList::Insert( const IDptr id, Account* account ) {
  Node* node;

  if (Find(id, node)) {
    return false;
  }

  num_node += 1;
  if (num_node > max_node) {
    max_node *= 2;

    int level = ninf->height;
    ninf->height += 1;
    ninf->left[level] = nullptr;
    ninf->right[level] = pinf;

    pinf->height += 1;
    pinf->left[level] = ninf;
    pinf->right[level] = nullptr;

    max_height +=1;
  }
  
  Node* node_add = new Node;
  node_add->data_accout = account;

  srand(time(NULL));
  int level = 0;
  do {
    while (level == node->height) {
      node = node->left[level-1];
    }

    node_add->left[level] = node;
    node_add->right[level] = node->right[level];
    node->right[level]->left[level] = node_add;
    node->right[level] = node_add;

    level += 1;
  } while (level < max_height && rand()%2 == 1);
  node_add->height = level;

  return true;
}

////////////////////////////////////////////////////////////////////////////////
// Get Node* of the next node of target node in the list                      //
//                                                                            //
// Parameters:                                                                //
// node: the pointer of the target node                                       //
//                                                                            //
// Return Value:                                                              //
// The pointer of next node, null pointer if this node is +inf                //
////////////////////////////////////////////////////////////////////////////////
Node* SkipList::Next( const Node* node ) {
  return node->right[0];
}

////////////////////////////////////////////////////////////////////////////////
// Get Node* of the previous node of target node in the list                  //
//                                                                            //
// Parameters:                                                                //
// node: the pointer of the target node                                       //
//                                                                            //
// Return Value:                                                              //
// The pointer of revious node, null pointer if this node is -inf             //
////////////////////////////////////////////////////////////////////////////////
Node* SkipList::Previous( const Node* node ) {
  return node->left[0];
}
