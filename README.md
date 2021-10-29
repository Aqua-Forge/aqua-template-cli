<h1>Aqua Template CLI</h1>

Automatically generates a project template of the specified language/technology.

---

<h3>Index</h3>

- [Dependencies](#dependencies)
- [Installation](#installation)
- [How to Use](#how-to-use)
  - [Basic usage](#basic-usage)
  - [Help](#help)
  - [Display languages](#display-languages)
- [Custom templates](#custom-templates)
  - [Customizing a template](#customizing-a-template)
  - [Adding a template](#adding-a-template)

---

# Dependencies

- [Ubuntu](https://ubuntu.com/download)
- [C++17](https://en.cppreference.com/w/cpp/17)
- [G++](https://linuxconfig.org/how-to-install-g-the-c-compiler-on-ubuntu-20-04-lts-focal-fossa-linux)
- [Make](https://www.gnu.org/software/make/)

---

# Installation

In this root directory, compile the project with the `make` command:

```shell
$ make
```

Then, install it (make it useable from anywhere as a command):

```shell
$ sudo make install
```

If you wish to change the installation locations and/or the command name, modify the `PREFIX` and `TARGET` variables in Makefile.

Finally, to add auto-completion to the aqua-template command, run the bash script:

```shell
$ source ./scripts/add_completion.sh
```

or, simply:

```shell
$ . ./scripts/add_completion.sh
```

---

# How to Use

This tool can be called with some command line arguments as:

## Basic usage

For generating a project, simply type:

```shell
$ aqua-template
```

You'll be asked for the project name and its language/technology.

Alternatively, you can pass those info by arguments:

```shell
$ aqua-template -n <project-name> -l <language>
```

or

```shell
$ aqua-template --name=<project-name> --language=<language>
```

Example:

```shell
$ aqua-template -n "Hello World Project" --language=cpp
```

## Help

In order to display help about the tool and all arguments type:

```shell
$ aqua-template -h
```

or

```shell
$ aqua-template --help
```

## Display languages

To display all template languages/technologies available for generation type:

```shell
$ aqua-template -d
```

or

```shell
$ aqua-template --display
```

---

# Custom templates

In order to customize or add templates, navigate into the template's save path: `/usr/local/etc/aqua-template/templates`

## Customizing a template

To customize a template, simply modify the base project of the language/technology in the save path.

## Adding a template

Simply add your language/technology template root directory to the save path. Then, when you use the command `aqua-template`, the added template will be available for generation.
