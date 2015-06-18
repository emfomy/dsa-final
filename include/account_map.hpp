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
  // Parameters:                                                            //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // Target account if exists, null pointer if not exists                   //
  ////////////////////////////////////////////////////////////////////////////
  Account* At( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Access account by its ID                                               //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Output Parameters:                                                     //
  // pit: the pointer of iterator                                           //
  //                                                                        //
  // Return Value:                                                          //
  // Target account if exists, null pointer if not exists                   //
  ////////////////////////////////////////////////////////////////////////////
  Account* At( const ID id, void** pit );

  ////////////////////////////////////////////////////////////////////////////
  // Find existing accounts by ID                                           //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Output Parameters:                                                     //
  // ids: an array of 10 best existing IDs                                  //
  ////////////////////////////////////////////////////////////////////////////
  void Existing( const ID id, ID* ids );

  ////////////////////////////////////////////////////////////////////////////
  // Find unused accounts by ID                                             //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Output Parameters:                                                     //
  // ids: an array of 10 best unused IDs                                    //
  ////////////////////////////////////////////////////////////////////////////
  void Unused( const ID id, ID* ids );

  ////////////////////////////////////////////////////////////////////////////
  // Construct and insert an account with target ID                         //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID                                                             //
  ////////////////////////////////////////////////////////////////////////////
  void Emplace( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Erase an account of target iterator                                    //
  //                                                                        //
  // Parameters:                                                            //
  // it: the iterator                                                       //
  ////////////////////////////////////////////////////////////////////////////
  void Erase( void* it );
};

}

#endif  // DSA_INC_ACCOUNT_MAP_HPP_
