////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.cpp                                                            //
// The class HistoryMap                                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#include "history_map.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The constructor of HistoryMap                                              //
////////////////////////////////////////////////////////////////////////////////
HistoryMap::HistoryMap( const IDptr id ) : _HistoryMap() {
  id_ = id;
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

}

////////////////////////////////////////////////////////////////////////////////
// Merge with target history map                                              //
//                                                                            //
// Parameters:                                                                //
// that: target history map                                                   //
////////////////////////////////////////////////////////////////////////////////
void HistoryMap::Merge( HistoryMap* that ) {

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
void HistoryMap::Search( const ID id ) {

}

}
