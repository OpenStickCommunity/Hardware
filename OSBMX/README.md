![OSBMX Buttons](https://github.com/TheTrainGoes/GP2040-Projects/blob/main/Open%20Source%20Buttons/OSBMX/OSBMX%20Buttons.JPG)
![OSBMX PCB](https://github.com/TheTrainGoes/GP2040-Projects/blob/main/Open%20Source%20Buttons/OSBMX/OSBMX%20PCB.png)
![OSBMX PCB 2.4mm](https://github.com/TheTrainGoes/GP2040-Projects/blob/main/Open%20Source%20Buttons/OSBMX/OSBMX%20PCB%20-%202.4mm.png)

OSBMX 24 / OSBMX 30
Open Source Button MX 24mm and 30mm buttons
---

!!!WARNING!!!

I am not responsible for prints that do not turn out as intended or any damages that occur as a result of installation or usage of these buttons.

!!!WARNING!!!

JLCPCB is known for flagging issues before producing these buttons.  I have re-made most of the standard files to comply with the 1.5mm minimum size for sprue rails in resin.  This may still lead to an error if you are having them done in nylon PA12 or another material.  I have always approved these errors and never run into any issues but please use your best judgement and think critically about what the error is they are reporting before approving.  Again, I am not responcible for prints that do not turn out as intended!

!!!WARNING!!!

There are a nearly endless number of MX switches floating around out there.  For the purposes of this project I focused on Cherry and Outemu switches.  My personal preference was Outemu switches for this project.  While you may be able to use all sorts of other switches in these, I cannot guarntee that any other switches will work.  It is highly recommended to try a switch our two out to ensure proper operation before buying a ton of them.

!!!WARNING!!!


---

Summary:

The OSBMX 24 / OSBMX 30 is based on the buttons from the OFOF1 by RanaLabs (https://github.com/rana-sylvatica/OFOF1).

The OSBMX 24 / OSBMX 30 allows for a compact all-in-one button to be constructed and placed securly into a small form factor case (total of 2.00mm thick).

The OSBMX 24 / OSBMX 30 project has now been updated with an additional PCB design that takes standard 2.4mm connectors. 

Please note that these buttons can also be used without the circuit board as the main housing of the button will hold the MX switches just fine.  You can then use a hot swap connector directly or just solder to the MX switches.  In this configuration you can also use any type of MX switch even without the notch in them.

A massive thank you to Bjart (https://twitter.com/bjartskular2) for making the original file and being great to work with throughout this project.


---

Board design choices:

There are several unique features of the PCB used for these buttons.  

Firstly, I have added double sided pads where the hot swap sockets are connected with a set of five vias on each.  This is designed to act as strein releaf in the event that pressure is put directly on the hot swap socket after soldering.  In pratice this leads to a far smaller likelyhood of tearout on your boards.

Secondly, I have made a custom cutout that is deisgned to fit a flipped over ZH 1.50mm 2pin SMD connector.  I have also added a set of double sided pads with vias as above to the tips of the board.  This allows you to solder on the ZH 1.50mm 2pin SMD connector upside down and utalize the space in most MX switches LED area to create a very low profile socket.  This attachement is very robust and should reduce the changes of tear out.

While not unique, the board also has offset screw holes to ensure no metal comes in contact with the hot swap sockets or pads.

Due to many requests I have added a second version of the PCB that takes normal 2.4mm connectors.  These have been tested and are working with the common 2.4mm connectors (two prong) found on AliExpress here: https://www.aliexpress.com/item/1005002539360973.html.


---

Assembly:

Assembly is quite strait forward on this board.  All that is needed is to solder the hot swap socket on as well as the ZH 1.50mm 2pin SMD connector.

Parts necessary for assembly of the main low profile board:

1 x LP MX board<br/>
1 x MX hot swap socket (https://www.aliexpress.com/item/4001051840976.html)<br/>
1 x ZH 1.50mm 2pin SMD horizonatal connector (https://www.aliexpress.com/item/1005003131441676.html)<br/>
2 x M2 5mm Hex Hexagon Socket Cap Head Self Tapping Screws (https://www.aliexpress.com/item/10000350027047.html)<br/>
1 x OOSBMX 24 / OSBMX 30 housing<br/>
1 x OSBMX 24 / OSBMX 30 plunger<br/>
1 x OSBMX 24 / OSBMX 30 washer<br/>
1 x MX switch (1) (https://www.aliexpress.com/item/1005004679651313.html)<br/>

(1) - Please note that these buttons will only work with MX switches that have the small notch cut out of them for RGB LED lighing.  As an exmaple, stock Cherry MX switches have a full bottom and will not work for these.  My switch of chose for these is Outemu Silent Peach switches.


Parts necessary for assembly of the newer 2.4mm version:

1 x LP MX board<br/>
1 x MX hot swap socket (https://www.aliexpress.com/item/4001051840976.html)<br/>
2 x DJ610-2.8-2 2.4mm male quick disonnect terminals (https://www.aliexpress.com/item/1005002539360973.html)<br/>
2 x M2 5mm Hex Hexagon Socket Cap Head Self Tapping Screws (https://www.aliexpress.com/item/10000350027047.html)<br/>
1 x OOSBMX 24 / OSBMX 30 housing<br/>
1 x OSBMX 24 / OSBMX 30 plunger<br/>
1 x OSBMX 24 / OSBMX 30 washer<br/>
1 x MX switch (1) (https://www.aliexpress.com/item/1005004679651313.html)<br/>

(1) - Please note that these buttons will only work with MX switches that have the small notch cut out of them for RGB LED lighing.  As an exmaple, stock Cherry MX switches have a full bottom and will not work for these.  My switch of chose for these is Outemu Silent Peach switches.


---

How to order a board:

All of the boards so far have been ordered though JLCPCB.  Due to the size of the boards you can order quite a lot of a very low cost.  I was able to order 125 of them and still meet their minimum shipping cost limits.  You do not need to get this many.  I have also opted not to do a panel for this since it appears to still be cheaper to get these done individualy.  Also please note that recently JLCPCB changed some of their prices for the PCB color, ensure you choose a color like black or green to get the lowest possible cost.

1 - Go to JLCPCB.com<br/>
2 - Click on `Instant Quote`<br/>
3 - Click on `Add Gerber file` and choose the file named `Gerber_OSBMX.zip` or `Gerber_OSBMX_-_2.4mm.zip<br/>
4 - Choose the following options for the board:<br/>
- Base Material = FR-4<br/>
- Layers = 2<br/>
- Dimensions = (should auto-populate) 21 * 17.3 mm<br/>
- PCB Qty = 125<br/>
- Product Type = Industrial/Consumer electronics<br/>
- Different Design = 1<br/>
- Delivery Format = Single PCB<br/>
- PCB Thickness = 1.6<br/>
- PCB Color = (up to you)<br/>
- Silkscreen = (defaults to white for all except white boards which is black)<br/>
- Surface Finish = HASL(with lead)<br/>
- Outer Copper Weight = 1oz<br/>
- Gold Fingers = No<br/>
- Confirm Production file = No<br/>
- Flying Probe Test = Fully Test<br/>
-  Castellated Holes = No<br/>
- Remove Order Number = Yes<br/>
- No advanced options<br/>

5 - Click on `SAVE TO CART`<br/>
6 - Go through checkout process, ensure to select economic shipping to keep costs low


---

How to order a button housing:

All of the button housings so far have been ordered though JLCPCB.  Due to the size of the buttons you can order a full sprue for a very small cost depending on the material you choose.  You will get the best quality our of PA12 nylon, but they are the most expensive.  If you are ordering in resin I have several larger sprue configurations in the `other sprue configurations` folder.

1 - Go to JLCPCB.com<br/>
2 - Click on `Instant Quote`<br/>
3 - Click on `3D Printing` <br/>
4 - Click on `Add 3D files` and choose the file named `OSBMX 24 - Single Sprue.stl` or `OSBMX 30 - Single Sprue.stl`<br/>
4 - Choose the following options for the board:<br/>
- 3D Technology = MJF (Nylon) (1)<br/>
- Material = PA12-HP Nylon (2)<br/>
- Color = Dyed Black<br/>
- Build Time = 72 hours<br/>
- Quantity = As needed<br/>
- Product Description = Anything you like<br/>
- 3D Remarks = "Please print facing flat down."<br/>

5 - Click on `SAVE TO CART`<br/>
6 - Go through checkout process, ensure to select economic shipping to keep costs low

(1) - These are best done in MJF (Nylon).  If you want to make cheaper buttons you can do them in SLA (Resin).  The sprues have been optamized for ordering in MJF (Nylon).  If you would like to order these in resin please check out some of the other files I have in here which have greater sized sprues.
(2) - PA12-HP Nylon is recommened due to finish and feel, although it is more expensive.  You can make these out of 9000R resin if you are looking to get a larger number for a lower cost, or want to experiment with doing dye jobs.
     

---

Donations:

Every part of this project is open source, all prototyping costs were taken care of by other projects!

Donations are not necessary but always welcome!  All received donations go into trying new things, ordering new boards, checking out new switches and helping people get items that might not be in an economic position to get one themselves.

https://www.paypal.com/donate/?hosted_button_id=2JMTZVCGLDYC2


---

Revision History:

v4.0 (current)
- Offset the post holes on the OSBMX 24 / OSBMX 30 housing and main PCB by 10o to ensure no electrical contact with the hot swap socket pads


v3.0
- Added cutout for the ZH 1.50mm 2pin SMD connector


v2.0
- Added post supports to the OSBMX 24 / OSBMX 30 housing


v1.0
- Original design

---

MIT License

Copyright (c) 2022 TheTrain

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

If you have any question please reach out to me on Twitter @TheTrain24 or join the GP2040-CE Discord server https://discord.gg/k2pxhke7q8
