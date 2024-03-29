////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.hpp                                                            //
// The header file of class AccountMap                                        //
//                                                                            //
// Author: kevin<skypole211221@gmail.com>                                     //
//         emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////

#ifndef DSA_ACCOUNT_MAP_HPP_

#define DSA_ACCOUNT_MAP_HPP_

extern "C"{
  #include "avl.h"
}
#include "dsa.hpp"
#include <string>
#include <vector>

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {
////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class Exist{ 
 public:
  int key ;
  ID id;
};

class AccountMap {
 private:
  struct avl_table* avl_tree;

 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of AccountMap                                          //
  ////////////////////////////////////////////////////////////////////////////
  AccountMap();

  ////////////////////////////////////////////////////////////////////////////
  // The destructor of AccountMap                                           //
  ////////////////////////////////////////////////////////////////////////////
  ~AccountMap();

  ////////////////////////////////////////////////////////////////////////////
  // Access account by its ID                                               //
  //                                                                        //
  // Parameters:                                                            //
  // id: the ID                                                             //
  //                                                                        //
  // Return Value:                                                          //
  // Target account if exists, null pointer if not exists                   //
  ////////////////////////////////////////////////////////////////////////////
  class Account* At( const ID& id );

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
  class Account* At( const ID& id, void** pit );

  ////////////////////////////////////////////////////////////////////////////
  // Display existing IDs                                                   //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Existing( const ID& id );
  void ExistingInt( const ID& id , std::vector<Exist>& , struct avl_node*);
  ////////////////////////////////////////////////////////////////////////////
  // Display unused IDs                                                     //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Unused( const ID& id );

  ////////////////////////////////////////////////////////////////////////////
  // Find existing IDs that matches the wildcard ID                         //
  //   but is different from target account                                 //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the wildcard ID                                                    //
  //                                                                        //
  // Ensure:                                                                //
  // Display all satisfying IDs to standand output,                         //
  //   separated by ',' in ascending dictionary order                       //
  ////////////////////////////////////////////////////////////////////////////
  void Find( const ID& id, const class Account* account );
  void FindInt( 
        const ID& id, const Account* account, 
          avl_node* p,std::vector<ID>& record );
  
  ////////////////////////////////////////////////////////////////////////////
  // Construct and insert an account                                        //
  //                                                                        //
  // Parameters:                                                            //
  // id:        the ID                                                      //
  // plaintext: the plain password                                          //
  //                                                                        //
  // Return Value:                                                          //
  // true if insert succeeded, false if the ID already exists               //
  ////////////////////////////////////////////////////////////////////////////
  bool Emplace( const ID& id, const Plaintext& plaintext );

  ////////////////////////////////////////////////////////////////////////////
  // Erase an account of target iterator                                    //
  //                                                                        //
  // Parameters:                                                            //
  // it: the iterator                                                       //
  ////////////////////////////////////////////////////////////////////////////
  void Erase( void* it );
};

}

#endif  // DSA_ACCOUNT_MAP_HPP_
