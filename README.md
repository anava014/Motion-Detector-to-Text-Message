# Motion-Detector-to-Text-Message
A Microcontroller (Arduino Yun) using a motion detector that sends a text message when someone approaches the front door.

Another project for fun. I wish I had more time to give detailed "How-To" Instructions
but if anyone ever has questions I would be more than glad to chat about it via email.

It starts with the motion detector connected to the arduino Yún. Once motion is detected, an html request is
sent to my Server on the raspberry Pi. The raspberry pi's php code recieves a trigger and then uses an exec
command to run linux commands. Prior to this I installed message transfer agent(MTA) "exim4" that enables my pi
to send emails through the command line interface. Major phone carriers offer an email address that corresponds to 
your phone using its phone number and the appropriate concatenated domain name. From there its as simple as it gets.
Enjoy!

![alt tag](http://i.imgur.com/ph8jbKX.png)

![alt tag](http://i.imgur.com/44vYkly.jpg)

![alt tag](http://i.imgur.com/YijPmxC.jpg)

![alt tag](http://i.imgur.com/TBewe6h.jpg)

