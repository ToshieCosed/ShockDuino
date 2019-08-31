# ShockDuino
Control A Pet Shock Collar With Arduino
Credit to: https://github.com/Johonis/arduino-pet-collar-control for reversing the collar protocall.
The model is a Pet Trainer Collar, the remote broadcasts on a 433 mhz frequency.
This model should work with MOST collar varieties or clones of the same design.

Dependency Library: https://github.com/aharshac/StringSplitter
This is only if you want the library to split the C-strings for you.
If you're a seasoned C-programmer you may not want, or need this functionality.

This is roughly what the collar looks like:
https://ae01.alicdn.com/kf/HTB1WVHrebZnBKNjSZFhq6A.oXXaS/Petrainer-998D-1-Electronic-Dog-Collar-Remote-Control-No-Shock-Pet-Training-Collar-With-LCD-Display.jpg

Hardware:
I used an Arduino Uno powered by USB, and a 433 mhz transmitter with 3 pins.
Pin 0 from left to right: Data
Pin 1 from left to right: 5V in
Pin 2 from left to right: GND

You can find them here:
https://www.amazon.ca/gp/product/B019SX6Y22/ref=ppx_yo_dt_b_asin_title_o00_s00?ie=UTF8&psc=1

The range sucks without a 17 mm Antennae, but I found the coil on mine (builtin) to be good
if you only want to use it in a small room and not have a big range with it.
If you want to cover an entire house, good luck  probably need more knowledge of RF-Antennaes.
Either the top right pinhole, or lower mid pinhole is the Antennae.
The models I recieved from Amazon did not have board labels like the picture on the product page above, but the transmitter works!

All of this works and is an extension on some work that I found that was the only work that works with this model Collar.
Sidenote: It is the simplest thing I could find, to get the collar working with a 433 mhz transmitter out of the box.
Also: You will have to pull the batteries out of your remote, upload the sketch, reset the board, and then put the batteries back in so the collar and board boots up around the same time. If you hear a beep and a vibrate, it probably synced (linked the remote and collar together).

Good Luck, and Happy Hacking.
