# Project Synapse: FattyMenu
![alt text](https://img.shields.io/github/downloads/cpap7/FattyMenu/total.svg)

This repository contains the source code to a little side-project I've been working on while playing Project Synapse. 

FattyMenu is a Direct3D9-specific ImGui menu that serves as a "**F**ast, **A**ll-in-one, **T**rusty **T**oolset for **Y**ou."

It's packaged under a simple .dll file & folder that can be loaded onto Garry's Mod via the game itself, or via manual map injection. 
It uses in-game render hooks to create an ImGui window containing useful gameplay information relevant to the Combine factions on the server.

# Content
The menu itself contains the following in the form of dockable in-game panels: 

- An in-game version of roughly ~80% of the Civil Protection SOP (missing a few tables and verbose sections)

- A built-in library containing all the voicelines across each class on the server, which can be searched through in-game. Voiceline entries can be configured and hot-reloaded via a .JSON file

- Distribution permit info, including prerequisite civic point count & costs for permits, alongside costs for their associated packages

- A notepad utility panel for taking notes in-game

- A panel containing a map provided by the SOP

- A config settings panel, which can be used to control which panels get shown and the scale of the each image used within each panel

# Compatibility
This menu works with the following operating systems and versions of Garry's Mod:
- Windows 10, Garry's Mod x86-64 branch
- Windows 10, Garry's Mod 32-bit branch 
if the .dll is recompiled as Release x86 in Visual Studio. Project Synapse shouldn't be played on the 32-bit version of Garry's Mod anyhow.
- Windows 11, Garry's Mod x86-64 branch

Unfortunately for macOS and Linux users, this will not work for you as of right now. This may change in the future.

# Installation / Setup
## Prelude
As of v1.8.0, you will need to download the ```Microsoft's DirectX End-User Runtimes (June 2010)``` prior to installation.
This is so the menu can load custom images as textures.
Download it [here](https://www.microsoft.com/en-ca/download/details.aspx?id=8109)

The .dll file can be either injected or loaded by Garry's Mod directly.
- Note: You will need to ensure the game is running on ``Borderless Window`` mode first. Otherwise, you will run into more bugs.
- Once loaded, you should be greeted with an overlay at the top looking like this:
![alt text](https://raw.githubusercontent.com/cpap7/FattyMenu/refs/heads/master/Screenshots/fattymenu180_1.png)

- You can then set up the different panels in whichever configuration you find best. For example:
![alt text](https://raw.githubusercontent.com/cpap7/FattyMenu/refs/heads/master/Screenshots/fattymenu180_2.png)

## Direct Load via Garry's Mod
- The more popular/convenient method for loading the menu
1) Download the latest version of FattyMenu under the 'Releases' tab of this repository.
2) Navigate to your ``garrysmod > lua > bin `` folder, then drag and drop the ```FattyMenu``` folder and ``gmsv_fattymenu_win64.dll`` file in there.
- Note: If there is no bin folder present, create one.
- You could rename the ``FattyMenu.dll`` file to ``gmsv_fattymenu_win64.dll``, or use the one provided with the download (that's up to you) 
4) Navigate over to ``garrysmod > lua > menu `` and open up ``menu.lua`` in a text editor (i.e., Notepad++)
5) At the bottom of the file, copy and paste this: ``require("fattymenu")`` and save the file
6) Start Garry's Mod. The menu should load.

- Note: If you're on Windows 11, and have Windows Defender, you may need to set an exclusion for the bin folder path and/or file itself. This is because of the way the .dll file attaches to gmod.exe.
1) Open MS
2) Click Virus & Threat protection. 
3) Click Virus & Threat protection settings (manage settings)
4) Scroll down to the bottom
5) Click Add or Remove exclusions
6) Add an exclusion 
7) Click the File option
9) Exclude the file path to the bin folder
- For example: ``C:\Program Files (x86)\Steam\steamapps\common\GarrysMod\garrysmod\lua\bin``
10) You could also add the file itself to the exclusions list just in case
- For example: ``C:\Program Files (x86)\Steam\steamapps\common\GarrysMod\garrysmod\lua\bin\gmsv_fattymenu_win64.dll``
![alt text](https://raw.githubusercontent.com/cpap7/FattyMenu/refs/heads/master/Screenshots/exclusions.png)

## Injection
- Less convenient, but it's supported. The following steps should allow you to use the menu in-game. 
1) Download the latest version of FattyMenu.dll under the 'Releases' tab of this repository. FattyMenu.dll can be loaded in-game using any injector that supports manual map injection.
- Before injecting, ensure you've placed the ```FattyMenu``` folder in your ``garrysmod > lua > bin `` folder and have 
- For this tutorial we'll be using Xenos, as it's open source and fairly easy to use. Download the latest version of Xenos Injector here:
``
https://github.com/DarthTon/Xenos/releases/tag/2.3.2
``
3) Extract the files to your desktop (or wherever is convenient for you) 

4) Run Xenos64.exe. Your anti-virus will likely flag it, but do not worry. This is a false positive, so make sure you have it set up to exclude / ignore it.

5) Once the injector is opened, navigate over to the 'Advanced' button and click on it. Change the injection type to Manual map, then check off 'No exception support,' 'Manually resolve imports,' 'Ignore TLS,' and 'Erase PE headers.' In other words, it should look like this:

![alt text](https://raw.githubusercontent.com/cpap7/FattyMenu/refs/heads/master/Screenshots/manualmap1.png)

5) Press the 'OK' button at the bottom right.

6) Next, go to the 'Add' button and select FattyMenu.dll. The injector UI should now look like this:
![alt text](https://raw.githubusercontent.com/cpap7/FattyMenu/refs/heads/master/Screenshots/manualmap2.png)

7) Boot up Garry's Mod (x86-64 branch), and wait for it to load to the main menu.

8) Once you're at the main menu, alt-tab over to Xenos and press the box that says "process" next to it. Scroll down once you see 3 gmod.exe processes. Select the 2nd or 3rd one (usually the ones with the lowest process ID number next to it). Then, hit the 'Inject' button to inject it in-game. 
- Note: if that doesn't work, try the other two. If Xenos crashes, that's fine. Just launch the injector again, ensure your settings are correct, and try the remaining gmod.exe processes

9) If the menu loads up, you should see a minimized ImGui window. Congrats; it works! Be sure to resize the menu and close the injector as it's no longer needed.

10) Verify it works while in-game. In most cases, it should be fine to just load into a singleplayer map or server and open/close the menu without issue. However, for the safest results, I'd recommend doing the following from now on:
- Load up Garry's Mod
- Load into the server
- Once you're on the server and able to play (i.e., able to walk around), launch Xenos64.exe
- Inject the .dll
- Note: your settings for the injector should be saved from the first initial successful injection. Which means, the correct gmod.exe process will be selected every time Xenos64.exe is ran. FattyMenu.dll will need to be replaced over time as updates are added. 
- Close the injector

# Controls
- R-ALT key -> opens or closes the menu
- END key -> uninjects the menu
- C key -> pressing this in-game allows you to navigate the menu without needing to press escape. Very handy if you're simply browsing the in-game SOP, voiceline library or distribution permit info. 
- Pressing escape to access the menu might be preferable if you're writing notes or searching through the voiceline library 

# FAQ
Will this get me banned from the server?
- No.

Is Xenos64 a virus?
- No. If your anti-virus flags it as malware, bare in mind that it's a false-positive because it's an injector. The software itself is open-source, so you can see for yourself how exactly it functions and compile it yourself if you want. 

Is FattyMenu a virus?
- No.
- ``https://opentip.kaspersky.com/F341057305713D39ACC9FBBF5D01EEA294EAE064E67766934A7D7E4AAC0DC71E/static?tab=upload``

Will this make me better at playing Civil Protection?
- I've been making this since I was a probationary, and now I'm a CPTL. I've never needed to memorize anything from the actual SOP itself, and have only ever relied on this menu for my success. So, yes I'd say so.

Why make this?
- While Project Synapse is a fantastic server, it has a distinct lack of QOL features in a few key areas, which I felt needed to be rectified.
- This was originally an in-game crafting calculator for rebel gameplay, however, it quickly became apparent to me that it was unnecessary to have in-game. With crafting updates, the module became deprecated over time, and it eventually got axed entirely. 
- Playing Civil Protection became a bit of hassle in terms of having the SOP readily available to reference from. Granted, yes, you could have it open on another monitor and CTRL+f, or use your phone, but I needed something faster.
- Making a menu like this without being too invasive on the engine itself isn't particularly difficult. The only problem was that the SOP info was locked such that no-one could copy/paste from it (understandably so), and as such, strings had to be manually typed out.

# Requirements For Developers
You can clone the repo via ```git clone https://github.com/cpap7/FattyMenu.git```
- ```Visual Studio 2026``` - C++20 IDE
- ```vcpkg``` - For downloading certain dependencies (i.e., openssl)
Under the ```Scripts``` folder, you'll find a ```Win-GenProjects.bat``` file which can be used to generate project files for Visual Studio 2026. 

# Dependencies
The following are included for convenience:
- ```garrysmod_common``` - Common include headers for Garry's Mod
- ```html_parser``` - For parsing raw HTML files from disk
- ```http_lib``` - For making http requests for voiceline data. Requires openssl
- ```imgui``` - Immediate mode graphical user interface library for the menu
- ```json``` - File format used for serializing most of the content within this tool
- ```minhook``` - For function detouring, mainly for EndScene & Reset function calls for Garry's Mod, which uses Direct3D9 for rendering
- ```inifile-cpp``` - For serializing user config-specific files

The following must be installed via external means:
- ```openssl``` - Dependency for http_lib. You must already have vcpkg installed. Then, run the following command in cmd or powershell to install & compile it: ```vcpkg install openssl:x64-windows-static-md```
- ```Microsoft's DirectX End-User Runtimes (June 2010)``` - This is so the menu can load custom images as textures. Download it [here](https://www.microsoft.com/en-ca/download/details.aspx?id=8109)

# Project Structure
Under ```FattyMenu-Lib``` you'll find 3 folders:
- ```Data``` - Contains the most up-to-date data loaded in by the menu at runtime
- ```Source``` - Contains FattyMenu-specific source files (obviously)
- ```Vendor``` - Contains vendor source files. The inclusion of these files is managed with premake, specifically via the ```External.lua``` and ```premake5.lua``` files

# Developer Roadmap
- Include a built-in SOP and AOP for Transhuman and Airwatch classes, respectively. Might not be needed, but it would be nice to have.

- Include search / filtering functions for the SOP panel

- Add configurable keybinds, and settings for different themes (i.e., one for Transhuman Forces)

# Contributing
Pull requests are welcome. For major changes, please either message me on Discord or open an issue 
to discuss what you would like to change.

Please make sure to update tests as appropriate.

# License
[MIT](https://choosealicense.com/licenses/mit/)
