# Waveshare RP2350PiZero Experiments

Testing out the [Waveshare RP2350 PIZero](https://www.waveshare.com/rp2350-pizero.htm?&aff_id=DrJonEA) 
for a review on my YouTube channel [DrJonEA](https://youtube.com/@drjonea).

Experiments here are all compiled with the Pico SDK Version 2.2.0.  The libraries are those shipped by
Waveshare, though a few bug fizes to get working on SDK 2.2.0 have been added.


# Build steps

1. Build a build directory
``` bash
mkdir build 
```
2. Go to there
``` bash
cd build  
```

3. Generate makefiles using correct pico sdk and toolchain part
``` bash
cmake -DPICO_SDK_PATH=$PICO_SDK_PATH \
      -DPICO_TOOLCHAIN_PATH=$PICO_TOOLCHAIN_PATH \
       ../exp/path
```

4. Compile with make
``` bash
make
```