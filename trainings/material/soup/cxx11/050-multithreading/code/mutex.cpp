#include <gtest/gtest.h>
#include <future>


TEST(mutex_suite, basic)
{
    std::mutex lock;
    lock.lock();
    lock.unlock();
}

TEST(mutex_suite, try_lock)
{
    std::mutex lock;
    ASSERT_EQ(lock.try_lock(), true);
    ASSERT_EQ(lock.try_lock(), false);
}

// TEST(mutex_suite, self_deadlock)
// {
//     std::mutex lock;
//     lock.lock();
//     lock.lock();
//     FAIL();
// }

TEST(mutex_suite, recursive)
{
    std::recursive_mutex lock;
    lock.lock();
    lock.lock();
}

TEST(mutex_suite, recursive_unlock_num_times)
{
    std::recursive_mutex lock;
    lock.lock();
    lock.lock();
    lock.unlock();

    auto success = std::async([&lock]() {
        return lock.try_lock();
    });

    ASSERT_EQ(success.get(), false);
}
