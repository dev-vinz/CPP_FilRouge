<br></br>
```
     __      __       .__
    /  \    /  \ ____ |  |   ____  ____   _____   ____
    \   \/\/   // __ \|  | _/ ___\/  _ \ /     \_/ __ \
     \        /\  ___/|  |_\  \__(  <_> )  Y Y  \  ___/
      \__/\  /  \___  >____/\___  >____/|__|_|  /\___  >
           \/       \/          \/            \/     \/
```
<br></br>
# Project Overview

This project was made as part of the C++ course, during the year 2020-2021 in the HE Arc.

We had to do a RPG, which means it's a Role Player Game. You will choose a Hero, who is gonna be moved in a virtual map, and you are able to choose his next direction. There is opponents, and when you are in front of them you have the choice to fight. You win the game when all opponents are defeated.

The opponents are moving automatically, and you can collect some potions in the map, which are going into your backpack. You can drink them later in a battle.

# Table of Contents

- [Project Overview](#project-overview)
- [Table of Contents](#table-of-contents)
- [Information](#information)
- [UML Diagrams](#uml-diagrams)
    - [Global](#global)
    - [Actors](#actors)
    - [Objects](#objects)
    - [Game](#game)
- [How To Play](#how-to-play)
- [Improvements](#improvements)

# Information

Here's some informations about how this project is structured.

- First, we have to main folder, RPG. It contains all the project. We have the file `main.cpp`, which contains the code and the verification for the guided beginning. My main file is `rpg.cpp`, it's the start of my game.
- Then we have the folder `apps`. It contains all the classes I needed, ordered by type, for example all my Heroes are in folder `actors`, and my objects are in `stuff`.
- We have to folder `bin`, which contains the final `rpg.exe` after the compilation is completed. In this folder we have the logs too, which repertories all the main actions of the game.
- And finally, we have the folder `settings`, which contains a unique file, `Settings.hpp`. This file is only settings for the smooth running of the game.

The tree looks like this :
```
RPG
├── apps
│   ├── actors
│   ├── enums
│   ├── game
│   ├── stuff
│   └── utils
├── bin
│   ├── logs
│   └── rpg.exe
├── settings
│   └── Settings.hpp
├── main.cpp
└── rpg.cpp
```

The logs, as I said before, are in the folder `bin/logs`. When we start a new game, and if the line number `30` in `rpg.cpp` isn't commented, then a new folder is automatically created, in the following format : First, we have the year, then the month, the day, `_` as separator, and finally the hour.

For example, if you launch the program the 7th of June, at 17:14:30, the folder name will be `20210607_171430`, and all the logs for this game will be in `bin/logs/20210607_171430`.

Then you have multiple files. One for the gam in general, one for the objects collected and used, and two new folders. The first one list a log file for all battles you made, and the second contains two files, the movements of the player, and the movements of the opponents.

# UML Diagrams

Here I will list all the diagrams of my project. One global, with all the main classes, and many others with classes described more specifically.

## Global

This diagram represents all the project, and how the different classes are linked.

We have on top of the tree the class `Game`, which is directly linked to the class `Hero` and `Map`. The map is alone by its side, but the heroes are separated in two other classes, the opponents and the player.

The hero possesses a backpack, which contains some objects, which are considered as `IObject`. Here, I choose to store only potions in the backpack, but in theory it can contains other stuffs, like a sword or a shield.

![Diagram of Global](http://www.plantuml.com/plantuml/svg/RP71Zi8W48RlVGhEc_GDzj3iPUsXjec9FOymAbeOCgKn6XzUX3P6XOI4__l8Ju1gzC1-CaCXmlW7WuBAKgoGwPqqu29u6l5x3wGRu8hy0LldoABrB_mJw1_8SnTcf4k8jNMxEw7qOpHBI5KD7BJimQgCwyXhiXcnaUWySiuSDGug9ox4YQSR9Te3ioR-vle6QVkyJ7YDaic0bVFPopiaMziziiw81jKqGaPimJZDM5HeLVYT1m00.svg)

## Actors

Actors are all the classes for the heroes. You have in total 6 kind of heroes, but only 3 of them can be choose as player. The 3 others are the opponents.

For the player, we have
- The Warrior : A strongest hero, with a great strength, but stupid as a donkey
- The Wizard : A hero with a big intelligence, quite nimble, but not very strong
- The Necromancer : A powerful wizard, with powerful attacks. Unfortunately, its attacks made damage to him

The opponents can be
- An Inferi : It's a dead man controlled by black magic. He looks like the warrior ; strong but stupid
- A Vampire : I don't need to explain what's a vampire, he sucks you, and gains life
- A Medusa : The horrible monster of the mythology, she can petrifies you by his look

![Diagram of Actors](http://www.plantuml.com/plantuml/svg/rLVXRkCs3FxVfn0mO6XloM4Fq1kkmuQrFwxjbkrk_SdOJABLbWo9RjTqjsUVR3bCeZ2EinO7N86WjlX99B-FbEJtdi1HNHOdAloXgKjrGGJPVVl-VAAwluiRWwFrs--FTlDjuH3RryydxJ-OUdAGaRf4PvELlWacRURAG8ay-FRjsguDAPZhGjFJzc3uOL7eEPeCjorXIJHpMeZhvRQU5gWMrSvGLhimZouhSTxLpVGl33cygIPKpsOYPcfjeRI_BU09NJASstoEr_WtxSsoilxFdP4x2VxTZq6Is_1Jq-w1JUFn6jNGVNgctgaS2oHC30tZenMreoqwHqpXA10rKZ7b4QTsbYoLMUEZkkfRoT_pgW8-gtzZK1jPgL-G29tVIh2hYZdIDPGOacXTdAm1sb1ZlOZXCo2rNsrajHSqwP8Lt7Ib4K2NbM3ceWY0bYC1qwZVXjAHjp-Psr00R1MCTpq1CXM_0MdBm0INKd88pDIaG1Pl8eZtO7Mk_8OugIcocOv60kvEjQ6s77S0ZvgonKzD7-rChgiS24M7R4rzic6jlzXiNLStZaDDRe3OWf1Bt7pKZceemgFO2Z42Zx66JhcMcWxwVl-Cfb6RrzEstzwCkXtwm2o_i8-h60yZ9mIaFUdCItdTLEY0RA9wR7_RsTuTt1HcJgF9bGtE4ShrpFFpKnuRgQrLkaFbVPZNd55yMcsVCXlRx_FQ7JSVHvAOZjyGp-GTZZtP1tHEvzYwd45Ta5XVU-k05pYsg7Bjgn14B0oMa9Vxd_KbJvSBJVJO8rvMWFVg4mIqJQKRj-jYG2z-hU4Uky3E4a1LcspHsJh_2S8_MfTFo6bUWt72wHc34Ik6RQzLCknhUCqSbZb1z-WguMKXXuYeb-3oLCFWNPLWGCfct6MpN3vDga1WhuXp3OO-mSCG2MCeWe9iUYq1sTCW_VXG_m06LXmdz6VWIMRZgwg6QyoS3S9dABTr1i5jyUJBFLrTw1bE285f48NUy9AgdTfVJV9jdyDqRrDoskCV9aV8EQUlJDJLvqUgg6-ydVC1zeCg9xJlusIrHl3FbCb4hv02JhYcNLlwkQpuaw2t_IPwYRquJeLinS1TQsrY9ljrh1exuyya7Phu1zvmRghA6ZIKtd5Mus8Fi75m0-mfV5veQDMFZxZXZ8yg-x5SnaVUcUJUoHRW57037NMHkJ8pT5hSyAQ5Dddnr7l6wRAqqo3F4dqlBWmLKCyNDE0iZ249bS6cbzO5U-YlYcEthCDiVy2yzY2oNI4vFTCPaBQc_t8O5icm7sBW7cDy0mYFKGc4i-cbXBE7BqtuHoWhxL2kRw0UYfZAEhldsavj6JWSG70NXS0msrvCCVluWXotayx_6OytlsHvS7lpZmx2A1_9xN2S6F7yKPMEypszUup3cnUsniZ-eZaskM3W9amCN2nTily1.svg)

## Objects

Objects are there to give a plus to the game. They are mainly weapons, but some are potions. Weapons give a benefit to the player, and potions boost the statistics.

Among them we can find
- A magic wand, for the wizards
- Potions of Agility, Heal and Strength, to boost the hero's statistic
- A scepter, for the necromancers
- A shield, for the opponents, it's their object per default
- A sword, for the warriors

Potions can be found and collected by moving in the map, but weapons are fixed since the beginning for each type of heroes.

![Diagram of Object](http://www.plantuml.com/plantuml/svg/pPRTRjCm5CVl-nIMa50Zbea706dSy741JEhug10NRdoM6RbsPPziciPuTfpvpCJpoJJWeijDu_Ft-V3ldxGz2YWz3bkp4F7I5i6VoWx4ku-R7z3XJVHg8UXw4ZU8dGjVgyWwHmuFy-spAxa9w6M7r-8NLLmsugLGS2e7WvCSyGOmzYwonz8zu77i5xCwPmDoufh4ejogBdVkj18XrLilO_x1UDvcclLPHnRIp9s1Uhu6YOE7sxRnFC_PxV5JstxC-22tzVRhnH5ODQ8lJUYC346ybxtklaYhxbZG9k0Nu5dYEQtcNCfqz2gUPinhyRJXxPmsSkVWlLPGToncu_7bx78ZKQjttOSExB0L9vSxE7QedRs3xbMlZSRBl7uBqkJ52ZtO7i-e_iI9kXPlG_kdiHYmRDNIip0EUE9Yhs_VMKGfdVUEj9kc1xSTcafFkD9YrhqaFzowoT5wm4-fDtdpdsOJcN_ncmnQTR13y7_teb0IYpgBz9AKKI9Cgrd4fFECzqtiJ8DH7B3WZ5RHMtR2bCOY8us8bK42bXQpl9ByS5pA3Hi3meCQEbZHsCiKRVOE-C9vbg-IMza3JpVci7198hPbZD36-tl8ZkeZUmxftu1uyRDjoz-wKg8ltofERrSbq5DMnSaH6kOt)

## Game
![Diagram of Game](http://www.plantuml.com/plantuml/svg/bLNXJjim4FxFK_ZNbAvfNs0RGi06aqQffareFrtdI2mIsxAlBHrYpxxOJkh5Je1LQbBVVNTdttsVUsQGQjmszGbfFo2s3VcnrSAjdkpJVTOrFO3EZ-jRfQG0WSxmVE9UhAR6a7EAM4CKljX8MHDkRdUWW_4Qj2JlbKsTM6KeqDdjhWYsZyYqvq90Y5ykewgi0lQmsZORq9cceeIS2BUQ4IQ5mJ7uBp0hcHtiCw3I_3l92r9mOu-GnK3l5V28TflPB7BuOu-w-hEFEMqH1WKazdjULfZvvkN4lzF48CufUrYttudzAWsAQhYKHGbTjWIuEFwS-sctkJwH0cf0I5nJEve_qOr1JHa-apzzch4kptra2NZd9ftDFdIiEmDHMEAEKFYIQs38PSpZdofm-1lSOrXTohq8g--scs6vadWZTz3L3MNyZjwcbK4w0QbohcYJwEQ6AiAsMeF0zcUmSu54RFhC9dQifJsxIVHdjyP5cRPvKeqxO2ZrH-yy9JKt65SDA5-snuLDfCLyuqXvznRnVd7KPXLzIR9sFWq8p8wZxpdtgeAfKlKX53d6ZS7ICeb0ARBAdpspqtZCYNqTPlzrRnZ0jJJSTJ2RZMhFygLpXVMU5rZbf097u7yvCY6zACjoIQu04RGPQD3oi0JBmMI_yuWY9GI6nE11Jj-jIae3NZAPe0tC8W288YtfF5nmvBJclo6BWtnZ9w-9eBbUL4z31Rak3aske-CaQgZgJf-J2obrmGL5CAUaQet7AGxmdLII2ENC8p6BmIow2_UURciSE8RpdnYvnRqwSNjcU-VQVEa0Ek-rA_FYbBkRvu8Q-DmeF6Ij7WvTG8BgYRC2gXFWvF_2P5G4tLVogna7-75O26TL2afg3nJiih_BoL08EOblnN4QRrL14R84F0qBDSR_CEygYbQm-_QTdcLI4VOc87AnSABe87y1)

# How To Play

When you start the `rpg.exe` file, you'll have a welcome message, with a short description of the project. If you don't want to see the welcoming message, just type directly
> `.\rpg.exe --start`

Then the program will start, you'll enter you name, and the game start.

Each turn, a map is displayed in the shell, and you can choose the next direction of you player, by typing
- `w` for Up
- `a` for Left
- `s` for Down
- `d` for Right

When you're near an opponent, you have the choice to fight him or not. If you choose to fight, you'll have a menu with choices, for example you can choose between opening you backpack, fighting, preparing to dodge or conceding.

When you try to dodge, your chance is increased by 20% compared to usual. If you choose to fight, then you have the choice between 3 different attacks, with different damages.

The game is finished when you're dead, or if you win against all the opponents. Per default, the number of opponent is 3, but you can change in line number `34`, in the game's constructor.

# Improvements