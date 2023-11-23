#include "suite.h"

#include <gtest/gtest.h>
#include <filesystem>

TEST_F(filesystem_suite, create_directory_error)
{
    try {
        std::filesystem::create_directory(dirname / "parent/child");
        ASSERT_FALSE(true);
    }
    catch (const std::filesystem::filesystem_error&) {}

    // this would be more to the point ...

    //     ASSERT_THROW(std::filesystem::create_directory(dirname / "parent/child"),
    //                  std::filesystem::filesystem_error);

    // ... but (using -O3) ...

    // In file included from /usr/include/c++/12/ios:40,
    //                  from /usr/include/c++/12/ostream:38,
    //                  from /usr/include/c++/12/bits/unique_ptr.h:41,
    //                  from /usr/include/c++/12/memory:76,
    //                  from /home/jfasch/work/jfasch-home/googletest/googletest/include/gtest/gtest.h:55,
    //                  from /home/jfasch/work/jfasch-home/trainings/material/soup/cxx-code/fixtures/./fixture-tmpdir.h:3,
    //                  from /home/jfasch/work/jfasch-home/trainings/material/soup/cxx-code/fixtures/./fixture-tmpdir-cwd.h:3,
    //                  from /home/jfasch/work/jfasch-home/trainings/material/soup/cxx11/filesystem/code/suite.h:3,
    //                  from /home/jfasch/work/jfasch-home/trainings/material/soup/cxx11/filesystem/code/create_directory_error.cpp:1:
    // In static member function ‘static constexpr std::char_traits<char>::char_type* std::char_traits<char>::copy(char_type*, const char_type*, std::size_t)’,
    //     inlined from ‘static constexpr void std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_S_copy(_CharT*, const _CharT*, size_type) [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>]’ at /usr/include/c++/12/bits/basic_string.h:423:21,
    //     inlined from ‘constexpr std::__cxx11::basic_string<_CharT, _Traits, _Allocator>& std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::_M_replace(size_type, size_type, const _CharT*, size_type) [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>]’ at /usr/include/c++/12/bits/basic_string.tcc:532:22,
    //     inlined from ‘constexpr std::__cxx11::basic_string<_CharT, _Traits, _Alloc>& std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::replace(size_type, size_type, const _CharT*, size_type) [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>]’ at /usr/include/c++/12/bits/basic_string.h:2171:19,
    //     inlined from ‘constexpr std::__cxx11::basic_string<_CharT, _Traits, _Alloc>& std::__cxx11::basic_string<_CharT, _Traits, _Alloc>::replace(size_type, size_type, const _CharT*) [with _CharT = char; _Traits = std::char_traits<char>; _Alloc = std::allocator<char>]’ at /usr/include/c++/12/bits/basic_string.h:2196:22,
    //     inlined from ‘std::string testing::internal::CanonicalizeForStdLibVersioning(std::string)’ at /home/jfasch/work/jfasch-home/googletest/googletest/include/gtest/internal/gtest-type-util.h:83:14:
    // /usr/include/c++/12/bits/char_traits.h:431:56: error: ‘void* __builtin_memcpy(void*, const void*, long unsigned int)’ accessing 9223372036854775810 or more bytes at offsets [2, 9223372036854775807] and 1 may overlap up to 9223372036854775813 bytes at offset -3 [-Werror=restrict]
    //   431 |         return static_cast<char_type*>(__builtin_memcpy(__s1, __s2, __n));
    //       |                                        ~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~
}
