Musica  
=======

Musica is a cellular automaton based music generator. Musica also has the ability to generate pictures of rule 30.  

##Compiling  

###Prerequisites  

* Sound samples  
  I used one octave of piano samples from http://theremin.music.uiowa.edu/MISpiano.html. 
They need to all have a specific filename, so to make things easier you can <a href="http://cl.ly/Sd4p">
download a zip here.</a> Put the media folder in the same directory as the executable once you build it.
* LibGD  
  I am using 2.1, but any version that supports SetPixel and exporting to PNG should work.
* irrKlang  
  Version 1.4, free version works.  

###Building  
Change the -I and -L flags in rule30.sh to where these libraries are located on your filesystem, then run it.
