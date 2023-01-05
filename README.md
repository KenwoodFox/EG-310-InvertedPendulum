[![Display Hardware](https://github.com/KenwoodFox/EG-310-InvertedPendulum/actions/workflows/hardware_workflow.yml/badge.svg)](https://github.com/KenwoodFox/EG-310-InvertedPendulum/actions/workflows/hardware_workflow.yml)
[![Firmware Workflow](https://github.com/KenwoodFox/EG-310-InvertedPendulum/actions/workflows/firmware_workflow.yml/badge.svg)](https://github.com/KenwoodFox/EG-310-InvertedPendulum/actions/workflows/firmware_workflow.yml)
[![Discord](https://img.shields.io/discord/914358168379867216.svg?label=&logo=discord&logoColor=ffffff&color=7389D8&labelColor=6A7EC2)](https://discord.gg/Eczua62m7v)

EG-310 Inverted Pendulum
========================

This project is full of blank media! It will need filling out and cleaning before production, you have been warned!

# Welcome!

Put a welcome here!

# Getting Started

## Cloning this repo

First, clone this repo (and optionally checkout a branch)

```shell
git clone https://github.com/KenwoodFox/InvertedPendulum.git
cd InvertedPendulum
```

## Init Submodules

Some libraries and resources are included as git submodules, run the following
command to initialize them before opening the main sch

(If you get a missing library error, make sure to do this!)

```shell
git submodule update --init --recursive
```

# Where is everything?!

Look to...
```shell
├── CAD                     # CAD and design files
├── Firmware                # Software and Firmware source code
├── Hardware                # PCB And component design files
└── Media
    ├── Notes               # Notes and scratch ideas/misc resources
    ├── Letters             # Status letters, letters of request, etc
    └── Presentations       # Presentations (CDR, FDR..)
```

# I just want to edit a single file!

Start by cloning this repo down and making a new branch, offical team communication
is through discord so hop on over any time! If you're new to git check out this video: https://youtu.be/mJ-qvsxPHpY
