////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_node.hpp                                                           //
// The header file of class HistoryNode                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORY_NODE_HPP_

#define DSA_HISTORY_NODE_HPP_

#include <list>
#include <memory>
#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The unique pointer of History                                              //
////////////////////////////////////////////////////////////////////////////////
typedef std::unique_ptr<class History> HistoryUnique;

////////////////////////////////////////////////////////////////////////////////
// The list of History                                                        //
////////////////////////////////////////////////////////////////////////////////
typedef std::list<HistoryUnique> HistoryList;

////////////////////////////////////////////////////////////////////////////////
// The class of a node of transfer history                                    //
////////////////////////////////////////////////////////////////////////////////
class HistoryNode {
  friend class HistoryMap;

 private:
  // The history map of this account
  class HistoryMap* this_map_;

  // The history const of another account
  class HistoryNode* that_node_;

  // The history list of existing account
  HistoryList existing_;

  // The history list of deleted account
  HistoryList deleted_;

 public:
  // Constructor
  HistoryNode( class HistoryMap* map );

  // Destructor
  ~HistoryNode();

  // Link with target history node
  void Link( class HistoryNode* that );

  // Insert a transfer history
  void Insert( const Money money );

  // Merge with target history node
  void Merge( class HistoryNode* that );

  // Display all history
  void Display( const IDptr id );
};

}

#endif  // DSA_HISTORY_NODE_HPP_
