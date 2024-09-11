# Vewlix NESiCA NFC Reader
![VVewlix NESiCA NFC Reader 01](Assets/NESiCA_Reader_01.JPG)

---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on the Vewlix Control Panel SiTong Adapter Rings by TheTrain

Copyright © 2024 [TheTrain](https://github.com/TheTrainGoes)

Special thanks to:
    [Lucipher](https://github.com/arntsonl)
    [NickGuyver](https://github.com/NickGuyver)
    [Wizzomafizzo](https://github.com/wizzomafizzo)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here


## Summary

The Vewlix NESiCA NFC Reader allows you to add a PN532 NFC module to your RP2040 based control panel setup.

There are two versions of this, one with RGB LED and one without. 

The reason I made this was to allow me to launch Nintendo Switch games at the tap of a card and not have to navigate to them manually.  It also allows me to hide buttons like `Home`, `Capture` and `- (select / insert coin)` from the main control panel.

Please note that I am not very strong in code writing so there are likely a number of optamizations which could be done.  

For this to work, you will need to write the include Arduino code to an RP2040 based device like the Pico or the Waveshare RP2040 Zero and then connect the pins on the boards directly to your RP2040 based board running GP2040-CE.  In my case I have the Ardunio code running on a Waveshare RP2040 Zero which is connected to an RP2040 Advanced Breakout Board.

I would not consider this project finished, but it is currently in a good working state.  

Please also note that the current RGB LED board must be hand soldered and cannot be assembled.

Future plans are:
1 - Make a custom board to interface with the RP2040 Advanced Breakout Board
2 - Look to add OLED support which will mimic the serial.print info
3 - Model a custom NESiCA reader that can be ordered from JLCPCB
4 - Make a SMD assembly version of the RGB LED board


## Basic Implementation

The basic implementation of this contains the following parts:
1 x NESiCA reader shell - https://www.aliexpress.us/item/3256806549568116.html
1 x PN532 NFC module - https://www.aliexpress.us/item/3256805740552837.html

You will then need an RP2040 based board to attach the PN532 NFC module to and something like the RP2040 Advanced Breakout Board to wire the RP2040 based board to.

You can also find a custom 3D printable bracket to hold the PN532 module [HERE](/3D%20Print%20Files/NESiCA%20Reader%20Bracket.stl).

In my case I am using a Waveshare RP2040 Zero and then connecting the pins on the board directly to my RP2040 Advanced Breakout Board running GP2040-CE.


## Advanced Implementation

The basic implementation of this contains the following parts:
1 x NESiCA reader shell - https://www.aliexpress.us/item/3256806549568116.html
1 x PN532 NFC module - https://www.aliexpress.us/item/3256805740552837.html
1 x NESiCA Reader RGB LED board - [HERE](/Hardware%20files/Gerber%20-%20NESiCA%20Reader%20RGB%20Board.zip)

For the advanced implemetation you can add an RGB LED board that will make the reader stay `white` and then turn `green` when an allowed card and `red` when a non-allowed card is tapped.

If you are making the NESiCA Reader RGB LED board you can find the spacer posts [HERE](/3D%20Print%20Files/NESiCA%20Reader%20Bracket%20-%20Short%20Post.stl) and [HERE](/3D%20Print%20Files/NESiCA%20Reader%20Bracket%20-%20Long%20Post.stl).

You will need some nuts and bolts to assemble everything.  They are M3 in size and I will update this at a later time with exact sizes.


## How The Arduino Sketch Works

The Arduino sketch allows you to read the UID of NFC cards and stickers that are tapped.  To read the value of a tapped card you will need to write the sketch to an RP2040 based device like a Pico or Waveshare RP2040 Zero and then leave it connected with the serial monitor running.  The serial monitor will show you information about the tapped cards.  

There is a good amount of documentation inside the sketch about what everything does and how to use it.

As a summart, when you tap a card or sticker the sketch will check the UID.  If the UID is in the allowed list it will make the LEDs (if you have them connected) turn green and do the inputs you have specified in the sketch.  If the UID is not in the allowed list it will make the LEDs (if you have them connected) turn red.  When an allowed UID is tapped it will process a series of inputs that can be used to do many things on a connected controller.

My examples are simple and allow you to input single buttons but you can also do a series of buttons to launch a game, press a combination of buttons for a shortcut or even press buttons that are not otherwise connected to your setup.

I will build this section out more when I have some time.


## Donations

Donations are not necessary but always welcome!  All received donations will be used for further prototyping.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v1.0
- Initial open source design

## Acknowledgments

- [TheTrain](https://github.com/TheTrainGoes) for doing the original design
