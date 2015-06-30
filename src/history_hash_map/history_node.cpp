////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_node.cpp                                                           //
// The class HistoryNode                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history_node.hpp"
#include <iostream>
#include "history.hpp"
#include "history_map.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of HistoryNode                                             //
//                                                                            //
// map:  the history map of this account                                      //
////////////////////////////////////////////////////////////////////////////////
HistoryNode::HistoryNode( HistoryMap* map ) : existing_(), deleted_() {
  this_map_  = map;
  that_node_ = nullptr;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of HistoryNode                                              //
////////////////////////////////////////////////////////////////////////////////
HistoryNode::~HistoryNode() {
  // Move existing to deleted
  if ( that_node_ ) {
    that_node_->that_node_ = nullptr;
    that_node_->deleted_.merge(that_node_->existing_);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Link with target history node                                              //
//                                                                            //
// Parameters:                                                                //
// that: target history node                                                  //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Link( HistoryNode* that ) {
  this->that_node_ = that;
  that->that_node_ = this;
}

////////////////////////////////////////////////////////////////////////////////
// Insert a transfer history                                                  //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to transfer                                     //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Insert( const Money money ) {
  this->existing_.emplace_back(new History(money, true));
  that_node_->existing_.emplace_back(new History(money, false));
}

////////////////////////////////////////////////////////////////////////////////
// Display all history with target ID                                         //
//                                                                            //
// Parameters:                                                                //
// id: target ID                                                              //
//                                                                            //
// Ensure:                                                                    //
// Display 'no record' if no record exists                                    //
// Display all history with target ID to standand output, line by line        //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Display( const ID& id ) {
  if ( existing_.empty() && deleted_.empty() ) {
    cout << "no record" << endl;
  } else {
    for ( auto& ptr : deleted_ ) {
      ptr->Display(id);
    }
    for ( auto& ptr : existing_ ) {
      ptr->Display(id);
    }
  }
}

}
