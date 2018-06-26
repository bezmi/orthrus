# PCB

PCB design files and gerbers for the orthrus keyboard. See the [mitosis build log](https://imgur.com/a/mwTFj#JtzXTCD) for an overview of how to put this together.

There are a couple of minor differences. For example, for the programming header, my right angle connector footprint is too far in from the edge of the PCB, which resulted in the particular right angle headers I had not being reachable. I compromised by just using straight headers that go through the holes in the top (switch plate) pcb. It works just fine and the header is optional anyway. You could just as well solder temporary wires, program, then desolder before final assembly.

For the foam base, I did not have access to a lasercutter, so I cut a cloth mouse pad to size (including a cutout for the module on the bottom), cut all of the switch pins flush to the bottom of the PCB and hot glued the mousepad bits to the bottom. It is a little bumpy if you feel the bottom of the keyboard, but the typing feel is not compromised. Make sure you put tape on the module to avoid shorts!

For the receiver, I use the [mitosis receiver PCB](https://github.com/reversebias/mitosis-hardware). You can look at the BOM there (adjusting for extra switches, etc). I designed the PCBs to use the cheaper black nrf modules from aliexpress (Yj-14015), which are slightly smaller than the official waveshare module. For the receiver I had a legitimate waveshare module (blue) laying around, so I just used that, but soldering a Yj-14015 module to the receiver PCB can be very tricky. Feel free to extend the mitosis receiver pads and submit a pull request.

Make sure the PCB fab house can do 0.8mm slots. I've got mine manufactured from JLCPCB and the PCBs came out perfect.

