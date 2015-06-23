////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// skip_list_for_account.hpp                                                  //
// The interface of class SkipList                                            //
//                                                                            //
// Author: daivdzan<davidzan830@gmail.com>                                    //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_SKIP_LIST_FOR_ACCOUNT_HPP_

#define DSA_SKIP_LIST_FOR_ACCOUNT_HPP_

#include "dsa.hpp"
#include "account.hpp"
#include <vector>
#include <cstring>

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class SkipList {
 private:
  // Current maxinum number of nodes
  size_t max_node;

  // Current number of nodes
  size_t num_node;

  // Current maximum height(start at 1, will be increas when max_node increase)
  size_t max_height;

  // Node of skip list
  struct Node {
    // Height of this node
    int height;

    // left[i]: pointer to left side at level i (start at 0)
    vector<node*> left;

    // right[i]: pointer to right side at level i
    vector<node*> right;

    // Account data in this node
    Account* data_account;

    // Start pointer of ID in the data_account
    IDptr data_id;
  };

  // -inf node, which has id = "!"
  Node ninf;

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
  bool Find( const IDptr id, Node* node );

  ////////////////////////////////////////////////////////////////////////////
  // Remove target node in skip list                                        //
  //                                                                        //
  // Parameters:                                                            //
  // node: the pointer of the target node                                   //
  //                                                                        //
  // Ensure:                                                                //
  // Remove the target node in the skip list                                //
  ////////////////////////////////////////////////////////////////////////////
  void Remove( const Node* node );

  ////////////////////////////////////////////////////////////////////////////
  // Insert target account into a new node with the key id                  //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID used as key(usually equal to the ID of target account)      //
  // account: the pointer of the target account                             //
  //                                                                        //
  // Ensure:                                                                //
  // Add a new node with id as key and account as content                   //
  ////////////////////////////////////////////////////////////////////////////
  void Insert( const IDptr id, Account* account );

  ////////////////////////////////////////////////////////////////////////////
  // Get Node* of the next node of target node in the list                  //
  //                                                                        //
  // Parameters:                                                            //
  // node: the pointer of the target node                                   //
  //                                                                        //
  // Return Value:                                                          //
  // The pointer of next node, null pointer if the next node is +inf        //
  ////////////////////////////////////////////////////////////////////////////
  Node* Next( const Node* node );

  ////////////////////////////////////////////////////////////////////////////
  // Get Node* of the previous node of target node in the list              //
  //                                                                        //
  // Parameters:                                                            //
  // node: the pointer of the target node                                   //
  //                                                                        //
  // Return Value:                                                          //
  // The pointer of revious node, null pointer if this node is -inf         //
  ////////////////////////////////////////////////////////////////////////////
  Node* Previous( const Node* node );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
