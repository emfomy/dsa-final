////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_map.hpp                                                            //
// The interface of class HistoryMap                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_INC_HISTORY_MAP_HPP_

#define DSA_INC_HISTORY_MAP_HPP_

#include "dsa.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a map of historys                                             //
////////////////////////////////////////////////////////////////////////////////
class HistoryMap {
 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of HistoryMap                                          //
  ////////////////////////////////////////////////////////////////////////////
  HistoryMap( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of HistoryMap                                           //
  ////////////////////////////////////////////////////////////////////////////
  ~HistoryMap();

  ////////////////////////////////////////////////////////////////////////////
  // Merge with target history map                                          //
  //                                                                        //
  // Parameters:                                                            //
  // that: target history map                                               //
  ////////////////////////////////////////////////////////////////////////////
  void Merge( HistoryMap* that );

  ////////////////////////////////////////////////////////////////////////////
  // Display all history with target ID                                     //
  //                                                                        //
  // Parameters:                                                            //
  // id: target ID                                                          //
  //                                                                        //
  // Ensure:                                                                //
  // Display 'no record' if no record exists                                //
  // Display all history with target ID to standand output, line by line    //
  ////////////////////////////////////////////////////////////////////////////
  void Search( const ID id );
};

}

#endif  // DSA_INC_ACCOUNT_MAP_HPP_
