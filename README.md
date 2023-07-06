# Calculator app
It's a basic calculator we wanna expand in future

## Prerequisites
In order to start contributing to the project, you should go through installation process

### Apps and libraries
- Git or Git Desktop (Windows only)
- VSCode (IDE)[^1]
[^1]:Just install the IDE from [official website](https://code.visualstudio.com/download) if you don't have it yet
- NodeJs[^2]
[^2]:NodeJs is an app that lets us install different JS libraries onto our system using npm. In order to install it, just go to [this website](https://nodejs.org/en), download and install LTS version
- Python3[^3]
[^3]:Python won't be used in a project itself, but it is required for *emsdk library*. In order to install python, follow [this tutorial](https://realpython.com/installing-python/#how-to-install-python-on-windows)
- emsdk library[^4]
[^4]:The library lets us convert `.cpp/.c/.h` files into binary (WebAssembly so to speak, or wasm). Without it, nothing will work
  > We will install the library globally, so you won't have to install it again if you will use it in other project. But if you want, you can surely just install it in our project repo, just don't commit it by defining a rule in `.gitignore` file
  - Open cmd. Go to a folder to which you want to install the library using 'cd' command
  - Go through the tutorial on [this website](https://emscripten.org/docs/getting_started/downloads.html). It's an official guide on installation.
  > **Don't forget to read the key notes for each OS**
  - To define the library globally, use [this guide](https://docs.oracle.com/en/database/oracle/machine-learning/oml4r/1.5.1/oread/creating-and-modifying-environment-variables-on-windows.html#GUID-DD6F9982-60D5-48F6-8270-A27EC53807D0) as a reference.
  > **Don't create a new system variable**. Just choose preexisting PATH variable, add a path to your emsdk folder to it, and confirm your choice

### Repo setup
Now we can start setting up the repository. I hope you installed every single app and library from above. Otherwise, nothing will work
<!-- Add seperate tutorials for Git and Git Desktop -->
1. Go to a folder where you want to put this repo
2. Open cmd and use `cd` command to go to newly created folder
3. Copy the SSH key of this repository
> ![image](https://github.com/QuarterPL/Calculator/assets/85429908/fa519119-d078-4ff6-af46-2898aaf94bc6)
4. Print `git clone {INSERT THE SSH KEY}`
> Press *enter* after each command
5. Print:
```bash
emsdk activate latest
source ./emsdk_env.sh
code .
```
Now you've configured emsdk library and opened the repo. If VScode suggest you any libraries, install them. After that, restart VSCode and boot it again from cmd by printing `code .` again. The last step we need to do is install all required JS modules using npm. Just print `npm i` in cmd and you're done

## Environment
Now let's have a tour over the codebase. Firstly, open up VSCode console by pressing ctrl+shift+~. Look at upper right corner of it. If it doesn't say `git bash` or `bash`, click the arrow to the right of plus key, choose one of those and click on them. Now choose the previous console from the newly opened menu, and click the trash bin icon. Now we're ready to proceed

### Files
Here is the code structure of the repo. If you are only going to contribute to the calculator functionality, not the website as a whole, you should worry only about `bundle.c` and be aware of `package.json`
> ![image](https://github.com/QuarterPL/Calculator/assets/85429908/2de2de66-d7fd-4c65-b5d0-534ca3fe44be)
- bundle.c: This file is the meat of the calculator. There you define all its functionality using functions. Before each function, you must type `EMSCRIPTEN_KEEPALIVE`. This will tell emsdk that the function should be exported
- package.json: This configuration file is required for the system in order to make the environment setup and testing easier. The `dependencies` and `dev-dependencies` tell npm which packages should be installed (we installed those using `npm i`). `Scripts` are quick commands that do one or more actions for us. They are defined by contributors themselfs, meaning that any possible bash commands can be executed using these scripts. In order to run a script, simply print `npm run {INSERT COMMAND NAME}` in the console (either cmd or VSCode one)
    - "build:c": it's used when you just want to export all functions from `bundle.c` to binary (`.wasm` file)
    - "build:site": it's used when you want to compile the whole website, both bundle.c and all JS files, but don't run the website
    - "run": does compile the whole website as build:site, but also locally runs it in the browser
