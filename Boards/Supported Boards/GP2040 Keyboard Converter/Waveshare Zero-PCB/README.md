# GP2040-CE Keyboard Converter

![GP2040-CE Keyboard Converter Case IRL](assets/GP2040-CE-Keyboard-Converter-Case-IRL.jpg)

---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Copyright 2023 [InfraredAces](https://github.com/InfraredAces)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

## Summary

The GP2040-CE Keyboard Converter is designed to be a USB Host Device for the use of a keyboard with the GP2040-CE project. The end result is a device that allows you to play on a keyboard, but have it registered as a GP2040-CE controller, whether that is XInput, DInput, PS4, or Switch.

You can find a pre-compiled .UF2 firmware file for the RP2040 Advanced Breakout Board in the GP2040-CE release section under `GP2040-CE_X.X.X_WaveshareZero-KeyboardConverter.uf2`.

We have a small but passionate Discord group which you can access here if interested: https://discord.com/invite/k2pxhke7q8

A massive thank you to [FeralAI](https://github.com/FeralAI) who made most of this possible!

## Assembly

### Circuit Board

These circuit boards are designed to be ordered through a PCB fabricator and components soldered on by the end user.    

Once the circuit boards have been fabricated and received the following parts are necessary for assembly.

| Solder Order | Component Name | Quantity Required Per Board | Link to Example Component |
| :----------: | :------------- | --------------------------: | :-----------------------: |
| 1 | Waveshare Zero (**without headers**) | 1 | [Waveshare - Waveshare Zero](https://www.waveshare.com/product/rp2040-zero.html) |
| 2 | USB A THT Port | 1 | [DigiKey - USB-A-S-RA-SMT](https://www.digikey.com/en/products/detail/adam-tech/USB-A-S-RA-SMT/9832349) |
| 3 | 6x6x13.5mm THT Tactile Switch | 6 | [DigiKey - TL1105KF160Q](https://www.digikey.com/en/products/detail/e-switch/TL1105KF160Q/1805437) | 

Note: THT: Through Hole Technology Mounting 

It's recommended that the Waveshare Zero be flashed first with the most recent version of GP2040-CE and then the boards tested for proper functioning before soldering to the primary board.

Please note that we are not responsible for issues that arise from the manufacturing of these boards done by any manufacturer.  These board files have been ordered and tested for functionality.  

### 3D Printed Case

![GP2040-CE-Keyboard-Converter-Case-Assembled](assets/GP2040-CE-Keyboard-Converter-Case-Assembled.png)

![](assets/GP2040-CE-Keyboard-Converter-Case-Top.png)

![](assets/GP2040-CE-Keyboard-Converter-Case-Bottom.png)

| Hardware Name | Quantity Required Per Board | Link to Example Hardware |
| :------------: | --------------------------: | :-----------------------: |
| M2x18mm Screws | 4 | [McMaster-Carr](https://www.mcmaster.com/92000A024/) |
| M2x1.6mm Nuts | 4 | [McMaster-Carr](https://www.mcmaster.com/90592A075/) |

The screws are inserted through the top and pass though the PCB and out the bottom. The nuts can be embedded in the recesses on the bottom of the case. An alternative is to use glue to hold them permanently in place.

## How to upload firmware

### Uploading the firmware before assembly

Hold the BootSel button on the Waveshare Zero and plug the device into your computer.  It will show up as an external device.  Copy the `GP2040-CE_X.X.X_WaveshareZero-KeyboardConverter.uf2` file to it and wait for the device to disconnect after copying completes.  

### Uploading the firmware after assembly

Plug the GP2040-CE Keyboard Converter into your computer and quickly press the BootSel button twice on the GP2040-CE Keyboard Converter.  You should see an external device show up on your computer.  Copy the `GP2040-CE_X.X.X_WaveshareZero-KeyboardConverter.uf2` file to it and wait for the device to disconnect after copying completes.  

### Flashing for Troubleshooting
If something goes wrong and you want to upload the firmware again (or if you have tested out the configuration tool and made a mistake) you can enter BootSel mode via either of the methods above and drag over the included `flash_nuke.uf2` file.  This file will take a moment to write to the Pico, once completed you will see the device disconnect and then re-connect as an external device.  After it has shown up again you can copy the same `GP2040-CE_X.X.X_WaveshareZero-KeyboardConverter.uf2` firmware over to it again.

## Sales recommendations

Through the licensing, you are free to make and sell these boards in group buys or even commercial applications.  

The intended purpose of this board, as well as the overall GP2040-CE project is to get low cost boards into the hands of as many people as possible to everyone can enjoy the project.  

As such, we have a recommend MSRP of $20 USD for the GP2040-CE Keyboard Converter or $30 USD with free shipping within the USA or Canada.

You are free to set your own price as you see fit. 
## Acknowledgements

- [FeralAI](https://github.com/FeralAI) for starting the GP2040 project and the original design of the Pico Fighting Board
- Everyone that works on the GP2040-CE project to make it the best controller firmware around
