# RP2040 Advanced Breakout Board v5.6 - Vendor resources - Advanced ordering from JLC

---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on RP2040 Advanced Breakout board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board and the RP2040 Advanced Breakout board - USB Passthrough Edition from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough.

Copyright 2024 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

---

## Summary

If you are planning to order a larger amount of boards (100+) and want to maxalize quality while minimizing defect rates please follow these order steps and not the ones on the main RP2040 Advanced Breakout Board v5.6 page.

If you are intested in having JLC do some or all of the testing and setup for you they can do these additional services for extra money.  I needed to contact `support@jlcpcb.com` with my list of requests and then note it on my order.  This resulted in an additional supplemental charge being added to my order that had to be paid before they proceeded with the order.  Through my experiences this added around $1.50 to each board but they have stated this may go up in the future.

Here was the process that I asked them to follow:<br/>
"1 - Plug in via USB-C<br/>
2 - Drag firmware file onto external drive that appears<br/>
3 - Check on https://hardwaretester.com/gamepad to see if device appears as a controller<br/>
4 - Press the `web-config` button on the board to see if it appears as the `start` button<br/>
5 - Flip over the USB-C to ensure both sides are working<br/>
6 - For the boards that also have USB-B, unplug USB-C and plug in USB-B to ensure connection is still there<br/>"

---

## Ordering Process

1 - Go to JLCPCB.com<br/>

2 - Click on `Order now`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - RP2040 Advanced Breakout Board v5.6E - PT.zip` from the `Hardware files` folder found [HERE](/Boards/GP2040-CE%20Official%20Boards/RP2040%20Advanced%20Breakout%20Board/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough/Hardware%20files/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough%20-%20USB-C/Gerber%20-%20RP2040%20Advanced%20Breakout%20Board%20-%20Version%205.6%20-%20PT.zip)<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 96.3 mm x 45.31 mm<br/>
- PCB Qty = (however large your run will be, minimum should be 100 for these instructions)<br/>
- Product Type = Industrial/Consumer electronics<br/>
- Different Design = 1<br/>
- Delivery Format = Single PCB<br/>
- PCB Thickness = 1.6<br/>
- PCB Color = (up to you)<br/>
- Silkscreen = (defaults to white for all except white boards which is black)<br/>
- Surface Finish = ENIG<br/>
- Gold Thickness = 1 U"<br/>

Under `High-spec Options`<br/>
- Outer Copper Weight = 1oz<br/>
- Via Covering = Tented<br/>
- Board Outline Tolerance = +/- 0.2mm (Regular)<br/>
- Confirm Production file = Yes <br/>
- Remove Order Number = Yes<br/>
- Flying Probe Test = Fully Test<br/>
- Gold Fingers = No<br/>
- Castellated Holes = No<br/>
- Edge Plating = No<br/>

Under `Advanced Options`<br/>
- No advanced options (keep as is)<br/>

5 - Choose the following options for the PCB assembly
- PCBA Type = Standard<br/>
- Assembly Side = Top Side<br/>
- PCBA Qty = Total number of boards you are ordering as per above<br/>
- Edge Rails / Fiducials = Added by JLCPCB<br/>
- Confirm Parts Placement = Yes<br/>

Under PCB Assembly `Advanced Options`<br/>
- Photo Confirmation = No<br/>
- Conformal Coating = No<br/>
- Packaging = Antistatic bubble film<br/>
- Solder Paste = Sn95%, Ag3.0%, Cu0.5%(260°C)<br/>
- Others = No<br/>
- Board Cleaning = Yes (*Note 1)<br/>
- Bake Components = No<br/>
- Depanel boards & edge rail before delivery = Yes (*Note 2)<br/>
- Add paste for unpopulated pad & step stencil opening = No<br/>
- Remark = *Note 3<br/>

Note 1 - It is recommended to have board cleaning done on larger batches.  Board cleaning is $0.15 per board and will be charged to you after you have paid you innitial bill.  This will be sent as a supplimental bill that must be paid before production begins on your order.

Note 2 - It is recommended to have board & edge rails depaneled before delivery.  The cost to have this done is $1.40 per order + $0.30 per board.  I assure you that you do not want to depanel 100x boards on your own.  

Note 3 - If you are going to be having JLC do any extra work on these board like flashing the firmware, testing ports, etc please note that in this section.  

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree <br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - RP2040 Advanced Breakout Board v5.6E - PT.csv` file that is located in the Hardware files folder [HERE](/Boards/GP2040-CE%20Official%20Boards/RP2040%20Advanced%20Breakout%20Board/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough/Hardware%20files/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough%20-%20USB-C/BOM%20-%20RP2040%20Advanced%20Breakout%20Board%20-%20Version%205.6%20-%20PT.csv)<br/>
- For the `Add CPL File` you will need to choose the `CPL - RP2040 Advanced Breakout Board v5.6E - PT.csv` file that is located in the Hardware files folder [HERE](/Boards/GP2040-CE%20Official%20Boards/RP2040%20Advanced%20Breakout%20Board/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough/Hardware%20files/RP2040%20Advanced%20Breakout%20Board%20-%20Passthrough%20-%20USB-C/CPL%20-%20RP2040%20Advanced%20Breakout%20Board%20-%20Version%205.6%20-%20PT.csv)<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button (*Note 4)

Note 4 - You will likely get an error about H3 and H4 not existing in the BOM.  These are the two optional headers for the debug and USB direct ports.  You can click `Continue`.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here and there are no shortfalls on any parts you can click on on the `NEXT` button. (*Note 5), (*Note 6), (*Note 7), (note 8), (note10)

Note 5 - You can also use this page to omit parts from the assembly.  This can primarily be used to not include specific headers or the screw terminals.  Please only do this if you understand what you are doing as omitting main parts of the design will lead to non-functioning boards.  We are not responsible for any boards that are non-functioning. 

Note 6 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything we would recommend you not proceed unless you understand how to find replacmeent parts.  If you are unsure, please feel free to join up in the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

Note 7 - Occasionally JLC will not correctly load the BOM file and there will be parts that are not linked to their proper part number.  You can either reference the BOM file directly and update these or try loading the BOM file again into JLC.  Please note that we are not responsible for board made by JLCPCB or any other manufacturer that do note work due to incorrect parts being entered into the parts selector.

Note 8 - Some of the basic LEDs are being phased out by JLC.  Unless you have stock of them already the 0603 yellow LED (part number C72038) can be used.  If you want a different color you can explore other 0603 footprint LEDs that will meet your needs.  To replece the LED click on the magnifying glass image for the line with `LED3` on it.  In the `search` field put in `C72038` and click `search`.  Check the stock of this part listed under `JLCPCB Stock` and if there are enough you can click on the `Select` button at the end of the line.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known good.  If all looks well press the `NEXT` button. (*Note 11)(*Note 12)

Note 11 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do not work.

Note 12 - In some cases you will get a pop up box called `Confirm Parts Placement` letting you know they are force adding the `Confirm PArts Placement` and `Confirm PCB Production File` options.  This is OK, we have already selected them.  You can click on `OK`.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 

Please remember that if you selected the `board cleaning`, `depaneling` and are having additinoal services done like flashing etc you may get additinoal supplementry bills that must also be paid before prduction is started.
