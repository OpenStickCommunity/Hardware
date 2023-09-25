# USB Passthrough Board
![usb_passthrough_board](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Images/USB_Passthrough_Kit.JPG)
---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on the USB Passthrough Board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/USB%20Passthrough%20Board/

Copyright 2023 [TheTrain](https://github.com/TheTrainGoes) and [Lucipher](https://github.com/arntsonl)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here


## Summary

The USB Passthrough Board is a small add-on board primarily designed for use with a [RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board), but can be used on its own with a number of Pico and RP2040-based designs.

This board will allow you to plug in a compatible dongle or controller to authenticate on the PS4 or PS5 for use either natively on the PS4, or as an arcade stick on the PS5 for titles that support legacy PS4 arcade sticks.

We have a small but passionate Discord group which you can access here if interested: https://discord.com/invite/k2pxhke7q8

A massive thank you to [Lucipher](https://github.com/arntsonl/) who made USB passthrough a reality for our project!

There is a massive step-by-step tutorial for installing and setting up these boards located [HERE](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/README.md)


## Board design choices

The form factor on this was taken directly from the [RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board), as it is designed to be a module placed on top of that board or ones like it.  As such there are three separate JST 2.00mm 2pin connectors which allow you to connect Data+ (D+), Data- (D-), +5V, and Ground to the board from the [RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board).  

For those with other setups, custom implementations or just using a raw Pico a JST 2.00mm 4pin connector was added that has all needed connections in one place.  

Each data line has one 22Ω resistor inline and there is a 500mA fuse inline on the +5v line.

A SMD female USB socket has also been added to ensure there is no direct contact under the board.  

Two 3mm standoff holes are also found on the board allowing you to screw it directly onto the [RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board) via 1mm screw standoffs or any mounting application of your choice if you are not planning to connect it in this way.


## Connecting to an RP2040 Advanced Breakout Board

To connect this to a [RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board) you will need three JST 2.00mm 2pin cables.  

The first cable will be connected between the port labeled `5v OUT` on the RP2040 Advanced Breakout Board, which is located just below the USB-C port to the `5v IN` on the USB Breakout Board.  

The second cable will need to be connected from the `D+ OUT` port on the USB Passthrough Board to either `Option 1`, `Option 2`, `Option 3`, `Option 4` or `Option 5` on the RP2040 Advanced Breakout Board.  

The third cable will need to be connected from the `D- OUT` port on the USB Passthrough Board to either `Option 2`, `Option 3`, `Option 4`, `Option 5` or `Option 6` on the RP2040 Advanced Breakout Board.  This cable must be connected to the `Option` port which comes immediately after the one chosen for the `D+ OUT` option port.

As an example, if you connected `D+ OUT` on the USB Passthrough Board to `Option 2` on the RP2040 Advanced Breakout Board, you would need to connect `D- OUT` on the USB Passthrough Board to `Option 3`on the RP2040 Advanced Breakout Board.

The same will hold true if you are connecting this to another RP2040-based device or a Pico directly.  

As an example, on the Raspberry Pi Pico, if you connected `D+ OUT` on the USB Passthrough Board to `GPIO14` on the Raspberry Pi Pico, you would need to connect `D- OUT` on the USB Passthrough Board to `GPIO15` on the Raspberry Pi Pico.


## Assembly

These boards are designed to be made and assembled by JLCPCB.  As such, you will find a folder called `Hardware files` that contains a copy of the three files needed to have these boards made by JLCPCB.  

Those files are:
- A gerber file for the design of the board
- A BoM file for the list of parts to be assembled
- A PnP file for the placement of the parts in the BoM file

This design includes both SMD and through hole parts from JLCPCB.  There are additional costs associated with having through hole parts added to the board.  You can reduce overall costs by removing headers that are not needed for your specific application of the board.  This can be done in EasyEDA directly by choosing to exclude the part from the BoM before exporting the necessary files.

These boards have been designed to be fully assembled by JLCPCB.  You will not need to do any soldering or assembly of any kind should you order a batch of them. 

It is possible to hand solder these boards, however the resistors and fuse on it may be tricky.  The resistors and fuse can be omitted and just bridged over with solder if you choose, but it is recommended to have them in place.

Please note that we are not responsible for any issues that arise from the manufacturing of these boards done through JLCPCB or any other manufacturer.  These board files have been ordered and tested for functionality.  


## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these basic breakout boards.  Here are the steps to make your first order and the options I chose along the way.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - USB Passthrough Board v2.0.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 22.3 mm x 45.3 mm<br/>
- PCB Qty = (however large your run will be, minimum of 5)<br/>
- Product Type = Industrial/Consumer electronics<br/>
- Different Design = 1<br/>
- Delivery Format = Single PCB (note 1)<br/>
- PCB Thickness = 1.6<br/>
- PCB Color = (up to you)<br/>
- Silkscreen = (defaults to white for all except white boards which is black)<br/>
- Surface Finish = HASL(with lead)<br/>
- Outer Copper Weight = 1oz<br/>
- Via Covering = Tented<br/>
- Board Outline Tolerance = +/- 0.2mm (Regular)<br/>
- Confirm Production file = Yes (note 2)<br/>
- Remove Order Number = Yes (note 3)<br/>
- Flying Probe Test = Fully Test<br/>
- Gold Fingers = No<br/>
- Castellated Holes = No<br/>
- No advanced options<br/>

Note 1 - If ordering under 50 units you can use single PCB.  For orders of more than 50 units JLCPCB will require you to make a larger plate for them.  I have compared the costs of doing this for runs in the hundreds and there is only a very small decrease in price over ordering 50 single PCBs at a time.  Ordering the 50 single PCBs has the added bonus of coming as individual pieces which do not require additional processing like the plated ones will.

Note 2 - This adds around $1 to the total cost of the order and is 100% worth doing as it will allow you one last chance to catch any issues that may have popped up.

Note 3 - This adds a small cost to the boards but removes the JLCPCB order number.  If you are looking to make a run as cheap as possible you can leave this on and either let them place it on the board or add `JLCJLCJLCJLC` somewhere on the board in silk screen and they will place the order number there.

5 - Choose the following options for the PCB assembly
- PCBA Type = Economic (note 4)<br/>
- Assembly Side = Top Side<br/>
- PCBA Qty = (however large your run will be, minimum of 2)<br/>
- Tooling holes = Added by Customer<br/>
- Confirm Parts Placement = Yes (note 5)<br/>

Note 4 - Economic assembly is much cheaper on smaller batch runs of 10-30 units.  Standard assembly will yield less dead on arrival boards but is more expensive to have done.  On average I expect a 5-10% failure rate on the boards from JLC so please factor in that when making your order.

Note 5 - This adds around $1 to the total cost of the order and is 100% worth doing as they will check the placement of all SMD parts and make any necessary changes or reach out if there are concerns.  I cannot stress enough that this is the best $1 you will spend for the piece of mind of not messing up an entire batch.

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree <br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - USB Passthrough Board v1.0.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - USB Passthrough Board v1.0.csv` file that is located in the Hardware files folder<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here you can click on on the `NEXT` button. (note 6), (note 7)

Note 6 - You can also use this page to omit parts from the assembly.  This can primarily be used to omit specific headers or the screw terminals.  Please only do this if you understand what you are doing as omitting main parts of the design will lead to non-functioning boards.  We are not responsible for any non-functional boards. 

Note 7 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything, we would recommend you not proceed unless you understand how to do find replacement parts.  If you are unsure, please feel free to join the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known good.  If all looks well press the `NEXT` button. (note 8)

Note 8 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do note work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This done not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 


## Sales recommendations

Through the licensing you are free to make and sell these boards in group buys or even commercial applications.  

The intended purpose of this board, as well as that of the overall GP2040-CE project, is to get low-cost boards into the hands of as many people as possible so that everyone can enjoy the project.  

As such, we have a recommended MSRP of $10 USD for the USB Passthrough Board or $20 USD with included shipping within the USA or Canada.

You are free to set your own price as you see fit. 


## Donations

Every part of this project is open source: from the GP2040-CE firmware, to the original Pico Fighting Board design, to this RP2040 Advanced Breakout Board design.  

Donations are not necessary but always welcome!  All received donations will be split evenly between TheTrain and N-I-X.  TheTrain will typically use donations to pay for Discord boosts and try out new designs or sending boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v2.0
- Removed the 4pin JST 2.00 connector
- Did the traces on the board again

v1.0
- Initial design (nailed it first try)

## Acknowledgments

- [TheTrain](https://github.com/TheTrainGoes) for doing the board design
- [Lucipher](https://github.com/arntsonl) for helping with parts selection
- Everyone that works on the GP2040-CE project to make it the best controller firmware around
