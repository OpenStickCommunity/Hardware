# Sanjuks V3 AM5 Adapter Plate
![Sanjuks_V3_AM5_Adapter_Plate](https://github.com/OpenStickCommunity/Hardware/blob/main/Sanjuks%20V3%20AM5%20Adapter%20Plate/Images/Sanjuks_V3_AM5_Adapter_Plate.jpg)
---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on the Shuriken JLF PCB V2 by BitBangGaming LLC - https://bitbanggaming.com/products/shuriken-jlf-pcb-v2

Copyright © 2023 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here


## Summary

The Sanjuks V3 AM5 Adapter Plate allows you to replace the stock Gersung A3 switches on a Sanjuks V3 or V3P lever with [Panasonic AM5 switches](https://focusattack.com/seimitsu-ls-33-ls-55-ls-56-ls-58-187-fastener-microswitch/) (either stock soft or spring swapped with the Gersung A3).

Please note that this plate is designed exclusively for and will only work with Panasonic AM5 switches due to the position of the pins.

While this project is not directly connected to the Open Stick Discord, you can join here to see more of the awesome projects we have: https://discord.com/invite/k2pxhke7q8


## Board design choices

The Sanjuks V3 AM5 Adapter Plate is a skirt-style PCB which will go around the Panasonic AM5 switches.  On the Sanjuks V3, This design is superior to a stack plate design as it will not change the overall throw of the lever nor the alignment of the actuator and restrictor gate. 


## Assembly

This board is designed to be hand-soldered.  At this time, the through hole fuse clips are not available for assembly at JLC.  

**There are 9 total parts needed to assemble each unit:<br/>**

8 x Keystone Electronics Fuse Clip Blade 500V 30A PCB - 36-3557-ND<br/>
1 x JST Connector Header R/A 5 position 2.5mm - 455-4200-ND

These parts can be sourced from DigiKey directly via the numbers at the end above.

It is recommended to have a spare Sanjuks V3 to use as an assembly jig when making these boards.

Note that the AM5 switches you use during the assembly process will be progressively worn down as you assemble more boards.  If you intend to produce saleable quantities, make sure you have "donor" AM5 switches you do not intend to use in a lever handy.

**The process that I follow to make these is:<br/>**

1 - Place the Sanjuks V3 AM5 Adapter Plate on the Sanjuks V3 main body<br/>
2 - Place the four Panasonic AM5 switches into the Sanjuks V3 main body<br/>
3 - Press fit the 8 x Keystone Electronics Fuse Clip Blade's onto the Panasonic AM5 switch legs<br/>
4 - Place the Sanjuks V3 top (bottom) housing onto the four Panasonic AM5 switches and screw in place<br/>
5 - Flip over assembly, ensure the 8 x Keystone Electronics Fuse Clip Blade's are aligned correctly and solder in place<br/>
6 - Place and solder the JST Connector


## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would need to get at least five of these basic breakout boards.  Here are the steps to make your first order and the options I chose along the way.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - Sanjuks V3 AM5 Adapter Plate.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 72 mm x 72 mm<br/>
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
- Confirm Production file = Yes (note 1)<br/>
- Remove Order Number = Specify a location (note 2)<br/>
- Flying Probe Test = Fully Test<br/>
- Gold Fingers = No<br/>
- Castellated Holes = No<br/>
- No advanced options<br/>

Note 1 - This adds around $1 to the total cost of the order and is 100% worth doing as it will allow you one last chance to catch any issues that may have popped up.

Note 2 - I have added `JLCJLCJLCJLC` on the board in a spot that will be covered by the Sanjuks V3 main body.

If all looks well here you can click on the `SAVE TO CART` button.

5 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 


## Sales recommendations

Through this project's licensing, you are free to make and sell these boards in group buys or even commercial applications.  

There is a recommended MSRP of $18 USD for the Sanjuks V3 AM5 Adapter Plate including shipping within the USA or Canada.

You are free to set your own price as you see fit. 


## Donations

Donations are not necessary but always welcome!  All received donations will be split evenly between TheTrain and BitBangGaming.  TheTrain will typically use donations to try out new designs or send boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v1.0
- Initial open source design

## Acknowledgments

- [TheTrain](https://github.com/TheTrainGoes) for doing the board design
- [BitBangGaming](https://bitbanggaming.com/) base of the design
