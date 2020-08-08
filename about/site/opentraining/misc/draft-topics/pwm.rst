.. jf-topic:: draft.hardware.pwm

Userspace PWM
=============

TODO:

* PWM "theory": sketches to explain period and duty cycle
* Explanation why that should not be done in software (see-also
  "realtime" topic)
* Picture of PCA soldering (macro lens)
* Datasheet download
* Fritzing diagram with LED

Wiring
------

* ``A0-A5`` to ground. Highest bit is hardwired to ``1``, so this
  gives ``0b1000000``, or ``0x40``

Configure Raspberry
-------------------

.. code-block:: console
   :caption: /boot/config.txt
   
   dtparam=i2c_arm=on
   dtoverlay=i2c-pwm-pca9685a,addr=0x40

* ``addr=0x40`` can be omitted (is default anyway)
* Reboot
   
Talk to Chip Using the ``sysfs`` Interface
------------------------------------------

``Documentation/driver-api/pwm.rst``

* PCA9685 (PWM controller)

  * Datasheet https://www.nxp.com/docs/en/data-sheet/PCA9685.pdf
