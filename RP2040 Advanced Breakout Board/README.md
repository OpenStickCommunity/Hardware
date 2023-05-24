# RP2040 Advanced Breakout Board
![rp2040_advanced_breakout_board](https://github.com/OpenStickCommunity/Hardware/assets/440158/6245f3fc-1d2b-4c7a-83c1-52d48b58f4c8)
---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on RP2040 Advanced Breakout board from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/RP2040%20Advanced%20Breakout%20Board

Copyright 2023 [TheTrain](https://github.com/TheTrainGoes) and [n-i-x](https://github.com/n-i-x)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

## Summary

The RP2040 Advanced Breakout Board is the official embedded design for the GP2040-CE project.

You can find a pre-compiled .UF2 firmware file for the RP2040 Advanced Breakout Board in the GP2040-CE release section under `GP2040-CE_0.X.X_RP2040AdvancedBreakoutBoard.uf2`.  This configuration will be maintained as long as the project is active and the pinout will not change.  Should there be another version of the board, it will be kept as a seperate hardware entry.

The RP2040 Advanced Breakout Board is an embedded design based on the original Pico Fighting Board (https://github.com/FeralAI/PicoFightingBoard) by FeralAI.

The RP2040 Advanced Breakout Board is an embedded SMD design with through hole components.  It is not recommened to assemble these yourself unless you have a setup to do SMD assembly.

With the RP2040 Advanced Breakout Board using an embedded RP2040 chip, we are able to access all of the additional GPIO pins that are not easily accessible on the standard Raspberry Pi Pico board.  This allows us to have many more options on the board so that people can make truly unique and custom contollers.

We have a small but passionate Discord group which you can access here if interested: https://discord.gg/k87GQU2n

A massive thank you to FeralAI who made most of this possible!

## Board design choices

The Brook form factor was chosen due to its compatibility with a number of existing enclosures and holders.

A 4pin (1x4pin) JST 2.00mm connector labeled `expansion` can be found on the left side that allows for either a compatible OLED display to be connected or general I2C expansion add-ons.

A 4pin (1x4pin) 2.54mm connector labeled `toggle` can be found on the left side that allows for the connection of common toggle switches found on some arcade sticks.  These are generally used for actions like a LS/DP/RS or SOCD toggle.  As these are normal GPIO pins they can be mapped to anything you wish via the web-config.

A 3pin (1x3pin) JST 2.00mm connector labeled `RGB LED` can be found on the left side that allows for the connection of addressable RGB LEDs.  A list of compatible RGB LED types can be found HERE.

A 20pin (2x10pin) 2.54mm connector is located in the bottom left of the board, matching the location and pinout of standard Brook boards.  If you are planning to use the 20pin connector you do not need to use the screw terminals on the board and vice versa if you prefer to wire a stick yourself.

A 4pin (1x4pin) JST 2.00mm connector is located beside the 20pin connector which can be used with the standard Brook 4-pin harness allowing for access to A2, L3 and R3.

Six 2pin (1x2pin) JST 2.00mm connector labeled `option X` can be found along the bottom of the board.  These can use assigned via the web-config to setup any number or combination of features such as dual direction, turbo, reverse direction, etc.

A 2pin (1x2pin) JST 2.00mm connector labeled `5v out` can be found on the right side of the board which can be used for connecting additional devices needing to be powered via 5v such as an additional board like the Antagonist v2.0 or a strip of remote controlled LEDs.  Please take note of the power draw these connected devices will have and ensure you are not drawing too much power.

A 20pin (1x20pin [5x4pin]) 3.5mm screw terminal row can be found along the top of the board which allows for an additional way to connect joysticks and buttons to the board should you not want to use the 20pin harness.  This screw terminal row also has access to `option 1`.

A USB-C port can be found on the right side of the board.  USB-C was chosen as it is the current industry standard and can allow for very low profile builds should you choose to make a version of the board with depopulated headers.

There are three buttons on the board:
  - A BootSel button, which can be held when plugging in to enter BootSel mode which is used to flash the device with firmware.
  - A reset button, which can be pressed to reset the device.
  - A web-conifg button, which can be held while plugging in to go to web-config mode.

Please note that web-config can also be accessed by pressing and holding S2.  This is an extra mapping of S2 to allow for easy access and setup of the web-config utility for those that are working on raw boards not already installed or connected to anything.

A 3pin (1x3pin) 2.54mm header area labeled `debug` can be found near the middle of the board.  This allows those interested to debug the RP2040.  It requires either a 1x3pin 2.54mm header to be soldered or wires to be connected directly.

A 5pin (1x5pin) 2.54mm header area labeled `USB direct` can be found near the right of the board.  This allows for direct connection of a USB connection.  A double ground is common in commercial fightsticks so it has been included here.  Please take note of the exact pinout on the USB cable you are trying to connect here as there is no universal standard for the order of the wires.  We are not resposible for any damages that occur as a result of incorrectly wiring the USB direct area.

## Assembly

These boards are designed to be made and assembled by JLC PCB.  As such, you will find a folder called `Hardware files` that contains a copy of the three files needed to have these boards made by JLC PCB.

Those files are:
- A gerber file for the design of the board
- A BoM file for the list of parts to be assembled
- A PnP file for the placement of the parts in the BoM file

This design includes both SMD and through hole parts from JLC PCB.  There are additional costs associated with having through hole parts added to the board.  You can reduce overall costs by removing headers that are not needed for your specific application of the board.  This can be done in EasyEDA directly by choosing to exclude the part from the BoM before exporting the necessary files.

These boards have been designed to be fully assembled by JLC PCB.  You will not need to do any soldering or assembly of any kind should you order a batch of them.  The only thing you will need to do is flash the boards with the most recent version of GP2040-CE and then test the boards.

Please note that we are not responsible for issues that arise from the manufacturing of these boards done through JLC PCB or any other manufacturer.  These board files have been ordered and tested for functionality.

## How to order a board

All of the boards so far have been ordered though JLC PCB.  Due to minimum order numbers you would get at least five of these basic breakout boards.  Here are the steps to make your first order and what options I choose along the way.

1 - Go to JLCPCB.com

2 - Click on `Instant Quote`

3 - Click on `Add Gerber file` and choose the file named `Gerber - RP2040 Advanced Breakout Board v5.2E.zip` from the `Hardware files` folder

4 - Choose the following options for the board:
- Base Material = FR-4
- Layers = 2
- Dimensions = (should auto-populate) 96.3 mm x 45.31 mm
- PCB Qty = (however large your run will be, minimum of 5)
- Product Type = Industrial/Consumer electronics
- Different Design = 1
- Delivery Format = Single PCB
- PCB Thickness = 1.6
- PCB Color = (up to you)
- Silkscreen = (defaults to white for all except white boards which is black)
- Surface Finish = HASL(with lead)
- Outer Copper Weight = 1oz
- Via Covering = Tented
- Board Outline Tolerance = +/- 0.2mm (Regular)
- Confirm Production file = Yes
- Remove Order Number = Yes
- Flying Probe Test = Fully Test
- Gold Fingers = No
- Castellated Holes = No
- No advanced options

5 - Choose the following options for the PCB assembly
- PCBA Type = Economic
- Assembly Side = Top Side
- PCBA Qty = (however large your run will be, minimum of 2)
- Tooling holes = Added by Customer
- Confirm Parts Placement = Yes

6 - Make sure you have read the terms and conditions of JLC PCB assembly service and then click on the `Confirm` button if you agree

7 - The Bill of Materials page will show you a render of the board without parts.  You can click the `NEXT` button here unless you see any issues with the board

8 - You will now have the option to upload two files. For the `Add BOM File` choose the `BOM - RP2040 Advanced Breakout Board v5.2E.csv` file from the Hardware files folder. For the `Add CPL File` choose the `CPL - RP2040 Advanced Breakout Board v5.2E.csv` file from the Hardware files folder. Once both files have been uploaded you can press the `Process BOM & CPL` button.

9 - You will now see a list of components that will be used to assemble the boards.  If there are no issues here you can click on the `NEXT` button.
- *You can also use this page to omit parts from the assembly.  Please only do this if you understand what you are doing as omitting main parts of the design will lead to non-functioning boards.  We have spent extensive time to ensure that the parts chosen will work for this board.  If you get warnings about anything, we recommend you not proceed.  We are not responsible for modified boards that are non-functioning.  If you are unsure, please feel free to join the Discord and ask us.*
    ***Please note that it is not uncommon for JLC PCB to have part shortages. Most of the parts listed here come back in stock in a few days, so waiting on your order may be necessary.***

10 - There will now be a render of the board with parts on the Component Placements page.  Check this page to make sure that all parts are in the correct spots and orientation.  We have ordered based on these files before and they are known to be correct.  If everything looks well press the `NEXT` button.  ***Please note that we are not responsible for faulty boards made by JLC PCB or any other manufacturer.***

11 - The Quote & Order page will give you a breakdown of the costs associated with the boards and assembly parts based on the quantity you have chosen. This does not include shipping, which will be calculated at a later step. For Product Description I typically choose `Other` and type in `Controller board`. If everything looks correct you can click on the `SAVE TO CART` button.

12 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your needs.

## How to upload firmware

The latest firmware release can be downloaded at the GP2040-CE page here: https://github.com/OpenStickCommunity/GP2040-CE/releases/latest. You will want the file labeled `GP2040-CE_X.Y.Z_RP2040AdvancedBreakoutBoard.uf2` (X.Y.Z label is 0.7.1 as of this README).

To upload the firmware, hold the BootSel button on the board while plugging the device into your computer.  It should show up as an external storage device.  Copy the `GP2040-CE_X.Y.Z_RP2040AdvancedBreakoutBoard.uf2` file to this device and it will restart itself after the upload is complete.

If something goes wrong and you want to upload the firmware again (or if you have tested out the configuration tool and made a mistake) you can enter BootSel as above and drag over the included `flash_nuke.uf2` file.  This file will take a moment to write to the Pico which will restart once completed and re-connect as an external storage device.  After it has shown up again you can copy the same `GP2040-CE_X.Y.Z_RP2040AdvancedBreakoutBoard.uf2` firmware over to it as before.

## Sales recommendations

Through the licensing you are free to make and sell these boards in group buys or even commercial applications. The intended purpose of this board, as well as the overall GP2040-CE project, is to get low cost boards into the hands of as many people as possible so everyone can enjoy the project. As such, we have a recommended MSRP of $20 USD for the RP2040 Advanced Breakout Board or $30 USD with free shipping within the USA or Canada

You are free to set your own price as you see fit.

## Donations

Every part of this project is open source, from the GP2040-CE firmware to the original Pico Fighting Board design and also this RP2040 Advanced Breakout Board design.

Donations are not necessary but always welcome!  All received donations will be split evenly between TheTrain and N-I-X.  TheTrain will typically use donations to pay for Discord boosts and try out new designs or sending boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v5.2e
- Added larger solder pads on the debug and USB direct sections

v5.1e
- Changed the routing of some parts
- Other minor changes

v5.0e
- Initial design

## Acknowledgements

- [n-i-x](https://github.com/n-i-x) from [acustomarcade.com](https://acustomarcade.com/) for helping with the board design
- [TheTrain](https://github.com/TheTrainGoes) for helping the board design
- FeralAI for starting the GP2040 project and the original design of the Pico Fighting Board
- Everyone that works on the GP2040-CE project to make it the best controller firmware around
