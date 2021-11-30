# NFE (ArcticFox Configuration)

![](res/nfe_ss.png)

This is an **UNOFFICIAL** configuration utility for devices running the ArtixFox Firmware, especially the STM32 branch.
Please see the official forum here:
https://nfeteam.org/forum
and the STM32 thread:
https://nfeteam.org/forum/threads/lost-vape-quest-chip-grus-ursa-cyborg-btb-thelema.4905

# Audience
This currently only works on Linux. It could be ported on other OSs (just needs another USB library), but I don't suppose anyone needs that. For Windows there are the official tools and the Apple people probably only have DNA devices :)

# Warning
The official tools know things about firmare versions and device models and capabilities and stuff. This tool doesn't.
Even though it probably won't brick your device, I don't recommand using it on other devices than STM32.

# Installation
You'll have to build this yourselves.
Besides, you have to give yourselves permission to access the USB device ("hidraw").
Create the file `/etc/udev/rules.d/99-af.rules` and paste this to it:
```
KERNEL=="hidraw*", MODE="0666", TAG+="uucp", TAG+="udev-acl", TAG+="uaccess"
```

## Prerequisites
### Arch and derivates
- base-devel
- qt5-base
- qt5charts
- hidapi

### Ubuntu and derivates (tested on Linux Mint 20.2 "Uma")
- build-essential
- qt5-default
- libqt5charts5-dev
- libhidapi-dev

## Build
Clone this repo and `cd` to it. Then:
```
mkdir build && cd build
cmake ..
make -j
```
That's it. You should have the `nfe` executable, which you can put anywhere (copy `nfe.png` to the same place if you want to see the icon in the taskbar)

## Copyright
I got the logo picture from here: https://github.com/TBXin/NFirmwareEditor/blob/master/src/NToolbox/Resources/arcticfox_logo.png