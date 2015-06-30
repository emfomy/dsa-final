////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// skip_list_for_account.hpp                                                  //
// The interface of class SkipList                                            //
//                                                                            //
// Author: daivdzan<davidzan830@gmail.com>                                    //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_SKIP_LIST_FOR_ACCOUNT_HPP_

#define DSA_SKIP_LIST_FOR_ACCOUNT_HPP_

#include <vector>
#include <cstring>
#include "dsa.hpp"
#include "account.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

// Node of skip list
struct SkipListNode {
  // Height of this node
  int height;

  // left[i]: pointer to left side at level i (start at 0)
  std::vector<SkipListNode*> left;

  // right[i]: pointer to right side at level i
  std::vector<SkipListNode*> right;

  // Account data in this node
  Account* data_account = nullptr;

  // Start pointer of ID in the data_account
  ID data_id;

  ~SkipListNode () {
    delete data_account;
  }
};

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class SkipList {
 protected:
  // Current maxinum number of nodes
  size_t max_node;

  // Current number of nodes
  size_t num_node;

  // Current maximum height(start at 1, will be increas when max_node increase)
  size_t max_height;

  // -inf node, which has id = "!"
  SkipListNode* ninf;

  // +inf node, which has id = "{"
  SkipListNode* pinf;
 
 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of SkipList                                            //
  ////////////////////////////////////////////////////////////////////////////
  SkipList();

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of SkipList                                             //
  ////////////////////////////////////////////////////////////////////////////
  ~SkipList();

  ////////////////////////////////////////////////////////////////////////////
  // Get Node* for correspond id                                            //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Output Parameters:                                                     //
  // node: the pointer of target if exit, otherwise the previous one that   //
  //       assume id exits in this skip list.                               //
  //                                                                        //
  // Return Value:                                                          //
  // true if exist, false if not                                            //
  ////////////////////////////////////////////////////////////////////////////
  bool Find( const ID& id, SkipListNode*& node );

  ////////////////////////////////////////////////////////////////////////////
  // Remove target node in skip list (without the content of account)       //
  //                                                                        //
  // Parameters:                                                            //
  // node: the pointer of the target node                                   //
  //                                                                        //
  // Ensure:                                                                //
  // Remove the target node in the skip list                                //
  ////////////////////////////////////////////////////////////////////////////
  void Remove( const SkipListNode* node );

  ////////////////////////////////////////////////////////////////////////////
  // Insert target account into a new node with the key id                  //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID used as key(usually equal to the ID of target account)      //
  // plaintext: the plain password of the account                           //
  //                                                                        //
  // Retrun Value:                                                          //
  // true if successfully add node, false if id already exits               //
  ////////////////////////////////////////////////////////////////////////////
  bool Insert( const ID& id, const Plaintext& plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // Get Node* of the next node of target node in the list                  //
  //                                                                        //
  // Parameters:                                                            //
  // node: the pointer of the target node                                   //
  //                                                                        //
  // Return Value:                                                          //
  // The pointer of next node, null pointer if this node is +inf            //
  ////////////////////////////////////////////////////////////////////////////
  SkipListNode* Next( const SkipListNode* node );

  ////////////////////////////////////////////////////////////////////////////
  // Get Node* of the previous node of target node in the list              //
  //                                                                        //
  // Parameters:                                                            //
  // node: the pointer of the target node                                   //
  //                                                                        //
  // Return Value:                                                          //
  // The pointer of revious node, null pointer if this node is -inf         //
  ////////////////////////////////////////////////////////////////////////////
  SkipListNode* Previous( const SkipListNode* node );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
