# Ideas

```
[3:06 PM]KW1FOX: i know the steps are not fine, it will step and stop every time at a very fast level, but a nice smooth modulation of the steps would make me happy :3
[3:07 PM]Kaede: well, learn about fractional division in context of frequency dividers
[3:08 PM]Kaede: such algorithm even flew as Bell202 modulator
[3:08 PM]KW1FOX: Ive actually used bell202 lol haha~ I could do that for sure but, idk, still seems clunky, would it actually be inappropriate to set one of the HW timers almost every cycle?
[3:09 PM]KW1FOX: I see what ur saying tho i can just choose not to execute a step if im dividing the "fundamental" timer frequency
[3:10 PM]Kaede: you don't need to change timer division ratio on every timer overflow
[3:10 PM]Kaede: but then you need to clock second timer from output of first
[3:10 PM]Kaede: see old PLL loops with prescaler
```


# Possibly this idea?

Slow speed        |....|....|....|....|....|....|
Fast speed        |..|..|..|..|..|..|..|..|..|..|
Very fast speed   |.|.|.|.|.|.|.|.|.|.|.|.|.|.|.|

Timer             |||||||||||||||||||||||||||||||
