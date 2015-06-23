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
// node: the history const of another account                                 //
// sign: the sign of money                                                    //
////////////////////////////////////////////////////////////////////////////////
HistoryNode::HistoryNode( HistoryMap* map ) {
  this_map_  = map;
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of HistoryNode                                              //
////////////////////////////////////////////////////////////////////////////////
HistoryNode::~HistoryNode() {
  // Change transfer direction
  if ( this->direction_ ) {
    for ( auto& ptr : *existing_ ) {
      ptr->direction_ = !(ptr->direction_);
    }
  }

  // Move existing to deleted
  if ( that_node_ ) {
    that_node_->that_node_ = nullptr;
    if( that_node_->deleted_ ) {
      that_node_->deleted_->splice(
          that_node_->deleted_->begin(),
          *that_node_->existing_
      );
      delete that_node_->existing_;
    } else {
      that_node_->deleted_ = that_node_->existing_;
      that_node_->existing_ = nullptr;
    }
  } else {
    delete existing_;
    delete deleted_;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Link with target history node                                              //
//                                                                            //
// Parameters:                                                                //
// that: target history node                                                  //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Link( HistoryNode* that ) {
  if ( that_node_ ) {
    this->that_node_ = that;
    that->that_node_ = this;
    this->existing_ = new HistoryList();
    that->existing_ = this->existing_;
    this->direction_ = true;
    that->direction_ = false;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Insert a transfer history                                                  //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to transfer                                     //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Insert( const Money money ) {
  this->existing_->emplace_back(new History(money, direction_));
}

////////////////////////////////////////////////////////////////////////////////
// Merge with target history node                                             //
//                                                                            //
// Parameters:                                                                //
// that: target history node                                                  //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Merge( HistoryNode* that ) {

}

////////////////////////////////////////////////////////////////////////////////
// Display all history                                                        //
//                                                                            //
// Ensure:                                                                    //
// Display 'no record' if no record exists                                    //
// Display all history with target ID to standand output, line by line        //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Display() {
  if ( existing_->empty() && deleted_->empty() ) {
    cout << "no record" << endl;
  } else {
    IDptr& id = that_node_->this_map_->id_;
    for ( auto& ptr : *deleted_ ) {
      cout << ((direction_ == ptr->direction_) ? "To " : "From ")
           << id << ' ' << ptr->money_ << endl;
    }
    for ( auto& ptr : *existing_ ) {
      cout << ((direction_ == ptr->direction_) ? "To " : "From ")
           << id << ' ' << ptr->money_ << endl;
    }
  }
}

}
