# LAN-Anonymous-Message-System
Broadcasts messages over the local network while masking the senders IP Address

Sections

1 - How to build
 
2 - Strategy
 
3 - Sources

4 - Screenshots

## Section 1 - How to Build

To build the application
    - cd to the src directory
    - type "make"

To run the application
	- cd to the src directory
    - Use the command "sudo ./P2P"

To run the application in verbose mode (To see sender info)
	- cd to the src directory
	- Use the command "sudo ./P2P -v"

To run the application in unhidden mode (This will stop masking
your IP address)
	- cd to the src directory
	- Use the command "sudo ./P2P -uh"

There should be no warnings/errors as long as theres no missing
dependencies.

Notes:
  - Application requires the NCurses library (For UI) to be 
  	installed on the computer running the application
  - verbose and unhidden flags can be combined E.g. 
  	"sudo ./P2P -uh -v"
  - This was developed on OSX
  - Application must be ran with sudo to allow for "broadcast"
    messages
  - Application will only send messages to others on the local
    network
  - Each message is limited to 60 characters

## Section 2 - Strategy

The strategy was to "spoof" the sender IP  addresses on all of 
the packets sent, so they can't be traced. If another user
looks at the senders IP of your message, then it will show
up as "1.0.0.0"

![alt text](http://tylerherbert.ca/images/anonws.png)

Since there will be no legitimate return address, I didn't want
any replies to the packet, so I decided to send the messages as
UDP packets.

In order to alter the sender address I had to make changes to the
IP header. This is why I chose to do it in C, so I had lower 
level access to the raw packet headers.

To not track who to send messages to (To keep it more anonymous) 
I set all messages to "broadcast" to all other users on the 
network. This way anyone running the application will be looking
for messages broadcasted on port 8820, and pick them up with no
idea who sent them. The limitation from this is that to keep it
decentralized it will only send messages on the local network.

This application is only designed to hide the IP address, not the
devices MAC address, this can still be hidden with a macchanger, or
the application can be altered to also write the ethernet header.

## Section 3 - Sources

Editting raw sockets:
http://www.cs.binghamton.edu/~steflik/cs455/rawip.txt

Broadcasting over LAN in C:
http://www.tack.ch/multicast/broadcast.shtml

## Screenshots

![alt text](http://tylerherbert.ca/images/anon.png)

