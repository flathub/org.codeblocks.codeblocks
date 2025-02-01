/app/share/ide-flatpak-wrapper/first_run.h

------------------------------------------------------------------------------------
| Warning: You are running an unofficial Flatpak version of Code::Blocks IDE !!! |
------------------------------------------------------------------------------------
Note: THIS IS A DEVELOPMENT VERSION, ERRORS MAY BE FOUND, IN THE TESTS CARRIED OUT THE PROGRAM HAS WORKED PROPERLY.
Please open issues under: https://github.com/flathub/org.codeblocks.codeblocks/issues
For updated information visit: https://github.com/flathub/org.codeblocks.codeblocks/blob/master/README.md


WORKING WITH THE SDK AND ITS EXTENSIONS
--------------------------------------------------------------

This version is running inside a container and is therefore not able
to access SDKs on your host system!

This flatpak provides a standard development environment (gcc, python, etc).
To see what's available:

  $ flatpak run --command=sh org.codeblocks.codeblocks
  $ ls /usr/bin (shared runtime)
  $ ls /app/bin (bundled with this flatpak)

To get support for additional languages, you have to install SDK extensions, e.g.

  $ flatpak install flathub org.freedesktop.Sdk.Extension.dotnet
  $ flatpak install flathub org.freedesktop.Sdk.Extension.golang

To enable selected extensions, set FLATPAK_ENABLE_SDK_EXT environment variable
to a comma-separated list of extension names (name is ID portion after the last dot):

  $ FLATPAK_ENABLE_SDK_EXT=dotnet,golang flatpak run org.codeblocks.codeblocks

To make this persistent, set the variable via flatpak override:

  $ flatpak override --user org.codeblocks.codeblocks --env=FLATPAK_ENABLE_SDK_EXT="dotnet,golang"

You can use

  $ flatpak search <TEXT>

to find others.


Using the Code::Blocks plugin
--------------------------------------------------------------

The Code::Blocks plugin org.codeblocks.codeblocks.Plugin.devtools, adds development tools, contains:
- sfml2
- sfml3
- wxWidgets3.2
- raylib5
- fltk1

They are installed in /app/plugins/devtools/ with the structure:

├── bin
├── include
│   ├── FL
│   ├── GL
│   ├── GLFW
│   ├── SFML3
|   |   └── SFML
│   └── SFML2
│       └── SFML
├── lib
│   ├── SFML3
│   |   ├── cmake
│   |   └── pkgconfig
|   └── SFML2
        ├── cmake
        └── pkgconfig

For example, to configure a project with SFML3 you must indicate the use of headers and libraries,
in Proyect-> Build Options-> Search directories, having created a project for SFML2.
* /app/plugins/devtools/include/SFML3 (Add to Compiler)
* /app/plugins/devtools/lib/SFML3 (Add to Linker)

For SFML2,
* /app/plugins/devtools/include/SFML2 (Add to Compiler)
* /app/plugins/devtools/lib/SFML2 (Add to Linker)


ROLLBACK TO VERSION 20.03
--------------------------------------------------------------

If you want to install version 20.03 of Code::Blocks you must install the current version and then run,

sudo flatpak update --commit=5e9b0df4e7c901558d22c8c28cd51177fa7d486d9c88bab64d8691d0345ebeaf org.codeblocks.codeblocks//stable


Adjust Theme
--------------------------------------------------------------
If you want Code::Blocks to match the system theme, the set theme must be located in the ~/themes path.
