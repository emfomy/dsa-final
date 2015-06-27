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
#include <iostream>

using namespace std;

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
  
  ninf = new SkipListNode;
  pinf = new SkipListNode;

  ninf->height = 1;
  ninf->left.push_back(nullptr);
  ninf->right.push_back(pinf);
  ninf->data_id = new ID;
  ninf->data_id[0] = '!';
  ninf->data_id[1] = '\0';

  pinf->height = 1;
  pinf->left.push_back(ninf);
  pinf->right.push_back(nullptr);
  pinf->data_id = new ID;
  pinf->data_id[0] = '{';
  pinf->data_id[1] = '\0';
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of SkipList                                                 //
////////////////////////////////////////////////////////////////////////////////
SkipList::~SkipList() {
  SkipListNode* temp = ninf;
  SkipListNode* temp_del;

  while (temp!=nullptr) {
    delete temp->data_account;
    temp_del = temp;
    temp = temp->right[0];
    delete temp_del;
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
bool SkipList::Find( const IDptr id, SkipListNode*& node ) {
  node = ninf;
  SkipListNode* next;
  int level = (int)max_height - 1;
  
  while (strcmp(id, node->data_id) != 0) {
    next = node->right[level];

    if (strcmp(id, next->data_id) < 0) {
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
void SkipList::Remove( const SkipListNode* node ) {
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
  SkipListNode* node;

  if (Find(id, node)) {
    return false;
  }

  num_node += 1;
  if (num_node > max_node) {
    max_node *= 2;

    ninf->height += 1;
    ninf->left.push_back(nullptr);
    ninf->right.push_back(pinf);

    pinf->height += 1;
    pinf->left.push_back(ninf);
    pinf->right.push_back(nullptr);

    max_height +=1;
  }

  SkipListNode* node_add = new SkipListNode;
  node_add->data_account = account;
  node_add->data_id = account->id();

  srand(time(NULL));
  int level = 0;
  do {
    while (level == node->height) {
      node = node->left[level-1];
    }

    node_add->left.push_back(node);
    node_add->right.push_back(node->right[level]);
    node->right[level]->left[level] = node_add;
    node->right[level] = node_add;

    level += 1;
  } while (level < (int)max_height && rand()%2 == 1);
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
struct SkipListNode* SkipList::Next( const SkipListNode* node ) {
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
struct SkipListNode* SkipList::Previous( const SkipListNode* node ) {
  return node->left[0];
}

}
