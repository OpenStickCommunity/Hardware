# USB Passthrough Kit - Installation Guide
![USB Passthrough Kit](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/USB_Passthrough_Kit.JPG)
---
## Summary
This is the installation guide for the USB passthrough kit.  Please make sure that you follow all steps here!  If you run into any trouble and need more help please join the OpenStick [Discord](https://discord.gg/k2pxhke7q8).

This kit is primarily designed to work with the RP2040 Advanced Breakout Board although it can be used with most RP2040 devices as long as you have appropiate pins available.  If you do not have a RP2040 Advanced Breakout Board you can jump to THIS section where I go over install on a Raspberry Pi Pico.

![RP2040 Advanced Breakout Board](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/RP2040_Advanced_Breakout_Boards.JPG)


---
## Installation Guide

Workspace Setup:
Prepare a clean work surface and get your RP2040 ADvanced Breakout Board, USB passthough board and cables ready.

![USB Passthrough Board](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/USB_Passthrough_Kit_with_RP2040_Advanced_Breakout_Board.JPG)

---

Step 1:

Take the USB passthough board and place it on a clean surface.

![Step_01](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_01.JPG)

---

Step 2:

Take one of the cables and place it on a clean surface.

Note: The cables are JST 2.00mm 2pin same direction cables that are 10cm (100mm) in length.  They can be made by hand or purchsed directly from a variety of sellers on AliExpress.  If you plan on installing the USB passthrough board somewhere else in your case you may want to get longer cables.  For this install guide you will need three of the cables.  

![Step_02](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_02.JPG)

---

Step 3:

Connect one end of the first JST 2.00mm 2pin cable into the socket labeled `5V IN` on the USB passthrough board.

Note: The direction of the cable does not matter as they are all same direction cables.  

![Step_03](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_03.JPG)

---

Step 4:

Connect the other end of the first JST 2.00mm 2pin cable to the socket labeled `5v OUT` on the RP2040 Advanced Breakout Board.

![Step_04](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_04.JPG)

---

Step 5:

Connect one end of the second JST 2.00mm 2pin cable into the socket labeled `D+ OUT` on the USB passthrough board.

![Step_05](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_05.JPG)

---

Step 6:

Connect the other end of the second JST 2.00mm 2pin cable to the socket labeled `OPTION 5` on the RP2040 Advanced Breakout Board.

Note: You can use other option sockts for this as well, but for the sake of this installation guide we will be using `Option 5` and `Option 6`. 

![Step_06](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_06.JPG)

---

Step 7:

Connect one end of the third JST 2.00mm 2pin cable into the socket labeled `D- OUT` on the USB passthrough board.

![Step_07](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_07.JPG)

---

Step 8:

Connect the other end of the third JST 2.00mm 2pin cable to the socket labeled `OPTION 6` on the RP2040 Advanced Breakout Board.

Congradulations!  You have now connected the USB passthrough board to your RP2040 Advanced Breakout Board!

![Step_08](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_08.JPG)

---

Firmware update and web-configuration:

In the following steps we will be updateing the firmware on your RP2040 Advanced Breakout Board and then making the necessary changes to web-configuration get you up and running.  If you prefer to not play around in the web-configuration, I have created a special version of the firmware with all of the necessary changes already made which can be found HERE. 

---

Step 9:

We will now connect the RP2040 Advanced Breakout Board to a computer to see what version of the firmware is currently on the board.  

Start by plugging a USB cable into the RP2040 Advanced Breakout Board.  

Note: Currently there are (officially) USB-C and USB-B versions of the RP2040 Advanced Breakout Board.  

![Step_09](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_09.JPG)

---

Step 10:

While holding the button labeld `WEB CONFIG` on the RP2040 Advanced Breakout Board plug the other end of the USB cable into your computer.

Your RP2040 Advanced Breakout Board will now be in web-config mode.

![Step_10](https://github.com/OpenStickCommunity/Hardware/blob/main/USB%20Passthrough%20Board/Vendor%20resources/Assets/Step_10.JPG)
