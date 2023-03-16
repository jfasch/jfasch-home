#pragma once

#include <hal.h>

#include <gtest/gtest.h>


struct HAL_Fixture : public ::testing::Test 
{
    HAL_Fixture()
    {
        jf::hal::init();
    }

    ~HAL_Fixture()
    {
        jf::hal::deinit();
    }
};
