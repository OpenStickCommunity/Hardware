# Hori Fighting Edge PS4 (FE PS4) Drop-in Replacement Board
![Hori FE PS4](Assets/Hori%20Fighting%20Edge%20PS4.JPG)

---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Copyright © 2023 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here


## Summary

The Hori Fighting Edge PS4 (FE PS4) Drop-in Replacement Board is designed to be a quick and easy drop-in solution for the Hori Fighting Edge PS4.

Please note that I do not consider this board to be finished.  Hori uses some tricks to get their three-way sliders working so currently those are not mapped here.  There may be a further revision if I can figure that out.

The Trackpad is currently mapped as a single button press assigned to a GPIO pin.  

Please also note that there is no set configuration for this board and you may need to configure on your own until I post a dedicated configuration for it.  Until then please reference the source files for the pinout of the RP2040.

Given that I do not consider this board finished, please proceed at your own risk!  I will not answer any questions about ordering the boards or setup, and no support will be offered on it.  If you do not know how to order a board from JLCPCB with assembly this might not be for you.

When ordering through JLCPCB you may see that one of the screw terminal sets is backwards.  I am not sure why this is as it is correct in EasyEDA.  Make sure to add a note about its orientation and pay the extra $0.50 to have placement and the board checked.

A STEP model is available [HERE](3D%20Files/STEP%20-%20Hori%20Fighting%20Edge%20PS4.step) although it is not really needed since this board directly replaces the original board.

You will need to rewire the main 8 buttons + the start button as they are soldered onto the original board.  

As a fun fact about the Hori FE PS4, you can move the original board to the slot to the right of the new one and then connect it to the USB passthrough port to do auth off of.  Instructions to do this are not included since it requires lots of soldering and is very much done at your own risk.


## Sales recommendations

It is not recommended to sell this board as it is not completed yet and should only be used for hobby purposes.


## Donations

Donations are not necessary but always welcome!  I typically use donations to try out new designs or send boards to people for testing, iterations and helping people get board setups that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2

## Revision History

v1.0
- Initial open source design

## Acknowledgments

- [TheTrain](https://github.com/TheTrainGoes) for doing the board design
