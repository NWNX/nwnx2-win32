TMI, "Too Many Instructions" fix plugin,
by David Strait 2008, aka addicted2rpg.  


GNU license, see licence.txt.


Key files: nwnx_TMI.dll, nwnxtmi.ini

INSTALL:

1.  Put the nwnx_TMI.dll in your NWN folder (where your other NWNX dlls are, and the nwnserver executable).
2.  Two ways to do this step.  
	
	a)  Easy way is to run NWNX2 and then exit.  A TMI section will be automatically added to your NWNX.INI
	OR
	b) Lookover your NWNX.ini file add this section manually (use with values you like.  Their meaning described further below):
		[TMI]
		Limitlevel=4
		Unlimited=0


3.  Enjoy =)


PURPOSE:

To give you control over the error message "TOO MANY INSTRUCTIONS" that occurs when scripts in Neverwinter Nights run too long.  You may now increase the number of instructions, or simply allow yourself to run on an unlimited number of instructions.


WORDS OF WISDOM:

Disabling the "TOO MANY INSTRUCTIONS" safety feature by setting it to unlimited can be very risky.  If a script does not terminate through the course of its own processing, it will lock up your server, and possibly your computer.  There may be other consequences, both intended and not, from the lag generating from scripts that are obscenely excessive (NWN clients would disconnect if they thought the server was not responding to their last action in a certain amount of time).  Use with care.


---------------------------------------------------
Description of a sample TMI section of the INI file:

;The limit level represents the level of instructions you can have.  Out of the box default NWN uses 
;a level of 2.  A level of 4 means twice the number of instructions as the default.  
;Setting this too high can and will cause system instability.  If you need a level higher than 8-12,
;you may want to reconsider optimizing some of your scripts.

Limitlevel=4

;Setting this to 1 *should* give you unlimited instructions.  This is extremely dangerous and can cause 
;your computer to lockup if your module runs a non-terminating script. 
;You are strongly advised not to turn this setting on unless you are doing some local testing for 
;highly specialized purposes -- and, of course, you know what you are doing.
Unlimited=0
---------------------------------------------------------

.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.
.

A LITTLE HISTORY FOR ADVANCED USERS, DEVELOPERS, AND HEX EDITORS etc..:


-------------------------------------------------------------------------------
TMI fix shortcut method

Sent at: Thu Nov 27, 2008 7:42 am
From: addicted2rpg
To: jjjerm 


In nwnserver.exe, Look for:

8B C1 3D 00 00 02 00 89 4E 08 0F 8D 83 23 00 00 8B 45
00 8A 14

Once you have the pattern found, change the second
byte in the pattern "C1" to "C3"

This will give you unlimited instructions. Obviously, you know the risks of this.

It has worked for me in a local test mod.

To raise the TMI limit instead, change "02" in the above pattern to something like "04" - this will double the number of instructions you have available.

I'll be trying to NWNX'ify this next. It may take me awhile...... so if you get impatient, there is always this dirty little hack :) NWNX mod will of course ultimately be the best instead of people changing their exe's, although it is doubtful Bioware will update again.

Have fun!

------------------------------------------------------------------------------------------------


Addendum:  The TMI limit is actually 20,000 hexadecimal, or 131,072 instructions.  Some instruction blocks "count" differently
in the various nwscripts than is intuitive, but that is the number!    The 02 hex mentioned in the above mail is simply 
changing the leading portion of the 20,000 hexadecimal number.


And now, it is NWNX'ified, 1.5 days later. =-)  You guys don't need to modify your exe's, but I thought the HowTo 
should be included for those who may not want to run NWNX but still enjoy the benefits of TMI handling by just changing
their nwserver.exe's.  And for the love of god, anyone who tries this, make a backup, yes? :)


I'd like to take this moment to make a small tribute to the Island of Fredian, and its creator Makzimia De Graaf, 
and all the other DM's there, and of course, to myself, as its head scripter.  HAHAH :)  I know, I know, the modesty is coming out.  

On a serious note, without the experiences I have had there, and the players who propelled our project forward, 
I would have never written this plugin.  When I saw the server of Arelith "facing" many of the same issues we 
did on IoF, I felt it was high time the whole NWN community receives a TMI fix that works, once and for all.
I would have written it for IoF, but I was not the developer then that I am now.

