# RP2040 Mini Breakout Board
![rp2040_mini_breakout_board](Assets/RP2040%20Mini%20Breakout%20Board%20-%20Top.jpg)
---

## Attribution

The following text must be included in any distribution of derivitives of this board. All links must also be included.

Based on RP2040 Advanced Breakout board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board

Copyright 2023 [TheTrain](https://github.com/TheTrainGoes) and based on the original work by [n-i-x](https://github.com/n-i-x)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

## Summary

The RP2040 Mini Breakout Board is a spin off of the official embedded embedded design for the GP2040-CE project.  The Mini version cuts down on a number of extras and offers a basic fightstick solution in a small form factor and a lower overall cost compared to the Advanced Breakout Board.

You can find a pre-compiled .UF2 firmware file for the RP2040 Mini Breakout Board in the GP2040-CE release section under `GP2040-CE_0.X.X_RP2040MiniBreakoutBoard.uf2`.  This configuration will be maintained as long as the project is active and the pinout will not change.  Should there be another version of the board, it will be kept as a seperate hardware entry.

The RP2040 Basic Breakout Board is an embedded design based on the Advanced Breakout Board (https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board) by TheTrain and N-I-X.

The RP2040 Mini Breakout Board is an embedded SMD design with through hole components.  It is not recommened to assemble these yourself unless you have a setup to do SMD assembly.

We have a small but passionate Discord group which you can access here if interested: https://discord.com/invite/k2pxhke7q8

A massive thank you to FeralAI who made most of this possible!

## Board design choices

The Mini Breakout Board uses a non-standard form factor.  This was not based on anything directly, rather just me playing around with sizes.  I am currently working on a micro versino of this as well.  Also included with this repo are some 3D print files to make a nice little box for it.  

A 3pin (1x3pin) JST 2.00mm connector labeled can be found on the top side that allows for the connection of addressable RGB LEDs.  A list of compatible RGB LED types can be found HERE.

A 20pin (2x10pin) 2.54mm connector is located in the bottom right of the board, matching the location and pinout of standard Brook boards.  If you are planning to use the 20pin connector you do not need to use the screw terminals on the board, and vice versa if you prefer to wire a stick yourself.

A 4pin (1x4pin) JST 2.00mm connector is located on the top size which can be used with the standard Brook 4-pin harness allowing for access to A2, L3 and R3.  

A 3pin (1x3pin) JST 2.00mm connector is located on the top side which allows for access to two `option` pins.  These can use assigned via the web-config to setup any number of combinations of features such as dual directional, turbo, reverse direction etc.  Please note there are only two of these on this board.  It is mainly intended for arcade applications that would make use of an additional button for connecting a coin acceptor as well as turbo.

A USB-C port can be found on the top left side of the board.  USB-C was chosen as it is the current industry standard and can allow for very low profile builds should you choose to make a version of the board with depopulated headers.  

There are three buttons on the board:
  - A BootSel button, which can be held on plug-in to enter BootSel mode which is used to flash the device with firmware. 
  - A reset button, which can be pressed to reset the device.
  - A web-config button, which can be held while plugging in to go to web-config mode.*

Please note that web-config can be accessed by pressing and holding S2.  This is an extra mapping of S2 to allow for easy access and setup of the web-config utility for those that are working on boards not already installed or connected to anything. 

## Assembly

These boards are designed to be made and assembled by JLCPCB.  As such, you will find a folder called `Hardware files` that contains a copy of the three files needed to have these boards made by JLC PCB.  

Those files are:
- A gerber file for the design of the board
- A BoM file for the list of parts to be assembled
- A PnP file for the placement of the parts in the BoM file

This design includes both SMD and through hole parts from JLC PCB.  There are additional costs associated with having through hole parts added to the board.  You can reduce overall costs by removing headers that are not needed for your specific application of the board.  This can be done in EasyEDA directly by choosing to exclude the part from the BoM before exporting the necessary files.

These boards have been designed to be fully assembled by JLCPCB.  You will not need to do any soldering or assembly of any kind should you order a batch of them.  The only thing you will need to do is flash the boards with the most recent version of GP2040-CE and then test the boards.

Please note that we are not responsible for issues that arise from the manufacturing of these boards done through JLC PCB or any other manufacturer.  These board files have been ordered and tested for functionality.  

## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these basic breakout boards.  Here are the steps to make your first order and what options I choose along the way.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - RP2040 Mini Breakout Board v7.0E.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 55 mm x 24 mm<br/>
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

Note 5 - This adds around $1 to the total cost of the order and is 100% worth doing as they will check the placement of all SMD parts and make any necessary changes or reach out if there are concerns.  I cannot stress enough that this is the best $1 you will spend for the peace of mind of not messing up an entire batch.

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree <br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - RP2040 Mini Breakout Board v7.0E.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - RP2040 Mini Breakout Board v7.0E.csv` file that is located in the Hardware files folder<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here you can click on on the `NEXT` button. (note 6), (note 7)

Note 6 - You can also use this page to omit parts from the assembly.  This can primarily be used to not include specific headers or the screw terminals.  Please only do this if you understand what you are doing as omiting main parts of the design will lead to non-functioning boards.  We are not responsible for any boards that are non-functioning. 

Note 7 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything, we would recommend you not proceed unless you understand how to find replacmeent parts.  If you are unsure, please feel free to join up in the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known good.  If all looks well press the `NEXT` button. (note 8)

Note 8 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do not work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 

## How to upload firmware

If uploading the firmware before assembly you can hold the BootSel button on the Pico and plug the device into your computer.  It will show up as an external device.  Copy the `GP2040-CE_0.X.X_RP2040MiniBreakoutBoard.uf2` file to it and wait for the device to disconnect after copying completes.  

If uploading the firmware after assembly plug the Pico into your computer and quickly press the BootSel button twice on the Pico Basic Breakout Board.  You should see an external device show up on your computer.  Copy the `GP2040-CE_0.X.X_RP2040MiniBreakoutBoard.uf2` file to it and wait for the device to disconnect after copying completes.  

If something goes wrong and you want to upload the firmware again (or if you have tested out the configuration tool and made a mistake) you can enter BootSel mode via either of the methods above and drag over the included `flash_nuke.uf2` file.  This file will take a moment to write to the Pico, once completed you will see the device disconnect and then re-connect as an external device.  After it has shown up again you can copy the same `GP2040-CE_0.X.X_RP2040MiniBreakoutBoard.uf2` firmware over to it again.

## Sales recommendations

Through the licensing you are free to make and sell these boards in group buys or even commercial applications.  

The intended purpose of this board, as well as the overall GP2040-CE project is to get low cost boards into the hands of as many people as possible so everyone can enjoy the project.  

As such, we have a recommended MSRP of $15 USD for the RP2040 Mini Breakout Board or $25 USD with free shipping within the USA or Canada.

You are free to set your own price as you see fit. 


Also, a note about failure rates on boards from JLCPCB.

I (TheTrain) have ordered just over 160 of Advanced Breakout Boards in various color and design variaitions with another 20 on the way.  Here are my current failure rates from orders:
- 20x Black, 2x dead = Failure rate of 10%
- 30x Black, 3x dead = Failure tate of 10%
- 20x Red, no dead = Failure rate of 0%
- 20x Purple, 1x dead = Failure rate of 5%
- 20x White, 3x dead = Failure rate of 15%
- 10x Black, 1x dead = Failure rate of 10%

Overall the blended rate is around 10%.  So for every 100 boards ordered expect to get 10 dead ones give or take.  This should be factored in when placing orders for commercial purposes or group buys.  

Of those that arrived dead there have only been a few that I have been able to get working again, usually due to soldering issues on the SMD parts.


## Donations

Every part of this project is open source, from the GP2040-CE firmware to the original Pico Fighting Board design and also this RP2040 Advanced Breakout Board design.  

Donations are not necessary but always welcome!  All received donations will be split evenly between TheTrain and N-I-X.  TheTrain will typically use donations to pay for Discord boosts and try out new designs or sending boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v7.0E
- Initial design (nailed it first try)

## Acknowledgements

- [n-i-x](https://github.com/n-i-x) from [acustomarcade.com](https://acustomarcade.com/) for helping with the board design
- [TheTrain](https://github.com/TheTrainGoes) for helping the board design
- FeralAI for starting the GP2040 project and the original design of the Pico Fighting Board
- Everyone that works on the GP2040-CE project to make it the best controller firmware around
