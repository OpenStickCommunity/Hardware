# Flatbox Rev 5 RGB v2.0
![Flatbox Rev 5 RGB - Art Case](https://github.com/TheTrainGoes/flatbox-rev5-rgb/blob/main/Flatbox%20rev%205%20RGB%20case%20-%20Art%20Case/Images/Flatbox%20rev%205%20RGB%20-%20Art%20Case.jpg?raw=true)
![Flatbox Rev 5 RGB - Art Case (illuminated)](https://github.com/TheTrainGoes/flatbox-rev5-rgb/blob/main/Flatbox%20rev%205%20RGB%20case%20-%20Art%20Case/Images/Flatbox%20rev%205%20RGB%20-%20Art%20Case%20(illuminated).jpg?raw=true)
---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on the Flatbox Rev 5 RGB v2.0 from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/Flatbox%20Rev%205%20RGB%20v2.0
Based on the original Flatbox Flatbox Rev 5 project located at https://github.com/jfedor2/flatbox/tree/master/hardware-rev5

Copyright 2023 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

---

## Summary: 

The Flatbox Rev 5 RGB v2.0 is a three-part project that offers RGB and premium construction features to the existing Flatbox Rev 5. 

There are three version of the Flatbox Rev 5 RGB v2.0:
- Flatbox Rev 5 RGB v2.0 - Basic
- Flatbox Rev 5 RGB v2.0 - Art Case
- Flatbox Rev 5 RGB v2.0 - Premium Art Case

Please note that all three of these versions use the same PCB.

The `basic` verion is a remake of the Flatbox Rev 5 PCB that has a modified case to include Player LEDs as well as cutouts for tactile switch caps over the flaps that are present on the basic Rev 4 and Rev 5 cases.
The `art case` version goes a step further and offers a unique case design that uses a mid-frame drop in (idea taken from Mavercade and their line of Keebfighters) as well as a top plexi layer.
The `Premium Art Case` version adds a bottom aluminum plate and foam to the `art case` version while also removing some height from the main body of the `art case` version.

The top plexi is a .DXF file which should be usable by most places that can cut plexi.  It is recommended to do this part in 1-2mm plexi.

Please note that printing the buttons in white resin will allow the LEDs to show through better, but there are no issues with printing them in PLA with a normal 3D printer.  I prefer to have them done in PA12 black nylon.

---

## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these at a time.  As a bonus, if you do not choose to have all of them populated with parts you will still have usable boards as basic Flatbox Rev 5 boards.  Here are the steps to make your first order and what options I choose along the way.

Please note that you will need to source and solder your own Waveshare RP2040-Zero board as that is not a part JLC can get and assemble for you.


Please also note that this version has the auxiliary tactile switches pre-connected.  They are a length that will work with the plastic caps you can get from AliEXpress.  If you would rather not use these please omit them from the BOM and CPL.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - Flatbox Rev 5 RGB v2.0.zip` from the `Hardware files` folder<br/>

4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 210 mm x 120 mm<br/>
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

Note 4 - Economic assembly is much cheaper on smaller batch runs of 10-30 units.  Standard assembly will yield less dead on arrival boards but is more expensive to have done.  On average I expect a 5-10% failure rate on the boards from JLC so please factor that in when making your order.

Note 5 - This adds around $1 to the total cost of the order and is 100% worth doing as they will check the placement of all SMD parts and make any necessary changes or reach out if there are concerns.  I cannot stress enough that this is the best $1 you will spend for the peace of mind of not messing up an entire batch.

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree.<br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board.<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - Flatbox Rev 5 RGB v2.0.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - Flatbox Rev 5 RGB v2.0.csv` file that is located in the Hardware files folder<br/>

Once these two files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here you can click on on the `NEXT` button. (note 6), (note 7)


Note 6 - You can also use this page to omit parts from the assembly.  Please only do this if you understand what you are doing as omitting main parts of the design will lead to non-functioning boards.  We are not responsible for any boards that are non-functioning. 

Note 7 - We have spent extensive time to ensure that the parts chosen will work for this board.  If there are any parts that are out of stock, or you get warnings about anything we would recommend you not proceed unless you understand how to do find replacmeent parts.  If you are unsure, please feel free to join the Discord and ask us.  It is not uncommon for JLCPCB to have part shortages.  Most of the parts listed here come back in stock in a few days.  If that is the case, you may need to wait to place your order until all needed parts are in stock.

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known good.  If all looks well press the `NEXT` button. (note 8)

Note 8 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do not work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

** Please note that if you are planning to order the FLatbox Rev 5 RGB v2.0 premium aluminum bottom plate you will need to add an additional board to the order before checking out. **

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 

---

Attribution:


The main PCB was fully redesigned by myself (TheTrain) in EasyEDA.  All source files for this are located in the `Source Files` folder.

The case files were designed by myself (TheTrain) from scratch.  They were based on the case design of the Mavercade Keebfighter.  You can check out the awesome Mavercade Keebfighters here: https://mavercade.com/collections/mavercade-keebfighters

The buttons were designed from scratch by SGFDevices: https://github.com/sgfdevices/Bridget/tree/main/Buttons

---

