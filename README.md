# DSA_Final
Data Structures and Algorithms - Final Project

## Programming

### Git
* Uses [GitHub](https://github.com/NTUDSA2014/dsa15_final12) to host.
* Uses [git-flow](http://nvie.com/posts/a-successful-git-branching-model/) to control branches.

### C++
* Uses [Google C++ Style Guide](http://google-styleguide.googlecode.com/svn/trunk/cppguide.html) but uses `.cpp` and `.hpp` as extensions.

## Install
Compile with `make ACCOUNT=<account_map_type>`. The defalut value of `ACCOUNT` is `HASHMAP`.
* `ACCOUNT=AVLTREE`: use AVL tree for `AccountMap`.
* `ACCOUNT=HASHMAP`: use hash map for `AccountMap`.
* `ACCOUNT=SKIPLIST`: use skip list for `AccountMap`.

## Directories
Make sure $(DSA) is set to the root of this project

### `/src`
The source files (`*.cpp` and `*.hpp`).

#### `/src/main`
The main files (`final_project.cpp`).

#### `/src/core`
The core files.

#### `/src/account_void`
The source code of `AccountMap` without implementation.

#### `/src/account_avl_tree`
The implementation of `AccountMap` using AVL tree.

#### `/src/account_hash_map`
The implementation of `AccountMap` using hash map.

#### `/src/account_skip_list`
The implementation of `AccountMap` using skip list.

#### `/src/history_void`
The source code of `HistoryMap` without implementation.

#### `/src/history_hash_map`
The implementation of `HistoryMap` using hash map.

### `/lib`
The library files (`*.lib`).

### `/include`
The header files for library (`*.hpp`).

### `/interface`
The interface for library (`*.hpp`).

### `/doc`
The report (`*.pdf`).

### `/ext`
Third-party libraries.

#### `/ext/openssl`
* [OpenSSL cryptographic library](https://www.openssl.org/docs/crypto/crypto.html): uses for MD5 cryptography.

#### `/ext/gnu_avl`
* [GNU libavl](http://adtinfo.org/): uses for AVL tree.
