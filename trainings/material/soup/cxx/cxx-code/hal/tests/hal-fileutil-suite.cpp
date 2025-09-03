#include <hal.h>
#include <fixture-tmpdir.h>

#include <fstream>
#include <filesystem>
#include <stdexcept>

#include <fcntl.h>
#include <unistd.h>


struct fileutil_suite : public tmpdir_fixture {};


TEST_F(fileutil_suite, read_from_file)
{
    auto filename = tmpdir_fixture::dirname / "somefile";
    std::ofstream(filename) << "some-content";

    auto content = jf::hal::read_from_file(filename);
    ASSERT_EQ(content, "some-content");
}

TEST_F(fileutil_suite, read_from_file_noexist)
{
    auto filename = tmpdir_fixture::dirname / "no-such-file";

    try {
        jf::hal::read_from_file(filename);
        FAIL();
    }
    catch (const std::runtime_error&) {}

    // -Werror=restrict
    // ASSERT_THROW(jf::hal::read_from_file(filename), std::runtime_error);
}

TEST_F(fileutil_suite, write_to_file)
{
    auto filename = tmpdir_fixture::dirname / "file";
    jf::hal::write_to_file(filename, "some-content");

    int fd = open(filename.c_str(), O_RDONLY);
    ASSERT_NE(fd, -1);
    char buffer[64];

    ssize_t nread = read(fd, buffer, sizeof(buffer));
    ASSERT_NE(nread, -1);
    close(fd);

    ASSERT_EQ(std::string(buffer, nread), "some-content");
}

TEST_F(fileutil_suite, write_to_file_int)
{
    auto filename = tmpdir_fixture::dirname / "file";
    jf::hal::write_to_file_int(filename, 666);

    std::string content = jf::hal::read_from_file(filename);
    ASSERT_EQ(content, "666");
}
