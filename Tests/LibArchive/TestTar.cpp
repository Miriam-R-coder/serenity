#include <LibArchive/TarStream.h>
#include <LibTest/TestCase.h>

TEST_CASE(pax_extended_header_size_overflow)
{
    auto result = LibArchive::TarStream::validate_pax_header_size(2 * 1024 * 1024);
    EXPECT(result.is_error());
    EXPECT_EQ(result.error().string_literal(), "PAX extended header size exceeds maximum allowed limit");
}
