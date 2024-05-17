# ARC - Accessible and Reconfigurable Controller
![ARC](Assets/ARC%20v1.0%20-%2001.png)
---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on the ARC Controller board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/Boards/GP2040-CE%20Official%20Controllers/Open_Core0

Copyright 2024 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

## Summary

The ARC Controller is my take on an accessibility controller.  This was designed from scratch by myself taking some design ideas from [JFedor](https://github.com/jfedor2) as well as the universal standards for accessibility controller connectors.

A few immediate notes:
1 - Schematics have not been finished yet but will be added at a later time
2 - There are currently a limited number of modules posted, it is my hope that people make and share new modules for this controller.

The ARC is an embedded SMD design with through hole components.  It is not recommended to assemble these yourself unless you have a setup to do SMD assembly.

With the ARC using an embedded RP2040 chip, we are able to access all of the additional GPIO pins that are not easily accessible on the standard Raspberry Pi Pico board.  This allows us to have many more options on the board so that people can make truly unique and custom contollers.

We have a small but passionate Discord group which you can access here, if interested: https://discord.com/invite/k2pxhke7q8

## Board design choices

The ARC has a number of pins that can be accessed by different connectors.  The addition of a 20pin + 4pin headers will allow for easy connection to more traditional wiring looms.  

An 0.96" OLED has beed added to allow visibility into current controller settings.

The ARC also features a USB passthrough port which will allow you to use an authentication device for play on PS5 games that support legacy controllers (like Street Fighter 6 and Mortal Kombat 11) and Xbox One or Series X/S.

The four ADC pins are available via 2x 4pin JST 2.00 headers that include 3.3v for easy connection to analog joysticks.

## Assembly

These boards are designed to be made and assembled by JLC PCB.  As such, you will find a folder called `Hardware files` that contains a copy of the three files needed to have these boards made by JLC PCB.  

Those files are:
- A gerber file for the design of the board
- A BoM file for the list of parts to be assembled
- A PnP file for the placement of the parts in the BoM file

This design includes both SMD and through hole parts from JLC PCB.  There are additional costs associated with having through hole parts added to the board.  You can reduce overall costs by removing headers that are not needed for your specific application of the board.  This can be done in EasyEDA directly by choosing to exclude the part from the BoM before exporting the necessary files.

These boards have been designed to be fully assembled by JLC PCB less the OLED and hot-swap sockets.  

Please note that we are not responsible for issues that arise from the manufacturing of these boards done through JLC PCB or any other manufacturer.  These board files have been ordered and tested for functionality.  

You will also need the following hardware components to assembe the ARC:
- 0.96" OLED [AliExpress Link](https://www.aliexpress.com/item/1005003749784158.html) (make sure you get the module version)
Note: You will need to take off the plastic part of the header on it otherwise the plexi will not lay flush!  You will also need to snip the legs after soldered on.

Optionally you can get the following parts done to make a little stand-alone unit:
- 3x M2x8mm buttonhead bolts [AliExpress Link](https://www.aliexpress.com/item/32967225441.html)
- 3D printed body for 3D printing [HERE](3D%20print%20files/ARC%20v1.0%20-%20Base.stl)
- 3D printed spacers for 3D printing [HERE](3D%20print%20files/ARC%20v1.0%20-%20Spacer.stl)
- Top plexi files for laser cutting [HERE](Laser%20cut%20files/ARC%20v1.0%20-%20PT%20-%20Top%20Plexi.svg)
- Bottom foam files for laser cutting [HERE](Laser%20cut%20files/ARC%20v1.0%20-%20PT%20-%20Bottom%20Foam.svg)

## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these basic breakout boards.  Here are the steps to make your first order and what options I choose along the way.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - ARC v1.0 - PT.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 100 mm x 97.02 mm<br/>
- PCB Qty = (however large your run will be, minimum of 5)<br/>
- Product Type = Industrial/Consumer electronics<br/>
- Different Design = 1<br/>
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

Note 4 - Economic assembly is much cheaper on smaller batch runs of 10-30 units.  Standard assembly will yield less dead on arrival boards but is more expensive to have done.  On average I expect a 5-10% failure rate on the boards from JLC so please factor that in when making your order.

Note 5 - This adds around $1 to the total cost of the order and is 100% worth doing as they will check the placement of all SMD parts and make any necessary changes or reach out if there are concerns.  I cannot stress enough that this is the best $1 you will spend for the peace of mind of not messing up an entire batch.

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree <br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - ARC v1.0 - PT.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - ARC v1.0 - PTcsv` file that is located in the Hardware files folder<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button. 

You will likely get an error message here saying that one of the below parts won't be assembled due to missing date.  If this pops up and the part in question is `NONE1` then you can press `Continue` because `NONE1` is the OLED module and JLC cannot assemble those.

9 - You will now see a list of components that will be used to assemble the boards.  If there are no listed issues here you can click on on the `NEXT` button. (note 6), (note 7)

Note 6 - You can also use this page to omit parts from the assembly.  

Note 7 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything we would recommend you not proceed unless you understand how to find replacement parts.  If you are unsure, please feel free to join the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known to be good.  If all looks well press the `NEXT` button. (note 8)

Note 8 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do note work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application.  If you are planning to also order the aluminum bottom plate then please check out the following section before placing your order.

## How to upload firmware

If uploading the firmware before assembly you can hold the BootSel button on the Pico and plug the device into your computer.  It will show up as an external device.  Copy the `GP2040-CE_X.X.X_ARC.uf2` file to it from the main firmware release section (https://github.com/OpenStickCommunity/GP2040-CE/releases) and wait for the device to disconnect after copying completes.  

If something goes wrong and you want to upload the firmware again (or if you have tested out the configuration tool and made a mistake) you can enter BootSel mode via either of the methods above and drag over the included `flash_nuke.uf2` file.  This file will take a moment to write to the Pico, once completed you will see the device disconnect and then re-connect as an external device.  After it has shown up again you can copy the same `GP2040-CE_X.X.X_ARC.uf2` firmware over to it again.


## Sales recommendations

Through the licencing you are free to make and sell these boards in group buys or even commercial applications.  

The intended purpose of this board, as well as the overall GP2040-CE project is to get low cost boards into the hands of as many people as possible to everyone can enjoy the project.  

I would like to see these boards offered at cost or as close to at cost as possible.  

You are free to set your own price as you see fit. 


## Donations

Every part of this project is open source, from the GP2040-CE firmware to the original Pico Fighting Board design and also this Open_Core0 design.  

Donations are not necessary but always welcome!  I typicly use donations to pay for Discord boosts and try out new designs or send boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v1.0
- Innitial design

## Acknowledgements

- [TheTrain](https://github.com/TheTrainGoes) for doing board design
- FeralAI for starting the GP2040 project and the original design of the Pico Fighting Board
- Everyone that works on the GP2040-CE project to make it the best controller firmware around