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
# Table of Contents

- [Project Overview](#project-overview)
- [Table of Contents](#table-of-contents)
- [Description](#description)
- [UML Diagrams](#uml-diagrams)
    - [Global](#global)
    - [Actors](#actors)
    - [Objects](#objects)
    - [Game](#game)

# Description
# UML Diagrams
## Global
![Diagram of Global](http://www.plantuml.com/plantuml/svg/RP71Zi8W48RlVGhEc_GDzj3iPUsXjec9FOymAbeOCgKn6XzUX3P6XOI4__l8Ju1gzC1-CaCXmlW7WuBAKgoGwPqqu29u6l5x3wGRu8hy0LldoABrB_mJw1_8SnTcf4k8jNMxEw7qOpHBI5KD7BJimQgCwyXhiXcnaUWySiuSDGug9ox4YQSR9Te3ioR-vle6QVkyJ7YDaic0bVFPopiaMziziiw81jKqGaPimJZDM5HeLVYT1m00.svg)
<br></br>
## Actors
![Diagram of Actors](http://www.plantuml.com/plantuml/svg/rLVXRkCs3FxVfn0mO6XloM4Fq1kkmuQrFwxjbkrk_SdOJABLbWo9RjTqjsUVR3bCeZ2EinO7N86WjlX99B-FbEJtdi1HNHOdAloXgKjrGGJPVVl-VAAwluiRWwFrs--FTlDjuH3RryydxJ-OUdAGaRf4PvELlWacRURAG8ay-FRjsguDAPZhGjFJzc3uOL7eEPeCjorXIJHpMeZhvRQU5gWMrSvGLhimZouhSTxLpVGl33cygIPKpsOYPcfjeRI_BU09NJASstoEr_WtxSsoilxFdP4x2VxTZq6Is_1Jq-w1JUFn6jNGVNgctgaS2oHC30tZenMreoqwHqpXA10rKZ7b4QTsbYoLMUEZkkfRoT_pgW8-gtzZK1jPgL-G29tVIh2hYZdIDPGOacXTdAm1sb1ZlOZXCo2rNsrajHSqwP8Lt7Ib4K2NbM3ceWY0bYC1qwZVXjAHjp-Psr00R1MCTpq1CXM_0MdBm0INKd88pDIaG1Pl8eZtO7Mk_8OugIcocOv60kvEjQ6s77S0ZvgonKzD7-rChgiS24M7R4rzic6jlzXiNLStZaDDRe3OWf1Bt7pKZceemgFO2Z42Zx66JhcMcWxwVl-Cfb6RrzEstzwCkXtwm2o_i8-h60yZ9mIaFUdCItdTLEY0RA9wR7_RsTuTt1HcJgF9bGtE4ShrpFFpKnuRgQrLkaFbVPZNd55yMcsVCXlRx_FQ7JSVHvAOZjyGp-GTZZtP1tHEvzYwd45Ta5XVU-k05pYsg7Bjgn14B0oMa9Vxd_KbJvSBJVJO8rvMWFVg4mIqJQKRj-jYG2z-hU4Uky3E4a1LcspHsJh_2S8_MfTFo6bUWt72wHc34Ik6RQzLCknhUCqSbZb1z-WguMKXXuYeb-3oLCFWNPLWGCfct6MpN3vDga1WhuXp3OO-mSCG2MCeWe9iUYq1sTCW_VXG_m06LXmdz6VWIMRZgwg6QyoS3S9dABTr1i5jyUJBFLrTw1bE285f48NUy9AgdTfVJV9jdyDqRrDoskCV9aV8EQUlJDJLvqUgg6-ydVC1zeCg9xJlusIrHl3FbCb4hv02JhYcNLlwkQpuaw2t_IPwYRquJeLinS1TQsrY9ljrh1exuyya7Phu1zvmRghA6ZIKtd5Mus8Fi75m0-mfV5veQDMFZxZXZ8yg-x5SnaVUcUJUoHRW57037NMHkJ8pT5hSyAQ5Dddnr7l6wRAqqo3F4dqlBWmLKCyNDE0iZ249bS6cbzO5U-YlYcEthCDiVy2yzY2oNI4vFTCPaBQc_t8O5icm7sBW7cDy0mYFKGc4i-cbXBE7BqtuHoWhxL2kRw0UYfZAEhldsavj6JWSG70NXS0msrvCCVluWXotayx_6OytlsHvS7lpZmx2A1_9xN2S6F7yKPMEypszUup3cnUsniZ-eZaskM3W9amCN2nTily1.svg)
<br></br>
## Objects

Objects are there to give a plus to the game. They are mainly weapons, but some are potions. Weapons give a benefit to the player, and potions boost the statistics.

Among them we can find
- A magic wand, for the wizards
- Potions of Agility, Heal and Strength, to boost the hero's statistic
- A scepter, for the necromancers
- A shield, for the opponents, it's their object per default
- A sword, for the warriors

Potions can be found and collected by moving in the map, but weapons are fixed since the beginning for each type of heroes.

![Diagram of Object](http://www.plantuml.com/plantuml/svg/nPNDRjGm4CVl-nIMaD16D1KF05Avy740ActvM24ENdkQ6ZdsofwqgafvTfnwDiJ9H7nms5nQptZcF_xzuyrPH1cmQ-rAfCSuX70f5OWtxtVVGE53z6ubw7cKDeYzZvzdaUqGEJqT_dro9tSHWrHuBtvGntKbdWiDbxApEAeHhm2JTb7Tjsu0pvDUgbBUHUIIMqeMxJRpTjVUQ15pl-qwrP_qvwt6LHzDOY7jqXb8yoL8x08SPDDvdhBRqr_ZchxYdMpds-zNP-1qZxuqGLaPetWh6wC-IQSd5jGP-0q4blXGLd1cqdJqMJpFEAp5uugtanLYHrgWvgyX1AEXt4Ym-5rBnC1rhRYutSEvH-FTXDYBnbY3jyFwDKWxB3OOm3LuHVr71h2z6FhrBs7HOIbLqolG3tZXazQNhooYNCvRHha7qPE3GZNBPrnviMZQe7F0-XlhHaTh03zaRVBcFyqcCl_YDncqKR1727ztFwY8Hqr9kXkJA16crI9YNk2ueAuCMCrnYjuQdInb9ynbF2dA4QWYI9poOX5JJl_vcwXzjxCW0kXEmOR6NkTeTNJ0DpwmVBLiPGCytLJ3mQKKiIrYX3RBBPDDMHxiyJ3Hjryy-rxNvPUjJD5lxYnEbuf9qAizYPCZDCnF.svg)
<br></br>
## Game
![Diagram of Game](http://www.plantuml.com/plantuml/svg/bLNXJjim4FxFK_ZNvAnfNs0RGi06aqQffareFztaI2mIEx8lBHrYpxxOJkh5Je1LQbBVVNTdttsVUwQHAMphweHq7n1jJNwqIjZLatdQpwPY1r3fSNtRD5A0G6juFh6lh69QatE6M44GlkJwTWVAhwz1IVA-CLaZg-npUxlP4C7k4PZsN0ZmyQkLzs-bh4XMGlQmRkijAAgOA20bmguIaacXSGh-2_HQqeDvUbISVoTvJdAkpH5e27HU0OzejacJmE6EFUaQpZxbD4Koo26ot_EYHEgQbnBtZXE3E6VPmwRxpkotKT0m1PSoBw3F5W6NnvyBD-WkroUIGmK8aMjkHuidjjMeM8RFvC-GPghB2nTP0DxPITFaGq-uCn2vuUm4Uo-vWWov32dyi_7q_GRtw5UNSY_ywhlffb-k9Tx87VHrVHctexV9P9HEG2oQArP7ahbX3SbQfK1WzzFRkK0YjaDc7JesqfnT1zJcscoDYo9kywmQTv2XL1-TyvHKN6DOrQDSsG7dDn4NSuqZnTrRnFl5KZihsKkIDVEfGI0zZdxWtAiAParJ7NoHOzmKB2uJ2PHXLhgpKpEDnvIOro7vhtj30swavhQ3D9dKdk4BJOBrdkTOfgG4I-1_EJ8ZlI3BQaMk016K7cdGyB00my5eluk08WLuXeJWKKxNhL9A3KuoLB0QaW008e-oE0yN73ch-6-WOP1hxEmruJKtYEffh23RnR79TNIIH3Lh-jEdv49AbNF14FGfAJlZSOfZl2D85D5OyqJCSZIB_iAzPss5OyTe_ZCZDxXN9sxEREvSaoyOWFTUsp8lJhc_UIwOXizrWmVQwU7G1qIeWJXhO2e6plqlp4M5q7qfl-ffW1k7WV2iZ45HxP62RVPtAHaB8INXhJXDuxR96GADmFCmNsFw3_EkP6W4k-_UqLdc5M5k0YANIoEA0V8N.svg)