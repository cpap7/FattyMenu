# Project Synapse: FattyMenu

This repository contains the source code to a little side-project I've been working on while playing Project Synapse. FattyMenu is a lightweight, .dll file that can be loaded onto Garry's Mod via manual map injection. It uses Direct3D9 render hooks and a hook for EndSceneFn to render an ImGui window in-game.

# Content
The menu itself contains the following tabs: 

- An in-game version of roughly ~80% of the Civil Protection SOP (missing a few tables and verbose sections)

- A built-in library containing all the voicelines across each class on the server (except Transhuman Soldier and Ordinal, still WIP)

- Distribution permit info, including prerequisite civic point count & costs for permits, alongside costs for their associate packages (except the water permit, still need to gather data and implement that)

- Notepads for writing Patrol Logs, Probationary Recommendations, and regular note-taking

The code itself uses classes as containers for data organization purposes, and separate UI files for each tab. Should be easy to navigate given the project's overall structure. 

The UI tabs are managed under 
``GUI.cpp.``  

# Compatibility
This menu works with the following operating systems and versions of Garry's Mod:
- Windows 10, Garry's Mod x86-64 branch
- Windows 10, Garry's Mod 32-bit branch 
if the .dll is recompiled as Release x86 in Visual Studio. Project Synapse shouldn't be played on the 32-bit version of Garry's Mod anyhow.
- Windows 11, Garry's Mod x86-64 branch

# Installation / Setup
## Prelude
This .dll file can be either injected or loaded by Garry's Mod directly.
Do note, you will need to ensure the game is running on ``Borderless Window`` mode first. Otherwise, you will run into more bugs.

## Direct Load via Garry's Mod
1) Download the latest version of FattyMenu.dll under the 'Releases' tab of this repository.
2) Rename it to ``gmsv_fattymenu_win64.dll``
3) Navigate to your ``garrysmod > lua > bin `` folder and drop it in there
- Note: If there is no bin folder present, create one
4) Navigate over to ``garrysmod > lua > menu `` and open up ``menu.lua`` in a text editor (i.e., Notepad++)
5) Add the bottom of the file, copy and paste this: ``require("fattymenu")`` and save the file
6) Start Garry's Mod. The file should load. 
- Note: clicking around on it may cause you to accidentally click other menu options behind it. 

## Injection
- Less convenient, but it's supported. The following steps should allow you to use the menu in-game. 
1) Download the latest version of FattyMenu.dll under the 'Releases' tab of this repository. FattyMenu.dll can be loaded in-game using any injector that supports manual map injection.
- For this tutorial we'll be using Xenos, as it's open source and fairly easy to use. Download the latest version of Xenos Injector here:
``
https://github.com/DarthTon/Xenos/releases/tag/2.3.2
``
3) Extract the files to your desktop (or wherever is convenient for you) 

4) Run Xenos64.exe. Your anti-virus will likely flag it, but do not worry. This is a false positive, so make sure you have it set up to ignore it.

5) Once the injector is opened, navigate over to the 'Advanced' button and click on it. Change the injection type to Manual map, then check off 'No exception support,' 'Manually resolve imports,' 'Ignore TLS,' and 'Erase PE headers.' In other words, it should look like this:

![alt text](https://puu.sh/Kt6GG/ec592af606.png)

5) Press the 'OK' button at the bottom right.

6) Next, go to the 'Add' button and select FattyMenu.dll. The injector UI should now look like this:
![alt text](https://puu.sh/Kt6HZ/5dc30ea9cc.png)

7) Boot up Garry's Mod (x86-64 branch), and wait for it to load to the main menu.

8) Once you're at the main menu, alt-tab over to Xenos and press the box that says "process" next to it. Scroll down once you see 3 gmod.exe processes. Select the 2nd or 3rd one (usually the ones with the lowest process ID number next to it). Then, hit the 'Inject' button to inject it in-game. 
- Note: if that doesn't work, try the other two. If Xenos crashes, that's fine. Just launch the injector again, ensure your settings are correct, and try the remaining gmod.exe processes

9) If the menu loads up, you should see a minimized ImGui window. Congrats; it works! Be sure to resize the menu and close the injector as it's no longer needed.
- Note: clicking around on it may cause you to accidentally click other menu options behind it. 

- For that reason, I recommend keeping the menu open in the middle of your screen if you only want to open it with the escape menu open. 
![alt text](https://puu.sh/Kt6Jj/f5062ebfcb.jpg)
- In-game, I've found having it off to the right works best. 
![alt text](https://puu.sh/Kt6Jq/05c9c24f2a.jpg)

10) Verify it works while in-game. In most cases, it should be fine to just load into a singleplayer map or server and open/close the menu without issue. However, for the safest results, I'd recommend doing the following from now on:
- Load up Garry's Mod
- Load into the server
- Once you're on the server and able to play (i.e., able to walk around), launch Xenos64.exe
- Inject the .dll
- Note: your settings for the injector should be saved from the first initial successful injection. Which means, the correct gmod.exe process will be selected every time Xenos64.exe is ran. FattyMenu.dll will need to be replaced over time as updates are added. 
- Close the injector

# Controls
- RCTRL key -> opens or closes the menu
- END key -> uninjects the menu
- C key -> pressing this in-game allows you to navigate the menu without needing to press escape. Very handy if you're simply browsing the in-game SOP, voiceline library or distribution permit info. 
- Pressing escape to access the menu is preferable if you're writing notes. 

# FAQ
Will this get me banned from the server?
- No

Is Xenos64 a virus?
- No. If your anti-virus flags it as malware, bare in mind that it's a false-positive because it's an injector. The software itself is open-source, so you can see for yourself how exactly it functions and compile it yourself if you want. 

Will this make me better at playing Civil Protection?
- I've been making this since I was a probationary, and now I'm a CPTL. I've never needed to memorize anything from the actual SOP itself, and have only ever relied on this menu for my success. So, yes I'd say so.

Why make this?
- While Project Synapse is a fantastic server, it has a distinct lack of QOL features in a few key areas, which I felt needed to be rectified.
- This was originally an in-game crafting calculator for rebel gameplay, however, it quickly became apparent to me that it was unnecessary to have in-game. With crafting updates, the module became deprecated over time, and it eventually got axed entirely. 
- Playing Civil Protection became a bit of hassle in terms of having the SOP readily available to reference from. Granted, yes, you could have it open on another monitor and CTRL+f, or use your phone, but I needed something faster.
- I used to develop a few hacks for Source engine games in my time, so making a menu like this without being too invasive on the engine itself was no issue. The only problem was that the SOP info was locked such that no-one could copy/paste from it (understandably so), and as such, strings had to be manually typed out. Despite being sent over the SOP pdfs, it still became a hassle as they changed a LOT over time.
- For those curious, here's a video showcasing an internal CS:GO cheat I developed a long time ago, which I loosely based this project off of:
``https://www.youtube.com/watch?v=MCxxw203-LM&feature=youtu.be``

# Developer Roadmap
- Include all the voiceline data for Transhuman Ordinal and Transhuman Soldier

- Include a built-in SOP and AOP for Transhuman and Airwatch classes, respectively. Might not be needed, but it would be nice to have.

- Finish the distribution permit tab (currently lacks water-permit package info, and I still need to verify that all the other data is up-to-date)

- Finish up comments/documentation that I either forgot to write or was otherwise too lazy to write

- Rework rendering methods for the SOP using a cleaner approach. 

- Include search / filtering functions for the Voiceline Libary and SOP tabs

- Add a settings tab for configurable keybinds, and setting different themes (i.e., one for transhuman)

- Add additional support for other operating systems (for MAC and Linux users specifically)

# Contributing

Pull requests are welcome. For major changes, please either message me on Discord (@wiener_water88) or open an issue 
to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License

[MIT](https://choosealicense.com/licenses/mit/)
