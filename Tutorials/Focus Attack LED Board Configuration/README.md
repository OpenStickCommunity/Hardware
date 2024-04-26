# Focus Attack LED Kit - Installation Guide for GP2040-CE on an RP2040 Advanced Breakout Board v5.6
![Focus Attack LED Kit](Assets/FA_LED_01.JPG)

---
## Summary

This is the unofficial installation guide for the Focus Attack LED kit.  Please make sure that you read this guide fully before asking questions on our Discord server.  

** Please note that the GP2040-CE / Open Stick Community is not responsible for any damages that happen to the LED modules, your board or any other pcrephials from incorrect instillation or configuration. **

If you have read this fully and are still running into trouble and need more help please join the OpenStick [Discord](https://discord.gg/k2pxhke7q8).

** Please note that you will need to contact Focus Attack if there are any hardware based issues with your LED kit. **

This kit is primarily designed to work with the RP2040 Advanced Breakout Board although it can be used with most RP2040 devices as long as you have appropiate pins available.  This guide has been centered around the RP2040 Advanced Breakout Board v5.6 which is also sold at Focus Attack.

The LED kits can be found on Focus Attack [HERE](https://focusattack.com/fa-30mm-button-rgb-led-8-pak-for-gp-2040-ce/).
Focus Attack also has a dedicated website section where individual parts can be purchased [HERE](https://focusattack.com/hardware-pcb/by-interest/led-lighting/).

Please note that the LED satellite modules were designed and made by 32Teeth and the adapter board was designed by TheTrain.

---
## Installation Guide

Workspace Setup:
Prepare a clean work surface and get your RP2040 Advanced Breakout Board, LED kit and cables ready.

Note: Your setup may look different than this.  

![FA_LED_01](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_01.JPG)

It is important to note that there are two different kinds of cables included with the LED kit.  I will refer to these as `Straight` and `Flipped` cables in the tutorial.

`Straight` cables are those that have the connector facing the same orientation (up/down) on each side.
`Flipped` cables are those that have the connector facing in an opposite orientation (up/down) on each side.

In the below picture, you can see that the top shorter cable is a `Flipped` cable which has the connector facing in an opposite orientation (up/down).  The bottom longer cable is a `Straight` cable which has the connector facing in an opposite orientation (up/down) on each side.

Note: You may get wires that are different colors other than black with your kit.  This does not matter.

![FA_LED_02](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_02.JPG)

---

Step 1:

Take the short `Straight` cable and plug it into the side marked `IN` on the LED adapter board.  

Note: This may have come connected to your LED adapter board already.  If so, plese check the cable to ensure it is the proper `Straight` cable.  If it is not, please replace it with a `Straight` cable.

![FA_LED_06](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_06.JPG)

---

Step 2:

Plught the  other end of the `Straight` cable into the RP2040 Advanced Breakout Board v5.6 in the slot labeled `RGB LEDs`.

Note: If you have another version of the RP2040 Advanced Breakout Board or a board by a different maker the location and label may be different.  If you are having trouble finding this on another board please contact the board maker.

![FA_LED_07](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_07.JPG)

---

Step 3:

Find the longer `Flipped` cable.

![FA_LED_08](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_08.JPG)

Take one of the LED satellite and locate the connector marked `in` on it.

![FA_LED_09](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_09.JPG)

Plug the longer `Flipped` cable into the side marked `OUT` on the LED adapter board and then the connector marked `in` on the LED satellite.

![FA_LED_10](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_10.JPG)


---

Step 4:

Plug in your RP2040 Advanced Breakout Board v5.6 to ensure that you are seeing the two LEDs on your satellite light up.

Note: If they are not, please go back to the beginning of this tutorial and ensure you have connected the correct wires to the correct places.  If you are still having issues try connecting to a different LED satellite.  If that satellite works but the first one does not ensure you are connecting to the right connector on the satellite.  If you are sure you are connecting to the correct connector on the satellite and you are still not getting anything on one satellite but are getting something on another you may have a bad satellite and should contact Focus Attack.

Note 2: You can take this as an opportunity to test all of your satellites before doing a full install.  Please ensure that you unplug the RP2040 Advanced Breakout Board v5.6 inbetween each test.

![FA_LED_11](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_11.JPG)

---

Step 5:

Locate one of the small `Flipped` cables.

![FA_LED_12](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_12.JPG)

Locate the connector marked `out` on the first LED satellite and the connector marked `in` on the next LED satellite you want to connect`.

![FA_LED_13](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_13.JPG)

Once connected your LED satellites should look somehthing like this.

![FA_LED_14](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_14.JPG)

Note: You can also take this as an opportunity to connect the RP2040 Advanced Breakout Board v5.6 to see if the chain of LED satellites are working as intended.

![FA_LED_15](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_15.JPG)

Here is what your setup may look like after you have connected 5 LED satellites.

![FA_LED_16](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_16.JPG)

And here is what it looks like when you have 5 LED satelites set to show solid green.

Note: By default you will see a chasing rainbow animation.  This can be change via a hot-key configuration.  Please consult the main GP2040-CE website for more information on this.

![FA_LED_17](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_17.JPG)

---

Step 6:

Now that your LEDs are connected you will notice that pressing a button only results in one LED on the satellite changing color, not both.

![FA_LED_18](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_18.JPG)

We will need to go into the GP2040-CE web-config to change that.  In order to access web-config you do one of the following:

1 - Hold the `web-config` button on the RP2040 Advanced Breakout Board while plugging it into the computer.
2 - Hold your `start` button while while plugging it into the computer.
3 - Hold your `start`, `P1` and `P2` buttons for 5 seconds while the RP2040 Advanced Breakout Board is already plugged in.

![FA_LED_19](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_19.JPG)

---

Step 7:

To access web-config while the RP2040 Advanced Breakout Board is in web-config mode navigate to `192.168.7.1` in your browser.

![FA_LED_20](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_20.png)

Click on `Configuration` and then `LED cConfiguration`.

![FA_LED_21](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_21.png)

In the `RGB LED Configuration` section find the entry box for `LEDs Per Button`.

![FA_LED_22](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_22.png)

Change the `LEDs Per Button` from `1` to `2`.

![FA_LED_23](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_23.png)

Scroll down to the bottom of the page and click on the `Save` button.

![FA_LED_24](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_24.png)

You should see the following message pop up indicating that the save was sucessful.

![FA_LED_25](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_25.png)

---

Step 8:

While you are in web-config, its a great time to change your LED `Assigned Buttons` order.

This order needs to match the order that you have installed the LED satellites in.

As an example, if you connected your LED satellites as `P1` -> `K1` -> `P2` -> `K2` etc you will need to drag the `Assigned Buttons` into that order as well.

Note: If you do not have any LED satellites connected to the main direcitons `Up`, `Down`, `Left` or `Right` you cna drag those from the right column to the left one.

![FA_LED_26](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_26.png)

This is what your list may look like after changing it.

![FA_LED_27](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_27.png)

Make sure you scroll down to the bottom of the page and click on the `Save` button again.

![FA_LED_24](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_24.png)

Note: It is expected that your web-config may show the old order of the LEDs after pressing the `Save` button.  This is OK, you can unplug and plug back in your RP2040 Advanced Breakout Board v5.6.

---

Step 9:

You should now see that pressing your buttons results in the correct number of LEDs being illuminated.

![FA_LED_28](https://github.com/OpenStickCommunity/Hardware/blob/main/Vendor%20Resources/Focus%20Attack%20LED%20Board%20Configuration/Assets/FA_LED_28.JPG)

---

Congratulations!  

You have successfully setup your Focus Attack RGB LED kit on the RP2040 Advanced Breakout Board.

Go play some games :)
