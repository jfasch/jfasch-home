#include "../eeprom.h"

#include <gtest/gtest.h>
#include <gmock/gmock.h>


class EEPROM_Mock : public EEPROM
{
public:
    virtual ~EEPROM_Mock() {}

    // MOCK_METHOD(void, write, (uint32_t offset, const void* data, uint32_t size), (override))
    // MOCK_METHOD(void, read, (uint32_t offset, void* data, uint32_t size), (override))
};

TEST(EEPROM_RangeViolations, ZeroSize)
{
    
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
