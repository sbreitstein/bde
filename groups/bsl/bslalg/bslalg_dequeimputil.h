// bslalg_dequeimputil.h                                              -*-C++-*-
#ifndef INCLUDED_BSLALG_DEQUEIMPUTIL
#define INCLUDED_BSLALG_DEQUEIMPUTIL

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide basic parameters and primitive data structures for deques.
//
//@CLASSES:
//  bslalg::DequeImpUtil: deque parameters and primitive data structures
//
//@SEE_ALSO: bslalg_scalarprimitives, bslalg_arrayprimitives, bslalg_typetraits
//
//@DESCRIPTION: This component provides primitive data structures for
// implementing a deque knowing only its value type and the number of objects
// in a block.  Conceptually, a deque is an array of blocks pointers, each
// block capable of containing a fixed number of objects.  An element in the
// deque is identified by an iterator which consists of a pointer to the block
// pointer array, and a pointer to a value.  A deque implementation is
// parameterized by the 'VALUE_TYPE' and a 'BLOCK_LENGTH' (fixed number of
// objects in a block).  'bslalg::DequeImpUtil' provides a namespace for the
// following types and constants:
//..
//  Type                   Short description
//  ----                   -----------------
//  ValueType              An alias for the templatized 'VALUE_TYPE'
//  Block                  An array (of length 'BLOCK_LENGTH') of 'ValueType'
//  BlockPtr               An alias for a pointer to a block
//
//  Constant               Short description
//  --------               -----------------
//  BLOCK_BYTES            Number of bytes in a block
//  BLOCK_ARRAY_PADDING    Number of empty blocks to keep at both ends of the
//                         block array pointer (one on each side).
//..
//
// The picture is as follows:
//..
//  +-----+-----+-----+-----+-----+-----+-----+-----+
//  |  *  |  *  |  *  |  *  |  *  |  *  |  *  |  *  |  (BlockPtr array)
//  +-----+-----+--|--+--|--+--|--+--|--+-----+-----+
//                 |     |     |     |                     Block
//                 |     |     |     |  +---+---+---+---+---+---+---+---+
//                 |     |     |     `--| V | W | X | Y | Z |   |   |   |
//                 |     |     |        +---+---+---+---+---+---+---+---+
//                 |     |     |                      Block
//                 |     |     |  +---+---+---+---+---+---+---+---+
//                 |     |     `--| N | O | P | Q | R | S | T | U |
//                 |     |        +---+---+---+---+---+---+---+---+
//                 |     |                      Block
//                 |     |  +---+---+---+---+---+---+---+---+
//                 |     `--| F | G | H | I | J | K | L | M |
//                 |        +---+---+---+---+---+---+---+---+
//                 |                      Block
//                 |  +---+---+---+---+---+---+---+---+
//                 `--|   |   |   | A | B | C | D | E |
//                    +---+---+---+---+---+---+---+---+
//..
// Depicted above is a deque consisting of an array of eight block pointers,
// only four actually used to point to blocks of eight elements.  In the first
// block, the first three elements are uninitialized, and the twenty six
// elements follow in sequence across the different blocks.  The value of the
// corresponding deque would be '[ A, B, C, ... X, Y, Z ]', its logical length
// 26, and its capacity would be 19 (the minimum number of prepend/append to
// force a reallocation of the block pointer array).
//
///Usage
///-----
// This component is for use by the 'bslalg' package.  Other clients should use
// the STL deque (in header '<deque>').

#ifndef INCLUDED_BSLSCM_VERSION
#include <bslscm_version.h>
#endif

namespace BloombergLP {

namespace bslalg {

                           // ==============
                           // class DequeImp
                           // ==============

template <class VALUE_TYPE, int BLOCK_LENGTH>
struct DequeImpUtil {
    // This 'struct', parameterized by the 'VALUE_TYPE' and a 'BLOCK_LENGTH',
    // provides the various parameters of the deque implementation.

    // PUBLIC CONSTANTS
    enum { BLOCK_BYTES         = BLOCK_LENGTH * sizeof(VALUE_TYPE) };
        // Actual number of bytes in a block.

    enum { BLOCK_ARRAY_PADDING = 2 };
        // Minimum number of (allocated) empty blocks to keep at both ends of
        // the block array pointer (one on each side of the deque).

    // PUBLIC TYPES
    typedef VALUE_TYPE  ValueType;
        // 'ValueType' is an alias for the 'VALUE_TYPE' provided as first
        // template parameter to this class.

    struct Block {
        // A block of one or more data objects.  A deque will be organized as a
        // sequence of blocks.

        VALUE_TYPE d_data[BLOCK_LENGTH];
    };

    typedef Block *BlockPtr;
        // Pointer to a block.  A deque will own an array of those.
};

}  // close package namespace


}  // close enterprise namespace

#endif

// ----------------------------------------------------------------------------
// Copyright (C) 2013 Bloomberg L.P.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------- END-OF-FILE ----------------------------------
