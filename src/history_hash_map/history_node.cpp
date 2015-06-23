////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_node.cpp                                                           //
// The class HistoryNode                                                      //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history_node.hpp"
#include "history.hpp"

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
  // Change sign
  if ( this->sign_ ) {
    for ( auto& ptr : *existing_ ) {
      ptr->money_ = -(ptr->money_);
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
    this->sign_ = true;
    that->sign_ = false;
  }
}

////////////////////////////////////////////////////////////////////////////////
// Insert a transfer history                                                  //
//                                                                            //
// Parameters:                                                                //
// money: the amount of money to transfer                                     //
////////////////////////////////////////////////////////////////////////////////
void HistoryNode::Insert( const Money money ) {
  this->existing_->emplace_back(new History(sign_ ? money : -money));
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

}

}
