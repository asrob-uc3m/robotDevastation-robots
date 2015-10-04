MT7601 driver [copy from porjo]
===============================

Chipset is Ralink 148f:7601. Firmware is copied off https://github.com/porjo/mt7601/raw/master/src/mcu/bin/MT7601.bin

As of 4/Oct/2015 (reading: http://groenholdt.net/Computers/RaspberryPi/MediaTek-MT7601-USB-WIFI-on-the-Raspberry-Pi/MediaTek-MT7601-USB-WIFI-on-the-Raspberry-Pi.html), we updated to raspi kernel 4.1.9+ with: 
```bash
sudo -s
apt-get update
apt-get upgrade
rpi-update
```

Got a -2 error on direct load of firmware. The final step is (reading: https://www.raspberrypi.org/forums/viewtopic.php?t=119095&p=808311) to put the firmware .bin file (stored a copy in this directory) in /lib/firmware for raspi 4.1.9+.

Appears as wlan0, so the rest are standard configurations in /etc/network/interfaces and /etc/wpa_supplicant/wpa_supplicant.conf

