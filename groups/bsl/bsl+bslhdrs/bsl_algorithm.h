// bsl_algorithm.h                                                    -*-C++-*-
#ifndef INCLUDED_BSL_ALGORITHM
#define INCLUDED_BSL_ALGORITHM

#ifndef INCLUDED_BSLS_IDENT
#include <bsls_ident.h>
#endif
BSLS_IDENT("$Id: $")

//@PURPOSE: Provide functionality of the corresponding C++ Standard header.
//
//@SEE_ALSO: package bsl+stdhdrs
//
//@DESCRIPTION: Provide types, in the 'bsl' namespace, equivalent to those
// defined in the corresponding C++ standard header.  Include the native
// compiler-provided standard header, and also directly include Bloomberg's
// implementation of the C++ standard type (if one exists).  Finally, place the
// included symbols from the 'std' namespace (if any) into the 'bsl' namespace.

#ifndef INCLUDED_BSLS_NATIVESTD
#include <bsls_nativestd.h>
#endif

#ifndef INCLUDED_BSLS_PLATFORM
#include <bsls_platform.h>
#endif

#include <algorithm>

namespace bsl {

    // Import selected symbols into bsl namespace
    using native_std::new_handler;
    using native_std::adjacent_find;
    using native_std::advance;
    using native_std::bad_alloc;
    using native_std::bidirectional_iterator_tag;
    using native_std::binary_search;
    using native_std::copy;
    using native_std::copy_backward;

    // 'count' and 'count_if' are provided in 'bslstl_algorithmworkaround' in
    // order to work-around the Sun standard library, libCstd.
    //
    // using native_std::count;
    // using native_std::count_if;

    using native_std::equal;
    using native_std::equal_range;
    using native_std::fill;
    using native_std::fill_n;
    using native_std::find;
    using native_std::find_end;
    using native_std::find_first_of;
    using native_std::find_if;
    using native_std::for_each;
    using native_std::forward_iterator_tag;
    using native_std::generate;
    using native_std::generate_n;
    using native_std::get_temporary_buffer;
    using native_std::includes;
    using native_std::inplace_merge;
    using native_std::input_iterator_tag;
    using native_std::iter_swap;
    using native_std::iterator;
    using native_std::lexicographical_compare;
    using native_std::lower_bound;
    using native_std::make_heap;
    using native_std::max;
    using native_std::max_element;
    using native_std::merge;
    using native_std::min;
    using native_std::min_element;
    using native_std::mismatch;
    using native_std::next_permutation;
    using native_std::nothrow;
    using native_std::nothrow_t;
    using native_std::nth_element;
    using native_std::output_iterator_tag;
    using native_std::partial_sort;
    using native_std::partial_sort_copy;
    using native_std::partition;
    using native_std::pop_heap;
    using native_std::prev_permutation;
    using native_std::push_heap;
    using native_std::random_access_iterator_tag;
    using native_std::random_shuffle;
    using native_std::remove;
    using native_std::remove_copy;
    using native_std::remove_copy_if;
    using native_std::remove_if;
    using native_std::replace;
    using native_std::replace_copy;
    using native_std::replace_copy_if;
    using native_std::replace_if;
    using native_std::return_temporary_buffer;
    using native_std::reverse;
    using native_std::reverse_copy;
    using native_std::rotate;
    using native_std::rotate_copy;
    using native_std::search;
    using native_std::search_n;
    using native_std::set_difference;
    using native_std::set_intersection;
    using native_std::set_new_handler;
    using native_std::set_symmetric_difference;
    using native_std::set_union;
    using native_std::sort;
    using native_std::sort_heap;
    using native_std::stable_partition;
    using native_std::stable_sort;
    using native_std::swap;
    using native_std::swap_ranges;
    using native_std::transform;
    using native_std::unique;
    using native_std::unique_copy;
    using native_std::upper_bound;

}  // close namespace bsl


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
