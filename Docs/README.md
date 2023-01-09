Using the documentation
=======================

[![.github/workflows/make-docs.yml](https://github.com/KenwoodFox/EG-310-InvertedPendulum/actions/workflows/make-docs.yml/badge.svg)](https://github.com/KenwoodFox/EG-310-InvertedPendulum/actions/workflows/make-docs.yml)


Storing docs alongside code is a common practice  
in the industry, it allows for syncronous updates  
to both the documentation for a product and the software  
itself, keeping them in sync.


# Requirements

There may be more, if you find we need to add extra reqs to this list, please make a new issue

## Arch

```shell
$ sudo pacman -S texlive-latexextra
```

## Ubuntu/Debian

```shell
$ sudo apt install texlive-latex-extra
```


# Getting started with these docs

To build a presenstation, first you must be in this directory:

```
$ cd docs
```

all the doc building is automated via Makefile, to build  
all of the presentations for example, run the following:

```
$ make pres
```

it will generate all of the presentations in `_build/pdf`
