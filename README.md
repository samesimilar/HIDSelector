# HIDSelector

## A convenient HID abstraction for Organelle
### By Michael Spears <mws@samesimilar.com>
### The author graciously acknowledges the contributions of the authors of pdbuilder, HID, readdir, mother.pd, PureData, and more, which make HIDSelector possible.
### Please see LICENSE.txt for Copyright, Warranty, Software Licenses, and further acknowledgments.


### Please note this is 'beta' software and it's design and operation may change frequently. Please check back for updates. Please make sure to have a backup of any important files on your Organelle before experimenting with `HIDSelector`.

The purpose of HIDSelector is two-fold: 

A. A useful abstraction of Hans-Christoph Steiner's `[hid]` external for generalized integration in Organelle patches, with the addition of the ability to "grab" an HID device for exclusive use by Pure Data.

B. A way to list and select attached USB HID hardware on the Organelle, with a persistent configuration file that saves the user's selected device.

## HID

HID stands for "Human Interface Device" and is a class of USB devices, like keyboards (of the typing-kind, not the musical kind), gamepads, mice and others. These can be useful for extending the functionality and complexity of Organelle patches. I think especially keyboards are interesting, because of the wide variety or products in the custom mechanical keyboard hardware ecosystem. This includes and is not limited to mini-keyboards, 4-key macro-keyboards, custom DIY keyboards, custom keycaps, customized switches, etc. 

## `[hidsr]`

In the `HIDSelectorReceiver` folder, you'll find the `[hidsr]` abstraction for Pure Data (and a subfolder of dependencies for it). To include it in your patch, just copy the entire contents of HIDSelectorReceiver into your patch folder. You can load `[hidsr]` into your patch just by adding it as an object into your PureData patch. There are no arguments or inlets/outlets for this object.

* `[hidsr]` will automatically attach to your configured HID device and start sending HID events to one of the following 'receive' symbols:

`hidsrin-1`
`hidsrin-2`
`hidsrin-3`
`hidsrin-4`
`hidsrin-5`
`hidsrin-6`
`hidsrin-7`
`hidsrin-8`
`hidsrin-9`
`hidsrin-0`

The number in the above symbols depends on the current 'application layer' that is selected for `[hidsr]`. The application layer concept is a way to logically separate input events between different layers of the system. For example, the OS could listen to events on `hidsrin-0`, while a modded mother.pd could listen to events on `hidsrin-1`. Incoming HID events are only dispatched to the current layer.  I recommend that regular patches listen to events on `hidsrin-2` or higher.

* To switch the current 'application-layer', press `ctrl+#` on the HID keyboard. E.g. press `ctrl+2` to send subsequent events to `[r hidsrin-2]`. 

The initial (default) layer can be specified in the `/sdcard/HIDSelector-Config.txt` file (see below). (The current application layer is not saved, and it's reset back to the default each time you launch a new Pure Data patch that uses `[hidsr]`.)

* A consequence of this design is that the `ctrl` key events (right and left) are reserved by `[hidsr]` and are not passed along to any patches.

* *Limitations*: currently there is no way to attach to multiple HID devices with `[hidsr]`, nor to switch application layers using other devices like gamepads or mice. (You can receive events for such devices from `[hidsr]` using the default layer as configured.)

For an example of a simple patch that uses `[hidsr]`, see my [RecBside patch here](https://github.com/samesimilar/RecBside).

## HIDSelectorSetup

`[hidsr]` reads a file located at `/sdcard/HIDSelector-Config.txt` to determine the HID device that it should listen to, so that it will "just work" when you start up your Organelle and launch a patch that uses `[hidsr]`.

`HIDSelectorSetup` is an Organelle patch that lets you modify HIDSelector-Config.txt entirely using the Organelle's OLED screen and encoder (so you don't have to edit/upload the text file by hand). 

### To install/use HIDSelectorSetup:

1. Copy the `HIDSelectorSetup` folder to your Organelle's `Patches` folder.
2. Attach your desired USB device.(Most likely) the device needs to be "class-compliant", e.g. doesn't require special software or drivers to be usable in Linux on your Organelle.
3. Start the `HIDSelectorSetup` patch.
4. Use the Organelle's main encoder knob to scroll down the list of attached devices.
5. Push the encoder knob to 'open' the device.
6. Press a few buttons on your device as a test. You should see events printed on the Organelle's OLED screen if it is reading the device.
7. Press the encoder on the 'Save' option to write your selection to `/sdcard/HIDSelector-Config.txt`.

Your setup is saved in a file, so it will be preserved if you reset your Organelle or select different patches. Your device is selected by its "ID", so it should be found by `[hidsr]` regardless of the order you attach devices to your Organelle.

Here is a sample `HIDSelector-Config.txt` file:

```
hidSelectorInputId usb-Compx_2.4G_Wireless_Receiver-event-kbd;
hidSelectorDefaultLayer 1;
```

* Tip: You can change the default startup "application layer" by setting the `hidSelectorDefaultLayer` parameter to a number 0-9 in this file by hand.

* Tip: The list of devices shown in the setup patch comes from the folder `/dev/input/by-id` in the Organelle's file system. You can see this list on the linux terminal by entering `ls -l /dev/input/by-id`. Note only links in this folder that point to `--> ../event*` files are valid for `[hidsr]`.
                                                                  
This program is distributed in the hope that it will be useful,   
but WITHOUT ANY WARRANTY; without even the implied warranty of    
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the     
GNU General Public License for more details.   