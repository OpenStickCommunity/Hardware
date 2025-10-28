# HE Breakout Board
![HE Breakout Board 01](Assets/HE%20Breakout%20Board%2001.png)
![HE Breakout Board 02](Assets/HE%20Breakout%20Board%2002.png)
---

## Attribution

The following text must be included in any distribution of derivatives of this project or the boards. All links must also be included.

Based on the HE Breakout Board by TheTrain.

Copyright © 2025 [TheTrain](http://x.com/thetrain24)<br/>

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

Anyone selling this commercially must include in the listing that this is an open source item, link to the original repo and include the copyright as well as the link to my X account.

---


## Summary

The HE Breakout Board is a hall effect button expander board designed to work with GP2040-CE.

This board will allow for up to 24 buttons via three mux channels.  

This was designed to fit on top of the RP2040 Advanced Breakout Board via standoffs.  If using standoffs I recommend M3 11mm brass standoffs.

The board has a 5v -> 3.3v chip on it (same used on the RP2040 Advanced Breakout Board).  This was used over taking 3v3 in since the RP2040 Advanced Breakout Board does not have an easily accessible 3v3 pin.


## Assembly

These boards are designed to be made and assembled by JLCPCB.  As such, you will find a folder called `Hardware files` that contains a copy of the three files needed to have these boards made by JLCPCB.  

Those files are:
- A gerber file for the design of the board
- A BoM file for the list of parts to be assembled
- A PnP file for the placement of the parts in the BoM file

This design includes SMD parts from JLCPCB. 

These boards have been designed to be fully assembled by JLCPCB.  You will not need to do any soldering or assembly of any kind should you order a batch of them. 

It is possible to hand solder these boards, but it is not recommended.

Please note that we are not responsible for any issues that arise from the manufacturing of these boards done through JLCPCB or any other manufacturer.  These board files have been ordered and tested for functionality. 


## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these basic breakout boards.  Here are the steps to make your first order and the options I chose along the way.

1 - Go to JLCPCB.com<br/>
2 - Click on `Instant Quote`<br/>
3 - Click on `Add Gerber file` and choose the file named `Gerber - HE Breakout Board v1.1.zip`<br/>
4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 96.3 * 45.31 mm<br/>
- PCB Qty = 5<br/>
- Product Type = Industrial/Consumer electronics<br/>
- Deburring/Edge Rounding = Yes<br/>
- Different Design = 1<br/>
- Delivery Format = Single PCB<br/>
- PCB Thickness = 1.6<br/>
- PCB Color = (up to you)<br/>
- Silkscreen = (defaults to white for all except white boards which is black)<br/>
- Surface Finish = HASL(with lead)<br/>
- Outer Copper Weight = 1oz<br/>
- Via Covering = Tented<br/>
- Min via hole size/diameter = 0.3mm/(0.4/0.45mm)<br/>
- Board Outline Tolerance = +/- 0.2mm(Regular)<br/>
- Confirm Production file = Yes (Note 1)<br/>
- Mark on PCB = Remove<br/>
- Flying Probe Test = Fully Test<br/>
- Gold Fingers = No<br/>
- Castellated Holes = No<br/>
- Edge Plating = No<br/>
- No advanced options<br/>

5 - Choose the following options for the PCB assembly
- PCBA Type = Economic (note 2)<br/>
- Assembly Side = Top Side<br/>
- PCBA Qty = (however large your run will be, minimum of 2)<br/>
- Tooling holes = Added by Customer<br/>
- Confirm Parts Placement = Yes (note 5)<br/>

Note 1 + 2 - This adds around $1 to the total cost of the order and is 100% worth doing as they will check the placement of all SMD parts and make any necessary changes or reach out if there are concerns.  I cannot stress enough that this is the best $1 you will spend for the piece of mind of not messing up an entire batch.

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree <br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - HE Breakout Board v1.1.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - HE Breakout Board v1.1.csv` file that is located in the Hardware files folder<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here you can click on the `NEXT` button. (note 3), (note 4)

Note 3 - You can also use this page to omit parts from the assembly.  Please only do this if you understand what you are doing as omitting main parts of the design will lead to non-functioning boards.  We are not responsible for any non-functional boards. 

Note 4 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything, we would recommend you not proceed unless you understand how to find replacement parts.  If you are unsure, please feel free to join the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known good.  If all looks well press the `NEXT` button. (note 5)

Note 5 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do note work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 


## Donations

Every part of this project is open source: from the GP2040-CE firmware, to the original Pico Fighting Board design, to thisboard design.  

Donations are not necessary but always welcome!  All received donations will be split evenly between TheTrain and N-I-X.  TheTrain will typically use donations to pay for Discord boosts and try out new designs or sending boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2


## Revision History

v1.1
- Updated part placement and silk screen labels

v1.0
- Initial design


## Acknowledgments

- [TheTrain](https://github.com/TheTrainGoes) for doing the board design