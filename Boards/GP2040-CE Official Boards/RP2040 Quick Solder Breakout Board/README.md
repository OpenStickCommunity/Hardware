# RP2040 Quick Solder Breakout Board
![rp2040_quick_solder_breakout_board](Assets/RP2040%20Quick%20Solder%20Breakout%20Board.jpg)
---


## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on RP2040 Quick Solder Breakout Board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Quick%20Solder%20Breakout%20Board

Copyright 2024 [TheTrain](https://github.com/TheTrainGoes) 
[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here


## Summary

The RP2040 Quick Solder Breakout Board is designed to be the cheapest way to get going with the GP2040-CE firmware.  On average you can make 5x of these for around $18 USD!

You can use the pre-compiled .UF2 firmware file for the RP2040 Waveshare Zero in the GP2040-CE release section under `GP2040-CE_0.X.X_WaveshareZero.uf2`.  This configuration will be maintained as long as the project is active and the pinout will not change.  Should there be another version of the board, it will be kept as a separate hardware entry.  Since this uses the same pinout as the Advanced Breakout Board you can use that .UF2.

This board will require some basic soldering to complete.

There are two versions of this. One version has a cutout and is designed for the Waveshare RP2040 Zero.  The second version has not cutout and desinged for the RP2040 SuperMini.

We have a small but passionate Discord group which you can access here if interested: https://discord.com/invite/k2pxhke7q8

A massive thank you to FeralAI who made most of this possible!


## Board design choices

The Brook form factor was chosen due to its compatibility with a number of existing enclosures and holders.

A 20pin (2x10pin) 2.54mm connector is located in the bottom left of the board, matching the location and pinout of standard Brook boards. 

A 4pin (1x4pin) PH 2.00mm connector is located beside the 20pin connector which can be used with the standard Brook 4-pin harness allowing for access to A2, L3 and R3.  


## Assembly

You will need four parts to make each board:
- Quick Solder board
- Waveshare RP2040 Zero or RP2040 SuperMini
- 1 x 20pin (2x10pin) 2.54mm header
- 1 x 4pin (1x4pin) PH 2.00mm right angle connector

Please note that we are not responsible for issues that arise from the manufacturing of these boards done through JLCPCB or any other manufacturer as well as any issues that arrise as a result of soldering manually.  These board files have been ordered and tested for functionality.  

## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these basic breakout boards.  Here are the steps to make your first order and what options I choose along the way.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - RP2040 Quick Solder Breakout Board v1.0.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 96.3 mm x 45.31 mm<br/>
- PCB Qty = (however large your run will be, minimum of 5)<br/>
- Product Type = Industrial/Consumer electronics<br/>
- Different Design = 1<br/>
- Delivery Format = Single PCB<br/>
- PCB Thickness = 1.6<br/>
- PCB Color = (up to you)<br/>
- Silkscreen = (defaults to white for all except white boards which is black)<br/>
- Surface Finish = HASL(with lead)<br/>
- Outer Copper Weight = 1oz<br/>
- Via Covering = Tented<br/>
- Board Outline Tolerance = +/- 0.2mm (Regular)<br/>
- Confirm Production file = Yes<br/>
- Remove Order Number = Yes<br/>
- Flying Probe Test = Fully Test<br/>
- Gold Fingers = No<br/>
- Castellated Holes = No<br/>
- No advanced options<br/>

If all looks well here you can click on the `SAVE TO CART` button.

5 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 


## How to upload firmware

It is recommended to check your Waveshare RP2040 Zero or RP2040 SuperMini first before soldering to ensure it works and can take firmware.  You can hold the BootSel button on the device and plug the device into your computer.  It will show up as an external device.  Copy the `GP2040-CE_0.X.X_WaveshareZero.uf2` file to it and wait for the device to disconnect after copying completes.  

If something goes wrong and you want to upload the firmware again (or if you have tested out the configuration tool and made a mistake) you can enter BootSel mode via either of the methods above and drag over the included `flash_nuke.uf2` file.  This file will take a moment to write to the RP2040, once completed you will see the device disconnect and then re-connect as an external device.  After it has shown up again you can copy the same `GP2040-CE_0.X.X_WaveshareZero.uf2` firmware over to it again.


## Sales recommendations

Through the licensing you are free to make and sell these boards in group buys or even commercial applications.  

The intended purpose of this board, as well as the overall GP2040-CE project is to get low cost boards into the hands of as many people as possible so everyone can enjoy the project.  

As such, we have a recommended MSRP of $10 USD or less for the RP2040 RP2040 Quick Solder.

You are free to set your own price as you see fit. 


## Donations

Every part of this project is open source, from the GP2040-CE firmware to the original Pico Fighting Board design and also this RP2040 Advanced Breakout Board design.  

Donations are not necessary but always welcome!  TheTrain will typically use donations to pay for Discord boosts and try out new designs or sending boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v1.0
- Initial design

## Acknowledgements

- [TheTrain](https://github.com/TheTrainGoes) for doing the board design
- FeralAI for starting the GP2040 project and the original design of the Pico Fighting Board
- Everyone that works on the GP2040-CE project to make it the best controller firmware around
