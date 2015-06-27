////////////////////////////////////////////////////////////////////////////////
// Data Structures and Algorithms - Final Project                             //
// account_map.cpp                                                            //
// The of class AccountMap                                                    //
//                                                                            //
// Author: kevin<skypole211221@gmail.com>                                     //
//         emfo<emfomy@gmail.com>                                             //
////////////////////////////////////////////////////////////////////////////////


#include "account_map.hpp"
#include <cstring>
#include "dsa.hpp"
#include "account.hpp"

////////////////////////////////////////////////////////////////////////////////
// The namespace dsa                                                          //
////////////////////////////////////////////////////////////////////////////////
namespace dsa {
bool string_cmp( const Account* a ,const Account* b ,void* NULL){
  string pa = *(a->IDptr) ;
  string pb = *(b->IDptr) ;
  return pa.compare(pb);
}
////////////////////////////////////////////////////////////////////////////////
// The class of a map of accounts                                             //
////////////////////////////////////////////////////////////////////////////////
class AccountMap {
 private:
  struct avl_table* avl_tree;
 public:
  ////////////////////////////////////////////////////////////////////////////
  // The constructor of AccountMap                                          //
  ////////////////////////////////////////////////////////////////////////////
  AccountMap(){
    avl_tree = avl_create( string_cmp ,NULL ,NULL)
  };
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
  class Account* At( const ID id ){
    const struct avl_node *p;
    for (p = avl_tree->avl_root; p != NULL; )
      {
      string pa = id ;
      string pb = *(p->data->IDptr) ;
      int cmp = pa.compare()
      if (cmp < 0)
        p = p->avl_link[0];
      else if (cmp > 0)
        p = p->avl_link[1];
      else /* |cmp == 0| */
        return p->avl_data;
      }
    return NULL;
  };

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
  class Account* At( const ID id, void** pit );

  ////////////////////////////////////////////////////////////////////////////
  // Display existing IDs                                                   //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Existing( const ID id );

  ////////////////////////////////////////////////////////////////////////////
  // Display unused IDs                                                     //
  //                                                                        //
  // Input Parameters:                                                      //
  // id: the ID                                                             //
  //                                                                        //
  // Ensure:                                                                //
  // Display best satisfying IDs to standand output, separated by ','       //
  ////////////////////////////////////////////////////////////////////////////
  void Unused( const ID id );

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
  void Find( const ID id, const class Account* account );

  ////////////////////////////////////////////////////////////////////////////
  // Insert an account                                                      //
  //                                                                        //
  // Parameters:                                                            //
  // account: the account                                                   //
  ////////////////////////////////////////////////////////////////////////////
  void Insert( class Account* account ){
    avl_insert(avl_tree, account);
  };

  ////////////////////////////////////////////////////////////////////////////
  // Erase an account of target iterator                                    //
  //                                                                        //
  // Parameters:                                                            //
  // it: the iterator                                                       //
  ////////////////////////////////////////////////////////////////////////////
  void Erase( void* it ){
    struct node* pit＝(node*) it ;
    avl_delete(avl_tree ,pit->data) ;
  };
};
}

// DSA_ACCOUNT_MAP_HPP_