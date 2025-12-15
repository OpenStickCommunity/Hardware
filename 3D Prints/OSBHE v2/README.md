## OSBHE v2 - 24mm + 30mm - Open Source Button Hall Effect v2
![OSBHE v2 01](Assets/OSBHE%20v2%2001.JPG)
![OSBHE v2 02](Assets/OSBHE%20v2%2002.png)
![OSBHE v2 03](Assets/OSBHE%20v2%2003.png)

---

!!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!!
!!!WARNING!!! Please note that HE will be coming with v0.7.12 and is not yet in the main firmware.  It is recommended to wait until v0.7.12 is released incase there are updates needed to these files !!!WARNING!!!
!!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!! !!!WARNING!!!

!!!WARNING!!!

I am not responsible for prints that do not turn out as intended or any damages that occur as a result of installation or usage of these buttons.

!!!WARNING!!!

These have only been tested with Gateron Jade switches.  Other HE switches may work but have not been tested.

!!!WARNING!!!

If you are planning on having more than 3 or 4 HE buttons in your build (depending on the number of ADC pins on your RP2040 based board) you will also need a mux board.  Our open source mux board can be in the boards section under "HE Breakout Board".

!!!WARNING!!!

These buttons are not compatible with SiTong caps.  I may work on a remix that is.

!!!WARNING!!!


---

## Attribution

The following text must be included in any distribution of derivatives of this project or the boards. All links must also be included.

Based on the OSBHE v2 by TheTrain.

Copyright © 2025 [TheTrain](http://x.com/thetrain24)<br/>

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

Anyone selling this commercially must include in the listing that this is an open source item, link to the original repo and include the copyright as well as the link to my X account.

---

## Summary

The OSBHE v2 is a remix of the OSBMX v2 that is designed to work with Hall Effect switches. 

This also includes the new `Thin Nut` design that will allow you to have a closer button cluster on your panel.

---

## Board design choices

There is a new PCB design for the OSBHE v2.

Currently, the only option for connection is via a PS2.00mm 3pin connector.

---

## Assembly

Assembly is quite straight forward on this board.

Parts necessary for assembly of the PCBs:

1 x PCB<br/>
1 x PH2.00mm 3pin connector
2 x M2 5mm Hex Hexagon Socket Cap Head Self Tapping Screws (https://www.aliexpress.com/item/10000350027047.html)<br/>

Parts necessary for assembly of 3D printed button:

1 x OSBMX v2 Plunger<br/>
1 x OSBMX v2 Rim<br/>
1 x OSBMX v2 Main Body<br/>
1 x OSBMX v2 Nut or Thin Nut<br/>

Optionally you can also print a matching wrench to help with tightning and untighning.  I have not updated this so it uses the original OSBMX wrench.

You will also need aa compatible HE switch.  Currently, only the Gateron Jade switch has been tested.  Other switches may work.

---

## How to order a PCBs:

All of the boards so far have been ordered though JLCPCB.  Due to the size of the boards you can order quite a lot at very low cost.  I was able to order 125 of them and still meet their minimum shipping cost limits.  You do not need to get this many.  I have also opted not to do a panel for this since it appears to still be cheaper to get these done individually.  Also please note that recently JLCPCB changed some of their prices for the PCB color, ensure you choose a color like black or green to get the lowest possible cost.

1 - Go to JLCPCB.com<br/>
2 - Click on `Instant Quote`<br/>
3 - Click on `Add Gerber file` and choose the file named `Gerber - OSBHE v2.zip`<br/>
4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 22 * 22 mm<br/>
- PCB Qty = 100<br/>
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
- Confirm Production file = No<br/>
- Mark on PCB = Remove<br/>
- Flying Probe Test = Fully Test<br/>
- Gold Fingers = No<br/>
- Castellated Holes = No<br/>
- Edge Plating = No<br/>
- No advanced options<br/>

5 - Choose the following options for the PCB assembly
- PCBA Type = Economic (note 1)<br/>
- Assembly Side = Top Side (note 2)<br/>
- PCBA Qty = (however large your run will be, minimum of 2)<br/>
- Tooling holes = Added by Customer<br/>
- Confirm Parts Placement = Yes<br/>

Note 1 - Economic assembly is much cheaper on smaller batch runs.  

Note 2 - You can opt to have both top and bottom side assembly done but it will increase the cost greatly.  It is recommended to have the top side assembled and then you hand-solder the 3-pin connectors.

6 - Make sure you have read the terms and conditions of JLCPCB assembly service and then click on the `Confirm` button if you agree <br/>

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board<br/>

8 - You will now have the option to upload two files:
- For the `Add BOM File` you will need to choose the `BOM - OSBHE v2.csv` file that is located in the Hardware files folder
- For the `Add CPL File` you will need to choose the `CPL - OSBHE v2.csv` file that is located in the Hardware files folder<br/>
Once these two files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are not listed issues here you can click on the `NEXT` button. 

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known good.  If all looks well press the `NEXT` button. (note 11)

Note 11 - Please note that we are not responsible for boards made by JLCPCB or any other manufacturer that do note work.

11 - The quote & order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping.  Shipping will be calculated at a further step. 
- For Product Description I typically choose `Other` `Other` and type in `Controller board`.

If all looks well here you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 

---

## How to print the OSBHE v2:

A .3MF file is included which can be loaded into most slicers with a set of my recommended settings.  

To make each button you will need:
1 x OSBMX v2 Plunger<br/>
1 x OSBMX v2 Rim<br/>
1 x OSBMX v2 Main Body<br/>
1 x OSBMX v2 Nut or Thin Nut<br/>

The rim should be printed flat side down.  The nut or thin nut should also be printed flat side down.  

There are no supports needed for this print.  

It is recommended to print at the lowest print layer height your printer can do.  

I have printed and tested these on my BambuLabs X1C and P1S using both a 0.4mm and 0.2mm nozzle on normal and matte PLA.  

The recommended print setting are to do 4-6 wall loops and then enough top and bottom laters to have solid infill.  

You may need to adjust to achieve a good print on your own printer.  

!!!Please note - I am not responsible for missprints or any costs incurred from missprints!!!

---

## Donations

Every part of this project is open source, all prototyping costs were covered out of pocket.

Donations are not necessary but always welcome!  All received donations go into trying new things and ordering new boards for this and other projects.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2


---

Revision History:

v1.0
- Original design