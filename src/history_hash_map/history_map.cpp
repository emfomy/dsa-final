////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.cpp                                                            //
// The class HistoryMap                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history_map.hpp"
#include <iostream>
#include "history.hpp"
#include "history_node.hpp"

using namespace std;

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of HistoryMap                                              //
//                                                                            //
// Parameters:                                                                //
// id: target ID                                                              //
////////////////////////////////////////////////////////////////////////////////
HistoryMap::HistoryMap( const IDptr id ) : _HistoryMap() {
  id_ = id;
  (*this)[id_].reset(new HistoryNode(this));
}

////////////////////////////////////////////////////////////////////////////////
// The destructor of HistoryMap                                               //
////////////////////////////////////////////////////////////////////////////////
HistoryMap::~HistoryMap() {
}

////////////////////////////////////////////////////////////////////////////////
// Insert a transfer history from this account to target account              //
//                                                                            //
// Parameters:                                                                //
// that: the history map of target account                                    //
// money: the amount of money to transfer                                     //
////////////////////////////////////////////////////////////////////////////////
void HistoryMap::Insert( HistoryMap* that, const Money money ) {
  this->Link(that)->Insert(money);
}

////////////////////////////////////////////////////////////////////////////////
// Merge with target history map                                              //
//                                                                            //
// Parameters:                                                                //
// that: target history map                                                   //
////////////////////////////////////////////////////////////////////////////////
void HistoryMap::Merge( HistoryMap* that ) {
  // Merge *-that history into *-this history
  for ( auto& pair23 : *that ) {
    auto node32 = pair23.second->that_node_;
    if ( !node32 ) {
      auto map3 = pair23.second->that_node_->this_map_;
      auto node31 = map3->Link(this);
      node31->existing_.merge(node32->existing_);
    }
  }

  // Merge that-* history into this-* history
  for ( auto& pair23 : *that ) {
    auto it13 = find(pair23.first);
    it13->second->existing_.merge(pair23.second->existing_);
    it13->second->deleted_.merge(pair23.second->deleted_);
    pair23.second->that_node_ = nullptr;
  }
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
void HistoryMap::Search( const IDptr id ) {
  auto it = find(id);
  if ( it == end() ) {
    cout << "no record" << endl;
  } else {
    it->second->Display(id);
  }
}

////////////////////////////////////////////////////////////////////////////////
// Create a history node of this history map and target history map           //
//                                                                            //
// Parameters:                                                                //
// that: target history map                                                   //
//                                                                            //
// Return Value:                                                              //
// the history node                                                           //
////////////////////////////////////////////////////////////////////////////////
HistoryNode* HistoryMap::Link( HistoryMap* that ) {
  // Insert node in this map 
  auto& uniptr12 = (*this)[that->id_];
  if ( this != that ) {
    if ( !uniptr12 ) {
      uniptr12.reset(new HistoryNode(this));
    }

    if ( !uniptr12->that_node_ ) {
      // Insert node in that map
      auto& uniptr21 = (*that)[this->id_];
      if ( !uniptr21 ) {
        uniptr21.reset(new HistoryNode(that));
      }

      // Link two nodes
      uniptr12->Link(uniptr21.get());
    }
  }

  return uniptr12.get();
}

}
