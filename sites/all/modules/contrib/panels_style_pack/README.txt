Description
-----------
Configurable panel style plugins. Provides 5 kinds of panels styles:
- Horizontal tabs
- Vertical tabs
- Accordion
- Grid
- Slideshow
  
For the slideshow functionality this module relies on jQuery cycle plugin.
This module also relies on jQuery easing plugin for some cool effects.

Dependencies
------------
- Panels
- Libraries
- jQuery cycle plugin (for slideshow style)


Installation
------------
1) Place this module directory in your modules folder (this will usually be
"sites/all/modules/").

2) Enable the module.

3) Go to the "Layout settings" tab of the Panels page, Mini panel, ... on
which you want to apply this style.

For Slideshow style:

1) Download and install the 'Libraries' module.

2) Create a folder named 'libraries' with path "sites/all/libraries".

3) Download jQuery cycle plugin from "http://jquery.malsup.com/cycle" and place it in folder 
   "jquery.cycle" so that the actual js file's path is 'sites/all/libraries/jquery.cycle/jquery.cycle.all.js'
   
4) For easing effects you can download the jQuery easing plugin from 
   "http://gsgd.co.uk/sandbox/jquery/easing/" and place it in a separate folder so that
   the easing plugin js file is in the path "sites/all/libraries/easing/jquery.easing.1.3.js"

