////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.hpp                                                            //
// The interface of class AccountMap                                          //
//                                                                            //
// Author: emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_INC_ACCOUNT_MAP_HPP_

#define DSA_INC_ACCOUNT_MAP_HPP_

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {

////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap
{
 public:
  AccountMap(){};
  ~AccountMap(){};

  ////////////////////////////////////////////////////////////////////////////
  // Access account by its ID                                               //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // The target account if exists, null pointer if not exists               //
  ////////////////////////////////////////////////////////////////////////////
  Account* At( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Access account by its ID                                               //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // The iterator of target account if exists, null pointer if not exists   //
  ////////////////////////////////////////////////////////////////////////////
  void* Find( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Find existing accounts by ID                                           //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // The best 10 existing IDs                                               //
  ////////////////////////////////////////////////////////////////////////////
  ID* Existing( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Find unused accounts by ID                                             //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // An array of the best 10 unused IDs                                     //
  ////////////////////////////////////////////////////////////////////////////
  ID* Unused( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Construct and insert an account with target ID                         //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // true if the ID is unused, false if the ID already exists               //
  ////////////////////////////////////////////////////////////////////////////
  bool Emplace( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Erase an account of target iterator                                    //
  //                                                                        //
  // Parameters:                                                            //
  // it: the iterator                                                       //
  //                                                                        //
  // Ensure:                                                                //
  // Erase the account of target iterator                                   //
  ////////////////////////////////////////////////////////////////////////////
  void Erase( void* it );
};

}

#endif  // DSA_INC_ACCOUNT_MAP_HPP_
