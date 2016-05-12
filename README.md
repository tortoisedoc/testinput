# testinput
Input tests with Qt

The test app presents an overaly containing a list view with items. 

The issue is broken input on the overlay in particular situations (depending on how fast you unlock your screen, see below).

Reproducing input issues on Mer/Jolla:

This issue has been experienced only after a clean boot.

It has also been observed to recover after a certain period of time (and also represent itself after even longer time).

To reproduce:

a) compile & install

b) reboot your jolla

c) There will be two results:

1) right after boot, if you UNLOCK the phone right away and the spinner still runs, the issue will NOT present itself

2) right after boot, if you WAIT about 30 seconds before unlocking (and the spinner is not running), the issue WILL be present.

Symptoms: on overlay window, input is not taken but from the border of the screen 

(i.e. by first clicking on the edge of the screen then sliding the finger on the listview).

This appears to be due to the type of input event sent being different.
