Proximity Sensor: VL53L1X
=========================

Time-of-Flight (ToF) ranging sensor
  
 * Data sheet: https://www.st.com/en/imaging-and-photonics-solutions/vl53l1x.html
 * Linux kernel driver exists for VL53L0X
   https://github.com/torvalds/linux/blob/master/drivers/iio/proximity/vl53l0x-i2c.c

   * User space access yet unclear, research needed
   * Maybe (if only for educational purposes) hack that across
     ``/dev/i2c-1``

