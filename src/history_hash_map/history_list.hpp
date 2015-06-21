////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// history_list.hpp                                                           //
// The header file of class HistoryList                                       //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_HISTORY_LIST_HPP_

#define DSA_HISTORY_LIST_HPP_

#include <vector>
#include "dsa.hpp"
#include "history.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

typedef std::vector<History> _HistoryList;

////////////////////////////////////////////////////////////////////////////////
// The class of a list of transfer history                                    //
////////////////////////////////////////////////////////////////////////////////
class HistoryList : private _HistoryList {
 public:
  // Constructor
  HistoryList();

  // Destructor
  ~HistoryList();
};

}

#endif  // DSA_HISTORY_LIST_HPP_
