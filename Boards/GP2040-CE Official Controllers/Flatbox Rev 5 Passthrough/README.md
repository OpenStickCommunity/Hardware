# Flatbox Rev 5 Passthrough
![Flatbox Rev 5 Passthrough](Assets/Flatbox%20Rev%205%20Passthrough%20-%2001.jpg)

---

## Attribution

The following text must be included in any distribution of derivatives of this board. All links must also be included.

Based on the Flatbox Rev 5 Passthrough from the GP2040-CE project located at https://github.com/OpenStickCommunity/Hardware/tree/main/Boards/GP2040-CE%20Official%20Controllers/Flatbox%20Rev%205%20Passthrough
Based on the original Flatbox Flatbox Rev 5 project located at https://github.com/jfedor2/flatbox/tree/master/hardware-rev5

Copyright 2024 [TheTrain](https://github.com/TheTrainGoes)

[Licensed under CC BY 4.0](https://creativecommons.org/licenses/by/4.0/)

Changes from the original design:
  - list any changes you make here

---

## Summary: 

The Flatbox Rev 5 Passthrough aims to add USB passthrough to the Flatbox Rev 5 allowing easy access to a board which can use USB passthrough.

While BOM and CPL files are provided, it is recommended to order and assemble these yourself.

---

## How to order a board

All of the boards so far have been ordered though JLCPCB.  Due to minimum order numbers you would get five of these at a time.  It is not recommended to have these assembled by JLC due to cost.  If you are looking to have them assembled you should check out another project that has an embedded RP2040.

Please note that you will need to source and solder your own Waveshare RP2040-Zero board (or similar), passthrough port, tactile switches and hotswap sockets.

1 - Go to JLCPCB.com<br/>

2 - Click on `Instant Quote`<br/>

3 - Click on `Add Gerber file` and choose the file named `Gerber - Flatbox Rev 5 Passthrough.zip` from the `Hardware files` folder<br/>

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

If all looks well here you can click on the `SAVE TO CART` button.

5 - The `Secure Checkout` process will be different based on your location in the world.  We recommend researching your shipping options to choose the one that is right for your application. 

You will need the following parts to assemble the Flatbox Rev 5 USB passthrough:
6 x 6x6 tactile switches (height will depend on the case and button cap style you are intending to use, I went with 6x6x7 switches)
6 x tactile switch caps (these will also depend on how you want the finished product to look, I went with the newer rubber style ones) - 
1 x Waveshare RP2040 Zero, clone or similar (I went with the RP2040 SuperMini for this) - [LINK](https://www.aliexpress.com/item/1005005910512138.html)
1 x Mid-mount USB passthrough port - [LINK](https://www.aliexpress.com/item/1005005686242161.html)
12 x Kailh Choc v1 hot-swap sockets - [LINK](https://www.aliexpress.com/item/1005003873653184.html)
12 x Kailh Choc v1 or v2 switches

Please also note that only print files for the choc v1 caps are included.  If you want to use Choc v2 switches you will need to source your own print files for the caps.

Optionally you can also get some of the new Choc v1 caps that are popping up on AliExpress.  Please note that the ones linked [HERE](https://www.aliexpress.com/item/1005006902597750.html) are an odd shape and you will need to use [THIS](3D%20Print%20Files/Flatbox%20Rev%205%20Passthrough%20-%20Top%20Plate%20-%20Larger%20holes.stl) larger hole top plate print.

---

Attribution:


The main PCB was fully redesigned by myself (TheTrain) in EasyEDA.  All source files for this are located in the `Source Files` folder.

The case files are a modified version of the Flatbox Rev5 case remix by Additive Arcade located [HERE](https://github.com/pett-j/Flatbox-Remix).  You can check out the awesome stuff from Additive Arcade here: https://www.etsy.com/shop/AdditiveArcade

The buttons were designed from scratch by SGFDevices located [HERE](https://github.com/sgfdevices/Bridget/tree/main/Buttons).

---
