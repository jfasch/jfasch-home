Audio Chip Bringup
==================

.. contents::
   :local:

Goal
----

* Given that I2C works with the Yocto kernel (see
  :doc:`hardware-bringup`), make I2S communication work.

Findings
--------

* Check Intel application notes
* Configure driver. Devicetree?

  * Connect chip to I2S signals (``AUDIO_MCK``, ``I2S0_CK``,
    ``I2S0_LRCK``, ``I2S0_SDOUT``). Where to find I2S implementation
    in kernel?

* Configure userspace? Which ALSA (?) device?


Further Information
-------------------

* `Datasheet TLV320DAC3203IRGER
  <https://www.digikey.at/product-detail/de/texas-instruments/TLV320DAC3203IRGER/296-50547-1-ND/9685686>`__
* `Datasheet TLV320DAC3203
  <https://www.ti.com/product/TLV320DAC3203>`__
* Linux Driver

  * `"TLV320DAC3203: Drive Code for TLV320DAC3203IRGER"
    <https://e2e.ti.com/support/audio-group/audio/f/audio-forum/928912/tlv320dac3203-drive-code-for-tlv320dac3203irger>`__,
    suggesting that *TLV320AIC32x4* is compatible with
    *TLV320DAC3203*. Driver is `tlv320aic32x4.c
    <https://github.com/torvalds/linux/blob/master/sound/soc/codecs/tlv320aic32x4.c>`__.
  * `"TLV320AIC31XXSW-LINUX (Linux Driver for TLV320AIC31XX)"
    <https://www.ti.com/tool/TLV320AIC31XXSW-LINUX>`__, suggesting
    that `tlv320aic31xx.c
    <https://github.com/torvalds/linux/blob/master/sound/soc/codecs/tlv320aic31xx.c>`__
    is responsible for the device.
