# Ghost Auth
![Ghost Auth](https://github.com/OpenStickCommunity/Hardware/blob/main/Ghost%20Auth/Images/Ghost%20Auth%20v1.0.jpg)
---

## Attribution

The following text must be included in any distribution of derivitives of this board. All links must also be included.

Based on the Ghost Auth board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/Ghost%20Auth

Copyright 2023 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here


## Summary

Ghost Auth is designed more for developers and those that tinker on the regular with the RP2040 based devices running GP2040-CE.

When you wipe your RP2040 based device running GP2040-CE (via nuke or otherwise) you will lose your personal DS4 keys if you uploaded them.

As someone who tests new builds and regularly wipes the flash on my board, the step of adding these files back became tedious.

Ghost Auth is a minimal RP2040 implementation that was heavily influenced by the WaveShare Zero. 

It allows you to load any of our hosted GP2040-CE .UF2 builds, then load the force web-config .UF2 that was made by Jfedor.  Once in web-config you can change it to PS4 controller mode and load your DS4 files then forever have a dongle to auth off of.

We have a small but passionate Discord group which you can access here if interested: https://discord.com/invite/k2pxhke7q8


## Board design choices

This is a very simple board.  I looked at other examples of RP2040 builds which used small package sized components and emulated those as best I could.  This was heavily based on the WaveShare Zero board.

I added a single BootSel button in the event you need to wipe the unit for some reason.

A future revision may add a button or pads for accessing the web-config.


## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these Ghost Auth boards.  Here are the steps to make your first order and what options I choose along the way.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - Ghost Auth v1.0.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 27.1 mm x 15 mm<br/>
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
- For the `Add BOM File` you will need to choose the `BOM - Ghost Auth v1.0.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - Ghost Auth v1.0.csv` file that is located in the Hardware files folder<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here you can click on on the `NEXT` button. (note 6), (note 7)

Note 6 - You can also use this page to omit parts from the assembly.  This can primarily be used to not include specific headers or the screw terminals.  Please only do this if you understand what you are doing as omitting main parts of the design will lead to non-functioning boards.  We are not responsible for any boards that are non-functioning. 

Note 7 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything, we would recommend you not proceed unless you understand how to do find replacmeent parts.  If you are unsure, please feel free to join the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known to be good.  If all looks well press the `NEXT` button. (note 8)

Note 8 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do not work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 


## Donations

Every part of this project is open source, from the GP2040-CE firmware to the original Pico Fighting Board design and also this RP2040 Advanced Breakout Board design.  

Donations are not necessary but always welcome!  All received donations will be split evenly between TheTrain and N-I-X.  TheTrain will typically use donations to pay for Discord boosts and try out new designs or sending boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2


## Revision History

v1.0
- Initial design


## Acknowledgements

- [TheTrain](https://github.com/TheTrainGoes) for the board design
- FeralAI for starting the GP2040 project and the original design of the Pico Fighting Board
- Everyone that works on the GP2040-CE project to make it the best controller firmware around
