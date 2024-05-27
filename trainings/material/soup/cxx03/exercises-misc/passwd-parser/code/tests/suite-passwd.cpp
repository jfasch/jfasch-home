#include <parse-passwd.h>

#include <fixture-tmpdir.h>
#include <gtest/gtest.h>

#include <cassert>
#include <fcntl.h>


TEST(passwd_line_suite, ok_no_linefeed)
{
    std::string line = "jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash";
    User user = parse_passwd_line(line);

    ASSERT_EQ(user.name, "jfasch");
    ASSERT_EQ(user.passwd, "x");
    ASSERT_EQ(user.uid, 1000);
    ASSERT_EQ(user.gid, 1000);
    ASSERT_EQ(user.descr, "Joerg Faschingbauer");
    ASSERT_EQ(user.homedir, "/home/jfasch");
    ASSERT_EQ(user.shell, "/bin/bash");
}

struct passwd_file_suite : public tmpdir_fixture
{
    passwd_file_suite()
    {
        filename = dirname / "passwd";

        int fd = open(filename.c_str(), O_WRONLY|O_CREAT, 0666);
        assert(fd != -1);

        std::vector<std::string> lines = {
            "root:x:0:0:Super User:/root:/bin/bash\n",
            "jfasch:x:1000:1000:Joerg Faschingbauer:/home/jfasch:/bin/bash\n",
        };

        for (const auto& line: lines) {
            ssize_t nwritten = write(fd, line.c_str(), line.size());
            assert(nwritten == (ssize_t)line.size());
        }

        close(fd);
    }

    std::string filename;
};


TEST_F(passwd_file_suite, basic)
{
    std::vector<User> users = parse_passwd_file(filename);

    ASSERT_EQ(users.size(), 2);

    ASSERT_EQ(users[0].name, "root");
    ASSERT_EQ(users[0].passwd, "x");
    ASSERT_EQ(users[0].uid, 0);
    ASSERT_EQ(users[0].gid, 0);
    ASSERT_EQ(users[0].descr, "Super User");
    ASSERT_EQ(users[0].homedir, "/root");
    ASSERT_EQ(users[0].shell, "/bin/bash");

    ASSERT_EQ(users[1].name, "jfasch");
    ASSERT_EQ(users[1].passwd, "x");
    ASSERT_EQ(users[1].uid, 1000);
    ASSERT_EQ(users[1].gid, 1000);
    ASSERT_EQ(users[1].descr, "Joerg Faschingbauer");
    ASSERT_EQ(users[1].homedir, "/home/jfasch");
    ASSERT_EQ(users[1].shell, "/bin/bash");
}

